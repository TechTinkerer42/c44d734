<?php

/**
 * Scalepoints behavior
 */
class core44_ol_pimp_behavior_zoomtolayer extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'point_zoom_level' => '5',
    );
  }
  
  /**
   * Returns an array of JS files.
   * @return array
   */
/*
  function js() {
    return array(
      drupal_get_path('module', 'core44_ol_pimp') . 
      '/plugins/behaviors/core44_ol_pimp_behavior_zoomtolayer.js'
    );
  }
*/
  
  function options_form($defaults = array()) {
    return array(
      'zoomtolayer' => array(
        '#title' => t('Layer 01'),
        '#type' => 'select',
        '#options' => $this->map['layers'],
        '#description' => t('Select layer to zoom to when the map is loaded'),
        '#default_value' => isset($defaults['zoomtolayer']) ? $defaults['zoomtolayer'] : array(),
      ),
      'zoomtolayer_alt' => array(
        '#title' => t('Layer 02'),
        '#type' => 'select',
        '#options' => $this->map['layers'],
        '#description' => t('Select layer to zoom to when the map is loaded'),
        '#default_value' => isset($defaults['zoomtolayer_alt']) ? $defaults['zoomtolayer_alt'] : array(),
      ),
      'point_zoom_level' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['point_zoom_level'])) ?
          $defaults['point_zoom_level'] : 5,
        '#size' => 5,
        '#title' => t('Point Zoom Level')
      )
    );
  }
  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'core44_ol_pimp') . 
    	'/plugins/behaviors/core44_ol_pimp_behavior_zoomtolayer.js');  
    return $this->options;
  }
}
