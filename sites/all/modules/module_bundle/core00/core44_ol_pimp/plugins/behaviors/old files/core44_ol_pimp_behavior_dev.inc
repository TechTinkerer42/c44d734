<?php

/**
 * Scalepoints behavior
 */
class core44_ol_pimp_behavior_dev extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
    //default form options
    );
  }
  
  /**
   * Options form.
   */
  function options_form($defaults = array()) {
    $form = array();
    
	//Add form options here    
    return $form;
  }


  /**
   * Render function
   */
  function render(&$map) {
    // Add JS
    drupal_add_js(drupal_get_path('module', 'core44_ol_pimp') . 
      '/behaviors/core44_ol_pimp_behavior_dev.js');
    return $this->options;
}
}