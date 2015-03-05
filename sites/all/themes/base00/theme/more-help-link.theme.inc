<?php

/**
 * Returns HTML for a "more help" link.
 *
 * @param $variables
 *   An associative array containing:
 *   - url: The URL for the link.
 */
function base00_more_help_link($variables) {
  return  t('<a href="@url" title="Click here for help" class="pull-right label label-info more-help" href="@url">Help</a>', array('@url' => url($variables['url'])));
}