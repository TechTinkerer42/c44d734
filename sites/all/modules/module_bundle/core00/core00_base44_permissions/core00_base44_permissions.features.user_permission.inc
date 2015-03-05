<?php
/**
 * @file
 * core00_base44_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function core00_base44_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'access bean overview'.
  $permissions['access bean overview'] = array(
    'name' => 'access bean overview',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(),
    'module' => 'contextual',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'robot' => 'robot',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer bean settings'.
  $permissions['administer bean settings'] = array(
    'name' => 'administer bean settings',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean types'.
  $permissions['administer bean types'] = array(
    'name' => 'administer bean types',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'administer beans'.
  $permissions['administer beans'] = array(
    'name' => 'administer beans',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: 'administer commerce_product entities'.
  $permissions['administer commerce_product entities'] = array(
    'name' => 'administer commerce_product entities',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'administer feeds_tamper'.
  $permissions['administer feeds_tamper'] = array(
    'name' => 'administer feeds_tamper',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(),
    'module' => 'image',
  );

  // Exported permission: 'administer mailsystem'.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(),
    'module' => 'mailsystem',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu attributes'.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(),
    'module' => 'menu_attributes',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'administer product types'.
  $permissions['administer product types'] = array(
    'name' => 'administer product types',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(),
    'module' => 'search_api',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer taxonomy edge'.
  $permissions['administer taxonomy edge'] = array(
    'name' => 'administer taxonomy edge',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_edge',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'clear c00_core_beans feeds'.
  $permissions['clear c00_core_beans feeds'] = array(
    'name' => 'clear c00_core_beans feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear c00_core_php_beans feeds'.
  $permissions['clear c00_core_php_beans feeds'] = array(
    'name' => 'clear c00_core_php_beans feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'configure store'.
  $permissions['configure store'] = array(
    'name' => 'configure store',
    'roles' => array(),
    'module' => 'commerce',
  );

  // Exported permission: 'context ajax block access'.
  $permissions['context ajax block access'] = array(
    'name' => 'context ajax block access',
    'roles' => array(),
    'module' => 'context_ui',
  );

  // Exported permission: 'create any basic_block bean'.
  $permissions['create any basic_block bean'] = array(
    'name' => 'create any basic_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any contact_block bean'.
  $permissions['create any contact_block bean'] = array(
    'name' => 'create any contact_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any php_block bean'.
  $permissions['create any php_block bean'] = array(
    'name' => 'create any php_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create commerce_product entities'.
  $permissions['create commerce_product entities'] = array(
    'name' => 'create commerce_product entities',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(),
    'module' => 'path',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any basic_block bean'.
  $permissions['delete any basic_block bean'] = array(
    'name' => 'delete any basic_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any contact_block bean'.
  $permissions['delete any contact_block bean'] = array(
    'name' => 'delete any contact_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any php_block bean'.
  $permissions['delete any php_block bean'] = array(
    'name' => 'delete any php_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in accommodation_features'.
  $permissions['delete terms in accommodation_features'] = array(
    'name' => 'delete terms in accommodation_features',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in animal_names'.
  $permissions['delete terms in animal_names'] = array(
    'name' => 'delete terms in animal_names',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in aquatic_life'.
  $permissions['delete terms in aquatic_life'] = array(
    'name' => 'delete terms in aquatic_life',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in autolocation'.
  $permissions['delete terms in autolocation'] = array(
    'name' => 'delete terms in autolocation',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in client_sectors'.
  $permissions['delete terms in client_sectors'] = array(
    'name' => 'delete terms in client_sectors',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in consultant_specialisms'.
  $permissions['delete terms in consultant_specialisms'] = array(
    'name' => 'delete terms in consultant_specialisms',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in contract_lengths'.
  $permissions['delete terms in contract_lengths'] = array(
    'name' => 'delete terms in contract_lengths',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in dive_site_access'.
  $permissions['delete terms in dive_site_access'] = array(
    'name' => 'delete terms in dive_site_access',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in education_levels'.
  $permissions['delete terms in education_levels'] = array(
    'name' => 'delete terms in education_levels',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in employment_categories'.
  $permissions['delete terms in employment_categories'] = array(
    'name' => 'delete terms in employment_categories',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in employment_types'.
  $permissions['delete terms in employment_types'] = array(
    'name' => 'delete terms in employment_types',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in english_football_leagues'.
  $permissions['delete terms in english_football_leagues'] = array(
    'name' => 'delete terms in english_football_leagues',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in issue_status'.
  $permissions['delete terms in issue_status'] = array(
    'name' => 'delete terms in issue_status',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in issue_types'.
  $permissions['delete terms in issue_types'] = array(
    'name' => 'delete terms in issue_types',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in it_certifications'.
  $permissions['delete terms in it_certifications'] = array(
    'name' => 'delete terms in it_certifications',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in job_titles'.
  $permissions['delete terms in job_titles'] = array(
    'name' => 'delete terms in job_titles',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in locations_australia'.
  $permissions['delete terms in locations_australia'] = array(
    'name' => 'delete terms in locations_australia',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in mythical_creatures'.
  $permissions['delete terms in mythical_creatures'] = array(
    'name' => 'delete terms in mythical_creatures',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in personal_skills'.
  $permissions['delete terms in personal_skills'] = array(
    'name' => 'delete terms in personal_skills',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in prefixes'.
  $permissions['delete terms in prefixes'] = array(
    'name' => 'delete terms in prefixes',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in priority'.
  $permissions['delete terms in priority'] = array(
    'name' => 'delete terms in priority',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in role_status'.
  $permissions['delete terms in role_status'] = array(
    'name' => 'delete terms in role_status',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in salaries'.
  $permissions['delete terms in salaries'] = array(
    'name' => 'delete terms in salaries',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in salary_brackets_eur'.
  $permissions['delete terms in salary_brackets_eur'] = array(
    'name' => 'delete terms in salary_brackets_eur',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in salary_brackets_nzd'.
  $permissions['delete terms in salary_brackets_nzd'] = array(
    'name' => 'delete terms in salary_brackets_nzd',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in salary_brackets_usd'.
  $permissions['delete terms in salary_brackets_usd'] = array(
    'name' => 'delete terms in salary_brackets_usd',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in salary_options'.
  $permissions['delete terms in salary_options'] = array(
    'name' => 'delete terms in salary_options',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in skill_sets'.
  $permissions['delete terms in skill_sets'] = array(
    'name' => 'delete terms in skill_sets',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in social_networks'.
  $permissions['delete terms in social_networks'] = array(
    'name' => 'delete terms in social_networks',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in suffixes'.
  $permissions['delete terms in suffixes'] = array(
    'name' => 'delete terms in suffixes',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in training_standards'.
  $permissions['delete terms in training_standards'] = array(
    'name' => 'delete terms in training_standards',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in years'.
  $permissions['delete terms in years'] = array(
    'name' => 'delete terms in years',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any basic_block bean'.
  $permissions['edit any basic_block bean'] = array(
    'name' => 'edit any basic_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any commerce_product entity'.
  $permissions['edit any commerce_product entity'] = array(
    'name' => 'edit any commerce_product entity',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any contact_block bean'.
  $permissions['edit any contact_block bean'] = array(
    'name' => 'edit any contact_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any php_block bean'.
  $permissions['edit any php_block bean'] = array(
    'name' => 'edit any php_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit bean view mode'.
  $permissions['edit bean view mode'] = array(
    'name' => 'edit bean view mode',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit mimemail user settings'.
  $permissions['edit mimemail user settings'] = array(
    'name' => 'edit mimemail user settings',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: 'edit own commerce_product entities'.
  $permissions['edit own commerce_product entities'] = array(
    'name' => 'edit own commerce_product entities',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit terms in accommodation_features'.
  $permissions['edit terms in accommodation_features'] = array(
    'name' => 'edit terms in accommodation_features',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in animal_names'.
  $permissions['edit terms in animal_names'] = array(
    'name' => 'edit terms in animal_names',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in aquatic_life'.
  $permissions['edit terms in aquatic_life'] = array(
    'name' => 'edit terms in aquatic_life',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in autolocation'.
  $permissions['edit terms in autolocation'] = array(
    'name' => 'edit terms in autolocation',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in client_sectors'.
  $permissions['edit terms in client_sectors'] = array(
    'name' => 'edit terms in client_sectors',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in consultant_specialisms'.
  $permissions['edit terms in consultant_specialisms'] = array(
    'name' => 'edit terms in consultant_specialisms',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in contract_lengths'.
  $permissions['edit terms in contract_lengths'] = array(
    'name' => 'edit terms in contract_lengths',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in dive_site_access'.
  $permissions['edit terms in dive_site_access'] = array(
    'name' => 'edit terms in dive_site_access',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in education_levels'.
  $permissions['edit terms in education_levels'] = array(
    'name' => 'edit terms in education_levels',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in employment_categories'.
  $permissions['edit terms in employment_categories'] = array(
    'name' => 'edit terms in employment_categories',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in employment_types'.
  $permissions['edit terms in employment_types'] = array(
    'name' => 'edit terms in employment_types',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in english_football_leagues'.
  $permissions['edit terms in english_football_leagues'] = array(
    'name' => 'edit terms in english_football_leagues',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in issue_status'.
  $permissions['edit terms in issue_status'] = array(
    'name' => 'edit terms in issue_status',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in issue_types'.
  $permissions['edit terms in issue_types'] = array(
    'name' => 'edit terms in issue_types',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in it_certifications'.
  $permissions['edit terms in it_certifications'] = array(
    'name' => 'edit terms in it_certifications',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in job_titles'.
  $permissions['edit terms in job_titles'] = array(
    'name' => 'edit terms in job_titles',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in locations_australia'.
  $permissions['edit terms in locations_australia'] = array(
    'name' => 'edit terms in locations_australia',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in mythical_creatures'.
  $permissions['edit terms in mythical_creatures'] = array(
    'name' => 'edit terms in mythical_creatures',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in personal_skills'.
  $permissions['edit terms in personal_skills'] = array(
    'name' => 'edit terms in personal_skills',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in prefixes'.
  $permissions['edit terms in prefixes'] = array(
    'name' => 'edit terms in prefixes',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in priority'.
  $permissions['edit terms in priority'] = array(
    'name' => 'edit terms in priority',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in role_status'.
  $permissions['edit terms in role_status'] = array(
    'name' => 'edit terms in role_status',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in salaries'.
  $permissions['edit terms in salaries'] = array(
    'name' => 'edit terms in salaries',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in salary_brackets_eur'.
  $permissions['edit terms in salary_brackets_eur'] = array(
    'name' => 'edit terms in salary_brackets_eur',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in salary_brackets_nzd'.
  $permissions['edit terms in salary_brackets_nzd'] = array(
    'name' => 'edit terms in salary_brackets_nzd',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in salary_brackets_usd'.
  $permissions['edit terms in salary_brackets_usd'] = array(
    'name' => 'edit terms in salary_brackets_usd',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in salary_options'.
  $permissions['edit terms in salary_options'] = array(
    'name' => 'edit terms in salary_options',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in skill_sets'.
  $permissions['edit terms in skill_sets'] = array(
    'name' => 'edit terms in skill_sets',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in social_networks'.
  $permissions['edit terms in social_networks'] = array(
    'name' => 'edit terms in social_networks',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in suffixes'.
  $permissions['edit terms in suffixes'] = array(
    'name' => 'edit terms in suffixes',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in training_standards'.
  $permissions['edit terms in training_standards'] = array(
    'name' => 'edit terms in training_standards',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in years'.
  $permissions['edit terms in years'] = array(
    'name' => 'edit terms in years',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'import c00_core_beans feeds'.
  $permissions['import c00_core_beans feeds'] = array(
    'name' => 'import c00_core_beans feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import c00_core_php_beans feeds'.
  $permissions['import c00_core_php_beans feeds'] = array(
    'name' => 'import c00_core_php_beans feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import media'.
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'send arbitrary files'.
  $permissions['send arbitrary files'] = array(
    'name' => 'send arbitrary files',
    'roles' => array(),
    'module' => 'mimemail',
  );

  // Exported permission: 'show format selection for bean'.
  $permissions['show format selection for bean'] = array(
    'name' => 'show format selection for bean',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for comment'.
  $permissions['show format selection for comment'] = array(
    'name' => 'show format selection for comment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for commerce_product'.
  $permissions['show format selection for commerce_product'] = array(
    'name' => 'show format selection for commerce_product',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for file'.
  $permissions['show format selection for file'] = array(
    'name' => 'show format selection for file',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for flagging'.
  $permissions['show format selection for flagging'] = array(
    'name' => 'show format selection for flagging',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for rules_config'.
  $permissions['show format selection for rules_config'] = array(
    'name' => 'show format selection for rules_config',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_vocabulary'.
  $permissions['show format selection for taxonomy_vocabulary'] = array(
    'name' => 'show format selection for taxonomy_vocabulary',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'tamper c00_core_beans'.
  $permissions['tamper c00_core_beans'] = array(
    'name' => 'tamper c00_core_beans',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper c00_core_php_beans'.
  $permissions['tamper c00_core_php_beans'] = array(
    'name' => 'tamper c00_core_php_beans',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'unlock c00_core_beans feeds'.
  $permissions['unlock c00_core_beans feeds'] = array(
    'name' => 'unlock c00_core_beans feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock c00_core_php_beans feeds'.
  $permissions['unlock c00_core_php_beans feeds'] = array(
    'name' => 'unlock c00_core_php_beans feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'use PHP for settings'.
  $permissions['use PHP for settings'] = array(
    'name' => 'use PHP for settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'php',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'use text format php_code'.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'view any basic_block bean'.
  $permissions['view any basic_block bean'] = array(
    'name' => 'view any basic_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view any commerce_product entity'.
  $permissions['view any commerce_product entity'] = array(
    'name' => 'view any commerce_product entity',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any contact_block bean'.
  $permissions['view any contact_block bean'] = array(
    'name' => 'view any contact_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view any php_block bean'.
  $permissions['view any php_block bean'] = array(
    'name' => 'view any php_block bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view bean page'.
  $permissions['view bean page'] = array(
    'name' => 'view bean page',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view bean revisions'.
  $permissions['view bean revisions'] = array(
    'name' => 'view bean revisions',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view diffs of changed files'.
  $permissions['view diffs of changed files'] = array(
    'name' => 'view diffs of changed files',
    'roles' => array(),
    'module' => 'hacked',
  );

  // Exported permission: 'view files'.
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

  // Exported permission: 'view own commerce_product entities'.
  $permissions['view own commerce_product entities'] = array(
    'name' => 'view own commerce_product entities',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'view style guides'.
  $permissions['view style guides'] = array(
    'name' => 'view style guides',
    'roles' => array(),
    'module' => 'styleguide',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(),
    'module' => 'system',
  );

  return $permissions;
}
