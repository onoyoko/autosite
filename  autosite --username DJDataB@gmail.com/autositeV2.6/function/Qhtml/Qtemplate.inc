<?php
	/**
	* @author Lieven Roegiers
	* @revisite 30 day
	* @copyright 2009
	* @CMS autosite
	*/
	class Qtemplate{
		private $template;
		private $html;
		private $taglist=array();
		private $htmltag;
		private $tagnotfound = array();
		private $toolsbar="";
		private $toolshandeler;
        private $y=0;
		/**
 		* @param var $html str html
  		 * @return
 		 */
 		function __construct(&$html){
 			//print("<!--Qtemplate locale translator by autosite-->");
	    	$this->html = $html;
	    	$this->htmltag=new Qtagmaker();
		}
		/**
		 * @param mixed $key
		 * @param mixed $value
		 * @return
		 */
		public function addtagitem($key,$value){
			$this->htmltag->addtagitem($key,$value);
		}
		/**
 		* @param var $html str html
		 * @return
		 */
		public function reset($html){
			$this->html= $html;
		}
		/**
		 * @param mixed $key
		 * @param mixed $value
		 * @return
		 */
		function toreplace($key,$value){
		  $this->html=str_replace("%".$key."%", $value, $this->html);
		}
		/**
		 * @param mixed $asoarr
		 * @return
		 */
		public function translate($asoarr){
		  if(is_array($asoarr)){
		  	 foreach ($asoarr as $key => $value){
		  	   if ($key != "toolbar"){
			  	   	if ($value !=" "){
			  	 		$this->toreplace($key,$value);
			  	 	}
		  	   }else{
		  	   		$this->toreplace($key,$this->toolsbar);
		  	   } 	
		  	 }
		  }
		}
		/**
		 * @param mixed $toolbar
		 * @param mixed $link
		 * @return
		 */
		function settoolbar($toolbar,$link){
				$this->toolsbar=$toolbar;
				$this->toolshandeler=$link;
		}
		/**
		 * @param mixed $asoarr
		 * @return
		 */
		public function setvalues($asoarr){
		  if(is_array($asoarr)){
		  	 foreach ($asoarr as $key => $value){
		  	 	$temp=$this->htmltag->tagmaker($key,$value);
		  	 	$this->toreplace($key."->value",$temp);
		  	 }
		  }
		}
		/**
		 * @return the translated data 
		 */
		public function gethtml(){
			return $this->html;
		}
		/**
		 * @return the translated data
		 */
		public function getdata(){
			return $this->html;
		}
	}
	/**
	 * teller()
	 * 
	 * @param mixed $i
	 * @return
	 */
	function teller($i){
		return $i++;
	}
?>