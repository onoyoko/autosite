<?php
class Trace{
    function Trace(){
		session_start();
	}
    
    function gethoax(){
        return '<script type="text/javascript">alert("Your IP address is "+ip);'+
        'window.defaultStatus = "Your IP address is "+ip;'+
        'document.write("<title>Your IP address is "+ip+"</title>");</script>';
    }
}
?>
