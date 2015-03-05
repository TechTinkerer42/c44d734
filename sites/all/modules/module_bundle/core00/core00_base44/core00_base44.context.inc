<?php
/**
 * @file
 * core00_base44.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function core00_base44_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = '';
  $context->tag = 'front';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ec82b4ed75d7d1548eb2949d930b1f31' => array(
          'module' => 'views',
          'delta' => 'ec82b4ed75d7d1548eb2949d930b1f31',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
      'layout' => 'default',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('front');
  $export['front'] = $context;

  return $export;
}
