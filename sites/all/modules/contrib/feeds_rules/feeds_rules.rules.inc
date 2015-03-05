<?php

/**
 * @file
 *   Rules plugins of feeds_rules.
 */

/**
 * Implements hook_rules_event_info().
 */
function feeds_rules_rules_event_info() {
  $items = array(
    'feeds_after_import' => array(
      'label' => t('After importing feed'),
      'group' => t('Feeds'),
      'variables' => array('source' => array('type' => 'feeds_source', 'label' => 'Feeds source')),
    ),
  );
  return $items;
}

/**
 * Implements hook_rules_data_info().
 */
function feeds_rules_rules_data_info() {
  return array(
    'feeds_source' => array(
      'label' => t('Feeds source'),
      'group' => t('Feeds'),
      'wrap' => TRUE,
      'property info' => _feeds_rules_feeds_source_property_info(),
    ),
  );
}

/**
 * Defines property info for feeds source objects, used by feeds_source data
 * type to provide a useful metadata wrapper.
 */
function _feeds_rules_feeds_source_property_info() {
  return array(
    'id' => array(
      'type' => 'text',
      'label' => t('ID'),
      'description' => t("The machine readable name of the source importer."),
    ),
    'imported ' => array(
      'label' => t("Date imported"),
      'type' => 'date',
      'description' => t("The date the source was last imported."),
    ),
    // @TODO: fetcher, parser, state ...
  );
}