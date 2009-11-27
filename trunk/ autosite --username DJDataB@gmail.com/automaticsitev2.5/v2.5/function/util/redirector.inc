<?php
/**
* @author Lieven Roegiers
* @copyright 2007
* @CMS autosite
*/
	function redirect($url){
		if (!headers_sent()){
			//print('Location: http://'.$_SERVER['SERVER_NAME'].$url);
			header('Location: http://'.$_SERVER['SERVER_NAME'].$url);
		}else {
			die('Redirect Headers error to send <a href="http://'.$_SERVER['SERVER_NAME'].$url.'" >here the link</a>');
		}
	}
?>