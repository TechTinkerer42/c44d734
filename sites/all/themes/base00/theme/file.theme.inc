<?php
/**
 * Returns HTML for a file upload form element.
 *
 * For assistance with handling the uploaded file correctly, see the API
 * provided by file.inc.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #title, #name, #size, #description, #required,
 *     #attributes.
 *
 * @ingroup themeable
 */
 
function base00_file($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'file';
  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-file'));

    $output = ''; 
    $output .= '<div class="fileupload fileupload-new" data-provides="fileupload">';
    $output .= '<div class="input-append">';
    $output .= '<div class="uneditable-input">';
    $output .= '<span class="fileupload-exists glyphicon glyphicon-file"></span>';    
    $output .= '<span class="fileupload-preview"></span>';
    $output .= '</div>';
    $output .= '<a href="#" class="remove btn btn-warning fileupload-exists" data-dismiss="fileupload">Remove</a>';
    $output .= '<span class="btn btn-primary btn-file">';
    $output .= '<span class="fileupload-new">Select file</span>';
    $output .= '<span class="fileupload-exists">Change</span>';
    $output .= '<input' . drupal_attributes($element['#attributes']) . ' />';
    $output .= '</span>';
    $output .= '</div>';
    $output .= '</div>';


return $output;
}