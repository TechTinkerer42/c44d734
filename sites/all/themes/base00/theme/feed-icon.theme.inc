<?php

 
function base00_feed_icon($variables) {
// Taken from original function
$text = t('Subscribe to !feed-title', array('!feed-title' => $variables['title']));
// Overridden to not render an image element (will use 100% CSS here instead)
return l('', $variables['url'], array('html' => TRUE, 'attributes' => array('class' => array('feed-icon c44icon-'), 'title' => $text)));
}