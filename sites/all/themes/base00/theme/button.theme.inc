<?php
/**
 * Returns HTML for a button form element.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #attributes, #button_type, #name, #value.
 *
 * @ingroup themeable
 */

function base00_button($variables) {
  $element = $variables['element'];
  $label = $element['#value'];
  element_set_attributes($element, array('id', 'name', 'value', 'type'));

  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled disabled';
  }
  
  // Prepare input whitelist - added to ensure ajax functions don't break
  $whitelist = _base00_element_whitelist();

  if (isset($element['#id']) && in_array($element['#id'], $whitelist)) {
    return '<input' . drupal_attributes($element['#attributes']) . ">\n"; // This line break adds inherent margin between multiple buttons
  }else{
   
    if($element['#value'] == 'Upload'){
      $element['#attributes']['class'][] = 'upload';
      return '<button' . drupal_attributes($element['#attributes']) .' ><span class="glyphicon glyphicon-upload"></span></button>';
    }else{ 
      return '<button' . drupal_attributes($element['#attributes']) . '>'. $label ."</button>\n"; // This line break adds inherent margin between multiple buttons
    }

  }
}