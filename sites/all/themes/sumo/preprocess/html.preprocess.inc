<?php

/**
 * Implements hook_preprocess_html().
 */
function sumo_preprocess_html(&$variables, $hook) {

  // Classes for body element. Allows advanced theming based on context
  // (home page, node of certain type, etc.).

  if (!empty($variables['page']['hero']) && !empty($variables['page']['hero'])) {
    $variables['classes_array'][] = 'hero-active';
  }
    
  // Detect if the map is present.
  if (!empty($variables['page']['map']) && !empty($variables['page']['map'])) {
    $variables['classes_array'][] = 'map-active';
  }
  // Add information about the number of map sidebars.
  if (!empty($variables['page']['map_first']) && !empty($variables['page']['map_second'])) {
    $variables['classes_array'][] = 'two-map-sidebars';
  }
  elseif (!empty($variables['page']['map_first'])) {
    $variables['classes_array'][] = 'one-map-sidebar map-sidebar-first';
  }
  elseif (!empty($variables['page']['map_second'])) {
    $variables['classes_array'][] = 'one-map-sidebar map-sidebar-second';
  }
  else {
    $variables['classes_array'][] = 'no-map-sidebars';
  }  
  
}