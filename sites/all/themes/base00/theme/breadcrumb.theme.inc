<?php
/**
 * Returns HTML for a breadcrumb trail.
 *
 * @param $variables
 *   An associative array containing:
 *   - breadcrumb: An array containing the breadcrumb links.
 */


 /**
 * Override of theme('breadcrumb').
 */
function base00_breadcrumb($variables) {
  $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

  // Add current page onto the end.
  if (!drupal_is_front_page()) {
    $item = menu_get_item();
    if(empty($item['title'])){ 
    	$item['title'] = drupal_get_title();
    }
    $end = end($variables['breadcrumb']);
    if ($end && strip_tags($end) !== $item['title'] && !empty($item['title'])) {
      $variables['breadcrumb'][] = "<strong>". check_plain($item['title']) ."</strong>";
    }
  }

  // Optional: Add the site name to the front of the stack.
  if (!empty($variables['prepend'])) {
    $site_name = empty($variables['breadcrumb']) ? "<strong>". check_plain(variable_get('site_name', '')) ."</strong>" : l(variable_get('site_name', ''), '<front>', array('purl' => array('disabled' => TRUE)));
    array_unshift($variables['breadcrumb'], $site_name);
  }

  $depth = 0;
  foreach ($variables['breadcrumb'] as $link) {
    if (strpos($link,'<none>') == false) {
      $output .= "<span class='breadcrumb-link breadcrumb-depth-{$depth}'>{$link}</span>";
      $depth++;	  
    }
  }
  return "<div class='breadcrumb-wrapper'><div id='breadcrumb'>" . $output . "</div></div>";
}


// function base00_breadcrumb($variables) {
//   $breadcrumb = $variables['breadcrumb'];
// 
//   if (!empty($breadcrumb)) {
//     // Provide a navigational heading to give context for breadcrumb links to
//     // screen-reader users. Make the heading invisible with .element-invisible.
//     $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
// 
//     // Override Drupal core breadcrumb item imploding (no arrow).
//     $output .= '<div class="breadcrumb-wrapper"><ul id="breadcrumbs-one"><li>' . implode('</li><li>', $breadcrumb) . '</li></ul></div>';
//     return $output;
//   }
// }