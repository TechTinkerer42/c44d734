(function($) {
/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Navigation Behavior
 */
Drupal.openlayers.addBehavior('core44_ol_pimp_behavior_navigation', function (data, options) {
  var map = data.openlayers;
  var mapDiv = map.viewPortDiv;
  var controlHTML = '<div id="nav-panel">';
    	controlHTML += '<span id="customZoomIn" class="scuButton sml"><a class="zoomPlus c44icon-"></a></span>';
    	controlHTML += '<span id="customZoomOut" class="scuButton sml"><a class="zoomMinus c44icon-"></a></span>';
  		controlHTML += '</div>';
  
  $(mapDiv).prepend(controlHTML);
  
  options.documentDrag = !!options.documentDrag;
  
  //clear tooltips -  working but leaves vector highlighted.
/*
	function clearTooltips(){
		//console.log(map);
    var layers = [];
    for (var i in map.layers) {
      if (map.layers[i].CLASS_NAME === 'OpenLayers.Layer.Vector' && map.layers[i].selectedFeatures.length > 0){
        layers.push(map.layers[i]);
        //console.log(layers);
      }
    }
    for (var y in layers) {	
		  for (var n=0; n<layers[y].map.popups.length; ++n){ 
	        layers[y].map.removePopup(layers[y].map.popups[n]);
	        popupLayers = layers.push(map.layers[i]);
	        //Drupal.core44_ol_pimp.Highlight.prototype.lastSelect = null;
	        Drupal.core44_ol_pimp.Highlight.prototype.clickUnhighlightAll(layers);
	    }
    }	
	}
*/
	
  //pan to function with zoom callback
	function doubleClick(clickpoint, callback){
	    map.panTo(clickpoint);
	    if(typeof callback === "function") 
	    setTimeout(function(){ callback(); },1000);
	}

  //override default double click event with new function
  options.defaultDblClick = 
	  function(event) { 
	  	var lonlat = map.getLonLatFromViewPortPx(event.xy);
	  	doubleClick(lonlat, function(){ map.zoomIn(); });
	  	//clearTooltips();
	  }
  options.defaultClick = 
	  function(event) { 
	  	var lonlat = map.getLonLatFromViewPortPx(event.xy);
	  	map.panTo(lonlat);
	  }	  
	  
  var zoomControls = new OpenLayers.Control.Zoom({		
      zoomInId: "customZoomIn",
      zoomOutId: "customZoomOut",
  })	  
	  
	//add the control to the map  
  Drupal.openlayers.addControl(data.openlayers, 'Navigation', options);
  map.addControl(zoomControls);
  //zoomControls.activate();  

});

})(jQuery);