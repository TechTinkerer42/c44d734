(function($) {
/**
 * Implementation of Drupal behavior.
 */
Drupal.openlayers.addBehavior('core44_ol_pimp_behavior_tooltip', function (data, options) {
var map = data.openlayers;
Drupal.core44_ol_pimp.tooltip = {

  // Over callback
  'over': function(feature) {	
  var clusteredClass = '';
  if(feature.cluster){ clusteredClass = "clustered" };
		//console.log("over");
		if (feature.attributes.selected != 'SELECTED') {
			var tooltip_content = 	
			"<div id='openlayers-extras-tooltip-hover' class='openlayers-tooltip " + clusteredClass + "'>" 
			+ createTooltip(feature) + 
			"<div class='openlayers-tooltip-tick " + clusteredClass + "'><span class='caret'></span></div></div>";
					
			//TOOLTIP POPUP HOVER
			tooltipHover = new OpenLayers.Popup(
				'popup',
				feature.geometry.getBounds().getCenterLonLat(),
				null,//new OpenLayers.Size(200,200),
				tooltip_content,
				null,
				true
			);
			
			// Assign popup to feature and map.
			feature.tooltipHover = tooltipHover;
			feature.layer.map.addPopup(tooltipHover);
			tooltipHover.map = feature.layer.map;
			
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
			
			$('#openlayers-extras-tooltip-hover').css({left: offsetX, top: offsetY});
			Drupal.attachBehaviors('#openlayers-extras-tooltip-hover');
		}
  },
  
  
  // Click callback
  'click': function(feature,noPan) {	

	  var clusteredClass = '';
	  if(feature.cluster){ clusteredClass = "clustered" };
	  
	  //console.log(feature);
	  	$('.scroll-to.highlight').removeClass('highlight');
	  	var element = '.scroll-to.' + feature.cluster[0].attributes.nid;
	  	$('.scroll-to.' + feature.cluster[0].attributes.nid).addClass('highlight');
//  	  	if(  ){
  	  	$('.l-main').scrollTo(element,{
  //		    axis:, //Axes to be scrolled, 'x', 'y', 'xy' or 'yx'. 'xy' is the default.
  		    duration:1000, //Length of the animation, none (sync) by default.
  		    easing:'easeOutQuart', //Name of the easing equation.
  //		    margin:, //If true, target's border and margin are deducted.
  //		    offset:, //Number or hash {left: x, top:y }. This will be added to the final position(can be negative).
  //		    over:, //Add a fraction of the element's height/width (can also be negative).
  //		    queue:, //If true and both axes are scrolled, it will animate on one axis, and then on the other. Note that 'axis' being 'xy' or 'yx', concludes the order
  //		    onAfterFirst:, //If queing, a function to be called after scrolling the first axis.
  //		    onAfter: //A function to be called after the whole animation ended.	  	
  	  	});
//  	  	}

			remove_tooltips(feature);

			if (typeof tooltipClick != 'undefined'){
				feature.layer.map.removePopup(tooltipClick);	
			}
			if (typeof tooltipHover != 'undefined'){
				feature.layer.map.removePopup(tooltipHover);	
			}			
			
			var map = $("#map .openlayers-map").data('openlayers').openlayers;
			var center = new OpenLayers.LonLat(feature.geometry.x,feature.geometry.y);
			if(noPan != 1){
				//map.panTo(center);
			}
/*
			setTimeout(function(){
				zoomtocluster(feature);
			}, 3000);
*/
			
			//Tooltip contents
			var tooltip_content = 
			"<div id='openlayers-extras-tooltip-click' class='openlayers-tooltip " + clusteredClass + "'>" 
			+ createTooltip(feature) + 
			"<div class='openlayers-tooltip-tick " + clusteredClass + "'><span class='caret'></span></div></div>";
				 						
			//TOOLTIP POPUP HOVER
			tooltipClick = new OpenLayers.Popup(
				'popup',
				feature.geometry.getBounds().getCenterLonLat(),
				null,//new OpenLayers.Size(200,200),
				tooltip_content,
				null,
				true
			);

			//console.log(feature);
			// Assign popup to feature and map.
			feature.tooltipClick = tooltipClick;
			feature.layer.map.addPopup(tooltipClick);
			tooltipClick.map = feature.layer.map;
			
			
			//Define variables for position
			var point  = new OpenLayers.LonLat(feature.geometry.x, feature.geometry.y);
			var position = feature.layer.getViewPortPxFromLonLat(point);
			var curr_tooltip = document.getElementById("openlayers-extras-tooltip-click");
			var curr_tooltip_width = (curr_tooltip.clientWidth);
			var curr_tooltip_height = (curr_tooltip.clientHeight);
			var curr_tooltip_width_half = (curr_tooltip_width / 2) + 0;
			var offsetX = 0 - curr_tooltip_width_half;
			var offsetY = 0 - 70;
			
			//Radius may not be defined!!!!
			if (feature.attributes.radius > 1){
				offsetY = 0 - (feature.attributes.radius + (curr_tooltip_height + 15));
			};
			
			$('#openlayers-extras-tooltip-click').css({left: offsetX, top: offsetY});
			Drupal.attachBehaviors('#openlayers-extras-tooltip-click');
			//Drupal.core44_ol_pimp.Highlight.prototype.highlight(feature);
			//feature.renderIntent = "select";
			$('a.zoomToCluster').click(function(){
				remove_tooltips(feature);
				Drupal.core44_ol_pimp.highlight.lastSelect = null;
				Drupal.core44_ol_pimp.highlight.newSelect = null;
				zoomtocluster(feature);
			})
  },
  

  // Out callback
  'out': function(feature) {
		var context = $(feature.layer.map.div);
		if (typeof tooltipHover != 'undefined'){
			feature.layer.map.removePopup(tooltipHover);
		}
  },
    
  // Clickout callback
  'clickout': function(feature) {	
  },
  

};
Drupal.core44_ol_pimp.tooltip.clusteredFeatures = data.map.behaviors.core44_ol_pimp_behavior_tooltip.clusteredFeatures;

//Define selected layers
var layers = [];
for (var i in options.selectedlayers) {
  var selectedLayer = map.getLayersBy('drupalID', options.selectedlayers[i]);
  if (typeof selectedLayer[0] != 'undefined') {
    layers.push(selectedLayer[0]);
  }
};

// Add control
var tooltip_controller = new OpenLayers.Control.SelectFeature(
  layers,
  {
    activeByDefault: true,
    highlightOnly: false,
    multiple: false,
    hover: false,
    clickout: false,
    callbacks: {
      'click': Drupal.core44_ol_pimp.tooltip.click,
      'clickout': Drupal.core44_ol_pimp.tooltip.clickout,
      'out': Drupal.core44_ol_pimp.tooltip.out,
      'over': Drupal.core44_ol_pimp.tooltip.over,
     },
  }
);
map.addControl(tooltip_controller);
tooltip_controller.activate();
//console.log(tooltip_controller);

//duplicate from highlight behavior, needs to be shared.
/*
function getFeatureFromDrupalFID(drupalFID){
		for (var i in layers) {
			for (var n in layers[i].features){
				if(layers[i].features[n].cluster){
					for (var v in layers[i].features[n].cluster){
						if(layers[i].features[n].cluster[v].drupalFID == drupalFID){
							//console.log(layers[i].features[n]);
								return layers[i].features[n];
						}	
					}
				}else{
						if(layers[i].features[n].drupalFID == drupalFID){
							//console.log(layers[i].features[n]);
								return layers[i].features[n];
						}	
				}	
			}
		};
	};
*/

//REGISTER EVENTS
/*
map.events.register(
	"zoomend", 
	map, 
	function reselectFeatures(){ 
			var prevDFID = Drupal.core44_ol_pimp.Highlight.prototype.lastSelect;
			//console.log(prevDFID);
			if(prevDFID != null){
				var matchedFeature = getFeatureFromDrupalFID(prevDFID);
				//console.log(matchedFeature);
				if(matchedFeature != null){
					if(matchedFeature.cluster && matchedFeature.cluster.length != Drupal.core44_ol_pimp.Highlight.prototype.lastSelectCount){
						Drupal.core44_ol_pimp.Highlight.prototype.lastSelectCount = matchedFeature.cluster.length;
						setTimeout(function(){
						  //console.log("cluster and cluster size different");
							Drupal.core44_ol_pimp.tooltip.click(matchedFeature,1);
						}, 100);
					}else{ return; }					
				}
			}
	}
); 
*/


//change this to zoomstart when update to ol2.14
/*
map.events.register(
	"movestart", 
	map, 
	function getCurrentFid(){ 
		console.log(Drupal.core44_ol_pimp.Highlight.prototype.lastSelect);
		for (var i in layers) {
			if(layers[i].selectedFeatures.length > 0 && layers[i].selectedFeatures[0].tooltipClick != null){ 
				Drupal.core44_ol_pimp.tooltip.lastSelect = layers[i].selectedFeatures[0];
			}
		}
	}
); 
*/


});//end behavior

/*
Remove Tooltip helper function
*/
function remove_tooltips(feature){ 
	for (var i=0; i<feature.layer.map.popups.length; ++i){ 
        feature.layer.map.removePopup(feature.layer.map.popups[i]); 
    }
};
/*
Zoom to cluster
*/
function zoomtocluster(feature) {
	//console.log(feature);
	var map = feature.layer.map;
	if (typeof feature.cluster === 'undefined'){
		return;
	}
  if (feature.cluster.length > 1){
	  clusterpoints = [];
	  for(var i = 0; i<feature.cluster.length; i++){
	      clusterpoints.push(feature.cluster[i].geometry);
	  }
	  var linestring = new OpenLayers.Geometry.LineString(clusterpoints);
	  //map.zoomToExtent(linestring.getBounds());
  	
  	var bounds = linestring.getBounds();
	  var scaledBounds = bounds.scale(1.2)
	  map.zoomToExtent(scaledBounds);
  }
}




/*
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////TOOLTIPS
*/
/*
Generate list of contained NIDs within current cluster to pass to VBO edit locations
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
Custom drupal theme openlayersTooltip
*/
Drupal.theme.prototype.openlayersTooltip = function(feature) {
	var output = "<div class='openlayers-tooltip-name'>" + feature.attributes.name + "</div>"
	return output; 
};
/*
USE "openlayersTooltip" theme to supply attributes from cluster
*/
Drupal.theme.openlayersTooltip = function(feature) {
	if(feature.cluster){
		var output = '';
		var visited = []; // to keep track of already-visited items
		for(var i = 0; i < feature.cluster.length; i++) {
			var pf = feature.cluster[i]; // pseudo-feature
			if ( typeof pf.drupalFID != 'undefined' ) {
				var mapwide_id = feature.layer.drupalID + pf.drupalFID;
				if (mapwide_id in visited) continue;
				visited[mapwide_id] = true;
			}
			var includedFeatures = Drupal.core44_ol_pimp.tooltip.clusteredFeatures;
	
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
	}else{
		return Drupal.theme.prototype.openlayersTooltip(feature);
	}
};
/*
Tooltip Builder
*/
function createTooltip(feature){
  var zoomToClusterLink = '';
  if(feature.cluster){
		var editLocationLink = '';//"<div class='zoomToCluster'><a href='/divesites/location/edit/"+ Drupal.theme('openlayersLocationEdit', feature) +"' class='popups direct-edit'>edit</a></div>";
		if(feature.cluster.length > 1){
			var zoomToClusterLink = "<div class='zoomToCluster'><a class='zoomToCluster' href='#'>zoom</a></div>";
		}
			var plural = '';
			  if(feature.cluster.length > 1)
			    //fix plural countries here...
			    plural = '<span>s</span>';
		  
			var plusFeaturesCount = '';
			  if(feature.cluster.length > Drupal.core44_ol_pimp.tooltip.clusteredFeatures)
			    plusFeaturesCount = "<div class='plus-features-wrapper'><div class='plus-features'> + " + (feature.cluster.length - Drupal.core44_ol_pimp.tooltip.clusteredFeatures) + " more</div></div>";
		    
			var layerName = "<div class='layer-name " + feature.cluster[0].attributes.type + "'>" + feature.cluster[0].attributes.type + plural + "</div>";
			var featureCount = '';
				if(feature.cluster.length > 1)
				featureCount = "<div class='feature-count'>" + (feature.cluster.length) + "</div>";
			
			var clusterInfo = "<div class='cluster-info'>" + featureCount + layerName + zoomToClusterLink + editLocationLink + "</div>";
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
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////END ------->> TOOLTIPS
*/
 

})(jQuery);

