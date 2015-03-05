<?php

/**
 * @file
 * Implementation of OpenLayers Cluster behavior.
 */

/**
 * Cluster behavior
 */
class core44_ol_pimp_behavior_scubox extends openlayers_behavior {
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

    return array(


    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'core44_ol_pimp') .
    '/plugins/behaviors/core44_ol_pimp_behavior_scubox.js');
    return $this->options;
  }
}
