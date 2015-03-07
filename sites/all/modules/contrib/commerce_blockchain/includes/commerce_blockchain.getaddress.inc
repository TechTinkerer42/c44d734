<?php

function commerce_blockchain_get_address($root_url , $parameters) {
$response = file_get_contents($root_url . '?' . $parameters);

return $response;

}
