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
for (var i in Drupal.settings.openlayers.maps){
	if(Drupal.settings.openlayers.maps[i].id == map.div.id){
		var map_settings = Drupal.settings.openlayers.maps[i];
	}
}



//function updateStyle(layer) {
//	var dStyle_id = getValue(map_settings.layer_styles, layer.drupalID);
//	var sStyle_id = getValue(map_settings.layer_styles_select, layer.drupalID);
//	if (dStyle_id == '0'){ 
//		dStyle_id = 'default'; 
//	}
//	if (sStyle_id == '0'){ 
//		sStyle_id = 'select'; 
//	}
//	var new_default = dynamic_style_default;
//	var new_select = dynamic_style_select;
//	
//	OpenLayers.Util.applyDefaults( new_default.defaultStyle, layer.styleMap.styles[dStyle_id].defaultStyle );
//	OpenLayers.Util.applyDefaults( new_select.defaultStyle, layer.styleMap.styles[sStyle_id].defaultStyle );
//	//var updatedStyleMap = new OpenLayers.StyleMap({ 'default': new_default, 'select': new_select });
//	return new_default;
//};



//Build the stye map
//var updatedStyleMap = new OpenLayers.StyleMap({ 
//	'default': dynamic_style_default, 
//	//'select': new_select 
//});

//OpenLayers.Util.applyDefaults( updatedStyleMap, layers[0].styleMap );

for(var i in layers){
	
	//Create a style object with context and property styles
	var dynamic_style_default = new OpenLayers.Style({
		'label': '${get_label}',
		'labelAlign': 'l',		
		'pointRadius': '${get_point_radius}',
		'labelXOffset': '${get_labelxoffset}'
	},
	//Second parameter contains a context parameter
	{context: {			
	get_point_radius:function(feature){
							///alert(options.max_field);
							var count = 0;
							var user_max = parseInt(options.point_radius_max);	
							var user_min = parseInt(options.point_radius_min);
							var radius = user_min;
							
							if(options.field == '' || options.max_field == '' || options.features_only == 1){
							//alert('1');
								if(feature.cluster && options.features_only == 1){
									//alert('2');
									radius = user_min + (feature.cluster.length * 3);//should have a feature weight field for this
							    }
							}else{
								//alert('3');
								if(feature.cluster){
									for (var i = 0; i < feature.cluster.length; i++) {
										var countFieldValue = parseInt(getValue(feature.cluster[i].attributes, options.field));	
										var view_max = parseInt(getValue(feature.cluster[0].attributes, options.max_field));
									    count += countFieldValue;  
									}
									var increment = user_max / view_max;
									radius = increment * count;
								//alert('4');
								}		
							}
							if(radius < user_min){radius = user_min};
							if(radius > user_max){radius = user_max};							
							return radius;
						},
	get_label: function(feature){
						var output = '';
						if(feature.cluster){
							output = getValue(feature.cluster[0].attributes, selected_attribute);
							if(feature.cluster.length > 1){
								return output + " + " + (feature.cluster.length - 1) + " more...";
							}else{
								return output;
							}
						}else{						
							output = feature.attributes.selected_attribute;
							return output;	
						} 
					},
	get_labelxoffset: function(feature){
							///alert(options.max_field);
							var count = 0;
							var user_max = parseInt(options.point_radius_max);	
							var user_min = parseInt(options.point_radius_min);
							var radius = user_min;
							
							if(options.field == '' || options.max_field == '' || options.features_only == 1){
							//alert('1');
								if(feature.cluster && options.features_only == 1){
									//alert('2');
									radius = user_min + (feature.cluster.length * 3);//should have a feature weight field for this
							    }
							}else{
								//alert('3');
								if(feature.cluster){
									for (var i = 0; i < feature.cluster.length; i++) {
										var countFieldValue = parseInt(getValue(feature.cluster[i].attributes, options.field));	
										var view_max = parseInt(getValue(feature.cluster[0].attributes, options.max_field));
									    count += countFieldValue;  
									}
									var increment = user_max / view_max;
									radius = increment * count;
								//alert('4');
								}		
							}
							if(radius < user_min){radius = user_min};
							if(radius > user_max){radius = user_max};							
							return radius + 5;
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
	point_radius: 	function(feature){
							///alert(options.max_field);
							var count = 0;
							var user_max = parseInt(options.point_radius_max);	
							var user_min = parseInt(options.point_radius_min);
							var radius = user_min;
							
							if(options.field == '' || options.max_field == '' || options.features_only == 1){
							//alert('1');
								if(feature.cluster && options.features_only == 1){
									//alert('2');
									radius = user_min + (feature.cluster.length * 3);//should have a feature weight field for this
							    }
							}else{
								//alert('3');
								if(feature.cluster){
									for (var i = 0; i < feature.cluster.length; i++) {
										var countFieldValue = parseInt(getValue(feature.cluster[i].attributes, options.field));	
										var view_max = parseInt(getValue(feature.cluster[0].attributes, options.max_field));
									    count += countFieldValue;  
									}
									var increment = user_max / view_max;
									radius = increment * count;
								//alert('4');
								}		
							}
							if(radius < user_min){radius = user_min};
							if(radius > user_max){radius = user_max};							
							return radius + 3;
						},
	
	}}
	);
	//var dStyle_id = getValue(map_settings.layer_styles, layers[i].drupalID);
	//console.log(layers[i].styleMap.styles[dStyle_id]);
	
	OpenLayers.Util.applyDefaults( dynamic_style_default.defaultStyle, layers[i].styleMap.styles[getValue(map_settings.layer_styles, layers[i].drupalID)].defaultStyle );
	OpenLayers.Util.applyDefaults( dynamic_style_select.defaultStyle, layers[i].styleMap.styles[getValue(map_settings.layer_styles_select, layers[i].drupalID)].defaultStyle );
	//console.log(dynamic_style_default);
	

//	//Create new stylemap using updated style
//	var updated_styleMap = new OpenLayers.StyleMap({ 
//		'default': dynamic_style_default, 
//	});
//	
//	OpenLayers.Util.applyDefaults(updated_styleMap, layers[i].styleMap);
	
	layers[i].styleMap.styles['default'] = dynamic_style_default;
	layers[i].styleMap.styles['select'] = dynamic_style_select;
	//console.log(layers[i].styleMap.styles[getValue(map_settings.layer_styles, layers[i].drupalID)]);
	//layers[i].redraw(layers[i]);	
}


});//end behavior
})(jQuery);











//	// Go through selected layers
//	for (var i in layers) {
//		var layer = layers[i];
//		
//		// Ensure vector layer
//		if (layer.CLASS_NAME == 'OpenLayers.Layer.Vector') {
//	
//			var dStyle_id = getValue(map_settings.layer_styles, layers[i].drupalID);
//			var sStyle_id = getValue(map_settings.layer_styles_select, layers[i].drupalID);
//			
//			if (dStyle_id == '0'){ 
//				dStyle_id = 'default'; 
//			}
//			if (sStyle_id == '0'){ 
//				sStyle_id = 'select'; 
//			}
//	//		layers[i].style_ids = {};
//	//		layers[i].style_ids.dStyle = dStyle_id;
//	//		layers[i].style_ids.sStyle = sStyle_id;
//	
//			
//	//		var dStyle_style = layers[i].styleMap.styles[layers[i].style_ids.dStyle];
//	//		var sStyle_style = layers[i].styleMap.styles[layers[i].style_ids.sStyle];
//	
//	//		if (dStyle !== 'undefined'){ 
//	//			dStyle = layers[i].styleMap.styles.default; 
//	//		}
//	
//	//		var sStyle = layers[i].styleMap.styles[sStyle_id];	
//	//		if (sStyle !== 'undefined'){ sStyle = layers[i].styleMap.styles.select; }			
//			
//			
//			//layers[i].custom_styles = {};
//			OpenLayers.Util.applyDefaults( dynamic_style_default.defaultStyle, layers[i].styleMap.styles[dStyle_id].defaultStyle );
//			//OpenLayers.Util.applyDefaults( dynamic_style_select.defaultStyle, layers[i].styleMap.styles['Locations_01_SELECT'].defaultStyle );
//	//		
//	//		
//	//		console.log(layer);
//	//		console.log(dynamic_style_default);
//	//		console.log(dynamic_style_select);
//			
//			
//			//layer.styleMap = new OpenLayers.StyleMap({  });
//			//0 = no style selected in openlayers module and openlayers API default is being used
//			
//			
//			
//			//Merge user selected style with updated dynamic version
//			
//			//OpenLayers.Util.applyDefaults( dynamic_style_default.defaultStyle, layer.styleMap.styles.default.defaultStyle );
//			//OpenLayers.Util.applyDefaults( dynamic_style_select.defaultStyle, layer.styleMap.styles.select.defaultStyle );
//			
//			//applying the same style to both layers?? isDefault in styleMap.styles..(use to get the current default style for a layer)
//			//map.layer_styles.<layer name>	contains current chosen layer styles		
//			
//			
//			//Create new stylemap using updated style
//			var vector_layer = new OpenLayers.StyleMap({ 
//				'Dives_Sites_01': dynamic_style_default, 
//				//'Locations_01_SELECT': dynamic_style_select 
//			});
//			
//			//Insert updated style into current stylemap
//			//layers[1].styleMap = vector_layer;
//			//console.log(layers[i]);
//			//layers[i].redraw();
//			layers[1].styleMap = vector_layer;
//			console.log(layers[1].styleMap);	
//			
//		}
//	}