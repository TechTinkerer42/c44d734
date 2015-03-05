<?php

/**
 * @file
 *   Default views hooks.
 */

/**
 * Implements hook_views_plugins().
 */
function geofield_proximity_views_plugins() {
  $plugins = array(
    'module' => 'geofield_proximity',
  );
  
  return $plugins;
}

/**
 * Implements hook_views_data_views_data_alter().
 *
 * This hook is implemented on behalf of geofield module.
 */
function geofield_field_views_data_views_data_alter(&$data, $field) {
  $field_name = $field['field_name'];
  $data_key = 'field_data_' . $field_name;
  // Views data for this field is in $data[$data_key]
  
  // Add a square proximity filter.
  $data[$data_key][$field_name . '_flat'] = array(
    'group' => t('Proximity'),
    'title' => t('GP: Square'), // TODO remove GP
    'help' => t('Gives locations contained within a square derived by a simple latitude/longitude comparison.'),
    'filter' => array(
      'handler' => 'geofield_proximity_handler_filter_square',
    ),
  );
  
  // Add a circular proximity filter.
  $data[$data_key][$field_name . '_circle'] = array(
    'group' => t('Proximity'),
    'title' => t('GP: Circle'), // TODO remove GP
    'help' => t('Uses the Great-circle distance formula to return locations within a circular area.'),
    'filter' => array(
      'handler' => 'geofield_proximity_handler_filter_circle',
    ),
  );
  
  // Add a distance field and sort.
  $data[$data_key][$field_name . '_distance'] = array(
    'group' => t('Proximity'),
    'title' => t('GP: Distance'),  // TODO remove GP
    'help' => t('Computed distance from a given point.'),
    'sort' => array(
      'handler' => 'geofield_proximity_handler_sort',
    ),
    'field' => array(
      'handler' => 'geofield_proximity_handler_field',
      'click sortable' => TRUE,
    ),
  );
  
}

