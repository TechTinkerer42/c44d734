<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page while offline.
 *
 * All the available variables are mirrored in html.tpl.php and page.tpl.php.
 * Some may be blank but they are provided for consistency.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 *
 * @ingroup themeable
 */
?><!DOCTYPE html>
<?php if (omega_extension_enabled('compatibility') && omega_theme_get_setting('omega_conditional_classes_html', TRUE)): ?>
<!--[if IEMobile 7]><html class="ie iem7" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
<!--[if lte IE 6]><html class="ie lt-ie9 lt-ie8 lt-ie7" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
<!--[if (IE 7)&(!IEMobile)]><html class="ie lt-ie9 lt-ie8" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
<!--[if IE 8]><html class="ie lt-ie9" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
<!--[if (gte IE 9)|(gt IEMobile 7)]><html class="ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
<![if !IE]><html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]>
<?php else: ?>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<?php endif; ?>
<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body<?php print $attributes;?>>

<div class="navbar-wrapper top">
<header class="l-header" role="banner"><nav class="navbar navbar-inverse" role="navigation">

    <!-- Admin links -->

    <div id="user-menu">
              
      <!-- Toggle -->
      <span class='login-wrapper'>
        <span class="login-msg"></span>
          <a href="user" class="toggle-trigger scuboxButton">
          <span class="c44icon-"></span><span class="login-status">login</span>
        </a>
      </span>
      <!-- links -->
      <div class="user-links toggle-block">
        <?php print render($user_admin); ?>  
      </div>

    </div>

	
  <div id="breadcrumb"><?php print $breadcrumb; ?></div>  
  
  <!-- Brand -->
  <div class="navbar-header pull-right">
    <div class="l-branding">
    <a class="navbar-brand site-name" href="<?php print $front_page; ?>" title="<?php print t('Home') . ' ' . $site_slogan; ?>" rel="home"><?php print $logos['h40']['333']; ?></a>
    </div>    
  </div>

</nav></header>
</div>

<div class="maintenance-message"><div class="message"><?php print $logos['h80']['col_w'];; ?><span class="text">Coming Soon</span></div></div>