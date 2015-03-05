(function ($) {

/**
 * The recommended way for producing HTML markup through JavaScript is to write
 * theming functions. These are similiar to the theming functions that you might
 * know from 'phptemplate' (the default PHP templating engine used by most
 * Drupal themes including Omega). JavaScript theme functions accept arguments
 * and can be overriden by sub-themes.
 *
 * In most cases, there is no good reason to NOT wrap your markup producing
 * JavaScript in a theme function.
 */
 
// Drupal.theme.prototype.core44ExampleButton = function (path, title) {
//   // Create an anchor element with jQuery.
//   return $('<a href="' + path + '" title="' + title + '">' + title + '</a>');
// };

/**
 * Behaviors are Drupal's way of applying JavaScript to a page. The advantage
 * of behaviors over simIn short, the advantage of Behaviors over a simple
 * document.ready() lies in how it interacts with content loaded through Ajax.
 * Opposed to the 'document.ready()' event which is only fired once when the
 * page is initially loaded, behaviors get re-executed whenever something is
 * added to the page through Ajax.
 *
 * You can attach as many behaviors as you wish. In fact, instead of overloading
 * a single behavior with multiple, completely unrelated tasks you should create
 * a separate behavior for every separate task.
 *
 * In most cases, there is no good reason to NOT wrap your JavaScript code in a
 * behavior.
 *
 * @param context
 *   The context for which the behavior is being executed. This is either the
 *   full page or a piece of HTML that was just added through Ajax.
 * @param settings
 *   An array of settings (added through drupal_add_js()). Instead of accessing
 *   Drupal.settings directly you should use this because of potential
 *   modifications made by the Ajax callback that also produced 'context'.
 */
// Drupal.behaviors.core44ExampleBehavior = {
//   attach: function (context, settings) {
//     // By using the 'context' variable we make sure that our code only runs on
//     // the relevant HTML. Furthermore, by using jQuery.once() we make sure that
//     // we don't run the same piece of code for an HTML snippet that we already
//     // processed previously. By using .once('foo') all processed elements will
//     // get tagged with a 'foo-processed' class, causing all future invocations
//     // of this behavior to ignore them.
//     $('.some-selector', context).once('foo', function () {
//       // Now, we are invoking the previously declared theme function using two
//       // settings as arguments.
//       var $anchor = Drupal.theme('core44ExampleButton', settings.myExampleLinkPath, settings.myExampleLinkTitle);
// 
//       // The anchor is then appended to the current element.
//       $anchor.appendTo(this);
//     });
//   }
// };


/**
 * Theme function to create the overlay iframe element.
 */
Drupal.theme.prototype.overlayContainer = function () {
  return '<div id="overlay-container"><div class="overlay-modal-background"><div class="progress progress-striped active"><div class="progress-bar"  role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%"><span class="sr-only">45% Complete</span></div></div></div>';
};


/*******************************************************************************
 * GROWL MESSAGES
 ******************************************************************************/
 
//Tweak jquery UI selectors to style with bootstrap
Drupal.behaviors.core44JqueryTweaks = {
  attach: function (context, settings) {


	$('.ui-dialog-titlebar-close:not(.processed)')
	.addClass('processed')
	.each(function() {
  	$(this).addClass('close').prepend('&times;');
	});
	 
	 $(".ui-dialog-buttonset button:contains('Ok'):not(.processed)")
  	 .addClass('btn-primary processed');
  
  }
};


Drupal.behaviors.base00ToggleBlocks = {
  attach: function (context, settings) {
  
  //Adds functionality to toggle blocks and triggers
  $('html.js .toggle-trigger:not(.processed)')
  	.addClass('processed')
  	.click(function() {
      $(this).parent().siblings('.toggle-block').slideToggle('fast').toggleClass('active');
      $(this).toggleClass('active');
      return false;
  })
  //Click out close function for toggle blocks
  $('html.js').click(function() {
    $('.toggle-block.active').slideToggle('fast').removeClass('active');
    $('.toggle-trigger.active').removeClass('active');  
  });
  $('.toggle-block').click(function(event){
      event.stopPropagation();
  });

  }
};


Drupal.behaviors.contextualLinks = {
  attach: function (context) {
    $('div.contextual-links-wrapper', context).once('contextual-links', function () {
      var $wrapper = $(this);
      var $region = $wrapper.closest('.contextual-links-region');
      var $links = $wrapper.find('ul.contextual-links');
      var $trigger = $('<a class="contextual-links-trigger c44icon-" href="#" />').click(
        function () {
          $links.stop(true, true).slideToggle(100);
          $wrapper.toggleClass('contextual-links-active');
          return false;
        }
      );
      // Attach hover behavior to trigger and ul.contextual-links.
      $trigger.add($links).hover(
        function () { $region.addClass('contextual-links-region-active'); },
        function () { $region.removeClass('contextual-links-region-active'); }
      );
      // Hide the contextual links when user clicks a link or rolls out of the .contextual-links-region.
      $region.bind('mouseleave click', Drupal.contextualLinks.mouseleave);
      $region.hover(
        function() { $trigger.addClass('contextual-links-trigger-active'); },
        function() { $trigger.removeClass('contextual-links-trigger-active'); }
      );
      // Prepend the trigger.
      $wrapper.prepend($trigger);
    });
  }
};



/*
 //Tweak ACDX selectors to style with bootstrap
 Drupal.autocomplete_deluxe.MultipleWidget.Item = function (widget, item) {
   if (item.newTerm === true) {
     item.label = item.value;
   }
   this.value = item.value;
   this.element = $('<span class="btn btn-primary btn-small">' + item.label + '</span>');
   this.widget = widget;
   this.item = item;
   var self = this;
 
   var close = $('<span class="autocomplete-deluxe-item-delete glyphicon glyphicon-remove"></span>').appendTo(this.element);
   // Use single quotes because of the double quote encoded stuff.
   var input = $('<input type="hidden" value=\'' + this.value + '\'/>').appendTo(this.element);
 
   close.mousedown(function() {
     self.remove(item);
   });
 };
 Drupal.autocomplete_deluxe.MultipleWidget.Item.prototype.remove = function() {
   this.element.remove();
   var values = this.widget.valueForm.val();
   var escapedValue = Drupal.autocomplete_deluxe.escapeRegex( this.item.value );
   var regex = new RegExp('()*""' + escapedValue + '""|' + escapedValue + '()*', 'gi');
   this.widget.valueForm.val(values.replace(regex, ''));
   delete this.widget.items[this.value];
 };
*/




//Apply bootstrap file upload to file elements
Drupal.behaviors.core44UploadDisable = {
  attach: function (context, settings) {

	$('input:file:not(.processed)')
	.addClass('processed')
	.each(function() {
	  var uploadButton = $(this).closest('.fileupload.fileupload-new, .fileupload.fileupload-exists').siblings('button.upload');
	  uploadButton.addClass('disabled'); 
	  
  	$(this).change(function (){
      var fileName = $(this).val();
        if (fileName) {
          /* alert(fileName); */
          uploadButton.removeClass('disabled btn-dark').addClass('btn-success');
        } else {
          uploadButton.removeClass('btn-success').addClass('disabled btn-dark');
        }
    });
	 
  });
}}



//  //Auto resize media module popup window.
//  Drupal.behaviors.core44IframeAutoHeightB = {
//    attach: function (context, settings) {
//  
//    var iframe = $("iframe#mediaBrowser", window.parent.document);
//    var height = $("#media-browser-page-wrapper").height();
//    iframe.height(height + 15);  
//    
//    // Called once the Iframe's content is loaded.
//    iframe.load(function(){
//      // The Iframe's child page BODY element.
//      var iframe_content = iframe.contents().find('#media-browser-page-wrapper');
//  
//      // Bind the resize event. When the iframe's size changes, update its height as
//      // well as the corresponding info div.
//      iframe_content.resize(function(){
//        var elem = $(this);
//        
//        // Resize the IFrame.
//        iframe.animate({ height: elem.outerHeight( true ) });
//      });
//      
//      // Resize the Iframe and update the info div immediately.
//      iframe_content.resize();
//    });
//  
//  }};

//	//Apply bootstrap tooltips to elements
//	Drupal.behaviors.core44Tooltips = {
//	  attach: function (context, settings) {
//	  $('span[data-toggle=popover]:not(.processed)')
//		.addClass('processed')
//		.each(function() {
//	    $(this).popover({placement: 'right', trigger: 'click'});
//	  });
//	  $('body').on('click', function (e) {
//	    $('span[data-toggle=popover]').each(function () {
//	        if (!$(this).is(e.target) && $(this).has(e.target).length === 0 && $('.popover').has(e.target).length === 0) {
//	            $(this).popover('hide');
//	        }
//	    });
//	  });
//	  }
//	}


     
//  //Add functionality to the base00 admin toolbar dropdown
//  Drupal.behaviors.core44Toolbar = {
//    attach: function (context, settings) {
//    
//    var toolbar_state = false;
//    $('#viewless').hide();
//    
//    $('.toolbar-toggle:not(.processed)')
//    .addClass('processed')
//    .each(function() {
//      $(this).click(function() {
//      	$(this).toggleClass('active');
//        toolbar_state = !toolbar_state;
//        $.cookie('toolbar_open', toolbar_state);  
//        $('#viewmore').toggle();
//        $('#viewless').toggle();      
//        $('.toolbar-wrapper').slideToggle('fast');       
//    	});
//    }); 
//    
//    if($.cookie('toolbar_open') == 'null'){
//      $('.toolbar-wrapper').show();
//      $('.toolbar-toggle').addClass('active');
//      $('#viewless').show();
//      $('#viewmore').hide();
//    }else{
//      $('.toolbar-wrapper').hide();
//      $('#viewless').hide();
//      $('#viewmore').show();
//    }
//    
//  }};






 

})(jQuery);


