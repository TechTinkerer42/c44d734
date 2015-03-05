<?php
/*
function taxonomy_get_vocabularies() {
  return taxonomy_vocabulary_load_multiple(FALSE, array());
}
*/

/**
* Implementation of hook_menu() to add menu item for map popup ajax request.
*/
function bulk_domain_check_search_form() {
  $search_form = '';
  $search_form['b44_vocabs'] = array(
	  '#markup' => '<iframe id="vocab-links" onload="grabiFrameContent()" src="http://base44.core44.com"></iframe>',
  );
	$search_form['#attached']['js'] = array(
	  drupal_get_path('module', 'bulk_domain_check') . '/domainsearch.js',
	);
	  
  $search_form['prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Prefix'),
//    '#field_suffix' => '',
//    '#required' => TRUE,
//    '#size' => 3,
//    '#default_value' => variable_get('chosen_minimum_width', 200),
    '#description' => t('Add a prefix to each keyword before checking'),
  );
  $search_form['keywords'] = array(
    '#type' => 'textarea',
    '#title' => t('Keywords'),
    '#rows' => 1,
//    '#field_suffix' => '',
    '#required' => TRUE,
//    '#size' => 3,
//    '#default_value' => variable_get('chosen_minimum_width', 200),
    '#description' => t('Enter a URL to scan for Keywords. Alternatively enter a comma separated list of words check'),
  );
  $search_form['suffix'] = array(
    '#type' => 'textfield',
    '#title' => t('Suffix'),
//    '#field_suffix' => '',
//    '#required' => TRUE,
//    '#size' => 3,
//    '#default_value' => variable_get('chosen_minimum_width', 200),
    '#description' => t('Add a suffix to each keyword before checking'),
  );  

  $search_form['tld_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('TLD options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $search_form['tld_fieldset']['tld'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Choose a value'),
    '#id' => 'tld', 
    '#default_value' => array(0 => 0),
    '#options' => 
			array(
			'.com',
						
			'.ac',
			'.aero',
			'.af',
			'.ag',
			'.am',
			'.as',
			'.at',
			'.au',
			'.be',
			'.biz',
			'.bj',
			'.br',
			'.bz',
			'.ca',
			'.cat',
			'.cc',
			'.cd',
			'.ch',
			'.ci',
			'.cl',
			'.cn',
			'.coop',
			'.cx',
			'.cz',
			'.de',
			'.dk',
			'.edu',
			'.ee',
			'.es',
			'.eu',
			'.fi',
			'.fr',
			'.gf',
			'.gg',
			'.gov',
			'.gr',
			'.graphics',
			'.guru',
			'.hk',
			'.hn',
			'.hu',
			'.ie',
			'.il',
			'.in',
			'.info',
			'.int',
			'.io',
			'.is',
			'.it',
			'.jp',
			'.ke',
			'.kr',
			'.kz',
			'.li',
			'.lt',
			'.lu',
			'.lv',
			'.me',
			'.mg',
			'.mil',
			'.mn',
			'.ms',
			'.museum',
			'.mx',
			'.my',
			'.na',
			'.name',
			'.net',
			'.nl',
			'.no',
			'.nu',
			'.nz',
			'.org',
			'.pl',
			'.pm',
			'.pr',
			'.pro',
			'.re',
			'.ro',
			'.ru',
			'.se',
			'.sg',
			'.sh',
			'.si',
			'.st',
			'.technology',
			'.tf',
			'.tj',
			'.tk',
			'.tl',
			'.tm',
			'.to',
			'.today',
			'.tr',
			'.tv',
			'.tw',
			'.ua',
			'.ug',
			'.uk',
			'.us',
			'.uz',
			'.ve',
			'.wf',
			'.ws',
			'.yt',
			'.xxx',
			'.academy',
			'.bike',
			'.builders',
			'.camera',
			'.camp',
			'.cab',
			'.careers',
			'.center',
			'.clothing',
			'.construction',
			'.contractors',
			'.company',
			'.computer',
			'.cool',
			'.diamonds',
			'.directory',
			'.domains',
			'.education',
			'.enterprises',
			'.email',
			'.equipment',
			'.estate',
			'.gallery',
			'.glass',
			'.holdings',
			'.kicthen',
			'.land',
			'.lighting',
			'.limo',
			'.ninja',
			'.institute',
			'.management',
			'.menu',
			'.photography',
			'.photos',
			'.plumbing',
			'.recipes',
			'.rentals',
			'.repair',
			'.sexy',
			'.shoes',
			'.singles',
			'.systems',
			'.support',
			'.soultions',
			'.tips',
			'.training',
			'.ventures',
			'.voyage',
			'.tattoo',
			'.uno',
			),
  );       
 
  
  $search_form['submit'] = array(
	  '#markup' => '<a id="submit-search" href="#" onClick="getDomains(); return false;" class="btn btn-primary">Search</a>'
	);
  $search_form['status'] = array(
	  '#markup' => '<div id="status"></div>'
	);
  $search_form['freeDomains'] = array(
	  '#markup' => '<table id="freeDomains" class="table table-bordered table-hover table-striped"><tbody></tbody></table>'
	);
  //return $form;
  return $search_form;
}





