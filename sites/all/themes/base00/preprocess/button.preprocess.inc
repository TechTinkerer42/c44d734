<?php
/**
 * Preprocessor for theme('button').
 */
function base00_preprocess_button(&$variables) {
  $variables['element']['#attributes']['class'][] = 'btn ';

  if (isset($variables['element']['#value'])) {
    $classes = array(


      //specifics
      t('Save and add') => 'btn-success',
      t('Add another item') => 'btn-success',
      t('Add effect') => 'btn-primary',
      t('Add and configure') => 'btn-primary',
      t('Update style') => 'btn-primary',
      t('Download feature') => 'btn-primary',
      t('Generate feature') => 'primary',            

      //generals
      t('Save') => 'btn-primary',
      t('Ok') => 'btn-primary',  
      t('Log in') => 'btn-primary',
      t('Apply') => 'btn-primary',
      t('Create') => 'btn-primary',
      t('Confirm') => 'btn-primary',
      t('Submit') => 'btn-primary',
      t('Export') => 'btn-primary',
      t('Import') => 'btn-primary',
      t('Update') => 'btn-default',
      t('Filter') => 'btn-primary',      
      t('Restore') => 'btn-primary',
      t('Rebuild') => 'btn-primary',
      t('Search') => 'btn-primary',
      t('Cancel') => 'btn-default',        
      t('Add') => 'btn-primary',
      t('Delete') => 'btn-danger',
      t('Remove') => 'btn-danger',
      t('Uninstall') => 'btn-danger',    
      t('Upload') => 'btn-success',   
      t('Next') => 'btn-primary',
      t('Previous') => 'btn-primary',
      t('Continue') => 'btn-primary',      
                     
    );
    foreach ($classes as $search => $class) {
      if (strpos($variables['element']['#value'], $search) !== FALSE) {
        $variables['element']['#attributes']['class'][] = $class;
        break;
      }
    }
    if (!array_key_exists($variables['element']['#value'] , $classes)){
	    $variables['element']['#attributes']['class'][] = 'btn-dark';
    }
  }
}