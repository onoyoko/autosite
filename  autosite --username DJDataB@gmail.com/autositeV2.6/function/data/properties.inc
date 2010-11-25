<?php
	/**
	* @author Lieven Roegiers
	* @copyright 2009
 	* @CMS autosite
 	* opensource http://code.google.com/p/autosite/ 
	*/

	/**
	 * getpropertiefile()
	 * 
	 * @param mixed $path the path where the translation file is
	 * @param mixed $lang lang = locale like(NL, FR) and is like form_FR.properties 
	 * @param mixed $name name of the file
	 * @return new properties()
	 */
	function getpropertiefile($path,$lang,$name){
		//print $path.$autosite['translations']. "forms_".$lang.".properties exist:".isexist_propertiefile($path,$lang,$name);
		if(isexist_propertiefile($path,$lang,$name)){
				print"<!-- @LANGlocale:".$lang." IS USED !!!properties!!! -->";
				return new properties($path,"_".$lang,$name);
		}else{
				print"<!-- @LANGlocale:".$lang." IS NOT EXIST !!!properties!!! -->";
				return new properties("./layout2/translations/","",$name);
		}
	}
	/**
	 * isexist_propertiefile()
	 * @param mixed $filelocation the path where the translation file is
	 * @param mixed $locale lang = locale like(NL, FR) and is like form_FR.properties 
	 * @param mixed $name name of the file
	 * @return bool
	 */
	function isexist_propertiefile($filelocation,$locale,$name){
		return is_file($filelocation.$name."_".$locale.".properties");
	}	
	class properties{
		private $filelocation;	
	    private	$file;
	    private	$toget=array();//!important!speed you if you not check of it is a array
	    private $delemiter = " ";
		/**
		 * properties::__construct()
		 * 
    	 * @param mixed $filelocation the path where the translation file is
    	 * @param mixed $locale lang = locale like(NL, FR) and is like form_FR.properties 
    	 * @param mixed $name name of the file
		 * @param integer $lifetime not used at this time
		 * @return
		 */
		function __construct($filelocation,$locale,$name,$lifetime = 0){
			$this->filelocation= $filelocation.$name.$locale.".properties";
			//$this->test();
		}
		/**
		 * properties::is_filelocation()
		 * 
		 * @return bool
		 */
		private function is_filelocation(){
			return(isset($this->filelocation)&& is_file($this->filelocation));
		}
		/**
		 * properties::open()
		 * 
		 * @param string $mode
		 * @return bool
		 */
		private function open($mode='r'){
			return $this->is_filelocation() && $this->file=fopen($this->filelocation,'r');
		}
		/**
		 * properties::open_2write()
		 * 
		 * @param string $mode
		 * @return bool
		 */
		private function open_2write($mode='a+'){
			return $this->is_filelocation() && $this->file=fopen($this->filelocation,'a+');
		}
		/**
		 * properties::getproperties()
		 * 
		 * @param mixed $tofind_keys
		 * @param string $prefix
		 * @return array(key=>value)
		 */
		public function getproperties($tofind_keys,$prefix=""){
			$asoarr=array();
            
			if(!is_array($tofind_keys)){
				print("[error]varkeys translations not found (properties.inc)");
			}else{
				if ($this->open()){
					while (!feof($this->file)){    			
			    			$fline = fgets($this->file, 4096);
			    			$pos = strpos($fline,$this->delemiter);
			    			$key = substr($fline,0,$pos);
                            $propertie = $prefix.$key;
			    			if($pos>1 && array_key_exists($propertie,$tofind_keys) ){
								$value = substr($fline,$pos+1);
								$asoarr[$key]=str_replace(array("\r\n", "\n", "\r"), "",$value);
							}
					}
				}
			//$this->test2($tofind_keys,$asoarr);
			}
			return $asoarr;	
		}
		/**
		 * properties::isexist()
		 * //TODO underconstruction
		 * @param mixed $label
		 * @return bool not used at this time
		 */
		private function isexist($label){//
			return true;
		}
		/**
		 * properties::find_value()
		 *  //TODO underconstruction
		 * @param mixed $str_tofind
		 * @param mixed $bufferarr
		 * @return return if exist in list else
		 */
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
		/**
		 * properties::test()
		 * 
		 * @return 
		 */
		private function test(){
			print("debug<br />");
			print($this->filelocation ."is".$this->is_filelocation().'<br />');
		}
		/**
		 * properties::test2()
		 * 
		 * @param mixed $keyarr
		 * @param mixed $foundarr
		 * @return
		 */
		private function test2($keyarr,$foundarr){
			print("debug<br />");
			print_r($keyarr);
			print("<br />");
			print_r($foundarr);
			print("<br />");
		}
		/**
		 * properties::__destruct()
		 * 
		 * @return
		 */
		function __destruct(){
			    $this->file=null ;	
		}	
	}
?>