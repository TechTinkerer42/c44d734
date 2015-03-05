<?php
/**
 * @file
 * core00_core.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function core00_core_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'c00_core_beans';
  $feeds_importer->config = array(
    'name' => 'c00_core_beans',
    'description' => 'pulls default instances of core00 beans from data.core44.com. Warning: This may overwrite user entered data.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcherExtended',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'source' => 'http://base44.core44.com/xml/bean/core00/basic_block,contact_block?token=ZcW4RagDP38rPh2AsgsJ',
        'token' => '?token=ZcW4RagDP38rPh2AsgsJ',
        'base' => 'http://base44.core44.com',
        'arg1' => 'xml',
        'arg2' => 'bean',
        'arg3' => 'core00',
        'arg4' => 'basic_block,contact_block',
        'arg5' => '',
        'arg6' => '',
        'request_timeout' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'beanUuid/text()',
          'xpathparser:1' => 'beanType/text()',
          'xpathparser:2' => 'beanTitle/text()',
          'xpathparser:3' => 'beanBlockDelta/text()',
          'xpathparser:4' => 'beanLabel/text()',
          'xpathparser:5' => 'beanViewMode/text()',
          'xpathparser:7' => 'companyName/text()',
          'xpathparser:8' => 'companyEmail/text()',
          'xpathparser:9' => 'companyTel/text()',
          'xpathparser:10' => 'linkFacebook/text()',
          'xpathparser:12' => 'linkLinkedin/text()',
          'xpathparser:14' => 'linkTwitter/text()',
        ),
        'rawXML' => array(
          'xpathparser:0' => 'xpathparser:0',
          'xpathparser:1' => 'xpathparser:1',
          'xpathparser:2' => 'xpathparser:2',
          'xpathparser:3' => 'xpathparser:3',
          'xpathparser:4' => 'xpathparser:4',
          'xpathparser:5' => 'xpathparser:5',
          'xpathparser:7' => 'xpathparser:7',
          'xpathparser:8' => 'xpathparser:8',
          'xpathparser:9' => 'xpathparser:9',
          'xpathparser:10' => 'xpathparser:10',
          'xpathparser:12' => 'xpathparser:12',
          'xpathparser:14' => 'xpathparser:14',
        ),
        'context' => '//bean',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:12' => 0,
            'xpathparser:14' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsBeanProcessor',
      'config' => array(
        'expire' => -1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'type',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'title_field',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'delta',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'label',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'view_mode',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_company_address:organisation_name',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_telephone',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_facebook:url',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_linkedin:url',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_twitter:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'php_code',
        'skip_hash_check' => 0,
        'author' => '1',
        'bean_type' => '',
        'bundle' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['c00_core_beans'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'c00_core_php_beans';
  $feeds_importer->config = array(
    'name' => 'c00_core_php_beans',
    'description' => 'pulls and updates core00 PHP beans from data.core44.com',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcherExtended',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'source' => 'http://base44.core44.com/xml/bean/core00/php_block?token=ZcW4RagDP38rPh2AsgsJ',
        'token' => '?token=ZcW4RagDP38rPh2AsgsJ',
        'base' => 'http://base44.core44.com',
        'arg1' => 'xml',
        'arg2' => 'bean',
        'arg3' => 'core00',
        'arg4' => 'php_block',
        'arg5' => '',
        'arg6' => '',
        'request_timeout' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'beanUuid/text()',
          'xpathparser:1' => 'beanLabel/text()',
          'xpathparser:2' => 'beanBlockDelta/text()',
          'xpathparser:3' => 'beanPhpCode/text()',
          'xpathparser:4' => 'beanTitle/text()',
          'xpathparser:5' => 'beanType/text()',
        ),
        'rawXML' => array(
          'xpathparser:0' => 'xpathparser:0',
          'xpathparser:1' => 'xpathparser:1',
          'xpathparser:2' => 'xpathparser:2',
          'xpathparser:3' => 'xpathparser:3',
          'xpathparser:4' => 'xpathparser:4',
          'xpathparser:5' => 'xpathparser:5',
        ),
        'context' => '//bean',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsBeanProcessor',
      'config' => array(
        'expire' => -1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'label',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'delta',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_php_code',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'title_field',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'type',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'php_code',
        'skip_hash_check' => 0,
        'author' => '1',
        'bean_type' => '',
        'bundle' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['c00_core_php_beans'] = $feeds_importer;

  return $export;
}
