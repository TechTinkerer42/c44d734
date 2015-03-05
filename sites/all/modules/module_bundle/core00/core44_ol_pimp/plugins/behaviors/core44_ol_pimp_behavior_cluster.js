(function($) {
/**
 * Implementation of Drupal behavior.
 */
 

            
            
Drupal.openlayers.addBehavior('core44_ol_pimp_behavior_cluster', function (data, options) {
    
    //var totalPopups = data.map.behaviors.core44_ol_pimp_behavior_cluster.totalPopups;
        
    var map = data.openlayers;
    var distance = parseInt(options.distance, 10);
    var threshold = parseInt(options.threshold, 10);
    var layers = [];
    for (var i in options.clusterlayer) {
      var selectedLayer = map.getLayersBy('drupalID', options.clusterlayer[i]);
      if (typeof selectedLayer[0] != 'undefined') {
        layers.push(selectedLayer[0]);
      }
    }
    
    // Go through chosen layers
    for (var i in layers) {
      var layer = layers[i];
      // Ensure vector layer
      if (layer.CLASS_NAME == 'OpenLayers.Layer.Vector') {
        var cluster = new OpenLayers.Strategy.Cluster(options);
        layer.addOptions({ 'strategies': [cluster] }); 
        cluster.setLayer(layer);
        cluster.features = layer.features.slice();
        cluster.activate();
        cluster.cluster();
      }
    }
});

})(jQuery);