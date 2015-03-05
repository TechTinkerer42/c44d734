<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php 
//define some variables

//dsm($fields);

$price = '';
$disable = ' disabled';
$buy = '';
$output = '';
$pid = $fields['nid']->raw;
$stock = 0;
$stock = isset($row->_field_data['commerce_product_field_data_field_product_product_id']['entity']->commerce_stock['und'][0]['value']) ? $row->_field_data['commerce_product_field_data_field_product_product_id']['entity']->commerce_stock['und'][0]['value'] : 0; 
if ( $stock > 0 ) { $price = $fields['commerce_price']->content; $disable = ''; $buy = $fields['field_product']->content; };

//build output

$output .= '<div class="product-left">';
	$output .= $fields['contextual_links']->wrapper_prefix . $fields['contextual_links']->content . $fields['contextual_links']->wrapper_suffix;
	$output .= $fields['field_brand_images']->content;
$output .= '</div>';
	
$output .= '<div class="product-right">';			
	// $output .= $fields['title_field']->wrapper_prefix . $fields['title_field']->content . $fields['title_field']->wrapper_suffix;
	$output .= $price;
	$output .= $fields['commerce_stock']->content;	

	$output .= '<span class="tags">';
		$output .= $fields['field_tags']->content;
	$output .= '</span>';
	
	$output .= '<div class="row-teaser">';
		$output .= $fields['field_description']->content;
	$output .= '</div>';

	$output .= '<span class="btn-group">';
		// $output .= '<a class="btn btn-dark" href="#overlay=node/' . $pid . '">More info</a>';
		$output .= '<a class="btn btn-dark' . $disable . '" href="/eform/submit/product-enquiry-form?field_product_reference=' . $pid . '">Enquire</a>';
		$output .= '<a class="btn btn-primary' . $disable . '" href="' . $buy . '" style="">' . t('Buy now') . '</a>';
	$output .= '</span>';
$output .= '</div>';

print $output;

?>