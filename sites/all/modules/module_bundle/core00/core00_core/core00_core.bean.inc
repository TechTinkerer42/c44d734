<?php
/**
 * @file
 * core00_core.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function core00_core_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'basic_block';
  $bean_type->label = 'Basic Block';
  $bean_type->options = '';
  $bean_type->description = 'A basic block for text and title.';
  $export['basic_block'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'contact_block';
  $bean_type->label = 'Contact Block';
  $bean_type->options = '';
  $bean_type->description = 'A simple block for displaying basic contact information';
  $export['contact_block'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'network_block';
  $bean_type->label = 'Network Block';
  $bean_type->options = '';
  $bean_type->description = 'A block for listing network links';
  $export['network_block'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'php_block';
  $bean_type->label = 'PHP Block';
  $bean_type->options = '';
  $bean_type->description = 'Processes and displays custom PHP code on the fly';
  $export['php_block'] = $bean_type;

  return $export;
}
