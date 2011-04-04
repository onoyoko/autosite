<?php
	class IMGmasker{
	   private $mimetype;
	   public function __construct() {
	       
	   }
       public function getbin($path,$name){
            return fread(fopen($path.$name, "r"), filesize($path.$name));
       }
       public function __getimg($path,$name){
            return "data:".$this->mimetype.";base64,".base64_encode($this->getbin($path,$name));
       }
    }
?>