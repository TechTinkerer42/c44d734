<?php

/**
 * Removes the ugly .panels-separator.
 */
function base00_panels_default_style_render_region(&$variables) {
  return implode('', $variables['panes']);
}
