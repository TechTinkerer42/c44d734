(function($) {
/**
 * Implementation of Drupal behavior.
 */
Drupal.openlayers.addBehavior('core44_ol_pimp_behavior_dynamic_styles', function (data, options) {

function getValue(Object, name) {
	return Object[name];
};

var map = data.openlayers;
var field = options.field;
var selected_attribute = options.label;

//Define selected layers
var layers = [];
for (var i in options.selectedlayers) {
  var selectedLayer = map.getLayersBy('drupalID', options.selectedlayers[i]);
  if (typeof selectedLayer[0] != 'undefined') {
    layers.push(selectedLayer[0]);
  }
};
//console.log(map);
/*
for (var i in Drupal.settings.openlayers.maps){
	if(Drupal.settings.openlayers.maps[i].id == map.div.id){
		var map_settings = Drupal.settings.openlayers.maps[i];
	}
}
*/

for(var i in layers){
	
	//Create a style object with context and property styles
	var dynamic_style_default = new OpenLayers.Style({
		'label': '${get_label}',
		'labelAlign': 'l',		
		'pointRadius': '${get_point_radius}',
		'labelXOffset': '${get_labelxoffset}',
		'labelOutlineColor': "#fff",
    'labelOutlineWidth': 2,
	},
	//Second parameter contains a context parameter
	{context: {			
	get_point_radius: function(feature){
											///alert(options.max_field);
											var count = 0;
											var user_max = parseInt(options.point_radius_max);	
											var user_min = parseInt(options.point_radius_min);
											var radius = user_min;
											if(options.field == '' || options.max_field == '' || options.features_only == 1){
												if(feature.cluster && options.features_only == 1){
													radius = user_min + (feature.cluster.length * 3);//should have a feature weight field for this
											    }
											}else{
												if(feature.cluster){
													for (var i = 0; i < feature.cluster.length; i++) {
														var countFieldValue = parseInt(getValue(feature.cluster[i].attributes, options.field));	
														var view_max = parseInt(getValue(feature.cluster[0].attributes, options.max_field));
													    count += countFieldValue;  
													}
													var increment = user_max / view_max;
													radius = increment * count;
												}		
											}
											if(radius < user_min){radius = user_min};
											if(radius > user_max){radius = user_max};							
											return radius;
										 },
				get_label:  function(feature){
												var output = '';
												if(feature.cluster){
												output = getValue(feature.cluster[0].attributes, selected_attribute);
												if(feature.cluster.length > 1){ return output + " + " + (feature.cluster.length - 1) + " more..."; }else{ return output; }
												}else{						
												output = getValue(feature.attributes, selected_attribute);
												return output;	
												} 
										 },
	get_labelxoffset: function(feature){
											return dynamic_style_default.context.get_point_radius(feature) + 5;
										},
	
	}}
	);
	//Create a style object with context and property styles
	var dynamic_style_select = new OpenLayers.Style({
		'label': '',
		'pointRadius': '${point_radius}',
		'labelXOffset': '',	
	
	},
	//Second parameter contains a context parameter
	{context: {				
	point_radius: function(feature){				
									return dynamic_style_default.context.get_point_radius(feature) + 3;
								}
						}
	});

	//This broke??? why? map_setting no longer available...
	//console.log(layers[i].drupalID);
	//var styleMap = Drupal.openlayers.getStyleMap(map,layers[i].name);	
	var default_style = 0;//getValue(map_settings.layer_styles, layers[i].drupalID);
	var select_style = 0;//getValue(map_settings.layer_styles_select, layers[i].drupalID);
	//console.log(map);
/*
	var styleMap = Drupal.openlayers.getStyleMap(map,layers[i].name);	
	var default_style = styleMap.styles.default;
	var select_style = styleMap.styles.select;	
*/

	
	if (default_style == '0'){ 
		default_style = 'default'; 
	}
	if (select_style == '0'){ 
		select_style = 'select'; 
	}
	
	
	OpenLayers.Util.applyDefaults( dynamic_style_default.defaultStyle, layers[i].styleMap.styles[default_style].defaultStyle );
	OpenLayers.Util.applyDefaults( dynamic_style_select.defaultStyle, layers[i].styleMap.styles[select_style].defaultStyle );

	layers[i].styleMap.styles['default'] = dynamic_style_default;
	layers[i].styleMap.styles['select'] = dynamic_style_select;
}


});//end behavior
})(jQuery);
