<?php

/**
 * Returns HTML for an individual file upload widget. SEE file.field.inc
 *
 * @param $variables
 *   An associative array containing:
 *   - element: A render element representing the widget.
 *
 * @ingroup themeable
 */
 
function base00_file_widget($variables) {
  $element = $variables['element'];
  $output = '';
  // The "form-managed-file" class is required for proper Ajax functionality.
  $output .= '<div class="file-widget form-managed-file clearfix">';
  $output .= '<span class="upload-wrapper">';
  if ($element['fid']['#value'] != 0) {
    // Add the file size after the file name.
    $element['filename']['#markup'] .= ' <span class="file-size">(' . format_size($element['#file']->filesize) . ')</span> ';
  }
  $output .= drupal_render_children($element);
  $output .= '</span>';
  $output .= '</div>';

  return $output;
}