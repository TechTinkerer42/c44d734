<?php

/**
 * @file
 * FeedsTermProcessor class.
 */

/**
 * Feeds processor extended plugin. Create taxonomy terms from feed items with additional uuid functionality.
 */
class FeedsTermProcessorExtended extends FeedsTermProcessor {


  /**
   * Validates a term.
   */
  protected function entityValidate($term) {
    if (empty($term->name)) {
      throw new FeedsValidationException(t('Term name missing.'));
    }
    if (empty($term->uuid)) {
      throw new FeedsValidationException(t('Term UUID missing.'));
    }    
  }

  /**
   * Saves a term.
   *
   * We de-array parent fields with only one item.
   * This stops leftandright module from freaking out.
   */
  protected function entitySave($term) {
    if (isset($term->parent)) {
      if (is_array($term->parent) && count($term->parent) == 1) {
        $term->parent = reset($term->parent);
      }
      if (isset($term->tid) && ($term->parent == $term->tid || (is_array($term->parent) && in_array($term->tid, $term->parent)))) {
        throw new FeedsValidationException(t("A term can't be its own child. GUID:@guid", array('@guid' => $term->feeds_item->guid)));
      }
    }
    taxonomy_term_save($term);
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array() + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    $form['vocabulary'] = array();
    return $form;
  }

  /**
   * Override parent::configFormValidate().
   */
  public function configFormValidate(&$values) {
  }

  /**
   * Override setTargetElement to operate on a target item that is a taxonomy term.
   */
  public function setTargetElement(FeedsSource $source, $target_term, $target_element, $value) {    
    switch ($target_element) {
      case 'vocab_name':
        if (!empty($value)) {
          $target_term->vocab_data['name'] = $value;
        }
      break;      
      case 'vocab_description':      
        if (!empty($value)) {
          $target_term->vocab_data['description'] = $value;
        }
      break;      
      case 'vocab_weight':
        if (!empty($value)) {
          $weight = intval($value);
        }
        else {
          $weight = 0;
        }
        $target_term->vocab_data['weight'] = $weight;
      break;          
      case 'vocab_machine_name':
        if (!empty($value)) {    
          if ($vocabulary = $this->vocabulary_get($value, 0)) {
            $vocabulary = $vocabulary;
          }else{
            //if no vocab matches, add a new one using the machine name in the term
            $vocab_array = array(
              'name' => $value . ' (unsynced)',
              'machine_name' => $value,
              'description' => 'System generated vocaulary',
              'module' => 'taxonomy',
            ); 
            $vocabulary = (object) $vocab_array;
            taxonomy_vocabulary_save($vocabulary);
            drupal_set_message(t('The vocabulary %vocab has been generated.', array('%vocab' => $value)));
            $vocabulary = $this->vocabulary_get($value, 0);
            //$vocabulary = $this->vocabulary();
          }
          //point the term at the defined vocabulary
          $target_term->vid = $vocabulary->vid;
          $target_term->vocabulary_machine_name = $vocabulary->machine_name;          
        }
      break;  
                 
      case 'parent_uuid':
        if (!empty($value)) {
          //use entity_uuid_load() to load parent term from its UUID value
          $terms = entity_uuid_load('taxonomy_term', array($value), array(), FALSE);
          $parent_tid = '';
          foreach ($terms as $term) {
            //use vocabulary_machine_name here as VID is not available in array returned by entity_uuid_load()
           // if ($term->vocabulary_machine_name == $target_term->vocabulary_machine_name) {          
              $parent_tid = $term->tid;
           // } 
          }
          //if a parent term is loaded, use it as the terms parent
          if (!empty($parent_tid)) {
            $target_term->parent[] = $parent_tid;
          }
          else { //if parent data is found but no parent loaded...
            $target_term->parent[] = 0;
          }
        }
        else { //set the parent value imported items that have no parent data
          $target_term->parent[] = 0;
        }
      break;   
      
      case 'weight':
        if (!empty($value)) {
          $weight = intval($value);
        }
        else {
          $weight = 0;
        }
        $target_term->weight = $weight;
      break;
      
      default:
        parent::setTargetElement($source, $target_term, $target_element, $value);
      break;
    }
    
    //Check incomming terms for vocab values, if new values exist update current vocabs.
    if(count($target_term->vocab_data) == 3){
      //load the vocab with machine name
      if ($v_values = db_query("SELECT name, description, weight FROM {taxonomy_vocabulary} WHERE machine_name = :machine_name", array(':machine_name' => $target_term->vocabulary_machine_name))){
        $current_vocab = array();
        foreach ($v_values as $key => $v_value) {
          $current_vocab[$key] = $v_value;
        }
      }
      if ($diff = array_diff($target_term->vocab_data,reset($this->toArray($current_vocab)))){
        if ($local_vocab = taxonomy_vocabulary_machine_name_load($target_term->vocabulary_machine_name)){      
          foreach($diff as $diffkey => $diffvalue){
              $local_vocab->$diffkey = $diffvalue;
          }
          taxonomy_vocabulary_save($local_vocab);
        }
      };
    }
 
  }
  
  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
/*     $targets = parent::getMappingTargets(); */
    $targets = array(
      //Term
      'name' => array(
        'name' => t('Term name'),
        'description' => t('Name of the taxonomy term.'),
        'optional_unique' => TRUE,
      ),      
      'uuid' => array(
        'name' => t('UUID'),
        'description' => t('UUID of the taxonomy term.'),
        'optional_unique' => TRUE,
      ),
      'parent_uuid' => array(
        'name' => t('Parent: Term UUID'),
        'description' => t('The UUID of the parent taxonomy term.'),
        'optional_unique' => TRUE,
      ),
      'weight' => array(
        'name' => t('Term weight'),
        'description' => t('Weight of the taxonomy term.'),
        'optional_unique' => TRUE,
      ),
      'description' => array(
        'name' => t('Term description'),
        'description' => t('Description of the taxonomy term.'),
      ),
      //Vocaublaries      
      'vocab_name' => array(
        'name' => t('Vocab name'),
        'description' => t('The name of the vocabulary a term belongs to.'),
        'optional_unique' => FALSE,
      ),
      'vocab_machine_name' => array(
        'name' => t('Vocab machine name'),
        'description' => t('The unique machine name of the vocabulary a term belongs to.'),
        'optional_unique' => FALSE,
      ),
      'vocab_description' => array(
        'name' => t('Vocab description'),
        'description' => t('Description of the taxonomy term.'),
      ),               
      'vocab_weight' => array(
        'name' => t('Vocab weight'),
        'description' => t('Weight of the taxonomy term.'),
        'optional_unique' => FALSE,
      ),      
    );

    // Let implementers of hook_feeds_term_processor_targets() add their targets.
    try {
      self::loadMappers();
      $entity_type = $this->entityType();
      drupal_alter('feeds_processor_targets', $targets, $entity_type);
    }
    catch (Exception $e) {
      // Do nothing.
    }
    return $targets;
  }  

  /**
   * Get id of an existing feed item term if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($tid = parent::existingEntityId($source, $result)) {
      return $tid;
    }
    // check UUID for unique target
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
/*       dsm($target); */
      if ($target == 'uuid') {
        if ($tid = db_query("SELECT tid FROM {taxonomy_term_data} WHERE uuid = :uuid", array(':uuid' => $value))->fetchField()) {
          return $tid;
        }
      }     
    }
    return 0;
  }

  /**
   * Return vocabulary to map to.
   */
  public function vocabulary() {
    if (isset($this->config['vocabulary'])) {
      if ($vocabulary = taxonomy_vocabulary_machine_name_load($this->config['vocabulary'])) {
        return $vocabulary;
      }
    }
    //throw new Exception(t('No vocabulary defined for Taxonomy Term processor.'));
  }
  
  /**
   * Return vocabulary to map to based on term vocabulary_machine_name.
   */
  public function vocabulary_get($machine_name, $tid = 0) {  
      if ($vocabulary = taxonomy_vocabulary_machine_name_load($machine_name)) {
        return $vocabulary;
      }
  }
  /**
   * Helper function to break out object to array
   */  
  public function toArray($obj) {
    if(is_object($obj)) $obj = (array) $obj;
    if(is_array($obj)) {
      $new = array();
      foreach($obj as $key => $val) {
        $new[$key] = self::toArray($val);
      }
    }
    else { 
      $new = $obj;
    }
    return $new;
  }
    
}