<?php

/**
 * @file
 * Default simple view template to display a list of summary lines.
 *
 * @ingroup views_templates
 */
?>

  <ul class="views-summary">
  <?php foreach ($rows as $id => $row): ?>
    <?php if (($row->url == '/'.current_path())) { $active = ' active'; }else{ $active = ''; }; ?>  
    <a class="list-group-item<?php print $active; ?>" href="<?php print $row->url; ?>"<?php print !empty($row_classes[$id]) ? ' class="'. $row_classes[$id] .'"' : ''; ?>><?php print $row->link; ?>
      <?php if (!empty($options['count'])): ?>
        <span class="badge badge-info pull-right"><?php print $row->count?></span>
      <?php endif; ?>
      </a>
  <?php endforeach; ?>
  </ul>
