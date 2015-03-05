<?php
//    /**
//     * Returns HTML for a single local task link.
//     *
//     * @param $variables
//     *   An associative array containing:
//     *   - element: A render element containing:
//     *     - #link: A menu link array with 'title', 'href', and 'localized_options'
//     *       keys.
//     *     - #active: A boolean indicating whether the local task is active.
//     *
//     * @ingroup themeable
//     */
//    
//    function base00_menu_local_task($variables) {
//      /* dsm($variables); */
//      $output = '';
//      
//      $link = $variables['element']['#link'];
//      $link_text = $link['title'];
//      $classes = array();
//    
//      if (!empty($variables['element']['#active'])) {
//        // Add text to indicate active tab for non-visual users.
//        $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';
//    
//        // If the link does not contain HTML already, check_plain() it now.
//        // After we set 'html'=TRUE the link will not be sanitized by l().
//        if (empty($link['localized_options']['html'])) {
//          $link['title'] = check_plain($link['title']);
//        }
//        $link['localized_options']['html'] = TRUE;
//        $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));
//    
//        $classes[] = 'active';
//      }
//      // Render child tasks if available.
//      $children = '';
//      if (element_children($variables['element'])) {
//        foreach ($variables['element'] as $key => $value) {
//          if (is_numeric($key)){
//            if(isset($value['#active'])){
//              $active = $value;   
//            }else{
//              $inactive[] = $value;        
//            }
//          }
//        }
//        $first_child = $active['#link']['title'];
//        $children = str_replace(array('li class="btn ', 'li class="btn-dark '), array('li class="', 'li class="'), render($inactive));
//    
//        $children = "<ul class='btn-group dropleft secondary-tabs'><button class='btn btn-mini btn-primary current'>" . $first_child . "</button><button class='btn btn-mini btn-primary dropdown-toggle' data-toggle='dropdown'><span class='caret'></span></button><ul class='dropdown-menu clearfix'>" . $children . "</ul></ul>";
//      }  
//    
//    
//      if (!empty($variables['element']['#active'])) {
//        $output = '<button type="button" class="btn btn-dark btn-small ' . implode(' ', $classes) . '">'. l($link_text, $link['href'], $link['localized_options']) . $children . '</button><button type="button" class="btn btn-dark btn-small dropdown-toggle" data-toggle="dropdown">
//        <span class="caret"></span>
//      </button>';
//      }else{
//        $output = '<li class="' . implode(' ', $classes) . '">' . l($link_text, $link['href'], $link['localized_options']) . $children . "</li>\n";
//      }
//      
//      return $output;
//    }


/**
 * Returns HTML for a single local task link.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: A render element containing:
 *     - #link: A menu link array with 'title', 'href', and 'localized_options'
 *       keys.
 *     - #active: A boolean indicating whether the local task is active.
 *
 * @ingroup themeable
 */

function base00_menu_local_task($variables) {

  $link = $variables['element']['#link'];
  $link_text = $link['title'];
  $classes = array();
	$id = strtolower(str_replace(' ','-',strip_tags($link['title']."-link")));
	
  if (!empty($variables['element']['#active'])) {
    // Add text to indicate active tab for non-visual users.
    $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));

    $classes[] = 'active';
  }

  if((arg(0) == 'nodeXXX') || (arg(0) == 'userXXX')){ //if is a node return normal links to style as contextual
    if ($link['path'] == 'node/%/view') return false;
    return '<li class="' . implode(' ', $classes) . '">' . l($link_text, $link['href'], $link['localized_options']) . "</li>\n";
  }else{ //return tasks as button group
    // Render child tasks if available.
    $children = '';
    if (element_children($variables['element'])) {
      foreach ($variables['element'] as $key => $value) {
        if (is_numeric($key)){
          if(isset($value['#active'])){
            $active = $value;   
          }else{
            $inactive[] = $value;        
          }
        }
      }
      $first_child = $active['#link']['title'];
      $children = str_replace(array('li class="btn ', 'li class="btn-dark '), array('li class="', 'li class="'), render($inactive));
      $children = "<ul class='btn-group dropleft secondary-tabs'><button class='btn btn-mini btn-primary current'>" . $first_child . "</button><button class='btn btn-mini btn-primary dropdown-toggle' data-toggle='dropdown'><span class='caret'></span></button><ul class='dropdown-menu clearfix'>" . $children . "</ul></ul>";
    }  
    return '<li id="' . $id . '" class="btn btn-dark ' . implode(' ', $classes) . '">' . l($link_text, $link['href'], $link['localized_options']) . $children . "</li>\n";
  }
}