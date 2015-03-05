<?php

function base00_preprocess_comment(&$variables) {
  
  $comment_no = $variables['id'];
  $variables['permalink'] = '<a href="/comment/'.$comment_no.'#comment-'.$comment_no.'" class="permalink pull-right" rel="bookmark"><span class="glyphicon glyphicon-link"><span class="icon-text"> Permalink</span></a>';
 
  //Node and comment links as button group 
  $comment_links = $variables['content']['links']['comment']['#links'];
  unset($variables['content']['links']['comment']['#links']);
  $new_links = '<div class="btn-group">';
  if(!empty($comment_links)){
    foreach ($comment_links as $key => $link) {
      if(!isset($link['attributes'])){$link['attributes'] = array();}
      $link['attributes']['class'] = array('btn','btn-small', 'btn-primary');
      $new_links .= l($link['title'], $link['href'], $link);
    }
  } 
  $new_links .= '</div>';
  $variables['new_comment_links'] = $new_links;

}


