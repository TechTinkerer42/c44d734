<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']: Items for the header region.
 * - $page['navigation']: Items for the navigation region, below the main menu (if any).
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
?>


<?php if(!$overlay){ include(drupal_get_path('theme', 'scubox') . "/layouts/page.navtop.inc"); } ?>

<?php if (!$overlay) : ?> 
	<?php print render($page['map_first']); ?>
	<?php if (!empty($page['map'])): ?> 	
		<div id="content-list"><?php print render($page['content_list']); ?></div><div id="map"><?php print render($page['map']); ?></div>
	<?php endif; ?>	
	<?php print render($page['map_second']); ?>
<?php endif; ?>  

<!-- Title -->  
<?php if (!$is_front): ?>
<div class="l-title title-block clearfix">
  <div class="l-title-inner">
	  <?php print render($title_prefix); ?>
	    <h1 class="page-title"><span class="<?php print $page_icon_class; ?>"></span><?php print $title; ?></h1>
	  <?php print render($title_suffix); ?>
	  <?php if ($action_links): ?>
	    <?php print render($action_tools); ?>
	  <?php endif; ?>
	    <ul id="map-switcher">
	    	<li class="dive-schools"><a href="#" class=""><span class="c44icon-"></span></a></li>
	    	<li class="dive-sites active"><a href="#" class=""><span class="c44icon-"></span></a></li>
	    	<li class="liveaboards"><a href="#" class=""><span class="c44icon-"></span></a></li>
	    </ul>
	  <div id='tabs' class='pull-right'>
	    <?php //print render($tabs); ?>
	  </div>
  </div>
</div>
<?php endif; ?>

<div id="main" class="l-main location">
	<?php if (!empty($page['hero'])): ?>
	  <div class="l-hero">
	    <?php print render($page['hero']); ?>
	  </div>
	<?php endif; ?>

	<!-- Main inner -->    
  <div class="l-main-inner">
	   <div id="console"><?php print $messages; ?></div>    
	   <div class="l-content" role="main">
	      <?php print render($page['highlighted']); ?>
	      <a id="main-content"></a>
	      <?php print render($page['help']); ?>
	      <div id='content' class='page-content contextual-links-region clearfix'>        
	      <?php if (!empty($page['content'])) print render($page['content']) ?>  
	      </div>
	      <?php print $feed_icons; ?>
	    </div>
	    <?php print render($page['sidebar_first']); ?>
	    <?php print render($page['sidebar_second']); ?>
	</div>
</div>

<footer class="l-footer" role="contentinfo">
  	<?php print render($page['footer']); ?>
</footer>













