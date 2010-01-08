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
	public function upload(&$FILES,&$formdata,$trueext,$topath){
		$this->UPL_trueext = $trueext;
       	if($FILES!=null&& is_array($FILES)){
       		foreach($FILES as $key=>$value){ //watch all sended files      			
       			if(array_key_exists($key,$formdata['items'])){//is the file askt in form
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
       			}
				//print_r($_FILES);
			}
		}
	}
	private function isfile($filename,$error){
		if ($this->is_trueext($this->getext($filename))){
			return $error<1;
		}
	}

	public function getlinks(){
		return $this->links;
	}
	private function is_trueext($ext){
       	return in_array($ext,$this->UPL_trueext);
	}
	private function getext($filename){
		//$exts = split("[/\\.]", $filename);
		//$n = count($exts)-1;
		//$ext = $exts[$n];
       	return (string)strtolower(strrchr($filename,'.'));
	}
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