<?php
/**
 * @author Lieven Roegiers
 * @copyright 2009
 * @CMS autosite
 * !important!ERROR
 * @underconstruction
 */
class resizer{
	private $TRUEext = array(".gif",".jpg",".png",".jpeg");
	private $file_type;
	private $file_name;
	private $file_size;
	private $file_tmp;
	private $imgfile;
	private $new_img;
	/** <%@ page contentType="text/html; charset=" %>
	 * @param $IMGfile $_FILES['imgfile'];(mixed part)
	 */
	function __construct($IMGfile) {
		$this->imgfile = $IMGfile['type'];
		$this->file_name = $IMGfile['name'];
		$this->file_size = $IMGfile['size'];
		$this->file_tmp = $IMGfile['tmp_name'];
		if($this->file_size){//wil mean it is a picture
			$this->new_img = getimgobj($this->IMGfile['type']);
  		}
  		$this->imgfile = $IMGfile;
	}
	/** <%@ page contentType="text/html; charset=" %>
	 * @param 
	 */
	function MOVEthumppic_to($asname,$thumppath="/",$maxthumpsize=150){
	   //list width and height and keep height ratio.
	   if(!is_uploaded_file($this->imgfile['tmp_name'])){
	       list($width, $height) = getimagesize($this->imgfile['tmp_name']);
	       $imgratio=$width/$height;
	       $newwidth = $maxthumpsize;
	       $newheight = $maxthumpsize;
	       if ($imgratio>1){
		   	    $newheight = $maxthumpsize/$imgratio;
	       }else{
	            $newwidth = $maxthumpsize*$imgratio;
	       }
	       if (function_exists(@imagecreatetruecolor)){
	       		$resized_img = imagecreatetruecolor($newwidth,$newheight);
	       		ImageJpeg($resized_img,$thumppath.$asname);
	       }else {
	       		imagecopyresized($resized_img,$this->new_img, 0, 0, 0, 0, $newwidth, $newheight, $width, $height);
	       }
	       return(is_file($thumppath.$asname));
		}else {
		   echo "Error:was not upload";
		   return false;
		}
	}
	public function MOVErealpic_to($asname,$bigpath="/"){
		return move_uploaded_file($this->imgfile['tmp_name'],$bigpath.$asname);	
	}
	function __destruct(){
       ImageDestroy ($resized_img);
       ImageDestroy ($this->new_img);
	}
	/**
	* make a "notfound","fatal","notexist","injection"
	*/
	private function getext($Fname){
		return strtolower(substr($Fname,strrchr($Fname,'.')));
	}
	public function is_trueextentie($ext){
	   $ext = getext($this->file_name);
       return(!in_array($ext,$this->TRUEext));
  	}
	public function seterrormsg($name,$msg){
		$this->msgarr[$name]=$msg;   	
	}
	private function seterror($name,$key){
		$this->isvalid=false;
		if(@array_key_exists($name,$this->msgarr)){
			$this->errormsg.= str_replace("%errkey%", $key, $this->msgarr[$name]);
		}else{
			$this->errormsg.= "%$name%".$key."%$name%";
		}
	}
	private function getimgobj($file_type){	
		switch ($file_type){ 
			case "image/pjpeg":
			case "image/jpeg":
				return imagecreatefromjpeg($file_tmp);
				break;
			case "image/x-png":
			case "image/png":
				return imagecreatefrompng($file_tmp);
				break;
			case "image/gif":
				return imagecreatefromgif($file_tmp);
				break;
			default :
				return null;
				break;
		}
	}
	private function getvalerrors(){
		 return $this->errormsg;
	}
}
?>