<?php
class User_data{
	 /**
	 * @author Lieven Roegiers
	 * @copyright 2007
	 * @CMS autosite
	 */
	private $encripty;
	private $kkey;
	public function __construct($username,$kkey){
		$this->kkey = (isset($kkey)&& $kkey!="")? $kkey:$this->generatekey(10);
	}
	function getkkey(){
  		return $this->kkey;
  	}  	
	private function generatekey($lengte ){
			/**
			* @author By eprogrammeur
			*/
		  srand(((double) microtime() ) * 1000000 );$string = '';
// De parser doet irri met zoveel tekens zonder spaties achter elkaar, verdeeld  over meerdere regels
		  $tekens = 'abcdefghijklmnopqrstuvwxyz';
		  $tekens .= 'ABCDEFGHIJKLMNOPQRSTUWXYZ';
		  $tekens .= '01234567890123456789';
		  for( $i = 0; $i < $lengte; $i++ )
		  {  
		  	$string .= $tekens{ rand( 0, ( strlen( $tekens ) - 1 ) ) };
		  }
		  return $string;
	}
}
?>