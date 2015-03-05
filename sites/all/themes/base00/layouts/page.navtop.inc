<nav class="navbar navbar-inverse" role="navigation">
<span class="nav-inner">
    <!-- Admin links -->
    <?php if (!$overlay) : ?>
    <div id="user-menu">
              
      <!-- Toggle -->
      <span class='login-wrapper'>
        <span class="login-msg"></span>
          <a href="user" class="toggle-trigger scuboxButton">
          <span class="c44icon-"></span><span class="login-status"><?php print $login_status; ?></span>
        </a>
      </span>
      <!-- links -->
      <div class="user-links toggle-block">
        <?php print render($user_admin); ?>  
      </div>

    </div>
    <?php endif; ?>	
	
  <?php print $breadcrumb; ?>
  
  <!-- Brand -->
  <div class="navbar-header pull-right">
    <div class="l-branding">
   <a class="navbar-brand site-name" href="<?php print $front_page; ?>" title="<?php print t('Home') . ' ' . $site_slogan; ?>" rel="home"><?php print $logos['h40']['col_w']; ?></a>
    </div>    
  </div>
</span>
</nav>