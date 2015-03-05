(function($) {
/*
Implementation of Drupal behaviors
*/
Drupal.behaviors.core44_ol_pimp_behavior_popup = {
  'attach': function(context, settings) {
  var data = $(context).data('openlayers');

  //alert(settings.layers)
  if (data && data.map.behaviors.core44_ol_pimp_behavior_popup) {
	Drupal.OpenLayersPopups = {};
	Drupal.OpenLayersPopups.clustered_features =
	data.map.behaviors.core44_ol_pimp_behavior_popup.clusteredFeatures;    
	
	var map = data.openlayers;
	var options = data.map.behaviors.core44_ol_pimp_behavior_popup;  
	var vector_layers = [];
	for (var i in options.layers) {
	var layer = map.getLayersBy('drupalID', options.layers[i]);
	if (typeof layer[0] != 'undefined') {
		vector_layers.push(layer[0]);
	}
	}
	// If no layers were found, include all vector layers
	if (vector_layers.length == 0) {
		vector_layers = map.getLayersByClass('OpenLayers.Layer.Vector');
	}
	// Add control
	var control = new OpenLayers.Control.SelectFeature(
	  vector_layers,
	  {
	    activeByDefault: true,
	    highlightOnly: false,
	    multiple: false,
	    hover: false,
	    callbacks: {
	      'over': Drupal.core44_ol_pimp_popup.openTooltip,
	      'out': Drupal.core44_ol_pimp_popup.out,
	      'click': Drupal.core44_ol_pimp_popup.openPopup
	    }
	  }
	);
	data.openlayers.addControl(control);
	control.activate();
  }
  else if ($(context).is('.openlayers-popupbox')) {
    // Popup close
    $('a.popup-close', context).click(function() {
    //alert("click works");
      $(this).parents('.openlayers-popupbox').fadeOut('fast', function() { $(this).remove(); });
      return false;
    });

  }

}};//end behavior

/*
USE "openlayerPopup" theme to supply attributes from cluster
*/
Drupal.theme.openlayersPopup = function(feature) {

    var output = '';
    var visited = []; // to keep track of already-visited items
    for(var i = 0; i < feature.cluster.length; i++) {
		var pf = feature.cluster[i]; // pseudo-feature

	      if ( typeof pf.drupalFID != 'undefined' ) {
	        var mapwide_id = feature.layer.drupalID + pf.drupalFID;
	        if (mapwide_id in visited) continue;
	        visited[mapwide_id] = true;
	      }
	
		//Define first and last features
		//Output list of clusters features
		var current = i;
		var next = i+1;
			if(next == feature.cluster.length)			
			next = 0;
		//console.log(next);	
		var prev = i-1;
			if(prev == -1)
			 prev = feature.cluster.length -1;
		var count = i+1 + " of " + feature.cluster.length;
		
		var nextNID = feature.cluster[next].attributes.nid;
		var prevNID = feature.cluster[prev].attributes.nid;
		//alert(nextNID);

		//should  limit these to a max result incase of very large clusters. 	    
		if(i == 0)
		output += "<div class='popup-wrapper row-" + i + "'>";
		if(i > 0)	
		output += "<div class='popup-wrapper row-" + i + "' style='display: none;'>";
		if(i >= 0)
		output += "<h1 class='popup-title'>" + pf.attributes.name + "</h1>" + 
				  "<div class='popup-content'>" + pf.attributes.description + "</div>";
		if(feature.cluster.length > 1)		  
		output += "<div class='popup-pager-bar'><span class='popup-pager-count'>"+ count +"</span><div class='popup-pager-pager'><ul class='links popup-links'><li><a class='prev' href='#' onclick='prev("+ current +","+ prev +","+ prevNID +")'>Prev</a></li><li><a class='next' href='#next' onclick='next("+ current +","+ next +","+ nextNID +")'>Next</a></li></ul></div></div>";
		output +=  "</div>";
	}
    return output;	
};

/*
Generate list of NIDs within current cluster to pass to VBO edit locations
*/
Drupal.theme.openlayersLocationEdit = function(feature) {
  if(feature.cluster)
	{
		var output = '';
		for(var i = 0; i < feature.cluster.length; i++) {
	      var pf = feature.cluster[i]; // pseudo-feature
		  if(i == 0){
		  output += feature.cluster[i].attributes.nid;	
		  }else{
		  output += ","+ feature.cluster[i].attributes.nid;
		  }
		  //alert(clusterNIDs);
		}
	}else{
		var output = feature.attributes.nid;
	}
return output;
};

/*
Implementation of theme openlayers Tooltip
*/
Drupal.theme.openlayersTooltip = function(feature) {
  if(feature.cluster)
  {
    var output = '';
    var visited = []; // to keep track of already-visited items
    for(var i = 0; i < feature.cluster.length; i++) {
      var pf = feature.cluster[i]; // pseudo-feature
      if ( typeof pf.drupalFID != 'undefined' ) {
        var mapwide_id = feature.layer.drupalID + pf.drupalFID;
        if (mapwide_id in visited) continue;
        visited[mapwide_id] = true;
      }
    var includedFeatures = Drupal.OpenLayersPopups.clustered_features;
	//Define first and last features
	
	var rowID = i + 1;
	if (i == 0)
		rowID = 'first '+ (i + 1);
	if (i == (includedFeatures - 1) || (i + 1) == (feature.cluster.length))
		rowID = 'last last-'+ (i + 1);

	 //Output list of clusters features
     if (i < includedFeatures){
      output += '<div class="openlayers-popup openlayers-popup-feature ' + rowID + '">' +
      Drupal.theme.prototype.openlayersTooltip(pf) + '</div>';
    
    }else{
      output += '';   
    }
    }
    return output;
  }
  else
  {
    return Drupal.theme.prototype.openlayersTooltip(feature);
  }
};

/*
Implementation of theme openlayers Tooltip
*/
Drupal.theme.prototype.openlayersTooltip = function(feature) {
	var output = "<div class='openlayers-tooltip-name'>" + feature.attributes.name + "</div>"
	return output; 
};

/*
Remove Popups
*/
function remove_popups(feature){ 
	for (var i=0; i<feature.layer.map.popups.length; ++i){ 
        feature.layer.map.removePopup(feature.layer.map.popups[i]); 
    }
};
/*
Build the tooltip elements
*/
function createTooltip(feature){
  if(feature.cluster){
		var editLocationLink = "<a href='/divesites/location/edit/"+ Drupal.theme('openlayersLocationEdit', feature) +"' class='popups direct-edit'>edit</a>";
		var plural = '';
		  if(feature.cluster.length > 1)
		    plural = '<span>s</span>';
		  
		var plusFeaturesCount = '';
		  if(feature.cluster.length > Drupal.OpenLayersPopups.clustered_features)
		    plusFeaturesCount = "<div class='plus-features-wrapper'><div class='plus-features'> + " + (feature.cluster.length - Drupal.OpenLayersPopups.clustered_features) + " more</div></div>";
		    
	    var layerName = "<div class='layer-name " + feature.cluster[0].attributes.type + "'>" + feature.cluster[0].attributes.type_rendered + plural + "</div>";
		var featureCount = '';
		  if(feature.cluster.length > 1)
		  featureCount = "<div class='feature-count'>" + (feature.cluster.length) + "</div>";
	    
	    var clusterInfo = "<div class='cluster-info'>" + featureCount + layerName + editLocationLink + "</div>";
		var tooltipClick = Drupal.theme('openlayersTooltip', feature) + clusterInfo + plusFeaturesCount;	

	}else{
	    var layerName = "<div class='layer-name " + feature.attributes.type + "'>" + feature.attributes.type_rendered + "</div>";
    	var featureCount = '';
		var clusterInfo = "<div class='cluster-info'>" + featureCount + layerName + "</div>";
		var tooltipClick = Drupal.theme('openlayersTooltip', feature) + clusterInfo;		
	}
	return tooltipClick;
};
/*
Define popup functions
*/
Drupal.core44_ol_pimp_popup = {

  // Click state
  'openPopup': function(feature) {
  		
			remove_popups(feature);
		    feature.layer.map.removePopup(tooltip);
					
		    var context = $(feature.layer.map.div);

		    // Initialize popup
		    if (!$('.openlayers-popupbox', context).size()) {
		      context.prepend("<div class='openlayers-popupbox popup'></div>");
		      //context.prepend("<div class='openlayers-popupbox-tooltip popup-tooltip'></div>");
		    }
		    else {
		      $('.openlayers-popupbox:not(.popup)').addClass('popup');
		    }
		    // Hide the layer switcher if it's open.
		    for (var key in context.data('openlayers').openlayers.controls) {
		      if (context.data('openlayers').openlayers.controls[key].CLASS_NAME == "OpenLayers.Control.LayerSwitcherPlus") {
		        context.data('openlayers').openlayers.controls[key].minimizeControl();
		      }
		    }
		    
		  	if(feature.cluster){	
			   var text;
			   text = "<div id='popupclose'><a href='#close' class='popup-close'>X</a></div>";
			   text += Drupal.theme('openlayersPopup', feature);
	
			   $('.openlayers-popupbox', context).html(text).show();
			   Drupal.attachBehaviors($('.openlayers-popupbox', context));
			   
		  	}else{
			   var text;
			   text = "<div id='popupclose'><a href='#close' class='popup-close'>X</a></div>";
			   text += "<h1 class='popup-title'>" + feature.attributes.name + "</h1>";
			   text += "<div class='popup-content'>" + feature.attributes.description + "</div>";
	
			   $('.openlayers-popupbox', context).html(text).show();
			   Drupal.attachBehaviors($('.openlayers-popupbox', context));  
		  
			}
			//Pan the map to center the feature allowing for popup position
	  		var map = $("#map .openlayers-map").data('openlayers').openlayers;
	  		var point = feature.geometry;
			var lonlat = new OpenLayers.LonLat(point.x,point.y);
			var center_point_pixel = map.getPixelFromLonLat(lonlat);
			var newX = center_point_pixel.x +180;

			var pixX = newX;
			var pixY = center_point_pixel.y;
			var newLonLatPix = new OpenLayers.Pixel(pixX,pixY);
			var newCenter = map.getLonLatFromPixel(newLonLatPix);
			
			map.panTo(newCenter);
	   		getPopup(feature.cluster[0].attributes.nid);
   		
			var tooltipClick = "<div id='openlayers-extras-tooltip-click' class='openlayers-tooltip clustered'>" 
				 + createTooltip(feature) + 
				"<div class='openlayers-tooltip-tick clustered'></div></div>";
		      	//TOOLTIP POPUP CLICK
		   		popup = new OpenLayers.Popup(
		    			'popup',
		                   feature.geometry.getBounds().getCenterLonLat(),
		                   null,//new OpenLayers.Size(200,200),
						   tooltipClick,
		                   null,
		                   true);
		
		          // Assign popup to feature and map.
		          feature.popup = popup;
		          feature.layer.map.addPopup(popup);
		          popup.map = feature.layer.map;
		          //Drupal.openlayers.popup.selectedFeature = feature;
	
			var point  = new OpenLayers.LonLat(feature.geometry.x, feature.geometry.y);
			var position = feature.layer.getViewPortPxFromLonLat(point);
			var curr_tooltip = document.getElementById("openlayers-extras-tooltip-click");
			var curr_tooltip_width = (curr_tooltip.clientWidth);
			var curr_tooltip_height = (curr_tooltip.clientHeight);
			var curr_tooltip_width_half = (curr_tooltip_width / 2) + 0;
			var offsetX = 0 - curr_tooltip_width_half;
			var offsetY = 0-70;
			if (feature.attributes.radius > 1){
				offsetY = 0 - (feature.attributes.radius + (curr_tooltip_height + 15));
			};
			//alert(feature.attributes.radius);
			$('#openlayers-extras-tooltip-click').css({left: offsetX, top: offsetY});
			Drupal.attachBehaviors('#openlayers-extras-tooltip-click');

  },

  // Hover state
  'openTooltip': function(feature) {
		
		var tooltipHover = "<div id='openlayers-extras-tooltip-hover' class='openlayers-tooltip clustered'>" 
			 + createTooltip(feature) + 
			"<div class='openlayers-tooltip-tick clustered'></div></div>";	

      	//TOOLTIP POPUP HOVER
   		tooltip = new OpenLayers.Popup(
    			'popup',
                   feature.geometry.getBounds().getCenterLonLat(),
                   null,//new OpenLayers.Size(200,200),
				   tooltipHover,
                   null,
                   true);

          // Assign popup to feature and map.
          feature.tooltip = tooltip;
          feature.layer.map.addPopup(tooltip);
          tooltip.map = feature.layer.map;
        
        //Drupal.openlayers.popup.selectedFeature = feature;
		var point  = new OpenLayers.LonLat(feature.geometry.x, feature.geometry.y);
		var position = feature.layer.getViewPortPxFromLonLat(point);
		var curr_tooltip = document.getElementById("openlayers-extras-tooltip-hover");
		var curr_tooltip_width = (curr_tooltip.clientWidth);
		var curr_tooltip_height = (curr_tooltip.clientHeight);
		var curr_tooltip_width_half = (curr_tooltip_width / 2) + 0;
		var offsetX = 0 - curr_tooltip_width_half;
		var offsetY = 0-70;
		if (feature.attributes.radius > 1){
			offsetY = 0 - (feature.attributes.radius + (curr_tooltip_height + 15));
		};
		//alert(offsetY);
		//alert(feature.attributes.radius);
		//alert(curr_tooltip_width);
		$('#openlayers-extras-tooltip-hover').css({left: offsetX, top: offsetY});
		Drupal.attachBehaviors('#openlayers-extras-tooltip-hover');
  },

  // Callback for hover state
  // Only show tooltips on hover if the story popup is not open.
  'over': function(feature) {
		var context = $(feature.layer.map.div);
		if (!$('.openlayers-popupbox.popup', context).size()) {
		  if (feature.attributes.name) {
		    var text = "<div class='openlayers-popupbox'>";
		    text += "<h2 class='popup-title'>" + feature.attributes.name + "</h2>";
		    text += "<div class='popup-count'>" + parseInt(feature.attributes.count, 10) + "</div>";
		    text += "</div>";
		    context.prepend(text);
		  }
		}
  },

  // Call back for out state.
  'out': function(feature) {
    var context = $(feature.layer.map.div);
    $('.openlayers-popupbox:not(.popup)', context).fadeOut('fast', function() { $(this).remove(); });
    feature.layer.map.removePopup(tooltip);

  },
};
})(jQuery);

/////////////////* AJAX and pager *////////////////////////
//Popup Pager links, next prev functions
function next(a, b, c){
	jQuery(".popup-wrapper.row-"+ a).hide();
	jQuery(".popup-wrapper.row-"+ b).show();
	getPopup(c);
};
function prev(a, b, c){
	jQuery(".popup-wrapper.row-"+ a).hide();
	jQuery(".popup-wrapper.row-"+ b).show();
	getPopup(c);
};
/////////////////* AJAX POPUP CALLING *////////////////////////
function getPopup(nid){

	// This function will get exceuted after the ajax request is completed successfully
	var getPopupCallback = function(data) { 
		if(data !== 'undefined'){
			jQuery('#divesite-popup.divesite-popup-'+ nid).html(data.popupDiveSite);
			jQuery('#country-popup.country-popup-'+ nid).html(data.popupCountry);
			jQuery('#location-one-popup.location-one-popup-'+ nid).html(data.popupLocationOne);
		    Drupal.attachBehaviors('.popup-content');
		}else{
			getPopup(nid);
		}
	}
	//whats this??
	var total = 5,
        current  = 1,
        response = [];
    
    //function do_ajax() {    
		jQuery.ajax({
			type: 'POST',
			url: "/popup/get/" + nid,
			success: getPopupCallback, // These are the js functions that will be called upon success request
			dataType: 'json', //define the type of data that is going to get back from the server
			data: 'js=1' //Pass a key/value pair
		});
	//}
	//do_ajax();
};	