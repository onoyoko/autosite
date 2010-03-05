<?php
 /**
 * @author Lieven Roegiers
 * @copyright 2009
 * @CMS autosite
 * 
 * generator for html from tagnames
 */
if (!function_exists('Qtagmaker')){//include_once its when it is include in the php lib
	class Qtagmaker{
		private $templates= array();
		/**
		 * functions 
		*/
		public function __construct(){
			$this->template["email"]="<a href='mailto:%value%'>%value%</a>";
			$this->template["link"]="<a href='http://%value%' target='_blank'>%value%</a>";
			$this->template["img"]="<img src='%value%' />";
			$this->template["logo"]="<img src='%value%' />";
			$this->template["tel"]="%value% <a href='skype:%value%?call'>call</a> <a href='skype:%value%?add'>add</a>";
		}
		public function addtagitem($key,$value){
			$this->template[$key]=$value;
		}
		public function tagmaker($tag,$value){
	    	$returnval = "";
	    	$crlft="%3A%0A-%20%20%20";//carry return line feet
	    	if($value!=""){
				if(array_key_exists($tag,$this->template)){
					return $this->generate($tag,$value);
				}else {					
					switch ($tag): 
						case "mail":
							return $this->generate("email",$value);
							break;
						case "website":
						case "site":
					        return $this->generate("link",$value);
							break;
						case "img":
						case "foto":
						case "image":
						case "pic":
							return $this->generate("img",$value);
							break;
					    case "tel":
						case "phone":
						case "telefone":
						case "gsm":
							return $this->generate("tel",$value);
							break;
						case "logo":
							return $this->generate("logo",$value);
							break;	
						default :
							return $value;
						endswitch;    			
			   }  
			}
	    }
	    private function generate($tagname,$value){
	    	return str_replace("%value%", $value, $this->template[$tagname]);
	    }
	}
}

//hidden class
class Qhtml{
 		
		//private $html["br"]=array("\r\n", "\n", "\r");
 		function __construct(){
		}
 		public function encode($html){
 			
 		}
 		public function decode($string){
 			
 		}
}
class oldstuf{

    /**
    * $arr[1]=array(13,"")
    */
    private function optionmaker($aso_arr ,$selected=1){
			print"<select name='speeldag'>";
			while (list ($key, $val) = each ($option_speeldag)) {
				print '<option'.$select_speeldag[$val]." value='$key' class='".funisdatepasse($val.'012006','green','red')."'>";
				if ($key==0){
					print '</option>'; 	
				}else{
					print $val.' jan</option>';	
				}
			 }
             print"</select>";
    }
}
 	
?> 