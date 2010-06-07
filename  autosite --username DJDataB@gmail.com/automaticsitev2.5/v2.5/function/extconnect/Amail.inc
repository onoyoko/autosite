<?php
 /**
 * @author Lieven Roegiers
 * @copyright 2009 
 * @CMS autosite
 * opensource http://code.google.com/p/autosite/
 * @underconstruction	
 */	
 	class Amail{
 		private $headers=array();
 		private $issend;
 		function __construct($from){
 			if($this->is_spammer($from)){
 				$this->headers["From:"] = "web<$from>";
 				$this->headers["Content-Type"] = "text/plain; charset='iso-8859-1'";
 				//$this->headers["MIME-Version"] = "1.0";
 				//$this->headers["Content-Transfer-Encoding"] = "8Bit";
 				$this->headers["X-Mailer"] = "PHP/".phpversion();
 				$this->headers["Reply-To:"]= "$from";
 			}else{
			   //$this=null;//kill myself
 			}

 		}
 		/**
 		* @param $naam   naam verzender
 		* @param $email  email adress
 		* @return true/false
 		* @walkit
 		* !important! do not remake watch to array_walk
 		*/
		function send($naam,$email){
			$this->issend = mail($email,$this->subject,$this->html,$this->headers);
			return $this->issend;
		}
		/**
 		* @maillist 
 		* asiosiatieve array (name => mail)
 		*/
		function maillist($array){
			(is_array ($array))? array_walk($array, 'send'):null;			
		}
		/**
		 * @param $key  vb: "From:"  ,"Reply-To:";
 		 * @return true/false
		*/
		public function setheader($key,$value){
			$this->headers[$key] =$value;
		}
		public function sethtml(){
			$this->headers["Content-Type:"] = " text/html; charset='iso-8859-1'";
		}
		private function getheaders(){
			return implode(" ",$this->headers);
		}
		private function getheaderstest(){
			array_walk($array, 'wrap_each');
			$array_csv = implode(" ", $array);
		}
		function wrap_each(&$item){
    		$item = "'$item'";
		}
		private function is_spammer($from){
			return $this->is_headerinject($from);
		}
		private function is_headerinject($from){
			//%0D%0A HTML-equivalent =>    \r\n
			return pos($var,"%0D%0A")||pos($var,"%0D%0Abcc:");
		}
	}
?>