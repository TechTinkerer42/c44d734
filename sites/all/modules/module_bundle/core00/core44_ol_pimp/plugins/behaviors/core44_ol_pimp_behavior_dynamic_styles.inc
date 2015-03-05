<?php

/**
 * Scalepoints behavior
 */
class core44_ol_pimp_behavior_dynamic_styles extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'point_radius_min' => 6,
      'point_radius_max' => 12,
      'count_components' => 0,
      'field' => NULL,
      'features_only' => FALSE,
      'max_field' => NULL,
      'label' => NULL,      
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
	$form['features_only'] = array(
      '#title' => t('Features only'),
      '#description' => t('If selected only the features within the clusters will be counted.'),
      '#type' => 'checkbox',
      '#default_value' => isset($defaults['features_only']) ? 
       	$defaults['features_only'] : FALSE,
    ); 
    $form['point_radius_min'] = array(
      '#type' => 'textfield',
      '#title' => t('Min radius'),
      '#description' => t('Minimum value for the point radius.'),
      '#default_value' => isset($defaults['point_radius_min']) ?
        $defaults['point_radius_min'] : 6,
    );
    $form['point_radius_max'] = array(
      '#type' => 'textfield',
      '#title' => t('Max radius'),
      '#description' => t('Maximum value for the point radius.'),
      '#default_value' => isset($defaults['point_radius_max']) ?
        $defaults['point_radius_max'] : 12,
    );
    $form['field'] = array(
      '#title' => t('Field'),
      '#description' => t('Enter a field that can be used for scaling points.'),
      '#type' => 'textfield',
      '#default_value' => isset($defaults['field']) ?
        $defaults['field'] : null,
    );   
   $form['max_field'] = array(
      '#title' => t('Max Field'),
      '#description' => t('Enter a field that can be used for scaling points.'),
      '#type' => 'textfield',
      '#default_value' => isset($defaults['max_field']) ?
        $defaults['max_field'] : null,
    );
   $form['label'] = array(
      '#type' => 'textfield',
      '#title' => t('Label'),
      '#description' => t('Attribute from view that contains label without object wrapper. ( e.g. title )'),
      '#default_value' => isset($defaults['label']) ?
        $defaults['label'] : 'title',
    );
    
    return $form;
  }


  /**
   * Render function
   */
  function render(&$map) {  
    // Add JS
    drupal_add_js(drupal_get_path('module', 'core44_ol_pimp') . 
      '/plugins/behaviors/core44_ol_pimp_behavior_dynamic_styles.js');
    return $this->options;
  }
}