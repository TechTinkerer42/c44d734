<?php

/**
 * @file
 * Home of the FeedsHTTPFetcher and related classes.
 */

/**
 * Fetches data via HTTP.
 */
class FeedsHTTPFetcherExtended extends FeedsHTTPFetcher {

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'auto_detect_feeds' => FALSE,
      'use_pubsubhubbub' => FALSE,
      'designated_hub' => '',
      'request_timeout' => '', 
      'source' => '',
      'token' => '',      
      'base' => 'http://base44.core44.com',
      'arg1' => '',
      'arg2' => '',  
      'arg3' => '',
      'arg4' => '',
      'arg5' => '',  
      'arg6' => '',                              
    );
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);

    $form['url_display'] = array(
      '#type' => 'item',
      '#markup' => '<h2>' . $this->config['source'] . '</h2>',
    );
    $form['source'] = array(
      '#type' => 'textfield',
      '#title' => t('Source URL'),
      '#description' => t('Output value of the calculated source URL.'),
      '#default_value' => $this->config['source'],
      '#maxlength' => NULL,
      '#required' => FALSE,
      '#disabled' => TRUE,      
    ); 
    $form['token'] = array(
      '#type' => 'textfield',
      '#title' => t('Token Auth'),
      '#description' => t('If the feed requires authentication, please enter full token value here'),
      '#default_value' => $this->config['token'],
      '#maxlength' => NULL,
      '#required' => TRUE,
    );     
    $form['base'] = array(
      '#type' => 'textfield',
      '#title' => t('Source Base URL'),
      '#description' => t('Enter a feed base URL.'),
      '#default_value' => $this->config['base'],
      '#maxlength' => NULL,
      '#required' => TRUE,
    );   
    $form['arg1'] = array(
      '#type' => 'textfield',
      '#title' => t('Source argument 01: Format'),
      '#description' => t('Enter the format argument to be passed to the feed.'),
      '#default_value' => $this->config['arg1'],
      '#maxlength' => NULL,
      '#required' => TRUE,
    );  
    $form['arg2'] = array(
      '#type' => 'textfield',
      '#title' => t('Source argument 02: Entity'),
      '#description' => t('Enter the entity argument to be passed to the feed.'),
      '#default_value' => $this->config['arg2'],
      '#maxlength' => NULL,
      '#required' => FALSE,
    ); 
    $form['arg3'] = array(
      '#type' => 'textfield',
      '#title' => t('Source argument 03: TAG'),
      '#description' => t('Enter the tag argument to be passed to the feed.'),
      '#default_value' => $this->config['arg3'],
      '#maxlength' => NULL,
      '#required' => FALSE,
    );
    $form['arg4'] = array(
      '#type' => 'textarea',
      '#title' => t('Source argument 04: Entity Arguments'),
      '#description' => t('Entity relevant arguments. This argument can accept multiple comma seperated values. Use "all" to import all'),
      '#default_value' => $this->config['arg4'],
      '#maxlength' => NULL,
      '#required' => FALSE,
    );    
    $form['arg5'] = array(
      '#type' => 'textfield',
      '#title' => t('Source argument 05: Custom 01'),
      '#description' => t('Enter the fifth argument to be passed to the feed.'),
      '#default_value' => $this->config['arg5'],
      '#maxlength' => NULL,
      '#required' => FALSE,
    );  
 
    $form['arg6'] = array(
      '#type' => 'textfield',
      '#title' => t('Source argument 06: Custom 02'),
      '#description' => t('Enter the sixth argument to be passed to the feed.'),
      '#default_value' => $this->config['arg6'],
      '#maxlength' => NULL,
      '#required' => FALSE,
    );                       
    return $form;
  }

  /**
   * Override parent::configFormValidate().
   */
  public function configFormValidate(&$values) {
    $arguments = array(
      isset($values['base']) ? $values['base'] : 'http://base44.core44.com',
      $values['arg1'],
      $values['arg2'],
      $values['arg3'],
      $values['arg4'],
      $values['arg5'],
      $values['arg6'],      
    ); 
    $empties = array();
    $url_parts = array();   
     
    foreach($arguments as $key => $arg){
      if(empty($arg)){
        $empties[] .= $key;
      }else{
        $url_parts[] .= $arg;
      }
    };
    $url = implode('/', $url_parts) . $values['token'];
    $end = isset($empties[0]) ? $empties[0] : count($url_parts); 
      
    if ($end < count($url_parts)) {
      form_set_error('arg'.$end, t('This argument is required'));
    }else{
      if (!feeds_valid_url($url, TRUE)) {
        form_set_error($form_key, t('The URL %source is invalid.', array('%source' => $url)));
      }else{
        $values['source'] = $url;
      }
      
      
/*
      elseif ($this->config['auto_detect_feeds']) {
        feeds_include_library('http_request.inc', 'http_request');
        if ($url = http_request_get_common_syndication($url)) {
          $values['source'] = $url;
        }
      }
*/

    }    
  }
  
  /**
   * Expose source form.
   */
  public function sourceForm($source_config) {
    $form = array();
    
/*
    $form['url_display'] = array(
      '#type' => 'item',
      '#markup' => '<h2>' . $this->config['source'] . '</h2>',
    );
*/
    $form['source'] = array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#description' => t('Enter a feed URL.'),
      '#default_value' => isset($this->config['source']) ? $this->config['source'] : '',
      '#maxlength' => NULL,
      '#required' => FALSE,
      '#disabled' => TRUE,  
      '#size' => 160,              
    );
    return $form;
  }




}