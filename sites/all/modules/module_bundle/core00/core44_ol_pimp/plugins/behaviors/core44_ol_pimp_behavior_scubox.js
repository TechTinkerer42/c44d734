(function($) {
/**
 * Implementation of Drupal behavior.
 */
Drupal.openlayers.addBehavior('core44_ol_pimp_behavior_scubox', function (data, options) {
Drupal.OpenLayersScubox = {};
Drupal.OpenLayersScubox.currentWidth = '';

Drupal.OpenLayersScubox.setWidth = function(width){
	setMapWidth(width);
};
		var map = data.openlayers;
		var newWidth = 50;						
		    step01 = 0;
		    step02 = 50;
		    step03 = 70;
		    step04 = 100;	
		    showMap = "<div class='scuButton showMap'><a class='c44icon-' href='#'></a></div>";	
		    showInfo = "<div class='scuButton showInfo'><a class='c44icon-' href='#'></a></div>";	
		    panel = "<div class='toggleMap'>";
		    panel += "<div class='scuButton sml moreMap'><a class='c44icon-' href='#'></a></div>";
		    panel += "<div class='scuButton sml lessMap'><a class='c44icon-' href='#'></a></div>";
		    panel += "</div>";

		$( document ).ready(function(){
			updateMapSize();
	
		});
		//define the map size and element postions
		window.onresize = function(){
			updateMapSize();
		}
		$('#map').prepend(panel);
		$('body').prepend(showMap); 
		$('.showMap').hide();
		$('.showMap').click(function() { 
			$('.toggleMap  .lessMap').click();
  	})	
		$('#map').prepend(showInfo); 
		$('.showInfo').hide();
		$('.showInfo').click(function() { 
			$('.toggleMap  .moreMap').click();
  	})					

    $('.toggleMap  .moreMap').click(function() {
	    	//Get the map width as a percent of the body
	    	var mapWidth = 100 - ( 100 * parseFloat($('#map').css('left')) / parseFloat($(window).width()) );  		
	    	if(mapWidth == step01){ newWidth = step02 };
	    	if(mapWidth == step02){ newWidth = step03 };
	    	if(mapWidth == step03){ newWidth = step04 };
	    	if(mapWidth == step04){ newWidth = step03 };	    		    		    
	    	setMapWidth(newWidth);
  	});
    $('.toggleMap  .lessMap').click(function() {
	    	//Get the map width as a percent of the body
  			var mapWidth = 100 - ( 100 * parseFloat($('#map').css('left')) / parseFloat($(window).width()) );	    	
	    	if(mapWidth == step01){ newWidth = step02 };
	    	if(mapWidth == step02){ newWidth = step01 };
	    	if(mapWidth == step03){ newWidth = step02 };
	    	if(mapWidth == step04){ newWidth = step03 };	    		    		    	    
	    	setMapWidth(newWidth);
  	});
  	
  	function updateMapSize() {
	  	documentWidth = $(window).width();
			breadHeight = $('.navbar.top').height();
			titleHeight = $('.l-title.title-block').height();	
			mapHeight = $(window).height() - (titleHeight + breadHeight);	
			$('#openlayers-map').css({height: mapHeight});
			$('.showMap').css({top: titleHeight + breadHeight});			
			$('#map,#map #openlayers-map,#map #openlayers-container-openlayers-map').css({top: breadHeight + titleHeight});
			map.updateSize();
  	}
  	function setMapWidth(toWidth){
  			var mainWidthPre = $('.l-main').width();
  			var currentMapWidth = 100 - ( 100 * parseFloat($('#map').css('left')) / parseFloat($(window).width()) );
  			if(currentMapWidth == 0 && toWidth > currentMapWidth) { $('.showMap').hide(); $('.toggleMap').show(); }
  			if(currentMapWidth == 100 && toWidth < currentMapWidth) { $('.showInfo').hide(); $('.toggleMap').show(); }  			
  			if(toWidth == 100){ $('.showInfo').show(); $('.toggleMap').hide(); };
  			if(toWidth == 0){ $('.showMap').show(); $('.toggleMap').hide(); };
  			toWidth =  (100 - toWidth) + '%';
  			var center = map.getCachedCenter();
  			centerPx = map.getLayerPxFromLonLat(center);

	  		$('#map,#map #openlayers-map,#map #openlayers-container-openlayers-map').animate({left: toWidth}, 200, function() {}); 
		    $('.l-main').animate({width: toWidth}, 200, function() {}); 
		    
		    //pan map back to previous center and updateSize()
		    setTimeout(function(){
		    	var mainWidthPost = $('.l-main').width();
		    	if(mainWidthPost > mainWidthPre){ 
		    		//decrease width
		    		var diff = mainWidthPre - mainWidthPost;
		    		centerPx.x = centerPx.x - (diff/2);
		    	}else{ 
		    		//increase width		    	
		    		var diff = mainWidthPost - mainWidthPre;
		    		centerPx.x = centerPx.x + (diff/2);			    	
		    	};
		    	/* console.log(mainWidthPre); */
		    	/* console.log(mainWidthPost);		    	 */
			  	var newCenter = map.getLonLatFromLayerPx(centerPx);
			  	map.panTo(newCenter);
			  	setTimeout(function(){
			  		map.updateSize();
			  	}, 500);
		    }, 500);

  	}
  	}); 
})(jQuery);