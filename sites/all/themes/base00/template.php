<?php

/**
 * Implements hook_theme().
 */
function base00_theme(&$existing, $type, $theme, $path) {

  return array(  
    //Custome image style theme function to style images outside the default file directory
    'image_style_external' => array(
      'variables' => array(
        'style_name' => NULL,
        'path' => NULL,
        'alt' => '',
        'title' => NULL,
        'attributes' => array(),
      ),
    ),


      
  );
}

//Override contrib CSS that needs tweaking TODO: process with foreach.
function base00_css_alter(&$css) {

    //unset the jquery UI theme CSS as base00 overrides this.
    unset($css['misc/ui/jquery.ui.all.css']);
    unset($css['misc/ui/jquery.ui.accordion.css']);
    unset($css['misc/ui/jquery.ui.autocomplete.css']);
    unset($css['misc/ui/jquery.ui.button.css']);
    unset($css['misc/ui/jquery.ui.core.css']);
    unset($css['misc/ui/jquery.ui.datepicker.css']);
    unset($css['misc/ui/jquery.ui.dialog.css']);
    unset($css['misc/ui/jquery.ui.draggable.css']);
    unset($css['misc/ui/jquery.ui.droppable.css']);
    unset($css['misc/ui/jquery.ui.mouse.css']);
    unset($css['misc/ui/jquery.ui.position.css']);
    unset($css['misc/ui/jquery.ui.progressbar.css']);
    unset($css['misc/ui/jquery.ui.resizable.css']);
    unset($css['misc/ui/jquery.ui.selectable.css']);
    unset($css['misc/ui/jquery.ui.slider.css']);
    unset($css['misc/ui/jquery.ui.sortable.css']);
    unset($css['misc/ui/jquery.ui.tabs.css']);
    unset($css['misc/ui/jquery.ui.theme.css']);


  if (isset($css['modules/overlay/overlay-child.css'])) {
    $css['modules/overlay/overlay-child.css']['data'] = drupal_get_path('theme', 'base00') . '/assets/css/overlay-child.css';
  }
}

//Override contrib JS that needs tweaking
function base00_js_alter(&$js) {
  //swap in base00 version of autocomplete_deluxe.js
  if(isset($js[drupal_get_path('module', 'autocomplete_deluxe') . '/autocomplete_deluxe.js'])){
    $js[drupal_get_path('module', 'autocomplete_deluxe') . '/autocomplete_deluxe.js']['scope'] = 'footer';
    $js[drupal_get_path('module', 'autocomplete_deluxe') . '/autocomplete_deluxe.js']['data'] = drupal_get_path('theme', 'base00') . '/assets/js/modules/autocomplete_deluxe.js';
    
  }
}



/**
 * Implements theme_links() targeting the main menu specifically
 */

function base00_links__navbar_menu($variables) {
  $menu_links = $variables['links'];
  $menu_classes = ''; 
  // Get all menu links and add float classes
/*
  if($variables['attributes']['id'] == 'main-menu'){
    $menu_links = menu_tree_output(menu_tree_all_data('main-menu'));
  }elseif($variables['attributes']['id'] == 'secondary-menu'){
    $menu_links = menu_tree_output(menu_tree_all_data('user-menu'));
    $menu_classes = 'right'; 
  }
*/
  // Initialize some variables to prevent errors
  $output = '';
  $sub_menu = '';
  $small_link = '';
  $options = '';

  foreach ($menu_links as $key => $link) {
    // Add special class needed for Foundation dropdown menu to work
    $small_link = $link; //duplicate version that won't get the dropdown class, save for later
    !empty($link['#below']) ? $link['#attributes']['class'][] = 'dropdown' : '';
    // Render top level and make sure we have an actual link
    if (!empty($link['#href'])) {
      // Issue #1896674 - On primary navigation menu, class 'active' is not set on active menu item.
      // @see http://drupal.org/node/1896674
      if (($link['#href'] == $_GET['q'] || ($link['#href'] == '<front>' && drupal_is_front_page())) && (empty($link['#localized_options']['language']) || $link['#localized_options']['language']->language == $language_url->language)) {
         $link['#attributes']['class'][] = 'active';
      }
      if (!empty($link['#below'])) {
        $output .= '<li' . drupal_attributes($link['#attributes']) . '><a class="dropdown-toggle" data-toggle="dropdown" href="'.$link['#href'] . '">' . $link['#title'] . '<b class="caret"></b></a>';        
      }else{
        $output .= '<li' . drupal_attributes($link['#attributes']) . '>' . l($link['#title'], $link['#href']);
      }
      // Uncomment if we don't want to repeat the links under the dropdown for large-screen
      // $small_link['#attributes']['class'][] = 'show-for-small';
      $sub_menu = '<li' . drupal_attributes($small_link['#attributes']) . '>' . l($link['#title'], $link['#href']);
      // Get sub navigation links if they exist
      foreach ($link['#below'] as $key => $sub_link) {
        if (!empty($sub_link['#href'])) {
        $sub_menu .= '<li>' . l($sub_link['#title'], $sub_link['#href']) . '</li>';
        }
      }
      $output .= !empty($link['#below']) ? '<ul class="dropdown-menu">' . $sub_menu . '</ul>' : '';
      // Reset dropdown to prevent duplicates
      unset($sub_menu);
      unset($small_link);
      $small_link = '';
      $sub_menu = '';

      $output .=  '</li>';
    }
  }
  return '<ul class="nav navbar-nav ' . $menu_classes . '">' . $output . '</ul>';
}

/**
 * Implements theme_links() targeting the main menu specifically
 */

function base00_links__dropdown_menu($variables) {
  // Initialize some variables to prevent errors
  $menu_links = $variables['links'];
  $menu_classes = ' '.'pull-right'; 
  $output = '';
  $options = '';

  foreach ($menu_links as $key => $link) {
    if (!empty($link['#href'])) {
      if (($link['#href'] == $_GET['q'] || ($link['#href'] == '<front>' && drupal_is_front_page())) && (empty($link['#localized_options']['language']) || $link['#localized_options']['language']->language == $language_url->language)) {
         $link['#attributes']['class'][] = 'active';
      }
      $output .= '<li' . drupal_attributes($link['#attributes']) . '>' . l($link['#title'], $link['#href']);
      $output .= !empty($link['#below']) ? '<ul class="dropdown-menu">' . $sub_menu . '</ul>' : '';
      $output .=  '</li>';
    }
  }
  return '<ul class="dropdown-menu' . $menu_classes . '"><div class="arrow-up"></div>' . $output . '</ul>';
}



/**
 * Implements template_preprocess_entity().
 *
 * Runs a entity specific preprocess function, if it exists.
 */
function base00_preprocess_entity(&$variables, $hook) {
  $function = __FUNCTION__ . '_' . $variables['entity_type'];  
  /*   dsm($function); */
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}

/**
 * Entity form specific implementation of template_preprocess_entity().
 */
function base00_preprocess_entity_entityform_type(&$variables, $hook) {
  if($variables['elements']['#entity']->type == 'basic_contact'){
    $variables['title'] = '';
  }
}

/**
 * Entity form specific implementation of template_preprocess_entity().
 */
function base00_preprocess_entity_bean(&$variables, $hook) {
  
  //PHP block
  if($variables['elements']['#bundle'] == 'php_block'){
    $variables['title'] = '';
  }
  //Basic block
  if($variables['elements']['#bundle'] == 'basic_block'){
    $variables['title'] = '';
  }
  //Network block
  if($variables['elements']['#bundle'] == 'network_block'){
    $variables['title'] = '';
  }
  //Slideshow block  
  if($variables['elements']['#bundle'] == 'slideshow_block'){
    $variables['carousel_items'] = '';
    $slides = isset($variables['elements']['field_slides']) ? $variables['elements']['field_slides'] : '';
    if (is_array($slides)){
      foreach($slides as $key => $slide){
        if (is_numeric($key)){
         $variables['carousel_items'][] = array_pop($slide['entity']['field_collection_item']); 
        }
      }
    } 
  }
}




//Helper functions

/**
 * Returns an array containing ids of any whitelisted drupal elements
 */
function _base00_element_whitelist() {
/**
 * Why whitelist an element?
 * The reason is to provide a list of elements we wish to exclude
 * from certain modifications made by the bootstrap theme which
 * break core functionality - e.g. ajax.
 */
  return array(
    //core
    'edit-refresh',
    'edit-pass-pass1',
    'edit-pass-pass2',
    //panels
    'panels-ipe-cancel',
    'panels-ipe-customize-page',
    'panels-ipe-save',
    // views
    'edit-displays-top-add-display-attachment',
    'edit-displays-top-add-display-block',
    'edit-displays-top-add-display-views-data-export',
    'edit-displays-top-add-display-entityreference',
    'edit-displays-top-add-display-search-api-views-facets-block',
    'edit-displays-top-add-display-feed',
    'edit-displays-top-add-display-media-browser',
    'edit-displays-top-add-display-openlayers',
    'edit-displays-top-add-display-page',
    'edit-displays-top-add-display-references',
  );
}

//Combine primary and secondary tabs
function _base00_local_tasks(&$variables) {
  if (!empty($variables['tabs']['#secondary']) && is_array($variables['tabs']['#primary'])) {
    foreach ($variables['tabs']['#primary'] as $key => $element) {
      if (!empty($element['#active'])) {
        $variables['tabs']['#primary'][$key] = $variables['tabs']['#primary'][$key] + $variables['tabs']['#secondary'];
        break;
      }
    }
  }
}

/**
 * Generate an icon class from a path.
 */
function _base00_icon_classes($path) {

  $classes = array();
  $args = explode('/', $path);
  if ($args[0] === 'admin' || $args[0] === 'cart' || $args[0] === 'checkout' || (count($args) > 1 && $args[0] === 'node' && $args[1] === 'add')) {
    // Add a class specifically for the current path that allows non-cascading
    // style targeting.
    $classes[] = 'c44icon-';
    $classes[] = 'path-'. str_replace('/', '-', implode('/', $args)) . '-';
    while (count($args)) {
      $classes[] = drupal_html_class('path-'. str_replace('/', '-', implode('/', $args)));
      array_pop($args);
    }
    return $classes;
  }
  return array();
}

/**
 * Returns an array of file paths for a given directory.
 */
function _base00_scan_image_dir($path){
    $clean = array('.DS_Store','.','..');
    $dir_contents = scandir( $path );
    foreach($dir_contents as $file){
      if(!in_array($file,$clean)){  
        $file_name = preg_replace("/\\.[^.\\s]{3,4}$/", "", $file);
        $file_paths[$file_name] = $path .'/'. $file;
      }  
    }
  return $file_paths;
}

 /**
 * This theme function is designed to deal with the limitation that
 * theme_image_style does not work with images outside the files directory.
 * 
 * Usage is the same as theme_image_style.
 * 
 * @param $variables
 */
function base00_image_style_external($variables) {
  $args = explode('/', $variables['path']);
  $arg = array_pop($args);
  $styled_path = image_style_path($variables['style_name'], $variables['path']);
  if (!file_exists($styled_path)) {
    $style = image_style_load($variables['style_name']);
    image_style_create_derivative($style, $variables['path'], $styled_path);
  }
  $variables['path'] = $styled_path;
  return theme('image', $variables);
}

/**
 * Returns a styled image from any path
 */
function _base00_image_style($path, $style, $title = '', $alt = '', $class = '') {
  $attributes = !empty($class) ? array('class' => $class) : '';
  if(!array_key_exists($style,image_styles()) || !file_exists($path)){
    return;
  }else{
    $image = theme('image_style_external', array( 
      '#theme' => 'image_style_external', 
      '#style_name' => $style,
      '#path' => $path,
      '#alt' => $alt,
      '#title' => $title,
      '#attributes' => $attributes,
    ));
    return $image;    
  }
}

/**
 * Override of theme('filter_guidelines').
 */
function base00_filter_guidelines($variables) {
  return '';
}

function base00_form_alter(&$form, $form_state, $form_id) {
  // Only make changes to these forms.
	if (in_array($form_id, array('user_login', 'user_login_block'))) {
		// now alter uname field to add placeholder text.
    $form['name']['#attributes']['placeholder'] = t( 'Username' );
    $form['name']['#attributes']['title'] = $form['name']['#description'];    
    $form['pass']['#attributes']['placeholder'] = t( 'Password' );  
    $form['pass']['#attributes']['title'] = $form['pass']['#description'];     
	}
}

