<?php if (!isset($hook)) { $hook = ''; } ?>
<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if (!empty($content)): ?>
    <div class='network_block-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>          
      <?php if (!empty($content['field_network_links'])): ?>  
      <?php print render($content['field_network_links']) ?>
      <?php endif; ?>      
    </div>
  <?php endif; ?> 
</div>
<?php if (!empty($post_object)) print render($post_object) ?>