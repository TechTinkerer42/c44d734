<?php

/**
 * Returns HTML for a progress bar.
 *
 * Note that the core Batch API uses this only for non-JavaScript batch jobs.
 *
 * @param $variables
 *   An associative array containing:
 *   - percent: The percentage of the progress.
 *   - message: A string containing information to be displayed.
 */
function base00_progress_bar($variables) {
  $output = '<div id="progress" class="progress progress-striped active">';
  $output .= '<div class="progress-bar" style="width: ' . $variables['percent'] . '%"></div>';
  $output .= '</div>';
  $output .= '<div class="progress-data"><div class="percentage pull-right">' . $variables['percent'] . '%</div>';
  $output .= '<div class="message pull-left">' . $variables['message'] . '</div></div>';  

  return $output;
}