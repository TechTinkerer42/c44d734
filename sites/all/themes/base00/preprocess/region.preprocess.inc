<?php

function base00_preprocess_region(&$variables) {
  if (isset($variables['region']) && $variables['region'] == 'content'){
    $variables['content_attributes_array']['class'][] = 'contextual-links-region';
  }
}