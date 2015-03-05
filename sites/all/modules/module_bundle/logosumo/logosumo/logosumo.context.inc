<?php
/**
 * @file
 * logosumo.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function logosumo_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front_page';
  $context->description = '';
  $context->tag = 'Front';
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
        'views-brand_filter-brand_filter' => array(
          'module' => 'views',
          'delta' => 'brand_filter-brand_filter',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-promo_block-promo_block' => array(
          'module' => 'views',
          'delta' => 'promo_block-promo_block',
          'region' => 'hero',
          'weight' => '-10',
        ),
      ),
      'layout' => 'brand-filter',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front');
  $export['front_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'product';
  $context->description = '';
  $context->tag = 'node';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'brand_pack' => 'brand_pack',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-brand_filter-filter_arg' => array(
          'module' => 'views',
          'delta' => 'brand_filter-filter_arg',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('node');
  $export['product'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tags';
  $context->description = 'sets the layout for taxonomy pages';
  $context->tag = 'taxonomy';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'tags' => 'tags',
        'tags/*' => 'tags/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-65d38bcf7855343e34357270e81671ca' => array(
          'module' => 'views',
          'delta' => '65d38bcf7855343e34357270e81671ca',
          'region' => 'hero',
          'weight' => '-10',
        ),
      ),
      'layout' => 'brand-filter',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('sets the layout for taxonomy pages');
  t('taxonomy');
  $export['tags'] = $context;

  return $export;
}
