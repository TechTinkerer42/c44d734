<?php

/**
 * Returns HTML for a marker for new or updated content.
 */
function base00_mark($variables) {
  $type = $variables['type'];

  if ($GLOBALS['user']->uid) {
    if ($type == MARK_NEW) {
      return ' <mark class="marker label label-primary"><span class="glyphicon glyphicon-star"></span>' . t('new') . '</span>';
    }
    elseif ($type == MARK_UPDATED) {
      return ' <mark class="marker label label-primary"><span class="glyphicon glyphicon-star"></span>' . t('updated') . '</span>';
    }
  }
}
