(function($) {
/**
 * Implementation of Drupal behavior.
 */
Drupal.openlayers.addBehavior('core44_ol_pimp_behavior_affix', function (data, options) {
var map = data.openlayers;


//Define selected layers
var layers = [];
for (var i in options.selectedlayers) {
  var selectedLayer = map.getLayersBy('drupalID', options.selectedlayers[i]);
  if (typeof selectedLayer[0] != 'undefined') {
    layers.push(selectedLayer[0]);
  }
};

//console.log(layers);
// Add control
var affix_controller = new OpenLayers.Control.SelectFeature(layers, {
              hover: false,
              highlightOnly: true,
              renderIntent: "temporary",
/*
              eventListeners: {                      
                  featurehighlighted: make_popup,
                  featureunhighlighted: kill_popup
              }
*/
          });


map.addControl(affix_controller);
affix_controller.activate();
//console.log(popup_controller);
	
});//end behavior


})(jQuery);