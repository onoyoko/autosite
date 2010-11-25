<?php	
/**
 *IMPORTANT SECURITY 
 */
if (!headers_sent()){
			header('Location: http://'.$_SERVER['SERVER_NAME'].'/');
		}else {
			die('Redirect Headers error to send');
		}
?>