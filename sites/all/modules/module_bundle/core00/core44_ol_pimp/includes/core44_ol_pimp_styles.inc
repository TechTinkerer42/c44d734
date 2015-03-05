<?php
/**
 * Define custom styles.
 */
function core44_ol_pimp_openlayers_styles() {
  $styles = array();
  
  //Location style
  $style = new stdClass();
  $style->api_version = 1;
  $style->name = 'custom';
  $style->title = t('Custom style');
  $style->description = t('');
  $style->data = array(
    'pointRadius' => '10',
    'fillColor' => '#888888',
    'strokeColor' => '#222222',
    'strokeWidth' => '1',
    'fillOpacity' => '0.5',
    'strokeOpacity' => '0.7',
  );
  $styles[$style->name] = $style;
  
  return $styles;
}  