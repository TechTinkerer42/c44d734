function Application() {
}

Application.prototype.Validate = function() {
	var validAddress = false;
	$.ajax({
		async: false,
		url: "address.php",
		dataType: 'json',
	    data: { address: $('#address').val() }, 
	    success: function(data) { validAddress = data; }
	});
	
	if (!validAddress) {
		$('#address').closest('.input-group').addClass('has-error');
//		$('#address').closest('.pop').attr('data-content', 'Enter valid bitcoin address').popover('show');
	} else {
		$('#address').closest('.input-group').removeClass('has-error');
//		$('#address').closest('.pop').attr('data-content', '').popover('hide');
	}
	
	var validAmount = false;
	var amountReg = new RegExp("^[0-9]*([.][0-9]+)?$");
	var validAmount = amountReg.test($('#amount').val());
	if (!validAmount) {
		$('#amount').closest('.input-group').addClass('has-error');
//		$('#amount').closest('.pop').attr('data-content', 'Enter valid bitcoin amount').popover('show');
	} else {
		$('#amount').closest('.input-group').removeClass('has-error');
//		$('#amount').closest('.pop').attr('data-content', '').popover('hide');
	}
	
    return validAddress && validAmount;
    
}

Application.prototype.Click = function() {
	if (this.Validate()) {
		this.Generate($('#label').val(), $('#address').val(), $('#amount').val());
	}
}

Application.prototype.Clear = function() {
	$('#label').val('');
	$('#address').val('');
	$('#amount').val('');
	$('#qr1, #qr2, #qr3, #qr4').attr('src', 'data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7');
	$('#amount').closest('.input-group').removeClass('has-error');
	$('#address').closest('.input-group').removeClass('has-error');
//	$('.pop').popover('hide');
}

Application.prototype.Donate = function() {
	$('#label').val('Donation');
	$('#address').val('1KaSZ1XzvvYPjWAKfkiY3M2MiQx214SJVK');
	$('#amount').val('0.001');
	$('#amount').closest('.input-group').removeClass('has-error');
	$('#address').closest('.input-group').removeClass('has-error');
//	$('.pop').popover('hide');
	
	this.Generate($('#label').val(), $('#address').val(), $('#amount').val());
}

Application.prototype.Generate = function(label, address, amount) {
	var btc = escape('bitcoin:'+address+'?');
	if (amount) btc = btc + escape('amount='+amount+'&');
	if (label) btc = btc + escape('label='+label+'&');
	$('#qr1').attr('src', 'qr.php?size=4&info='+btc+'&'+Math.random());
	$('#qr2').attr('src', 'qr.php?size=3&info='+btc+'&'+Math.random());
	$('#qr3').attr('src', 'qr.php?size=2&info='+btc+'&'+Math.random());
	$('#qr4').attr('src', 'qr.php?size=1&info='+btc+'&'+Math.random());
}

Application.prototype.Run = function() {
//	$('.pop').popover({trigger: 'manual', container: 'body'});
//	$('.qrimage, #generate, #donate, #clear').on('mouseover', function() { $(this).popover('show'); }).on('mouseout', function() { $(this).popover('hide'); })

	$('#generate').on('click', $.proxy(this.Click, this));
	$('#donate').on('click', $.proxy(this.Donate, this));
	$('#clear').on('click', $.proxy(this.Clear, this));

	//
}

$(function() {
	var app = new Application();
	app.Run();
});
