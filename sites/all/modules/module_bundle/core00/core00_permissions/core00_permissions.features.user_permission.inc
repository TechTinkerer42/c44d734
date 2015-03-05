<?php
/**
 * @file
 * core00_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function core00_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: access comments.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: administer comments.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: administer content types.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: create any basic_block bean.
  $permissions['create any basic_block bean'] = array(
    'name' => 'create any basic_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: create any php_block bean.
  $permissions['create any php_block bean'] = array(
    'name' => 'create any php_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: delete any basic_block bean.
  $permissions['delete any basic_block bean'] = array(
    'name' => 'delete any basic_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: delete any php_block bean.
  $permissions['delete any php_block bean'] = array(
    'name' => 'delete any php_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any basic_block bean.
  $permissions['edit any basic_block bean'] = array(
    'name' => 'edit any basic_block bean',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: edit any php_block bean.
  $permissions['edit any php_block bean'] = array(
    'name' => 'edit any php_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: edit own comments.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: post comments.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: skip comment approval.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: view any basic_block bean.
  $permissions['view any basic_block bean'] = array(
    'name' => 'view any basic_block bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: view any contact_block bean.
  $permissions['view any contact_block bean'] = array(
    'name' => 'view any contact_block bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: view any php_block bean.
  $permissions['view any php_block bean'] = array(
    'name' => 'view any php_block bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: view bean page.
  $permissions['view bean page'] = array(
    'name' => 'view bean page',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: view bean revisions.
  $permissions['view bean revisions'] = array(
    'name' => 'view bean revisions',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: view files.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'robot' => 'robot',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
