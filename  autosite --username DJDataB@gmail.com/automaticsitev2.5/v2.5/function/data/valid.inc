<?php
 /**
 * @author Lieven Roegiers
 * @copyright 2009 
 * @CMS autosite
 * opensource http://code.google.com/p/autosite/
 * <script language='JavaScript' src='<?php print $autosite['javascript']?>form.val.js'></script>
 * <form onsubmit="return formCheck()" enctype="text/plain" method="GET"></form>
*/
class valid{
   private	$msgarr;
   private	$errors=array();//aso_array
   private	$tovalidate;
   private	$isvalid= true;
   function __construct(){
   		//$this->seterrormsg("notexist","ERROR NOTEXIST Formfield:","is not exist watch to your form");	
   }
   public function is_valid(){
		return $this->isvalid;
   }
   public function dovalidation(&$GETorPOST,&$formdata,$is_inject=true){
   		$returnval = array();//array for to save !!!!only valid values!!!!
   		$this->errormsg="";
   		$this->isvalid=true;
		$formfields = $formdata['items'];
		$tovalidate = $formdata['tovalid'];
		$validfine=is_array($tovalidate);
		//print  "<br /> validatefine:".$validfine."<br />";
		if(is_array($formfields)){
			foreach($formfields as $key=>$value){
				$value = $this->makeitvalidate($key);
				if(is_array($GETorPOST[$key])){
					$GETorPOST[$key] = "".implode(",",$GETorPOST[$key])."";
				}
				$value =$GETorPOST[$key];
				if($validfine&& array_key_exists($key,$tovalidate)&&!array_key_exists($key,$GETorPOST)){
					//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< formfield is not exist but not to valid >>>>>>>>>>>>>>>>>>>>>>
					//!!!!!!!!!!!!!!OK!!!!!!!!!!
					$returnval[$key]=$value;//add val to array
				}elseif(!array_key_exists($key,$GETorPOST)){
					//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< formfield is not exist >>>>>>>>>>>>>>>>>>>>>>
					$this->seterror("notexist",$key);
					return; //form NOT ok
				}else{
					$tmp =(isset($value))? addslashes($value) : "" ;
					if ($validfine && trim($tmp) == ""){
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<not validation fine but empty >>>>>>>>>>>>>>>>>>>>>>
						$this->seterror("empty",$key);
					}elseif($validfine && !array_key_exists($key,$tovalidate)){
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<validation fine but field must not tovalidate >>>>>>>
						//!!!!!!!!!!!!!!OK!!!!!!!!!!
						if($testinjection &&  is_sqlinject($value)){
							$this->seterror("injection",$key);
							return;
						}
						$returnval[$key]=$value;//add val to array
					}elseif($validfine && $this->validatefine($key,$tmp)){
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<validation fine and field is also validfine >>>>>>>
						//!!!!!!!!!!!!!!OK!!!!!!!!!!
						if($testinjection && is_sqlinject($value)){
							$this->seterror("injection",$key);
							return;
						}
						$returnval[$key]=$value;//add val to array
					}else{
						$this->seterror("??!ERROR!??",$key);
					}	
				}
			}
		}else{
			$this->seterror("!implementation!",$key);
		}
		$this->test($formfield,$returnval);	
   		return $returnval;
   }
   private function validatefine($key , $value,$testinjection){	
	   	switch($key):
		 	case "email":
			case "mail":
				return is_email($value); 
				break;
			case "tel":
			case "telefoon":
				return true;// is_numeric($value); 
				break;
			case "name":
			case "naam":
				return is_name($value);
				break;
			default: 
				return true;
				break;
		endswitch;
   }
   private function makeitvalidate($key){	
	   	switch($key):
			case "now.date":
				return date("l j F Y"); 
				break;
		endswitch;
   } 
   private function get_arrfirstitem($post,$keys){//indien te valideren geeft hij de value
		foreach ($keys as $key) {
			if(array_key_exists($key,$this->formitemlist)){
				return $this->formitemlist[$key];
			}
		}
		return null;
   }
   public function setvalidatefine($tovalidate){
   	  $this->$tovalidate=$tovalidate;
   }
   private function getvalerrors(){
	 return $this->errormsg;
   }
   /**
    * make a "notfound","fatal","notexist","injection"
   */
   public function seterrormsg($name,$msg){
   		$this->msgarr[$name]=$msg;   	
   }
   private function seterror($msg,$key){
   		$this->isvalid=false;
		$this->errors[$key]= $msg;
   }
   public function geterrors(){
   	 return $this->errors;
   }
   private function setok(){}
   public function __printerrors(){
   		print "<div class='ERROR'>";
   		array_walk($this->errormsg,"__ERRtostring");
   		print "</div>";
   		print "<br /><input type='button' id='button' onClick='javascript:history.go(-1)' value=' Return '>\n";
   }
   private function __ERRtostring($item, $key,$ad ="<br />"){
   		print $key."".$item.$ad;
   }
   private function test($formfield,$returnval){
   		print("<div class='ERROR apanel'>test dovalidation formfields");
		print_r($formfields);
		print_r($returnval);
		print("</div>");
   }
}
/**
 * @param string;
 * @return boolean;
 */
function is_email($str){
	return (isset($str)&&eregi("^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4})$", $str));
}
function is_reknl($bankrekeningnummer){
    $som = NULL;
    if(strlen($bankrekeningnummer)==9){
        for ($i=0; $i<=8; $i++){
            $som += ($bankrekeningnummer[$i] * (9 - $i));
        } 
       	return ($som % 11 == 0);//valid invalid
    }
    return false;
}
function is_rek($bankrekeningnummer){
	return "underconstruction";
}
function is_postbank($reknr){
	$len = strlen($reknr);
	return ($len > 7 && $len < 3);
}
function is_positive_whole_number($var){
	return (is_whole_number($var) && $var>0);
}
function is_whole_number($var){
	return (is_numeric($var)&&(intval($var)==floatval($var)));
}
/**
 * @param string;
 * @return boolean;
 * <NL>is er een klinker.
 */
function is_avowel($var,$max){
	$max =($max<1)?5:$max;
	for ($i = 0; $i < $max; $i++) {
	 	switch($arr[$i]):
		case "a":
		case "e":
		case "i":
		case "o":
		case "u":
				return true;
				break;
	    endswitch;	
	}
	return false;
}
function is_name($var){
	return (is_avowel($var,5));//not posible name =>5 =>"schr"
}
function is_sqlinject($var){//DROP TABLE	
 	return pos($var,"DROP TABLE")||pos($var,"DROP")||(pos($var," WHERE ") && pos($var," OR "))||pos($var,"SELECT * FROM");
}
function is_phpinject($var){	
 	return pos($var,"print_r")||pos($var,"DROP");
}
function is_spaminject($var){	
 	return pos($var,"sex")||pos($var,"SEX");
}
/*
Wat zou er gebeuren als je het document als volgt aanroept?
files.php?login_id=1234567890 OR 1=1
De volgende SQL query wordt uitgevoerd:
SELECT * FROM files WHERE id = 1234567890 OR 1=1

*/
?>