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
    private $filelocation;
	public function __construct($location,$pagename){
		$this->filelocation = $location.$pagename.".dat";
	}
	public function saveasfile($pagecontent){
        if($this->isvalidate($pagecontent) &&$this->is_ReadyToUse()){
				$this->open();
				fwrite($this->file, stripslashes($pagecontent));
				return true;
		}else{
			print("<!-- path not ready-->");
		}
		return false;
	}
	public function get(){
		if(is_file($this->pagepath.$pagename)){

		}else{
			print("<!--path not ready-->");
		}
	}
    private function Page_create(){
        
    }
    /**
	 * @param string $mode
	 * @return
	 */
	private function open($mode='a+'){
		return($this->file = fopen($this->filelocation,$mode)); 
	}
    public function is_ReadyToUse(){
		return(isset($this->filelocation)&& is_file($this->filelocation));
	}
	private function isvalidate($pagecontent){
		return true;
	}
 }
}
?>