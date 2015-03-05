<?php

/**
 * Implements hook_preprocess_page().
 */
function sumo_preprocess_page(&$variables) {
	

  // Process local tasks. Only do this processing if the current theme is
  // indeed logosumo. Subthemes must reimplement this call.
  global $theme;
  if ($theme === 'sumo') {
    _base00_local_tasks($variables);
  }
}