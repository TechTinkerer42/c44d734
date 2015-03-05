<nav class="navbar navbar-fixed-top" role="navigation">
<span class="nav-inner">
  
  <!-- Brand -->
  <div class="navbar-header">
    <div class="l-branding">
    	<a class="navbar-brand site-name" href="<?php print $front_page; ?>" title="<?php print t('Home') . ' ' . $site_slogan; ?>" rel="home"><?php print $logos['h90']['logo_jp_wo']; ?></a>
    </div>    
  </div>
  
<div id="cart-link">
        
<!-- Toggle -->
<span class='login-wrapper'>
  <span class="login-msg"></span>
    <a href="#overlay=cart" class="toggle-trigger scuboxButton">
    <span class="c44icon-"></span><span class="login-status"><?php print t('Cart'); ?></span>
  </a>
</span>
<!-- links -->
<div class="user-links toggle-block">
	<?php print views_embed_view('pop_up_cart', 'pop_up_cart'); ?>  
</div>

</div>
    
<!--
<div class="toggle-trigger filter">
	<span class="c44icon-"></span>
</div> 
-->

</span>

 
<?php
/** Function to get the Exposed filter form **/
/*
function _test_get_exposed_filter_form(){
  $view = views_get_view('brand_filter');
  $view->set_display('brand_filter');
  $view->init_handlers();
  $exposed_form = $view->display_handler->get_plugin('exposed_form');
  return $exposed_form->render_exposed_form();
}
print "<div class='toggle-block'>" . _test_get_exposed_filter_form() . "</div>";
*/
?>



</nav>
