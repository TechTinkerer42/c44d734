<?php

/**
 * Implements hook_preprocess_views_view_table().
 */
function base00_preprocess_views_view_table(&$variables) {
  $variables['classes_array'][] = 'table';  
}
