(function($) {
/**
 * Implementation of Drupal behavior.
 */
Drupal.openlayers.addBehavior('core44_ol_pimp_behavior_zoomtolayer', function (data, options) {

  var map = data.openlayers;
  var layers = map.getLayersBy('drupalID', options.zoomtolayer);
  var layers_alt = map.getLayersBy('drupalID', options.zoomtolayer_alt);  
//console.log(layers);
//console.log(layers_alt);
  // Go through selected layers to get full extent.
  for (var i in layers) {
    if (layers[i].features !== undefined) {
      // For KML layers, we need to wait until layer is loaded.  Ideally
      // we could check for any layer that is loading from an external
      // source, but for now, just check KML
      if (layers[i].layer_handler == 'kml') {
        layers[i].events.register('loadend', layers[i], function() {
          layerextent = layers[i].getDataExtent();
          map.zoomToExtent(layerextent);
        });
      }
      else {
      	if(layers[i].features[0].geometry.CLASS_NAME == "OpenLayers.Geometry.Polygon"){
			//console.log("using first layer");
			layerextent = layers[i].getDataExtent();
			// Check for valid layer extent
			if (layerextent != null) {
				
				map.zoomToExtent(layerextent);
				// If unable to find width due to single point,
				// zoom in with point_zoom_level option.
				if (layerextent.getWidth() == 0.0) {
					map.zoomTo(options.point_zoom_level);
				}
			}
        }else{
			//console.log("using second layer");
			for (var i in layers_alt) {
				layerextent = layers_alt[i].getDataExtent();
				// Check for valid layer extent
				if (layerextent != null) {
					map.zoomToExtent(layerextent);
					
					// If unable to find width due to single point,
					// zoom in with point_zoom_level option.
					if (layerextent.getWidth() == 0.0) {
						map.zoomTo(options.point_zoom_level);
					}
				}
			}
        
        }
      }
    }
  }

});//end behavior
})(jQuery);