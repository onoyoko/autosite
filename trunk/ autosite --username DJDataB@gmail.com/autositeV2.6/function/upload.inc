<?php
include($autosite['functions']."GD/resizer.inc");
//echo "<div classe='right'><a href=\"$_SERVER[PHP_SELF]?key=".$kkey."&upload=1&id=".$path." \">Volgende upload</a><br>";
/**
 * http://be.php.net/manual/en/features.file-upload.common-pitfalls.php
 * http://be.php.net/manual/en/features.file-upload.multiple.php 
 * @author Lieven Roegiers
 * @copyright 2009 
 * @CMS autosite
 * Todo make links for multilink uploading
 * opensource http://code.google.com/p/autosite/ 
*/
class upload{
	private $UPL_trueext;
	private $maximgsize;
	private $links =array();
	/**
	 * @param $FILES	your $_FILES by reference
	 * @param $formdata	alle fields that can upload $formdata['items'][fieldname]
	 * @param $trueext	al true extentions array(".gif",".png")
	 * @param $to path	the path to move
	*/
	public function upload(&$FILES,&$formdata,$trueext,$topath){
		$this->UPL_trueext = $trueext;
       	if($FILES!=null&& is_array($FILES)){
       		foreach($FILES as $key=>$value){ //watch all sended files 
			   //print "<H2>$key = ".print_r($value)."</H2>";    			
       			if(is_array($formdata['items'])&& array_key_exists($key,$formdata['items'])){//is the file askt in form
					if($value['name']!=null ){//if there is a upload 
						if(is_array($value['name'])){//complex multiple upload
							foreach($value['name'] as $kkey=>$namevalue){
								$tmpname = $value['tmp_name'][$kkey];
								//todo is there a file uploaded
								if(self::isfile($namevalue,$value['error'][$kkey])){
									self::saveuploadedfile($tmpname,$namevalue,$topath,$key);
								}
							}
						}else{//normal single upload
							$tmpname =$value['tmp_name'];
							self::saveuploadedfile($value['tmp_name'],$value['name'],$topath,$key);	
						}
					}
       			}else{
       				print "upload.inc key not exist";
       			}
				//print_r($_FILES);
			}
		}
	}
	/**
	* @param $filename	string of the filename for get ext
	* @param $error	$value['error'][$kkey]   =>404 or anything else
	* @return true/false
	*/
	private function isfile($filename,$error){
		return ($this->is_trueext($this->getext($filename))&&$error<1);
	}
	/**
	* @return asoarray of the link to the files
	*/
	public function getlinks(){
		return $this->links;
	}
	/**
	* @param $ext	can use ext
	* TODO make control for mimes
	* @return true/false
	*/
	private function is_trueext($ext){
       	return in_array($ext,$this->UPL_trueext);
	}
	/**
	* @param $filename the name of the file
	* @return string extention and the point
	*/
	private function getext($filename){
		//$exts = split("[/\\.]", $filename);
		//$n = count($exts)-1;
		//$ext = $exts[$n];
       	return (string)strtolower(strrchr($filename,'.'));
	}
	/**
	* @param $tmpfile the name of the file to temp dir server
    * @param $filename new name on the server
    * @param $topath  the path on the server where we save the img
	* @return string extention and the point
	*/
	private function saveuploadedfile($tmpfile,$filename,$topath,$from="upload_"){
			if(!is_file($topath.$from.$filename)){
				$len = sizeof($this->links[$from]);
				$this->links[$from][$len]= $topath.$from.$filename;
				return move_uploaded_file($tmpfile,$topath.$from.$filename);
			}else{
				false;
			}
	}
	private function test(){
       print $_FILES['imgfile']['type'];
       print $_FILES['imgfile']['name'];
       print $_FILES['imgfile']['size'];
       print $_FILES['imgfile']['err'];
       print $_FILES['imgfile']['tmp_name'];
       //print_r($_FILES);
	}
	public function generatethump($height = 150,$with=0){
		if($ispic){
			$resizer = new resizer($_FILES);
			$resizer->MOVEthumppic_to();
			$resizer->MOVErealpic_to();
		} 
	}
}

?>