<?php

/**
 * Implements hook_preprocess_page().
 */
function base00_preprocess_maintenance_page(&$variables) {


  $variables['login_panel'] = '';
  if($variables['db_is_active'] == TRUE && $variables['logged_in'] == FALSE){
     $variables['login_panel'] = drupal_get_form('user_login');
  }
  
  //<------ Theme logo variables---------> Searches the logo directory and creates variables for each image
  global $theme_key;
  $base_path = drupal_get_path('theme', 'base00');
  $active_path = drupal_get_path('theme', $GLOBALS['theme']);
  $sub_dir = '/assets/logos';
  
  if(file_exists($base_path . '/logo.png')){
    $variables['base_logos']['logo'] = $base_path . '/logo.png';
  }else{
    $variables['base_logos'] = file_exists($base_path.$sub_dir) ? _base00_scan_image_dir($base_path.$sub_dir) : '';
  }
  if(file_exists($active_path . '/logo.png')){
    $variables['theme_logos']['logo'] = $active_path . '/logo.png';
  }else{
    $variables['theme_logos'] = file_exists($active_path.$sub_dir) ? _base00_scan_image_dir($active_path.$sub_dir) : '';
    if(empty($variables['theme_logos'])){
      $variables['theme_logos'] = $variables['base_logos'];
    }
  }
  $logo_paths = array_values($variables['theme_logos']);
  foreach($logo_paths as $key => $path ){
		$key = substr( $path, strpos( $path, 'logos/') + 6);
		$key = strtok($key, '.');
		if($key === 'logo') { $variables['logo'] =  _base00_image_style($path, 'h40', t('Home'), $variables['site_name']); };		
			$variables['logos']['h40'][$key] =  _base00_image_style($path, 'h40', t('Home'), $variables['site_name']);
			$variables['logos']['h80'][$key] =  _base00_image_style($path, 'h80', t('Home'), $variables['site_name']);
			$variables['logos']['h90'][$key] =  _base00_image_style($path, 'h90', t('Home'), $variables['site_name']);		
  }
  
  //<------ Theme maintenance BG variables---------> Searches the maintenance directory and creates a random variable.
  $maintenance_bg_path = file_exists( path_to_theme() . '/assets/images/maintenance' ) ? path_to_theme() . '/assets/images/maintenance'  :  drupal_get_path('theme', 'base00') . '/assets/images/maintenance'; 
  $bgs = scandir( $maintenance_bg_path );
  $clean = array('.DS_Store','.','..');
  foreach($bgs as $bg){
    if(!in_array($bg,$clean)){
      $clean_bgs[] = $bg;
    }
  };
  if(!empty($clean_bgs)){
    $rand_key = array_rand($clean_bgs);
    $rand_bg = $clean_bgs[$rand_key];
    $name = preg_replace("/\\.[^.\\s]{3,4}$/", "", $rand_bg);    
    $variables['maintenance_bg'] = _base00_image_style($maintenance_bg_path .'/'. $rand_bg, 'flexslider_full');
  }else{
    $variables['maintenance_bg'] = '';
  }

  //Define login panel
  $variables['login_panel'] = '';
  if (!user_is_logged_in()){
    $variables['login_panel'] = drupal_get_form('user_login');
  }
  
  //Define login status
  $variables['login_status'] = t('login');
  if (user_is_logged_in()){
    global $user;
    $variables['login_status'] = $user->name;
  }
  
  //$nav = menu_navigation_links('navigation');
  //<------ Theme user block--------->    
  if (user_is_logged_in()){
    $variables['user_admin'] = theme('links', array('links' => $variables['secondary_menu'], 'attributes' => array('id' => 'user-links','class' => 'links secondary-menu')));
  }else{
    $variables['user_admin'] = drupal_get_form('user_login');
  }
  
}