<?php
	/**
	* @author Lieven Roegiers
	* @copyright 2009
 	* @CMS autosite
 	* opensource http://code.google.com/p/autosite/ 
	*/
	/**
	* @param Lieven Roegiers
	* @return new properties()
	*/
	function getpropertiefile($path,$lang="",$name){
		//print $autosite['translations']. "forms_".$autosite['lang'].".properties";
		if(isexist_propertiefile($path,$lang,"forms")){
				print"<!-- @LANGlocale:".$autosite['lang']." IS USED -->";
				return new properties($path,"_".$lang,"forms");
		}else{
				print"<!-- @LANGlocale:".$autosite['lang']." IS NOT EXIST -->";
				return new properties("./layout2/translations/","","forms");
		}
	}
	function isexist_propertiefile($filelocation,$locale,$name){
		return is_file($filelocation.$name."_".$locale.".properties");
	}	
	class properties{
		private $filelocation;	
	    private	$file;
	    private	$toget=array();//!important!speed you if you not check of it is a array
	    private $delemiter = " ";
		function __construct($filelocation,$locale,$name,$lifetime = 0){
			$this->filelocation= $filelocation.$name.$locale.".properties";
			//$this->test();
		}
		private function is_filelocation(){
			return(isset($this->filelocation)&& is_file($this->filelocation));
		}
		private function open($mode='r'){
			return $this->is_filelocation() && $this->file=fopen($this->filelocation,'r');
		}
		private function open_2write($mode='a+'){
			return $this->is_filelocation() && $this->file=fopen($this->filelocation,'a+');
		}
		public function getproperties($tofind_keys){
			$asoarr=array();
			if(!is_array($tofind_keys)){
				print("[error]varkeys translations not found (properties.inc)");
			}else{
				if ($this->open()){
					while (!feof($this->file)){    			
			    			$fline = fgets($this->file, 4096);
			    			$pos = strpos($fline,$this->delemiter);
			    			$key = substr($fline,0,$pos);
			    			if($pos>1 && array_key_exists($key,$tofind_keys) ){
								$value = substr($fline,$pos+1);
								$asoarr[$key]=$value;
							}
					}
				}
			//$this->test2($tofind_keys,$asoarr);
			}
			return $asoarr;	
		}
		private function isexist($label){//
			return true;
		}
		public function find_value($str_tofind,&$bufferarr){
			if (array_key_exists($bufferarr,$str_tofind)){
				return $bufferarr[$str_tofind];
			}else{
				if ($this->open()){
					while (!feof($this->file)){    			
		    			$fline = fgets($handle, 4096);
		    			$pos = strpos($fline,$this->delemiter);
						if($pos>1 && substr($fline,0,$pos)===$str_tofind){
							$bufferarr[$str_tofind]= substr($fline,$pos+1,-0);//last pieces		
						}else{
							print substr($fline,0,$pos);
						}
					}
				}	
			}	
		}
		private function test(){
			print("debug<br />");
			print($this->filelocation ."is".$this->is_filelocation().'<br />');
		}
		private function test2($keyarr,$foundarr){
			print("debug<br />");
			print_r($keyarr);
			print("<br />");
			print_r($foundarr);
			print("<br />");
		}
		function __destruct(){
			    $this->file=null ;	
		}	
	}
?>