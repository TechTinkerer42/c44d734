<?php
/**
 * @file
 * core00_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function core00_core_user_default_roles() {
  $roles = array();

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 4,
  );

  return $roles;
}
