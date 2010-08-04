<?php
/**
 * @author Lieven Roegiers
 * @copyright 2009
 * @CMS autosite
 * !important!ERROR
 * @underconstruction
 */
 if (!function_exists('Qtagmaker')){//include_once its when it is include in the php lib
class QPage{//
	private $pagepath;
	public function __construct(){
		
	}
	public function saveasfile($location,$pagename,$pagecontent){
		if(is_file($location.$pagename.".dat")){
			    if($this->isvalidate($pagecontent)){
				$fp = fopen($location.$pagename.".dat", 'w');
				fwrite($fp, stripslashes($pagecontent));
				fclose($fp);
				return true;
			}else{
				print("<!-- not valid data-->");
			}
		}else{
			print("<!--path not ready-->");
		}
		return false;
	}
	public function get($pagename,$pagecontent){
		if(is_file($this->pagepath.$pagename)){

		}else{
			print("<!--path not ready-->");
		}
	}
	private function isvalidate($pagecontent){
		return true;
	}
 }
}
?>