<?php
	function ishash($type,$tohach,$code){
	switch ($type):
		case "md5":
			return(md5($tohach)=== $code);
        	break;
		case "sha1":
			return(sha1($tohach) === $code);
    		break;
		case "Base64.encode":
			return(base64_encode($tohach) === $code);
    		break;
     	default :
	    	return($tohach === $code);
		endswitch;
	}
	function funrandencript(){
		$i = 0;//TODO rand (0, 1) ;
		switch ($i):
		    case 0:return "md5";
		        break;
		    case 1:return "sha1";
		        break;
		    case 2:return "Base64.encode";
		        break;
		    default:
		        print "i is niet gelijk aan 0, 1 of 2";
		endswitch;
	}
?>