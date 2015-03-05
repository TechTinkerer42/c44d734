<?php if (!isset($hook)) { $hook = ''; } ?>

<?php if (!empty($pre_object)) print render($pre_object) ?>
<h1>this is a features .tpl file</h1>
<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>

  <?php if (!empty($content)): ?>
    <div class='contact-details-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
      <?php //print render($content); ?>
      <?php //dsm($content); ?>      
      
      <?php if (!empty($content['field_company_address'])): ?>  
      <address>
      <div class='field-address'><?php print render($content['field_company_address']) ?></div><hr>
      </address>  
      <?php endif; ?>
      <?php if (!empty($content['field_email_address'])): ?>  
        <div class='field-email'><span class="glyphicon glyphicon-envelope"></span><?php print render($content['field_email_address']) ?></div><hr>
      <?php endif; ?>
      <?php if (!empty($content['field_telephone'])): ?>  
        <div class='field-telephone'><span class="glyphicon glyphicon-phone"></span><?php print render($content['field_telephone']) ?></div><hr>
      <?php endif; ?>
      <?php if (!empty($content['field_fax'])): ?>  
        <div class='field-fax'><span class="glyphicon glyphicon-print"></span><?php print render($content['field_fax']) ?></div><hr>
      <?php endif; ?> 
        
    </div>
  <?php endif; ?> 


</div>

<?php if (!empty($post_object)) print render($post_object) ?>