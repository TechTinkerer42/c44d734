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
//map.behaviors.core44_ol_pimp_behavior_popup.clustered_features = options.clusteredFeatures;

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


map.events.register(
"zoomend", 
map
); 



});//end behavior



/*
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////END ------->> TOOLTIPS
*/


/*
Define control callbacks
*/
Drupal.core44_ol_pimp_popup = {
  // Click callback
  'click': function(feature) {	
	  var id = feature.cluster[0].attributes.nid;
	  $("#main .l-main-inner").prepend("<div class='popup-content'></div><div class='popup-loader' style='display:none;'><h1>Loading...</h1></div>");
	  getPopup(id);
	  
  },
  // Clickout callback
  'clickout': function(feature) {	
	
  },
  // Out callback
  'out': function(feature) {

  },
  // Over callback
  'over': function(feature) {	

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
	
/*
	var after = function(data) { 
		if(data !== 'undefined'){
			jQuery('.popup-loader').remove();
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
*/
	
	var after = function(data) { 
			jQuery('.popup-loader').remove();
			jQuery("#main .l-main-inner .l-content").hide();
			jQuery("#main .l-main-inner .popup-content").prepend(data.popup_dive_site_01);
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