<?php
/**
 *  <%@ page contentType="text/html; charset=" %>
 * @author Lieven Roegiers
 * @copyright 2009
 * @CMS autosite
 * !important!ERROR
 * @underconstruction
 */
class resizer{
	private $TRUEext = array(".gif",".jpg",".png",".jpeg");
	private $actualimgsize;
	private $thumbimgsize =array();
	private $Maxsize;
	function __construct($Maxsize = 200) {
		$this->Maxsize = $Maxsize;
        if (!function_exists(@imagecreatetruecolor)){
            die("Error: Please make sure you have GD library ver 2+(contact your hosting or watch to php.ini)");
        }
	}
    public function thumptornado($sourcepath,$destinationpath){
		
	}
    public function thumpcollection($aso_sourceFname,$aso_destinationFname){
		
	}
    private function getsize($fname){
        list($this->actualimgsize['y'], $this->actualimgsize['x']) = getimagesize($fname); //width , height
    }
	public function createthump($sourcename,$destinationname){
        list($width, $height, $type, $attr) = getimagesize($sourcename);
        $new_img = getimgobj($sourcename,$type);
                /* create a new image with the new width and height */
       
            $temp = imagecreatetruecolor($w, $h);
            /* making the new image transparent */
            $background = imagecolorallocate($temp, 0, 0, 0);
            ImageColorTransparent($temp, $background); // make the new temp image all transparent
            imagealphablending($temp, false); // turn off the alpha blending to keep the alpha channel
            /* Resize the PNG file */
            /* use imagecopyresized to gain some performance but loose some quality */
            imagecopyresized($temp, $src, 0, 0, 0, 0, $w, $h, imagesx($src), imagesy($src));

        /*if (function_exists(@imagecreatetruecolor)){
	       		$resized_img = imagecreatetruecolor($newwidth,$newheight);
	       		ImageJpeg($resized_img,$destinationname);
	       }else {
	       		imagecopyresized($resized_img,$this->new_img, 0, 0, 0, 0, $newwidth, $newheight, $width, $height);
	       }
        return(is_file($destinationname));*/
	}
    private function sethumbsize(&$x,&$y){
   	       $imgratio=$x/$y;
	       $thumbimgsize['x'] = $this->Maxsize;
	       $thumbimgsize['y'] = $this->Maxsize;
	       if ($imgratio>1){
		   	    $thumbimgsize['y'] = $maxthumpsize/$imgratio;
	       }else{
	            $thumbimgsize['x'] = $maxthumpsize*$imgratio;
	       }
        $this->thumbimgsize=$thumbimgsize;
    }
	public function is_trueextentie($ext){
	   $ext = getext($this->file_name);
       return(!in_array($ext,$this->TRUEext));
  	}
    private function getext($Fname){
		return strtolower(substr($Fname,strrchr($Fname,'.')));
	}

	private function getimgobj($Fname,$mime){
		switch ($mime){ 
			case "image/pjpeg":
			case "image/jpeg":
				return imagecreatefromjpeg($Fname);
				break;
			case "image/x-png":
			case "image/png":
				return imagecreatefrompng($Fname);
				break;
			case "image/gif":
				return imagecreatefromgif($Fname);
				break;
			default :
				return null;
				break;
		}
	}
    private function seterrormsg($name,$msg){
		$this->msgarr[$name]=$msg;   	
	}
    public function getimg(&$imgname,&$height,&$width){
                //header("Content-type: " . image_type_to_mime_type(IMAGETYPE_JPEG));
                //header('Content-type: ' .image_type_to_mime_type($type));
                //print $imgname;
                //return exif_thumbnail(&$imgname,&$height,&$width,IMAGETYPE_JPEG);
               // echo 'No thumbnail available';         
    }
}
?>