<?php
// $Id$

/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Legend Behavior
 */
class core44_ol_pimp_behavior_feature_highlight extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
    );
  }

  /**
   * Provide form for configurations per map.
   */
  function options_form($defaults = array()) {

    // Build a list of supported layers
    // We support: vector layers
    $supported_layers = array();
    foreach ($this->map['layers'] as $id => $name) {
      $layer = openlayers_layer_load($id);
      if ( isset( $layer->data['vector'] )
           && $layer->data['vector'] == TRUE) {
        $supported_layers[$id] = $name;
      }
    }


    return array(
      'layers' => array(
        '#title' => t('Layers'),
        '#type' => 'checkboxes',
        '#options' => $supported_layers,
        '#description' => t('Select layers to enable feature selection on. Selecting NO layers will enable ALL supported layers.'),
        '#default_value' => isset($defaults['layers']) ? $defaults['layers'] : array(),
      )
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'core44_ol_pimp') .
      '/behaviors/core44_ol_pimp_behavior_feature_highlight.js');
    return $this->options;
  }
}

