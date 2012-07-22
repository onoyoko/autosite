<?php
function customHandler($string, $file, $line, $context){
	$error_email = "info@djdb.be";
	$error = "Error on the site.\n";
	$error .= "Time: ".strftime("%d/%m/%y %H:%M", time())."\n";
	$error .= "\n";
	$error .= "Error: \"{$string}\" (error #{$number}).\n";
	$error .= backTrace($context);
	$br = new Browser;
	$error .= "\n\n";
	$error .= "Browser: $br->Platform, $br->Name version $br->Version".'\n';
	$error .= "IP: {$_SERVER['REMOTE_ADDR']}\n";
	$error .= "Host: ".gethostbyaddr($_SERVER['REMOTE_ADDR'])."\n";
	$error .= "\n";
	$error .= "Server name: {$_SERVER["SERVER_NAME"]}\n";
	$error .= "Server software: {$_SERVER["SERVER_SOFTWARE"]}\n";
	$error .= "\n";
	$error .= "URL: {$_SERVER["SCRIPT_NAME"]}\n";
	$error .= "Header: {$_SERVER["HTTP_ACCEPT"]}\n";
	$error .= "Referer: {$_SERVER["HTTP_REFERER"]}\n";
	$error .= "\n";
	$error .= "SQL says: ".mysql_error()."\n";
	$error .= "Query string: {$_SERVER["QUERY_STRING"]}\n";
	print str_replace("\n", '<br />', $error);
	if($stop) die();
}
function backTrace($context){
	$trace = debug_backtrace();
	$calls = "\nBacktrace:";
	for($i=2; $i<count($trace); $i++){
		$callNo = $i - 2;
		$calls .= "\n {$callNo}: {$trace[$i]['function']} ";
		$calls .= "(line {$trace[$i]['line']} in file {$trace[$i]['file']} ";
	}
    $calls .= "\n\nVariables in {$trace[2]['function']}():";
		foreach($context as $name => $value){
		if(!empty($value)){
			$calls .= "\n {$name} is {$value}";
		} else {
			$calls .= "\n {$name} is NULL";
		}
	}
	return $calls;
}	
?>