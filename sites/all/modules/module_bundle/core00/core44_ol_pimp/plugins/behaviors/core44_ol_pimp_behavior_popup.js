(function($) {
/**
 * Implementation of Drupal behavior.
 */
Drupal.openlayers.addBehavior('core44_ol_pimp_behavior_popup', function (data, options) {
var map = data.openlayers;
Drupal.OpenLayersPopups = {};
Drupal.OpenLayersPopups.clustered_features =
data.map.behaviors.core44_ol_pimp_behavior_popup.clusteredFeatures; 
Drupal.OpenLayersPopups.tooltipOnly =
data.map.behaviors.core44_ol_pimp_behavior_popup.tooltipOnly;  

//Define selected layers
var layers = [];
for (var i in options.selectedlayers) {
  var selectedLayer = map.getLayersBy('drupalID', options.selectedlayers[i]);
  if (typeof selectedLayer[0] != 'undefined') {
    layers.push(selectedLayer[0]);
  }
};

// Add control
var popup_controller = new OpenLayers.Control.SelectFeature(
  layers,
  {
    activeByDefault: true,
    highlightOnly: false,
    multiple: false,
    hover: false,
    clickout: false,
    callbacks: {
      'click': Drupal.core44_ol_pimp_popup.click,
      'clickout': Drupal.core44_ol_pimp_popup.clickout,
      'out': Drupal.core44_ol_pimp_popup.out,
      'over': Drupal.core44_ol_pimp_popup.over,
     },
  }
);
map.addControl(popup_controller);
popup_controller.activate();
//console.log(popup_controller);

map.events.register(
"zoomend", 
map, 
function remove_all_popups(){ 
/*
	for (var i=0; i<map.popups.length; ++i){ 
        map.removePopup(map.popups[i]); 
    }
    $('.openlayers-popupbox').fadeOut('fast', function() { $(this).remove(); });
*/
}
); 



});//end behavior


/*
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////POPUPS
*/
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
			//output += "<h1 class='popup-title'>" + pf.attributes.name + "</h1>" + 
			output += "" + //return title by deleting this line and uncomment above	
					  "<div class='popup-content'>" + pf.attributes.description + "</div><div class='popup-loader' style='display:none;'><h1>Loading...</h1></div>";
		if(feature.cluster.length > 1)		  
		output += "<div class='popup-pager-bar'><span class='popup-pager-count'>"+ count +"</span><div class='popup-pager-pager'><ul class='links popup-links'><li><a class='prev' href='#' onclick='prev("+ current +","+ prev +","+ prevNID +")'>Prev</a></li><li><a class='next' href='#next' onclick='next("+ current +","+ next +","+ nextNID +")'>Next</a></li></ul></div></div>";
		output +=  "</div>";
	}

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
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////END ------->> POPUPS
*/
/*

Define control callbacks
*/
Drupal.core44_ol_pimp_popup = {
  // Click callback
  'click': function(feature) {	
		//remove_popups(feature);

		//Drupal.OpenLayersScubox.setWidth(70);

		var context = $(feature.layer.map.div);
		
		// Initialize popup

			if (!$('.openlayers-popupbox', context).size()) {
			  context.prepend("<div class='openlayers-popupbox popup'></div>");
			}else{
			  $('.openlayers-popupbox:not(.popup)').addClass('popup');
			}

		// Hide the layer switcher if it's open.
		for (var key in context.data('openlayers').openlayers.controls) {
		  if (context.data('openlayers').openlayers.controls[key].CLASS_NAME == "OpenLayers.Control.LayerSwitcherPlus") {
		    context.data('openlayers').openlayers.controls[key].minimizeControl();
		  }
		}
		//Build popup
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
		var docWidth = Math.max(document.documentElement["clientWidth"], document.body["scrollWidth"]);
		var pageWidth = document.getElementById("main").offsetWidth;
		var visMapWidth = docWidth - pageWidth;
		var map = $("#map .openlayers-map").data('openlayers').openlayers;
		var point = feature.geometry;
		var lonlat = new OpenLayers.LonLat(point.x,point.y);
		var center_point_pixel = map.getPixelFromLonLat(lonlat);
		var newX = center_point_pixel.x /* - (docWidth / 2) + (visMapWidth / 2) */;
		var pixX = newX;
		var pixY = center_point_pixel.y;
		var newLonLatPix = new OpenLayers.Pixel(pixX,pixY);
		var newCenter = map.getLonLatFromPixel(newLonLatPix);
		
		map.panTo(newCenter);
		getPopup(feature.cluster[0].attributes.nid);
		
		jQuery('a.popup-close').click(function() {
			//alert("click works");
			$(this).parents('.openlayers-popupbox').fadeOut('fast', function() { $(this).remove(); });
			//Drupal.OpenLayersScubox.setWidth(50);
			return false;
		});
  },
  // Clickout callback
  'clickout': function(feature) {	
		//console.log("clickout");
  },
  // Out callback
  'out': function(feature) {
		var context = $(feature.layer.map.div);
		$('.openlayers-popupbox:not(.popup)', context).fadeOut('fast', function() { $(this).remove(); });

  },
  // Over callback
  'over': function(feature) {	
		//console.log("over");

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
	//jQuery('.popup-loader').show();
	//jQuery('#popup-loader').show();
	//This function will get exceuted after the ajax request is completed successfully
	
	var before = function() { 
			jQuery(".view-ajax-popups").remove();
    		jQuery('.popup-loader').show();
    };
	
	var after = function(data) { 
		if(data !== 'undefined'){
			jQuery('.popup-loader').hide();
			jQuery('#continent-popup.continent-popup-'+ nid).html(data.popup_continent_01);				
			jQuery('#country-popup.country-popup-'+ nid).html(data.popup_country_01);					
			jQuery('#region-popup.region-popup-'+ nid).html(data.popup_region_01);
			jQuery('#location-popup.location-popup-'+ nid).html(data.popup_location_01);
			jQuery('#dive-site-popup.dive-site-popup-'+ nid).html(data.popup_dive_site_01);
			jQuery('#dive-school-popup.dive-school-popup-'+ nid).html(data.popup_dive_school_01);						
			jQuery('#liveaboard-popup.liveaboard-popup-'+ nid).html(data.popup_liveaboard_01);
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
		beforeSend: before,
		success: after, // These are the js functions that will be called upon success request
		dataType: 'json', //define the type of data that is going to get back from the server
		data: 'js=1' //Pass a key/value pair
	});
	//}
	//do_ajax();
};