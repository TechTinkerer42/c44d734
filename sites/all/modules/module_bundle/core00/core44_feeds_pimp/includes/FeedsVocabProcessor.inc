<?php

/**
 * @file
 * FeedsVocabProcessor class.
 */

/**
 * Feeds processor plugin. Create vocabularies from feed items.
 */
class FeedsVocabProcessor extends FeedsTermProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'taxonomy_vocabulary';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Vocabularies');
    return $info;
  }

  /**
   * Creates a new term in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $vocab = new stdClass();
    $vocab->format = isset($this->config['input_format']) ? $this->config['input_format'] : filter_fallback_format();
    return $vocab;
  }

  /**
   * Loads an existing vocab.
   */
  protected function entityLoad(FeedsSource $source, $vid) {
    return taxonomy_vocabulary_load($vid);
  }

  /**
   * Validates a vocab.
   */
  protected function entityValidate($vocab) {
    if (empty($vocab->name)) {
      throw new FeedsValidationException(t('Vocabulary name missing.'));
    }
  }

  /**
   * Saves a vocab.
   */
  protected function entitySave($vocab) {
    taxonomy_vocabulary_save($vocab);
  }

  /**
   * Deletes a series of vocabularies.
   */
  protected function entityDeleteMultiple($vids) {
    foreach ($vids as $vid) {
      taxonomy_vocabulary_delete($vid);
    }
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
/*
    if (empty($values['vocabulary'])) {
      form_set_error('vocabulary', t('Choose a vocabulary'));
    }
*/
  }

  /**
   * Override setTargetElement to operate on a target item that is a taxonomy term.
   */
  public function setTargetElement(FeedsSource $source, $target_vocab, $target_element, $value) {
    switch ($target_element) {
      case 'weight':
        if (!empty($value)) {
          $weight = intval($value);
        }
        else {
          $weight = 0;
        }
        $target_vocab->weight = $weight;
        break;
      default:
        parent::setTargetElement($source, $target_vocab, $target_element, $value);
        break;
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
/*     $targets = parent::getMappingTargets(); */
    $targets = array(
      'name' => array(
        'name' => t('Vocab name'),
        'description' => t('Name of the taxonomy term.'),
        'optional_unique' => TRUE,
      ),
      'machine_name' => array(
        'name' => t('Vocab machine name'),
        'description' => t('Name of the vocabulary machine name.'),
        'optional_unique' => TRUE,
      ),      
      'weight' => array(
        'name' => t('Vocab weight'),
        'description' => t('Weight of the vocabulary.'),
        'optional_unique' => TRUE,
      ),
      'description' => array(
        'name' => t('Vocabulary description'),
        'description' => t('Description of the vocabulary'),
      ),
    );

    // Let implementers of hook_feeds_term_processor_targets() add their targets.
    try {
      self::loadMappers();
      $entity_type = $this->entityType();
/*       $bundle = $this->vocabulary()->machine_name; */
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
    if ($vid = parent::existingEntityId($source, $result)) {
      return $vid;
    }

    // The only possible unique target is name.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      if ($target == 'machine_name') {
/*         $vocabulary = $this->vocabulary(); */
        if ($vid = db_query("SELECT vid FROM {taxonomy_vocabulary} WHERE machine_name = :machine_name", array(':machine_name' => $value))->fetchField()) {
          return $vid;
        }
      }
    }
    return 0;
  }

}
