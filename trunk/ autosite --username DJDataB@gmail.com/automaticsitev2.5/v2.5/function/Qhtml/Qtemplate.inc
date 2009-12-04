<?php
	/**
	* @author Lieven Roegiers
	* @revisite 30 day
	* @copyright 2009 
	*/
	
	class Qtemplate{
		private $template;
		private $html;
		private $taglist=array();
		private $htmltag;
		private $tagnotfound = array();
		/**
 		* @param var $html str html
 		*/
 		function __construct(&$html){
 			print("<!--Qtemplate locale translator by autosite-->");
	    	$this->html = $html;
	    	$this->htmltag=new Qtagmaker();
		}
		public function addtagitem($key,$value){
			$this->htmltag->addtagitem($key,$value);
		}
		/**
 		* @param var $html str html
 		*/
		public function reset($html){
			$this->html= $html;
		}
		function toreplace($key,$value){
		  $this->html=str_replace("%".$key."%", $value, $this->html);
		}
		public function translate($asoarr){
		  if(is_array($asoarr)){
		  	 foreach ($asoarr as $key => $value){
		  	 	if ($value !=" "){
		  	 		$this->toreplace($key,$value);
		  	 		//print $key.":".$value;
		  	 	}//else{
		  	 	//	$new = "!".$key."!";
		  	 	//	$this->toreplace($key,$new);
		  	 		//print $key.":".$value;
		  	 	//}
		  	 }
		  }
		}
		public function setvalues($asoarr){
		  if(is_array($asoarr)){
		  	 foreach ($asoarr as $key => $value){
		  	 	$temp=$this->htmltag->tagmaker($key,$value);
		  	 	$this->toreplace($key."->value",$temp);
		  	 }
		  }
		}
		public function gethtml(){
			return $this->html;
		}
	}
?>