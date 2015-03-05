<?php

function base00_preprocess_node(&$variables) {
 
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];
 
  // dsm($variables);
  //Node and comment links as button group
  $node_links = $variables['content']['links']['node']['#links'];
  
  unset($variables['content']['links']['node']['#links']);
  $comment_links = '';//$variables['content']['links']['comment']['#links'];
  unset($variables['content']['links']['comment']['#links']);
  $new_links = '<div class="btn-group">';
  if(!empty($node_links)){
    foreach ($node_links as $key => $link) {
      if(!isset($link['attributes'])){$link['attributes'] = array();}
      $link['attributes']['class'] = array('btn','btn-small', 'btn-primary');
      $new_links .= l($link['title'], $link['href'], $link);
    }
  }
  if(!empty($comment_links)){
    foreach ($comment_links as $key => $link) {
      if(!isset($link['attributes'])){$link['attributes'] = array();}
      $link['attributes']['class'] = array('btn','btn-small', 'btn-primary');
      $new_links .= l($link['title'], $link['href'], $link);
    }
  }
  $new_links .= '</div>';
  $variables['new_node_links'] = $new_links;
    
  if ($variables['submitted']) {
    $variables['submitted'] = t('Submitted by !username on !datetime', array('!username' => $variables['name'], '!datetime' => $variables['date']));
  }
}