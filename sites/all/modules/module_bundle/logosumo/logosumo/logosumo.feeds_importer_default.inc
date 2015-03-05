<?php
/**
 * @file
 * logosumo.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function logosumo_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'taxonomy_feed_domain_words';
  $feeds_importer->config = array(
    'name' => 'Taxonomy Feed: Domain Words',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcherExtended',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'source' => 'http://base44.core44.com/xml/tax/domain-words/all?token=ZcW4RagDP38rPh2AsgsJ',
        'base' => 'http://base44.core44.com',
        'arg1' => 'xml',
        'arg2' => 'tax',
        'arg3' => 'domain-words',
        'arg4' => 'all',
        'arg5' => '',
        'arg6' => '',
        'token' => '?token=ZcW4RagDP38rPh2AsgsJ',
        'request_timeout' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'termUuid/text()',
          'xpathparser:1' => 'termName/text()',
          'xpathparser:2' => 'parentTermUuid/text()',
          'xpathparser:3' => 'termWeight/text()',
          'xpathparser:4' => 'termDescription/text()',
          'xpathparser:5' => 'vocabMachineName/text()',
          'xpathparser:6' => 'vocabName/text()',
          'xpathparser:7' => 'vocabDescription/text()',
          'xpathparser:8' => 'vocabWeight/text()',
        ),
        'rawXML' => array(
          'xpathparser:0' => 'xpathparser:0',
          'xpathparser:1' => 'xpathparser:1',
          'xpathparser:2' => 'xpathparser:2',
          'xpathparser:3' => 'xpathparser:3',
          'xpathparser:4' => 'xpathparser:4',
          'xpathparser:5' => 'xpathparser:5',
          'xpathparser:6' => 'xpathparser:6',
          'xpathparser:7' => 'xpathparser:7',
          'xpathparser:8' => 'xpathparser:8',
        ),
        'context' => '//taxonomy_term_data',
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
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessorExtended',
      'config' => array(
        'vocabulary' => '0',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'uuid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'parent_uuid',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'weight',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'vocab_machine_name',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'vocab_name',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'vocab_description',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'vocab_weight',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '259200',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['taxonomy_feed_domain_words'] = $feeds_importer;

  return $export;
}
