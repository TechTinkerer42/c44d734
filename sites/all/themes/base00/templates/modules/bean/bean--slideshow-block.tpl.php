<?php

/**
 * @file
 * Template for bootstrap carousel
 */

?>
<div id="carousel-bootstrap" class="carousel slide">
  <ol class="carousel-indicators">
  <?php if (is_array($carousel_items)) : ?>
  <?php foreach ($carousel_items as $id => $carousel_slide) : ?>
    <li data-target="#carousel-bootstrap" data-slide-to="<?php print $id; ?>" class="<?php ($id == '0') ? print 'active' : print ''; ?>"></li>
  <?php endforeach; ?>
  <?php endif; ?>
  </ol>
  
  <div class="carousel-inner">
  <?php if (is_array($carousel_items)) : ?>
    <?php foreach ($carousel_items as $id => $carousel_slide) : ?>
      <div class="item<?php ($id == '0') ? print ' active' : print ''; ?>">
       <?php print render($carousel_slide['field_slide_image']); ?>


          <div class="carousel-caption">
        <?php if (!empty($carousel_slide['title_field'])): ?>
        <h1><?php print render($carousel_slide['title_field']); ?></h1>
        <?php endif; ?>
        
        <?php if (!empty($carousel_slide['field_slide_caption'])): ?>
            <?php print render($carousel_slide['field_slide_caption']); ?>
        <?php endif; ?>
        
        <?php if (!empty($carousel_slide['field_slide_button'])): ?>
            <span class="btn btn-primary"><?php print render($carousel_slide['field_slide_button']); ?>
        <?php endif; ?>
                
          </div>

      </div>

    <?php endforeach; ?>

  </div><!-- .carousel-inner -->

  <!-- Controls -->
  <a class="left carousel-control" href="#carousel-bootstrap" data-slide="prev">
    <span class="glyphicon glyphicon-chevron-left"></span>
  </a>
  <a class="right carousel-control" href="#carousel-bootstrap" data-slide="next">
    <span class="glyphicon glyphicon-chevron-right"></span>
  </a>
  <?php endif; ?>
</div>
