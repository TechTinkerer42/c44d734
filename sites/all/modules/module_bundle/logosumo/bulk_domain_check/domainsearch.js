var arrayStep 		= 0;
var arraySize 		= 0;
var freeDomains 	= 0
var arrayWords 	  = '';
var tld 		    	= '';


jQuery( document ).ready(function() {
    
});

function grabiFrameContent(){
	//var vocabLinks = jQuery("iFrame#vocab-links").contents();
	//console.log(vocabLinks);
}

function getDomains() {
	
/*
	//Get the selected TLDs
	jQuery('.form-checkbox:checked')
		.each(function() {
			tldArray = jQuery(this).parent().text();
			console.log( jQuery(this).parent().text() );
	});
*/
	
	// Get the URL.
	var strWords = jQuery('#edit-keywords').val();
	var prefix = jQuery('#edit-prefix').val();
	var suffix = jQuery('#edit-suffix').val();
	var path = "/" + Drupal.settings.bulk_domain_check.path;	 
	

	
		
	// Give the user some info about what's going on.
	jQuery('#status').html('Retrieving unique words from ' + strWords);
	
	// Make a request to our search-file to retrieve a list of words from the URL.
	jQuery.getJSON(path + '/search.php?action=getDomains&url=' + strWords, function(data) {
		// Redeclare some variables.
		arraySize = data.words.length-1;
		arrayWords = data.words;
		//add prefix and suffix if available
		if (prefix || suffix){
			var index;
			for (index = 0; index < arrayWords.length; ++index) {
			    arrayWords[index] = prefix + arrayWords[index] + suffix;
			}
		}
		// Begin checking the domains
		//console.log(arrayWords); //"accessibility", "links", "skip",
		checkDomain(arrayWords[arrayStep]);
	});
}

function checkDomain(domain) {
	var path = "/" + Drupal.settings.bulk_domain_check.path;	 
	
	// If we're done checking domains, we should let the user now that.
	if (arrayStep == arraySize) {
		jQuery('#status').html('Found a total of <strong>' + freeDomains + '</strong> available domain names.');
	}
	arrayStep++;

	// Make a request to check againsts each selected TLD
	jQuery('#tld .form-checkbox:checked')
	.each(function() {
	tld = jQuery.trim(jQuery(this).parent().text());					
		
		jQuery.get(path + '/search.php?action=checkDomain&domain=' + domain + tld, function(data) {
			if(data.length > 4) {
				// Output the domain name if we get a response.
				jQuery('#freeDomains tbody').prepend('<tr><td><h2>' + data + '</h2></td><td>Available</td></tr>');
				freeDomains++; 
			}
			// Give the user some info about what's going on.
			if (arrayStep <= arraySize) {
				jQuery('#status').html('Checking: ' + arrayWords[arrayStep] + tld + '<br />Progress: ' + ((arrayStep/arraySize)*100).toPrecision(3) + '%');
				//  Repeat until we've processed all the words.
				checkDomain(arrayWords[arrayStep]);
			}
		});
		
	});
	
	
		

}