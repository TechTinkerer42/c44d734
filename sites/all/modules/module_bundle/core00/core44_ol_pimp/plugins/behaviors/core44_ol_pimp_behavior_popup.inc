<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Attribution Behavior
 */
class core44_ol_pimp_behavior_popup extends openlayers_behavior {

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
         'clusteredFeatures' => NULL,  
         'tooltipOnly' => FALSE, 
    );
  }
  
  /**
   * Options form.
   */
  function options_form($defaults = array()) {
    $form = array();
    
    
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


	$form['selectedlayers'] = array(
		'#title' => t('Layers'),
		'#type' => 'checkboxes',
		'#options' => $supported_layers,
		'#description' => t('Select layers'),
		'#default_value' => isset($defaults['selectedlayers']) ? $defaults['selectedlayers'] : array(),
	);
	$form['clusteredFeatures'] = array(
      '#type' => 'textfield',
      '#title' => t('Clustered Features'),
      '#description' => t(''),
      '#default_value' => isset($defaults['clusteredFeatures']) ?
        $defaults['clusteredFeatures'] : '',
    );
	$form['tooltipOnly'] = array(
		'#title' => t('Tooltip Only'),
		'#type' => 'checkbox',
		'#description' => t('Enable only the toolip for this map'),
		'#default_value' => isset($defaults['tooltipOnly']) ? $defaults['tooltipOnly'] : FALSE
	);  
      	  
    return $form;
  }
  
  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_css(drupal_get_path('module', 'core44_ol_pimp') . 
    	'/plugins/behaviors/core44_ol_pimp_behavior_popup.css');
    drupal_add_js(drupal_get_path('module', 'core44_ol_pimp') . 
	    '/plugins/behaviors/core44_ol_pimp_behavior_popup.js');
    return $this->options;
  }
}
