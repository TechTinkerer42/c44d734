<!DOCTYPE html>
<html>
	<head>
		<title>Bulk Domain Search</title>
		<style>
		body, input {
			font-family: verdana;
			font-size: 10px;
		}
		#status {
			margin: 10px 0 10px 0;
		}
		</style>		
	</head>
	<body>
		Enter PREFIX here: <input type="text" id="prefix">	
		Enter URL here: <input type="text" id="url">
		Enter SUFFIX here: <input type="text" id="suffix">
		<input type="button" value="Scan" onclick="getDomains();">
		<div id="status"></div>
		
		Availabile domain names:
		<div id="freeDomains"></div>
		
		<script src="domainsearch.js"></script>
		<script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
	</body>
</html>