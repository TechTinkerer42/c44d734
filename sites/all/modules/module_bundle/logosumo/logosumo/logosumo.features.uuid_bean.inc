<?php
/**
 * @file
 * logosumo.features.uuid_bean.inc
 */

/**
 * Implements hook_uuid_features_default_beans().
 */
function logosumo_uuid_features_default_beans() {
  $beans = array();

  $beans[] = array(
    'label' => 'sumo terms',
    'description' => NULL,
    'title' => '',
    'type' => 'php_block',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'sumo-terms',
    'view_mode' => 'default',
    'created' => 1399801252,
    'log' => '',
    'uid' => 1,
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => 'f235b30e-a095-4ca3-adb0-b9f33c8e9323',
    'uuid' => '5ad53c33-92c1-4f59-b85d-e07f143cb1d8',
    'field_custom_php' => array(),
    'title_field' => array(
      'und' => array(
        0 => array(
          'value' => NULL,
          'format' => NULL,
          'safe_value' => '',
        ),
      ),
    ),
  );
  $beans[] = array(
    'label' => 'sumo networks',
    'description' => NULL,
    'title' => '',
    'type' => 'network_block',
    'data' => array(
      'view_mode' => 'default',
    ),
    'delta' => 'sumo-networks',
    'view_mode' => 'default',
    'created' => 1399801222,
    'log' => '',
    'uid' => 1,
    'default_revision' => 1,
    'revisions' => array(),
    'vuuid' => 'b5a21bad-a7ef-41e8-b8ac-df5068e12cd3',
    'uuid' => '85e8d769-99a4-4b4c-afed-0adde1c6c85a',
    'field_network_links' => array(
      'und' => array(
        0 => array(
          'value' => '0f5560c2-7070-4623-b512-7a35b06c028e',
          'revision_id' => 1,
        ),
      ),
    ),
    'title_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Follow the Sumo on...',
          'format' => NULL,
          'safe_value' => 'Follow the Sumo on...',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => NULL,
          'format' => NULL,
          'safe_value' => '',
        ),
      ),
    ),
  );
  return $beans;
}
