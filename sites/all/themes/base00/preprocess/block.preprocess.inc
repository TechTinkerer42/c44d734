<?php

/**
 * Implements hook_preprocess_page().
 */
function base00_preprocess_block(&$variables) {
  $panel = 'panel panel-default';
  $panel_title = 'panel-heading panel-title';
  $panel_content = 'panel-body';
  
  if($variables['block']->module == 'bean') {
    $beans = isset($variables['elements']['bean']) ? $variables['elements']['bean'] : '';
    if(!empty($beans)){
      foreach($beans as $key => $bean){
        if (isset($bean['#bundle']) && $bean['#bundle'] == 'slideshow_block' ) {
          $panel = '';
          $panel_title = '';         
          $panel_content = '';
        }
        if (isset($bean['#bundle']) && $bean['#bundle'] == 'basic_block' ) {
          $panel = '';
          $panel_title = '';          
          $panel_content = '';        
        }    
        if (isset($bean['#bundle']) && $bean['#bundle'] == 'contact_details_block' ) {
          $panel = '';
          $panel_title = '';          
          $panel_content = '';        
        }                
      }
    }
  }
  $variables['classes_array'][] = $panel;
  $variables['content_attributes_array']['class'][] = $panel_content; 
  $variables['title_attributes_array']['class'][] = $panel_title;
}