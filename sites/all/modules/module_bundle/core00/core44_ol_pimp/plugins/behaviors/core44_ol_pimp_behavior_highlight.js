(function($) {
/**
 * Implementation of Drupal behavior.
 */
Drupal.core44_ol_pimp = Drupal.core44_ol_pimp || {};

Drupal.core44_ol_pimp.highlight = OpenLayers.Class(OpenLayers.Control.SelectFeature,
{

  lastSelectCount: 1,
  getFeatureFromDrupalFID: function (drupalFID){
		var layers = this.layers || [this.layer];
		for (var i in layers) {
			for (var n in layers[i].features){
				if(layers[i].features[n].cluster){
					for (var v in layers[i].features[n].cluster){
						if(layers[i].features[n].cluster[v].drupalFID === drupalFID){
							//console.log(layers[i].features[n]);
								return layers[i].features[n];
						}	
					}
				}else{
						if(layers[i].features[n].drupalFID === drupalFID){
							//console.log(layers[i].features[n]);
								return layers[i].features[n];
						}	
				}	
			}
		};
	},
  /* Get an index of drupal fids contained in the given feature
   * (possibly clustered)
   */
  getDrupalFids: function(feature) {
    var fids = [];
    if ( ! feature.cluster ) {
      if ( feature.drupalFID != undefined ) {
        if ( ! fids[feature.drupalFID] ) {
          fids[feature.drupalFID] = 1;
        }
      }
    }
    else {
      for(var i = 0; i < feature.cluster.length; i++) {
        var pf = feature.cluster[i]; // pseudo-feature
        if ( pf.drupalFID != undefined ) {
          if ( ! fids[feature.drupalFID] ) {
            fids[pf.drupalFID] = 1;
          }
        }
      }
    }
    return fids;
  },
  centerPoint: function(feature) {
    var style = feature.style || feature.layer.style || "default";
    var layer = feature.layer;
    layer.drawFeature(feature, style);
  },
  // @param candidate A feature
  // @param fids An index of drupalFIDs numbers
  hasAnyFID: function(candidate, fids) {
    if ( ! candidate.cluster ) {
      return fids[candidate.drupalFID] !== undefined;
    } else {
      for(var i = 0; i < candidate.cluster.length; i++) {
        var pf = candidate.cluster[i]; // pseudo-feature
        if ( fids[pf.drupalFID] !== undefined ) return true;
      }
      return false;
    }
  },
  unhighlightAll: function() {
    var layers = this.layers || [this.layer];
    var layer, feature;
    for(var l=0; l<layers.length; ++l) {
      layer = layers[l];
      for(var i=layer.selectedFeatures.length-1; i>=0; --i) {
        feature = layer.selectedFeatures[i];
        if(feature.attributes.selected !== "SELECTED"){
        this.unhighlight(feature);
        }
      }
      //layer.selectedFeatures = [];
    }
  },
  //layerArg: include to run the function on passed layer
  clickUnhighlightAll: function(layerArg) {
    var layers = this.layers || [this.layer];
	  if(layerArg != null){
		  layers = layerArg;
	  }    
    var layer, feature;
    for(var l=0; l<layers.length; ++l) {
      layer = layers[l];
      for(var i=layer.selectedFeatures.length-1; i>=0; --i) {
        feature = layer.selectedFeatures[i];
        feature.attributes.selected = "";
        this.unhighlight(feature);
        if(layerArg != null){
        	this.lastSelect = null;
        	console.log(this.lastSelect);
        }
      }
      layer.selectedFeatures = [];
    }
  },
  unhighlight: function(feature) {
    var style = feature.style || feature.layer.style || "default";
    var layer = feature.layer;
    layer.drawFeature(feature, style);
  },
  highlight: function(feature) {
  //console.log(feature);
    var style = this.selectStyle || this.renderIntent;
    var layer = feature.layer;
    layer.drawFeature(feature, style);
    layer.selectedFeatures.push(feature);
  },
  clickHighlight: function(feature) {
    var style = "select";
    var layer = feature.layer;
    layer.drawFeature(feature, style);
    layer.selectedFeatures.push(feature);
  },
  highlightByFIDS: function(layer, fids) {
    for(var i = 0; i < layer.features.length; i++) {
      var candidate = layer.features[i];
      if ( this.hasAnyFID(candidate, fids) && candidate.attributes.selected !== "SELECTED") {
        this.highlight(candidate);
      }
    }
  },
   clickHighlightByFIDS: function(layer, fids) {
    for(var i = 0; i < layer.features.length; i++) {
      var candidate = layer.features[i];
      if ( this.hasAnyFID(candidate, fids) ) {
        this.clickHighlight(candidate);
        candidate.attributes.selected = "SELECTED";
//      alert(candidate.attributes.type);
      }
    }
  },
  clickUnHighlightByFIDS: function(layer, fids) {
    for(var i = 0; i < layer.features.length; i++) {
      var candidate = layer.features[i];
      if ( this.hasAnyFID(candidate, fids) ) {
        this.clickHighlight(candidate);
        candidate.attributes.selected = "";
//      alert(candidate.attributes.type);
      }
    }
  },
  highlightLike: function(sample) {
    var fids = this.getDrupalFids(sample);
    if ( fids.length == 0 ) {
      // No drupalFID, we'll highlight this
      // feature only.
      highlight(sample);
      return;
    }
    // TODO: optionally refuse to highlight 
    //       multi-fid clusters
    // if ( theOption && fids.length > 1 );
    var layer = sample.layer;
    this.highlightByFIDS(layer, fids);
    // Remember for next time
    layer.selectedFIDS = fids;
  },
  clickHighlightLike: function(sample) {
    var fids = this.getDrupalFids(sample);
    if ( fids.length == 0 ) {
      // No drupalFID, we'll highlight this
      // feature only.
      clickHighlight(sample);
      return;
    }
    // TODO: optionally refuse to highlight 
    //       multi-fid clusters
    // if ( theOption && fids.length > 1 );
    var layer = sample.layer;
    this.clickHighlightByFIDS(layer, fids);
    // Remember for next time
    layer.selectedFIDS = fids;
  },
  movestart: function() {
    this.unhighlightAll();
    this.handlers['feature'].deactivate();
  },
  moveend: function() {
    this.handlers['feature'].activate();
  },
  zoomend: function() {
  	//grab the previously selected feature, find its new vector and select

    if(Drupal.core44_ol_pimp.highlight.lastSelect != null){
  		Drupal.core44_ol_pimp.highlight.newSelect = this.getFeatureFromDrupalFID(Drupal.core44_ol_pimp.highlight.lastSelect);
    	if(Drupal.core44_ol_pimp.highlight.newSelect != null){
    		this.click(Drupal.core44_ol_pimp.highlight.newSelect);
    		Drupal.core44_ol_pimp.tooltip.click(Drupal.core44_ol_pimp.highlight.newSelect,1);
    	}
    }
  },  
  over: function(feature) {
    // workaround to http://drupal.org/node/955332
    //if ( typeof(feature.CLASS_NAME) !== 'string' ) return;
    this.highlightLike(feature);
  },
  out: function(feature) {
    // workaround to http://drupal.org/node/955332
    //if ( typeof(feature.CLASS_NAME) !== 'string' ) return;
    this.unhighlightAll();
  },
  click: function(feature) {
	  //Store the feature incase of zoom
	  //console.log(feature);
	  //here we should search the new cluster for the lastSelect drupalFID, and use that feature if it exists. If not, use first feature of new
	  var newLast, sameLast;
	  if(feature.cluster){
	   var newLast = feature.cluster[0].drupalFID;	
	   this.lastSelectCount = feature.cluster.length;	  
	   for(var i = 0; i < feature.cluster.length; i++) {
		   if(feature.cluster[i].drupalFID === this.lastSelect){
			   sameLast = feature.cluster[i].drupalFID;
		   }
	   }
	  }else{
	  	newLast = feature.drupalFID;
	  	this.lastSelectCount = 1;		  		  
	  }
	  if(sameLast != null){ Drupal.core44_ol_pimp.highlight.lastSelect = sameLast }
	  else{ Drupal.core44_ol_pimp.highlight.lastSelect = newLast }
/*
    var layers = this.layers || [this.layer];
		for (var i in layers) {
			if(layers[i].selectedFeatures.length > 0 && layers[i].selectedFeatures[0].tooltipClick != null){ 
				if(layers[i].selectedFeatures[0].cluster){
					this.lastSelect = layers[i].selectedFeatures[0].cluster[0].drupalFID;	
					console.log(this.lastSelect);					
				}else{
					this.lastSelect = layers[i].selectedFeatures[0].drupalFID;	
				}
			}
		}
*/ 
		// console.log(feature);
    // workaround to http://drupal.org/node/955332
    //if ( typeof(feature.CLASS_NAME) !== 'string' ) return;
    this.centerPoint(feature);
    this.clickUnhighlightAll();
    this.clickHighlightLike(feature);
  },

  deactivate: function () {
   this.map.events.unregister("movestart", this, this.movestart);
   this.map.events.unregister("moveend", this, this.moveend);
    OpenLayers.Control.SelectFeature.prototype.deactivate.apply(this,
      arguments);
  },

  activate: function () {
    OpenLayers.Control.SelectFeature.prototype.activate.apply(this,
      arguments);

    // For clusters re-computation
    this.map.events.register("movestart", this, this.movestart);
    this.map.events.register("moveend", this, this.moveend);
    this.map.events.register("zoomend", this, this.zoomend);

  },

  initialize: function(layers, options) {

      OpenLayers.Control.prototype.initialize.apply(this, [options]);

      if(this.scope === null) {
          this.scope = this;
      }

      this.initLayer(layers);

      var callbacks = {
          over: this.over,
          click: this.click,
          out: this.out
      }

      this.callbacks = OpenLayers.Util.extend(callbacks, this.callbacks);
      this.handlers = {
          feature: new OpenLayers.Handler.Feature(
              this, this.layer, this.callbacks,
              {geometryTypes: this.geometryTypes}
          )
      };

      // HACK: forward all events to next handler 
      this.handlers['feature'].stopClick = false;
      this.handlers['feature'].stopDown = false;
      this.handlers['feature'].stopUp = false;
      this.handlers['feature'].dblclick = function(evt) {
        return true;
      };
  },
  // We'll allow selection of multiple features
  multiple: true,
  CLASS_NAME: 'Drupal.core44_ol_pimp.highlight'
});

Drupal.core44_ol_pimp.highlight.lastSelect = null;
Drupal.core44_ol_pimp.highlight.newSelect = null;

Drupal.openlayers.addBehavior('core44_ol_pimp_behavior_highlight', function (data, options) {
  if ( ! data ) return;
  if ( ! data.map.behaviors['core44_ol_pimp_behavior_highlight'] ) return;
  var map = data.openlayers;

  var layers = [];
  for (var i in options.layers) {
    var selectedLayer = map.getLayersBy('drupalID', options.layers[i]);
    if (typeof selectedLayer[0] != 'undefined') {
      layers.push(selectedLayer[0]);
    }
  }
  // If no layers were found, include all vector layers
  if (layers.length == 0) {
    layers = map.getLayersByClass('OpenLayers.Layer.Vector');
  }

  var control = new Drupal.core44_ol_pimp.highlight(layers, {clickout: false});
  map.addControl(control);
  control.activate();

});

})(jQuery);