<?php

/**
 * Implements hook_preprocess_views_view_grid().
 */
function base00_preprocess_views_view_grid(&$variables) {
  $variables['class'] .= ' table';
}
