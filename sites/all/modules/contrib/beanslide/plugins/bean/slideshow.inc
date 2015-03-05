<?php
/**
 * @file
 *   A bean slideshow plugin.
 */

class BeanslideBean extends BeanPlugin {
  /**
   * Implements BeanPlugin::values().
   */
  public function values() {
    return array(
      'slideshow_plugin' => 'jquery.cycle',
      'image_style' => 'beanslide-960',
      'cycle_effect' => 'fade',
      'vegas_overlay' => '01.png',
      'transition_duration' => 3000,
      'timeout' => 8000,
      'navigation' => array(
        'position' => '<none>',
        'previous' => '<',
        'next' => '>',
      ),
      'pager' => array(
        'type' => '<none>',
        'position' => 'before',
      ),
      'include_default_css' => TRUE,
      'caption_click' => array(
        'enable' => FALSE,
        'target' => '.caption',
      ),
    );
  }

  /**
   * Implements BeanPlugin::form().
   */
  public function form($bean, $form, &$form_state) {
    $form = array();

    $form['slideshow_plugin'] = array(
      '#type' => 'select',
      '#title' => t('Slideshow plugin'),
      '#options' => array(
        'jquery.cycle' => t('jQuery Cycle'),
        'flexslider'   => t('FlexSlider'),
        'jquery.vegas' => t('jQuery Vegas'),
        'responsiveslides' => t('responsiveSlides'),
      ),
      '#default_value' => $bean->slideshow_plugin,
    );

    $form['cycle_effect'] = array(
      '#type' => 'select',
      '#title' => t('Transition effect'),
      '#options' => array('fade' => 'Fade'),
      '#default_value' => $bean->cycle_effect,
      '#states' => array(
        'visible' => array(
          'select[name="slideshow_plugin"]' => array('value' => 'jquery.cycle'),
        ),
      ),
    );
    $form['responsive_maxwidth'] = array(
      '#type' => 'textfield',
      '#title' => t('Maximum slideshow width (pixels)'),
      '#default_value' => 960,
      '#states' => array(
        'visible' => array(
          'select[name="slideshow_plugin"]' => array('value' => 'responsiveslides'),
        ),
      ),
    );

    $vegas_overlay_options = array('<none>' => '- None -');
    foreach (range(1, 15) as $index) {
      $overlay = sprintf('%02d.png', $index);
      $vegas_overlay_options[$overlay] = $overlay;
    }

    // @TODO: Show the overlays using CSS with background-repeat and some extra markup.
    $form['vegas_overlay'] = array(
      '#type' => 'select',
      '#title' => t('Overlay pattern'),
      '#description' => t('Vegas can optionally use an overlay pattern to decrease the perception of pixelization, bluriness, and compression artifacts seen when a picture is stretched beyond its original size.'),
      '#options' => $vegas_overlay_options,
      '#default_value' => $bean->vegas_overlay,
      '#states' => array(
        'visible' => array(
          'select[name="slideshow_plugin"]' => array('value' => 'jquery.vegas'),
        ),
      ),
    );

    // Gather image styles
    $form['image_style'] = array(
      '#type' => 'select',
      '#title' => t('Image style'),
      '#options' => array('<none>' => t('None')) + drupal_map_assoc(array_keys(image_styles())),
      '#default_value' => $bean->image_style,
    );

    $form['transition_duration'] = array(
      '#type' => 'textfield',
      '#title' => t('Transition duration'),
      '#description' => t('The time it takes for each transition (such as fade), in milliseconds.'),
      '#default_value' => $bean->transition_duration,
    );

    $form['timeout'] = array(
      '#type' => 'textfield',
      '#title' => t('Timeout'),
      '#description' => t('The time each slide is shown, in milliseconds.'),
      '#default_value' => $bean->timeout,
    );

    $form['pager'] = array(
      '#type' => 'fieldset',
      '#title' => t('Pager'),
      '#tree' => TRUE,
    );
    $form['pager']['type'] = array(
      '#type' => 'select',
      '#title' => t('Pager'),
      '#options' => array(
        '<none>' => t('None'),
        'numbers' => t('Numbers (e.g. 1 2 3 4 5) [TODO]'),
        'position' => t('Position (e.g., 1/5)'),
        'thumbnails' => t('Thumbnails [TODO]'),
      ),
      '#description' => t('Attaches a pager.'),
      '#default_value' => $bean->pager['type'],
    );
    $form['pager']['position'] = array(
      '#type' => 'select',
      '#title' => t('Position'),
      '#options' => array(
        'before' => t('Before slideshow'),
        'after' => t('After slideshow'),
      ),
      '#description' => t('Where to place the pager.'),
      '#default_value' => $bean->pager['position'],
      '#states' => array(
        'invisible' => array(
          'select[name="pager[type]"]' => array('value' => '<none>'),
        ),
      ),
    );
    // Alert for responsiveSlides library
    $form['pager']['responsive_pager'] = array(
      '#type' => 'item',
      '#title' => t('ALERT'),
      '#markup' => '<label>' . t('The responsiveSlides library always appends the pager to the slideshow UL. TODO: incorporate an "append" selector') . '</label>',
      '#states' => array(
        'visible' => array(
          'select[name="slideshow_plugin"]' => array('value' => 'responsiveslides'),
          'select[name="pager[position]"]' => array('value' => 'before'),
        ),
      ),
    );

    $form['navigation'] = array(
      '#type' => 'fieldset',
      '#title' => t('Navigation controls'),
      '#tree' => TRUE,
    );
    $form['navigation']['position'] = array(
      '#type' => 'select',
      '#title' => t('Position'),
      '#options' => array(
        '<none>' => t('None'),
        'before' => t('Before slideshow'),
        'after' => t('After slideshow'),
      ),
      '#default_value' => $bean->navigation,
    );
    // Alert for responsiveSlides library
    $form['navigation']['responsive_navigation'] = array(
      '#type' => 'item',
      '#title' => t('ALERT'),
      '#markup' => '<label>' . t('The responsiveSlides library always appends the navigation controls to the slideshow UL. TODO: incorporate an "append" selector') . '</label>',
      '#states' => array(
        'visible' => array(
          'select[name="slideshow_plugin"]' => array('value' => 'responsiveslides'),
          'select[name="navigation[position]"]' => array('value' => 'before'),
        ),
      ),
    );
    $navigation_states =  array(
      'invisible' => array(
        'select[name="navigation[position]"]' => array('value' => '<none>'),
      ),
    );
    $form['navigation']['previous'] = array(
      '#type' => 'textfield',
      '#title' => t('Previous button text'),
      '#default_value' => $bean->navigation['previous'],
      '#states' => $navigation_states,
    );
    $form['navigation']['next'] = array(
      '#type' => 'textfield',
      '#title' => t('Next button text'),
      '#default_value' => $bean->navigation['next'],
      '#states' => $navigation_states,
    );

    // Enable clickable caption (if a link exists in the caption).
    $form['caption_click'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
    );

    $form['caption_click']['enable'] = array(
      '#type' => 'checkbox',
      '#title' => t('Clickable caption'),
      '#description' => t('If the caption contains a link, make the entire caption clickable.'),
      '#default_value' => $bean->caption_click['enable'],
    );
    $form['caption_click']['target'] = array(
      '#type' => 'textfield',
      '#title' => 'Caption CSS selector',
      '#default_value' => $bean->caption_click['target'],
      '#states' => array(
        'visible' => array(
          ':input[name="caption_click[enable]"]' => array('checked' => TRUE),
        ),
      ),
    );

    $form['include_default_css'] = array(
      '#type' => 'checkbox',
      '#title' => t('Include default CSS'),
      '#description' => t('Add the default CSS styles that come with Bean Slide.'),
      '#default_value' => $bean->include_default_css,
    );
    return $form;
  }

  /**
   * Implements BeanPlugin::view().
   */
  public function view($bean, $content, $view_mode = 'full', $langcode = NULL) {
    return $content;
  }
}
