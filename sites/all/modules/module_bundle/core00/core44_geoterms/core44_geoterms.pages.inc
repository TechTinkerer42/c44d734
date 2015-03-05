<?php

/**
 * @file
 * Geocoder autocomplete widget
 */

/**
 * Implements hook_menu().
 */
function core44_geoterms_autocomplete($string = '') {
  global $language;

  $matches = array();
  $hierachy = array();
  
  $params = array(
    'address' => $string,
    'language' => $language->language,
    'sensor' => 'false',
  );

  if ($string) {
    $url = GEOTERMS_AUTOCOMPLETE_URL . '/' . GEOTERMS_AUTOCOMPLETE_FORMAT . '?' . drupal_http_build_query($params);
    $response = drupal_http_request($url);

    if ($response->code == 200) {
      $data = json_decode($response->data);
      if ($data->status == 'OK') {

        foreach ($data->results as $result) {
          $formatted_address = '';
          $break = '';
                            
          
          //custom addition
          if (isset($result->address_components)) {
            foreach ($result->address_components as $key => $value) {
                  switch ($value->types[0]) {                  
                  case 'locality':
                    if (!empty($value->long_name)) {
                      $hierachy[$value->types[0]] = $value->long_name;
                    }
                  break; 
                  case 'administrative_area_level_2':
                    if (!empty($value->long_name)) {
                      $hierachy[$value->types[0]] = $value->long_name;
                    }
                  break; 
                  case 'administrative_area_level_1':
                    if (!empty($value->long_name)) {
                      $hierachy[$value->types[0]] = $value->short_name;
                    }
                  break; 
                  case 'country':
                    if (!empty($value->long_name)) {
                      $hierachy[$value->types[0]] = $value->long_name;
                    }
                  break; 
                  }                                                                    
            }
          }
          $hierachy_sort = array(
            $hierachy['locality'],
            $hierachy['administrative_area_level_2'],
            $hierachy['administrative_area_level_1'],
            $hierachy['country'],
          );
          if (!empty($hierachy_sort)) {
            $return = check_plain(implode(', ', array_filter($hierachy_sort)));
            $matches[$return] = $return;
          }
        }
      }
    }
  }
  drupal_json_output($matches);
}
