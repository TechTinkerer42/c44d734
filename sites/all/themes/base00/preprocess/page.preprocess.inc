<?php

/**
 * Implements hook_preprocess_page().
 */
function base00_preprocess_page(&$variables) {
  if(isset($variables['page']['content']['system_main']['default_message'])){
    $variables['page']['content']['system_main']['default_message'] = '';
  }
  if (isset($variables['node']->type)) { 
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
  }
  
    
  $variables['page_icon_class'] = ($item = menu_get_item()) ? implode(' ' , _base00_icon_classes($item['href'])) : '';  
  /* dsm($variables['page_icon_class']); */
  // Login panel for popup login
  
  $variables['login_panel'] = '';
  if (!user_is_logged_in()){
    $variables['login_panel'] = drupal_get_form('user_login');
    //      $variables['login_panel']['#theme_wrappers'] = array('');    
  }
  $variables['login_status'] = t('login');
  if (user_is_logged_in()){
    global $user;
    $variables['login_status'] = $user->name;
  }
  

  //<------ Theme logo variables---------> Searches the logo directory and creates variables for each image
  global $theme_key;
  $base_path = drupal_get_path('theme', 'base00');
  $active_path = drupal_get_path('theme',$GLOBALS['theme']);
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

  // Site navigation links.
  $main_menu = menu_tree_output(menu_tree_all_data('main-menu'));
  if (isset($variables['main_menu'])) {
    $variables['main_menu_links'] = theme('links__navbar_menu', array(
      'links' => $main_menu,
      'attributes' => array(
        'id' => 'main-menu',
        'class' => array('main-nav'),
      ),
      'heading' => array(
        'text' => t('Main menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      ),
    ));
  } 
  
  
  // Site navigation links.
  $user_menu = menu_tree_output(menu_tree_all_data('user-menu'));
  if (isset($user_menu)) {
    $variables['user_menu'] = theme('links__dropdown_menu', array(
      'links' =>  $user_menu,
      'attributes' => array(
        'id' => 'user-menu',
        'class' => array('user-menu'),
      ),
      'heading' => array(
        'text' => t('User menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      ),
    ));
  }    

  
  $variables['action_tools'] = '';
  if(!empty($variables['action_links'])){
        $singlelink = $variables['action_links'][0]['#link'];
        $singlelink = l($singlelink['title'], $singlelink['href'], isset($singlelink['localized_options']) ? $singlelink['localized_options'] : array());
        
      if(count($variables['action_links']) > 1){        
        $variables['action_tools'] = '<div class="btn-group action-tools"><div class="btn btn-primary main-action"><span class="glyphicon glyphicon-plus"></span>'. $singlelink . '</div><button type="button" class="btn btn-primary dropdown-toggle" data-toggle="dropdown"><span class="caret"></span></button><ul class="dropdown-menu">' . render($variables['action_links']) . '</ul></div>';
      }else{
        $variables['action_tools'] = '<div class="btn-group action-tools"><div class="btn btn-primary single-action"><span class="glyphicon glyphicon-plus"></span>'. $singlelink . '</div></div>';
      }
  }
  //Create under construction panel to display on unfinished sections
  $uc = '';
  $uc .= '<div class="panel panel-danger"><div class="panel-heading">'.t("This section is still under construction").'</div>';
  $uc .= t("Some sections of this site are currently still under construction. To see this section in a more completed state please check back later. Thank you.");
  $uc .= '</div>';
  $variables['under_construction'] = $uc;  
  
  
  
  
  
 //define the login panel for the modal
  $variables['login_panel'] = '';
  if($variables['db_is_active'] == TRUE && $variables['logged_in'] == FALSE){
     $variables['login_panel'] = drupal_get_form('user_login');
  }
  //define modal variable
  $variables['login_modal'] = '';
  $variables['login_modal'] = '<div class="modal" id="loginModal"><div class="modal-dialog login-modal"><div class="modal-content"><div class="modal-header"><a class="close" data-dismiss="modal" aria-hidden="true">&times;</a><h4 class="modal-title">Log in</h4></div><div class="modal-body">' . render($variables['login_panel']) . '</div></div></div></div>';  
  
  //define user widget
  $variables['user_widget'] = '';
  if (user_is_logged_in()){
    global $user;
    $variables['user_widget'] =    '<div class="btn-group"><a class="btn btn-dark" href="user">' . $user->name . '</a>';
    $variables['user_widget'] .=   '<button type="button" class="btn btn-dark dropdown-toggle" data-toggle="dropdown"><span class="caret"></span></button>';
    $variables['user_widget'] .=    $variables['user_menu'];
    $variables['user_widget'] .=   '</div>';
  }else{
    $variables['user_widget'] =    '<div class="btn-group user-widget"><a class="btn btn-dark" data-toggle="modal" href="#loginPanel">' . t('Log in') . '</a>';
    $variables['user_widget'] .=   '<button type="button" class="btn btn-dark dropdown-toggle" data-toggle="dropdown"><span class="caret"></span></button>';
    $variables['user_widget'] .=   '<ul class="dropdown-menu pull-right"><li class="new-pass">'. l(t('Request new password'), 'user/password', array('attributes' => array('title' => t('Request new password via e-mail.')))) . '</li></ul>';
    $variables['user_widget'] .=   '</div>' . $variables['login_modal'];    
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
  
  
  

  //Quick edit link
  $variables['quick_edit'] = '';
  if(module_exists('edit')) {
    $variables['quick_edit'] = edit_trigger_link(); 
  
    $hide_class = module_exists('edit') ? edit_trigger_link() : '';
    $variables['quick_edit']['#options']['attributes']['class'] = array($variables['quick_edit']['link_class'], 'glyphicon', 'glyphicon-edit',  'btn', 'btn-primary', 'pull-left');
    $variables['quick_edit']['#title'] = ''; 
      
    //make some checks if the link button should be displayed
    if (!user_access('Access in-place editing')){
      $variables['quick_edit']['link_class'] = 'hidden';
    }else{
      $variables['quick_edit']['link_class'] = '';
    }
    
  }
   
  //dsm($variables['quick_edit']);
  // Overlay is enabled.
  $variables['overlay'] = (module_exists('overlay') && overlay_get_mode() === 'child');

  // Process local tasks. Only do this processing if the current theme is
  // indeed Rubik. Subthemes must reimplement this call.
  global $theme;
  if ($theme === 'base00') {
    _base00_local_tasks($variables);
  }
}