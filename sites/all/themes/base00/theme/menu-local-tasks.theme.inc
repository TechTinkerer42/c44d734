<?php
/**
 * Returns HTML for primary and secondary local tasks.
 *
 * @param $variables
 *   An associative array containing:
 *     - primary: (optional) An array of local tasks (tabs).
 *     - secondary: (optional) An array of local tasks (tabs).
 *
 * @ingroup themeable
 * @see menu_local_tasks()
 */
 
/**  
 * NOTES: This needs a no js fallback as secondary links are hidden when dropdown not available. Look @ rubik CSS for solution.
 */

function base00_menu_local_tasks(&$variables) {
  
  $output = '';

    if (!empty($variables['primary'])) {
      $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
      $variables['primary']['#prefix'] .= '<ul class="btn-group tabs primary-tabs tabs--primary links pull-left">';    
      $variables['primary']['#suffix'] = '</ul>';
      $output .= drupal_render($variables['primary']);
    }
    if (!empty($variables['secondary'])) {
      $variables['secondary'] = '';
    }

    return $output;   
    
  
}