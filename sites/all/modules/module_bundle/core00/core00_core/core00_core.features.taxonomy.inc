<?php
/**
 * @file
 * core00_core.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function core00_core_taxonomy_default_vocabularies() {
  return array(
    'social_networks' => array(
      'name' => 'Social Networks',
      'machine_name' => 'social_networks',
      'description' => 'List of common social networks',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
