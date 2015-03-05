<?php

/**
 * Add stripping to tables (in case they don't have .table-no-striping class)
 */
function base00_preprocess_table(&$variables) {

  if (isset($variables['attributes']['class']) && is_string($variables['attributes']['class'])) {
    // Convert classes to an array.
    $variables['attributes']['class'] = explode(' ', $variables['attributes']['class']);
  }
  // Add in bootstrap classes
  $variables['attributes']['class'][] = 'table table-bordered table-hover';
  if(!in_array('table-no-striping', $variables['attributes']['class'])) {
    $variables['attributes']['class'][] = 'table-striped';
  }
  
}