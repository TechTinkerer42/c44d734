<?php
/**
 * @file
 * core00_base44.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function core00_base44_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'data_export_bean_01';
  $view->description = 'Pages of block data in shareable formats';
  $view->tag = 'export';
  $view->base_table = 'bean';
  $view->human_name = 'Data Export Bean 01';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Block: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'bean';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'bean type';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Block: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'bean';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = 'bean Label';
  /* Field: Block: Block Delta */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'bean';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = 'bean Block Delta';
  /* Field: Block: Block UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'bean';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'bean UUID';
  /* Field: Block: Internal, numeric block ID */
  $handler->display->display_options['fields']['bid']['id'] = 'bid';
  $handler->display->display_options['fields']['bid']['table'] = 'bean';
  $handler->display->display_options['fields']['bid']['field'] = 'bid';
  $handler->display->display_options['fields']['bid']['label'] = 'bean block ID';
  /* Field: Block: View Mode */
  $handler->display->display_options['fields']['view_mode']['id'] = 'view_mode';
  $handler->display->display_options['fields']['view_mode']['table'] = 'bean';
  $handler->display->display_options['fields']['view_mode']['field'] = 'view_mode';
  $handler->display->display_options['fields']['view_mode']['label'] = 'bean View Mode';
  /* Field: Block: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'bean Title';
  $handler->display->display_options['fields']['title_field']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_type'] = '0';
  $handler->display->display_options['fields']['title_field']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['field_api_classes'] = TRUE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: PHP Code */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'PHP Code';
  $handler->display->display_options['fields']['php']['label'] = 'bean PHP code';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php  
$bean = bean_load($row->bid);
echo $bean->field_php_code[\'und\'][0][\'value\'];
 ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Contextual filter: Block: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'bean';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  $handler->display->display_options['arguments']['type']['break_phrase'] = TRUE;

  /* Display: Bean Export All */
  $handler = $view->new_display('views_data_export', 'Bean Export All', 'bean_export_all');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['transform_type'] = 'camel';
  $handler->display->display_options['style_options']['root_node'] = 'beans';
  $handler->display->display_options['style_options']['item_node'] = 'bean';
  $handler->display->display_options['path'] = 'xml/bean/all/%';
  $export['data_export_bean_01'] = $view;

  $view = new view();
  $view->name = 'data_export_tax_01';
  $view->description = 'pages of taxonomy term data in shareable formats';
  $view->tag = 'export';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Data Export Tax 01';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['label'] = 'ParentTerm';
  /* Field: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = 'Term UUID';
  $handler->display->display_options['fields']['uuid']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['uuid']['element_type'] = '0';
  $handler->display->display_options['fields']['uuid']['element_label_type'] = '0';
  $handler->display->display_options['fields']['uuid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uuid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['uuid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uuid']['hide_alter_empty'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Term Name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_1']['label'] = 'Parent Term Name';
  /* Field: Taxonomy term: Taxonomy term UUID */
  $handler->display->display_options['fields']['uuid_1']['id'] = 'uuid_1';
  $handler->display->display_options['fields']['uuid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['uuid_1']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['uuid_1']['label'] = 'Parent Term UUID';
  $handler->display->display_options['fields']['uuid_1']['element_type'] = '0';
  $handler->display->display_options['fields']['uuid_1']['element_label_type'] = '0';
  $handler->display->display_options['fields']['uuid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uuid_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['uuid_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uuid_1']['hide_alter_empty'] = FALSE;
  /* Field: Taxonomy term: Weight */
  $handler->display->display_options['fields']['weight']['id'] = 'weight';
  $handler->display->display_options['fields']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['weight']['field'] = 'weight';
  $handler->display->display_options['fields']['weight']['label'] = 'Term Weight';
  $handler->display->display_options['fields']['weight']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['weight']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['weight']['element_type'] = '0';
  $handler->display->display_options['fields']['weight']['element_label_type'] = '0';
  $handler->display->display_options['fields']['weight']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['weight']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['weight']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['weight']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['weight']['separator'] = '';
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Term Description';
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['description']['element_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_type'] = '0';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_type'] = '0';
  $handler->display->display_options['fields']['tid']['element_label_type'] = '0';
  $handler->display->display_options['fields']['tid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['tid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['tid']['hide_alter_empty'] = FALSE;
  /* Field: Taxonomy edge: Distance to root */
  $handler->display->display_options['fields']['distance']['id'] = 'distance';
  $handler->display->display_options['fields']['distance']['table'] = 'taxonomy_term_edge';
  $handler->display->display_options['fields']['distance']['field'] = 'distance';
  $handler->display->display_options['fields']['distance']['label'] = 'Term Depth';
  $handler->display->display_options['fields']['distance']['separator'] = '';
  /* Field: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['fields']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['label'] = 'Vocab Machine name';
  $handler->display->display_options['fields']['machine_name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['machine_name']['element_type'] = '0';
  $handler->display->display_options['fields']['machine_name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['machine_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['machine_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['machine_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['machine_name']['hide_alter_empty'] = FALSE;
  /* Field: Taxonomy vocabulary: Description */
  $handler->display->display_options['fields']['description_1']['id'] = 'description_1';
  $handler->display->display_options['fields']['description_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['description_1']['field'] = 'description';
  $handler->display->display_options['fields']['description_1']['label'] = 'Vocab Description';
  /* Field: Taxonomy vocabulary: Name */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['label'] = 'Vocab Name';
  /* Field: Taxonomy vocabulary: Weight */
  $handler->display->display_options['fields']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['fields']['weight_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['weight_1']['field'] = 'weight';
  $handler->display->display_options['fields']['weight_1']['label'] = 'Vocab Weight';
  /* Sort criterion: Taxonomy edge: Distance to root */
  $handler->display->display_options['sorts']['distance']['id'] = 'distance';
  $handler->display->display_options['sorts']['distance']['table'] = 'taxonomy_term_edge';
  $handler->display->display_options['sorts']['distance']['field'] = 'distance';
  /* Contextual filter: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['arguments']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['arguments']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['default_action'] = 'access denied';
  $handler->display->display_options['arguments']['machine_name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['machine_name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['machine_name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['machine_name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['machine_name']['limit'] = '0';
  $handler->display->display_options['arguments']['machine_name']['break_phrase'] = TRUE;

  /* Display: Tax Export All */
  $handler = $view->new_display('views_data_export', 'Tax Export All', 'tax_export_all');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['transform_type'] = 'camel';
  $handler->display->display_options['style_options']['root_node'] = 'taxonomy_term_datas';
  $handler->display->display_options['style_options']['item_node'] = 'taxonomy_term_data';
  $handler->display->display_options['path'] = 'xml/tax/all/%';
  $export['data_export_tax_01'] = $view;

  $view = new view();
  $view->name = 'data_export_tax_wordlists';
  $view->description = 'pages of taxonomy term data in shareable formats';
  $view->tag = 'export';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Data Export Tax Wordlists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['label'] = 'ParentTerm';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextual filter: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['arguments']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['arguments']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['default_action'] = 'access denied';
  $handler->display->display_options['arguments']['machine_name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['machine_name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['machine_name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['machine_name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['machine_name']['limit'] = '0';
  $handler->display->display_options['arguments']['machine_name']['break_phrase'] = TRUE;

  /* Display: Tax Export Wordlists */
  $handler = $view->new_display('views_data_export', 'Tax Export Wordlists', 'tax_export_wordlist');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 0;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['path'] = 'csv/wordlists/%';
  $export['data_export_tax_wordlists'] = $view;

  $view = new view();
  $view->name = 'frontpage_tax_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Frontpage tax data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<?php
print get_vocab_list();

function get_vocab_list() {
	$list = \'\';

	$vocabs = taxonomy_vocabulary_get_names();

	foreach($vocabs as $m_name => $vocab) {
  	$list .= \'<tr><td>\' . $vocab->name . \'</td><td>http://base44.core44.com/csv/wordlists/\' . $m_name . \'</td></tr>\';
	}
	return \'<table class="table table-bordered table-hover table-striped"><tbody>\' . $list . \'</tbody></table>\';
}
?>';
  $handler->display->display_options['empty']['area']['format'] = 'php_code';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['value'] = 'thisisnotaterm';

  /* Display: Vocabs List */
  $handler = $view->new_display('block', 'Vocabs List', 'vocabs_list_block');
  $export['frontpage_tax_data'] = $view;

  return $export;
}
