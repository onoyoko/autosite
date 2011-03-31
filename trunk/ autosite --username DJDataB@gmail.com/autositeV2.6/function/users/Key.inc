<?php
/**
 * @author Lieven Roegiers
 * @copyright 2007 refactor 2009
 * @CMS autosite
 * opensource http://code.google.com/p/autosite/
 */
if (!function_exists('Key')){//include_once its when it is include in the php lib
class Key{
     /**
	 * @param int $len
	 * @return
	 */
    private $string;
    private $tekens = "";
    public function __construct($len){
        $this->tekens .= 'abcdefghijklmnopqrstuvwxyz';
        $this->tekens .= 'ABCDEFGHIJKLMNOPQRSTUWXYZ';
        $this->tekens .= '01234567890123456789';
		  srand(((double) microtime() ) * 1000000 );
          $string = '';
		  
		  for( $i = 0; $i < $len; $i++ ){  
		  	$string .= $tekens{ rand( 0, ( strlen( $tekens ) - 1 ) ) };
		  }
		  return $string;
    }
}
}
?>