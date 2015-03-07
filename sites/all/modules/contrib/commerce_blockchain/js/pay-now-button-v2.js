(function($) {
  Drupal.behaviors.commerce_blockchain = {
    attach: function(context, settings) {
      settings.commerce_blockchain = settings.commerce_blockchain || Drupal.settings.commerce_blockchain;
      var root = "https://blockchain.info/";
      var remote_id = settings.commerce_blockchain['remote_id'];

			if(document.getElementById('edit-commerce-payment-payment-method-blockchaincommerce-payment-blockchain').checked) {
      	$('#edit-continue').addClass('disabled');
			}else{
				$('#edit-continue').removeClass('disabled');
			}

	    function checkBalance() {
	        $.ajax({
	            type: "GET",
	            url: root + 'q/getreceivedbyaddress/'+remote_id,
	            data : {format : 'plain'},
	            success: function(response) {
	                if (!response) return;
	
	                var value = parseInt(response);
	
	                if (value > 0) {
	                    alert('Payment Received');
	                    /*
button.find('.blockchain').hide();
	                    button.find('.stage-paid').trigger('show').show().html(button.find('.stage-paid').html().replace('[[value]]', value / 100000000));
*/
	                } else {
	                    setTimeout(checkBalance, 5000);
	                }
	            }
	        });
	    }
	    ///Check for incoming payment
	    setTimeout(checkBalance, 5000);
    }
  };
})(jQuery);

/*


$(document).ready(function() {});
*/