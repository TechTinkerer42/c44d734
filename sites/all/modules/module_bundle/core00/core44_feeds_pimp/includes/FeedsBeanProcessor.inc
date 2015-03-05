<?php

/**
 * @file
 * Class definition of FeedsBeanProcessor.
 */

/**
 * Creates beans from feed items.
 */
class FeedsBeanProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'bean';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Beans');
    return $info;
  }

  /**
   * Creates a new bean in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    
  module_load_include('module', 'bean');  
  $bean = bean_create(array('type' => 'basic_block'));
//  $bean->label = 'Administrative Label';
  $bean->title = '';
  $bean->changed = REQUEST_TIME;
  $bean->created = REQUEST_TIME;  
  $bean->log = 'Created by FeedsBeanProcessor'; 
  $bean->uid = $this->config['author'];   
/*
  $bean->field_block_content = array(
    'LANGUAGE_NONE' => array(array(
      'value' => '<p>Text</p>',
      'format' => 'plain_text',
    )),
  );
*/
  //$bean->save();
  return $bean;
  }

  /**
   * Loads an existing bean.
   *
   * If the update existing method is not FEEDS_UPDATE_EXISTING, only the bean
   * table will be loaded, foregoing the bean_load API for better performance.
   *
   * @todo Reevaluate the use of node_object_prepare().
   */
  protected function entityLoad(FeedsSource $source, $bid) {
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      
      /**
      * Load the bean
      */
      $bean = bean_load($bid, NULL, TRUE);
    
    }
    else {
      // We're replacing the existing bean. Only save the absolutely necessary.
      $bean = db_query("SELECT bid, type FROM {bean} WHERE bid = :bid", array(':bid' => $bid))->fetchObject();
      $bean->uid = $this->config['author'];
    }
    
    /**
    * Prepare the bean object
    */
    bean_create($bean);
    

    // Populate properties that are set by node_object_prepare().
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $bean->log = 'Updated by FeedsBeanProcessor';
    }
    else {
      $bean->log = 'Replaced by FeedsBeanProcessor';
    }
    return $bean;
  }


  /**
   * Check that the user has permission to save a bean.
   */
  protected function entitySaveAccess($entity) {

    // The check will be skipped for anonymous beans.
    if ($this->config['authorize'] && !empty($entity->uid)) {

      $author = user_load($entity->uid);

      // If the uid was mapped directly, rather than by email or username, it 
      // could be invalid.
      if (!$author) {
        $message = 'User %uid is not a valid user.';
        throw new FeedsAccessException(t($message, array('%uid' => $entity->uid)));
      }

      if (empty($entity->bid)) {
        $op = 'create';
        $access = bean_access($op, $entity->type, $author);
      }
      else {
        $op = 'edit';
        $access = bean_access($op, $entity, $author);
      }

      if (!$access) {
        $message = 'User %name is not authorized to %op content type %content_type.';
        throw new FeedsAccessException(t($message, array('%name' => $author->name, '%op' => $op, '%content_type' => $entity->type)));
      }
    }
  }

  /**
   * Save a bean.
   */
  public function entitySave($entity) {
    bean_save($entity);
  }

  /**
   * Delete a series of beans.
   */
  protected function entityDeleteMultiple($bids) {
    $beans = bean_load($bids);
    foreach ($beans as $bean) {
      bean_delete($bean);
    }
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'bean_type' => '',
      'expire' => FEEDS_EXPIRE_NEVER,
      'author' => 'Anonymous',      
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {    
    
    $types = $this->bean_get_type_names();
    
    array_walk($types, 'check_plain');
    $form = parent::configForm($form_state);
    $form['bean_type'] = array(/*

      '#type' => 'select',
      '#title' => t('Bean type'),
      '#description' => t('Select the bean type for the beans to be created. <strong>Note:</strong> Users with "import !feed_id feeds" permissions will be able to <strong>import</strong> beans of the bean type selected here regardless of the bean level permissions. Further, users with "clear !feed_id permissions" will be able to <strong>delete</strong> imported beans regardless of their node level permissions.', array('!feed_id' => $this->id)),
      '#options' => $types,
      '#default_value' => $this->config['bean_type'],
    
*/);
    //dsm($form);
    $form['input_format'] = array();
    $author = user_load($this->config['author']);
    $form['author'] = array(
      '#type' => 'textfield',
      '#title' => t('Author'),
      '#description' => t('Select the author of the beans to be created - leave empty to assign "anonymous".'),
      '#autocomplete_path' => 'user/autocomplete',
      '#default_value' => empty($author->name) ?  'core44' : check_plain($author->name),
    );

    $form['update_existing']['#options'] = array(
      FEEDS_SKIP_EXISTING => 'Do not update existing beans',
      FEEDS_REPLACE_EXISTING => 'Replace existing beans',
      FEEDS_UPDATE_EXISTING => 'Update existing beans (slower than replacing them)',
    );
    return $form;
  }

  /**
   * Override parent::configFormValidate().
   */
  public function configFormValidate(&$values) {
    if ($author = user_load_by_name($values['author'])) {
      $values['author'] = $author->uid;
    }
    else {
      $values['author'] = 0;
    }
  }

  /**
   * Reschedule if expiry time changes.
   */
  public function configFormSubmit(&$values) {
    parent::configFormSubmit($values);
  }

  /**
   * Override setTargetElement to operate on a target item that is a bean.
   */
  public function setTargetElement(FeedsSource $source, $target_bean, $target_element, $value) {
    if($target_element == 'type'){

      $types = $this->bean_get_type_names();
      array_walk($types, 'check_plain');
      foreach($types as $machine => $label){
        $types_machine[$machine] = $machine;
      }
      if(in_array($value,$types_machine)){
        drupal_set_message(t('The bean type %beantype has been found and will be used.', array('%beantype' => $value)));                
      }else{
        $plugin_info = _bean_admin_default_plugin();
        $plugin_info['name'] = '';
        $new_bean_type = new BeanCustom($plugin_info);
        $new_bean_type->type = $value;
        $new_bean_type->setLabel(t($value));
        $new_bean_type->setDescription('System generated bean type');
        $new_bean_type->save(TRUE);
        drupal_static_reset();
        drupal_set_message(t('The bean type %beantype has been generated.', array('%beantype' => $value)));        
      }
/*
      if (  $this->bean_type_get($value) !== FALSE) {  
            dsm("New Type = ". $value);
          }else{
            dsm("No New Types");
      }
*/
    }
    
    switch ($target_element) {
      case 'created':
        $target_bean->created = feeds_to_unixtime($value, REQUEST_TIME);
        break;

      break;            
      
      case 'feeds_source':
        // Get the class of the feed node importer's fetcher and set the source
        // property. See feeds_node_update() how $node->feeds gets stored.
        if ($id = feeds_get_importer_id($this->config['bean_type'])) {
          $class = get_class(feeds_importer($id)->fetcher);
          $target_bean->feeds[$class]['source'] = $value;
          // This effectively suppresses 'import on submission' feature.
          // See feeds_node_insert().
          $target_bean->feeds['suppress_import'] = TRUE;
        }
        break;
      
      case 'uid':
        if ($user = user_load($value)) {
          $target_bean->uid = $user->uid;
        }
        break;            
      
      
      default:
        parent::setTargetElement($source, $target_bean, $target_element, $value);
        break;
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    //$type = node_type_get_type($this->config['bean_type']);
    
    $targets = parent::getMappingTargets();
    
    $targets['uuid'] = array(
      'name' => t('UUID'),
      'description' => t('UUID of the bean.'),
      'optional_unique' => TRUE,
    );
    $targets['delta'] = array(
        'name' => t('Bean delta'),
        'description' => t('The beans block delta.'),
        'optional_unique' => TRUE, 
    );
        
    $targets['label'] = array(
        'name' => t('Bean label'),
        'description' => t('The human-readable name of this bean.'),
    );
    $targets['bid'] = array(
        'name' => t('Bean ID'),
        'description' => t('The bid of the bean. NOTE: use this feature with care, bean ids are usually assigned by Drupal.'),
    );
    $targets['type'] = array(
        'name' => t('Bean type'),
        'description' => t('The beans block type.'),
    ); 
    $targets['view_mode'] = array(
        'name' => t('Bean view mode'),
        'description' => t('The default view mode of the bean.'),
    );                            

    // Include language field if Locale module is enabled.
    if (module_exists('locale')) {
      $targets['language'] = array(
        'name' => t('Language'),
        'description' => t('The two-character language code of the bean.'),
      );
    }

    // Let other modules expose mapping targets.
    self::loadMappers();
    $entity_type = $this->entityType();
    $bundles = $this->bean_get_type_names();
    foreach($bundles as $key => $bundle){
      drupal_alter('feeds_processor_targets', $targets, $entity_type, $key);
    }
    return $targets;
  }

  /**
   * Get bid of an existing feed item bean if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($bid = parent::existingEntityId($source, $result)) {
      return $bid;
    }

    // Iterate through all unique targets and test whether they do already
    // exist in the database.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      
      switch ($target) {     
        case 'bid':
        if ($bid = db_query("SELECT bid FROM {bean} WHERE bid = :bid", array(':bid' => $value))->fetchField()) {
          return $bid;
        }
        break;
        case 'delta':
        if ($bid = db_query("SELECT bid FROM {bean} WHERE delta = :delta", array(':delta' => $value))->fetchField()) {
          return $bid;
        }
        case 'uuid':      
        if ($bid = db_query("SELECT bid FROM {bean} WHERE uuid = :uuid", array(':uuid' => $value))->fetchField()) {
          return $bid;
        }        

        break;        
      }
      if ($bid) {
        // Return with the first bid found.
        return $bid;
      }
    }
    return 0;
  }

  /**
   * Return vocabulary to map to based on term vocabulary_machine_name.
   */
  public function bean_type_get($value) {  
      $types = $this->bean_get_type_names();
      foreach($types as $type => $label){
        if($type == $value){
          return FALSE;
        }else{
          return $type;
        }
      }
  }
  
//returns a list of available bean types
  public function bean_get_type_names() {
    foreach (bean_get_types() as $bean_type) {
      $label = $bean_type->getLabel();
      $type = check_plain($bean_type->type);
      $types[$type] = $label;
    }
    if(!empty($types)){
      return $types;
    }else{
      return FALSE;
    }
  }

}

