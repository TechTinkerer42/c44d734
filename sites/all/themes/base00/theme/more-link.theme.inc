<?php


/**
 * Returns HTML for a "more" link, like those used in blocks.
 *
 * @param $variables
 *   An associative array containing:
 *   - url: The URL of the main page.
 *   - title: A descriptive verb for the link, like 'Read more'.
 */
function base00_more_link($variables) {
  return  t('<a href="@url" title="' . $variables['title'] . '" class="pull-right label label-info more-link">More</a>', array('@url' => url($variables['url'])));  
}