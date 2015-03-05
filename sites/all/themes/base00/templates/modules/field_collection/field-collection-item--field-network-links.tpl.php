<?php
  $output = '';
  $network = isset($content['field_network_name'][0]['#markup']) ? $content['field_network_name'][0]['#markup'] : '';
      
  $url = isset($content['field_network_link'][0]['#element']['url']) ? $content['field_network_link'][0]['#element']['url'] : '';
  $target = isset($content['field_network_link'][0]['#element']['attributes']['target']) ? $content['field_network_link'][0]['#element']['attributes']['target'] : '';
  $title = isset($content['field_network_link'][0]['#element']['title']) ? $content['field_network_link'][0]['#element']['title'] : '';
  $alt = $network;

  $output .= '<a href="'.$url.'" title="'.$title.'" alt="" target="'.$target.'"><span class="c44icon- '.drupal_html_class($network).'"></span><span class="icon-text">'.$network.'</span></a>';
  
  print $output;
?>