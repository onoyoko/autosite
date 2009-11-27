<?php
	class FileScanner{
		 /**
		 * @author Lieven Roegiers
		 * @copyright 2009
		 * @CMS autosite
		 */
		private $dirs =array();
		private $files =array();
		private $inc_ext =array();
		private $exc_ext =array();
		private $isnotinc_ext = true;//!!!not!!!
		public function scandir($dir){
			$this->dirs =array();
			$this->files =array();
			if ($d = Dir($dir)){
				while (false !== ($entry = $d->read())) {
                	$pos = strpos($entry, ".");
                	if ($pos === false){
            	       array_push($this->dirs,$entry);	
		            }elseif(substr($entry, 0, 1) != "."){
            		   $name = substr($entry, 0, $pos);
            		   $ext = substr($entry, -4);
            		   //$this->test2($ext);
		               if (!in_array($ext,$this->exc_ext)){
							if ($this->isnotinc_ext||in_array($ext,$this->exc_ext)){
								array_push($this->files,$entry);
		               		}
		               }
           	        }
                }
			}
			//$this->test();
		}
		private function is_incext(){
			return count($this->inc_ext,1)<1;
		}
		public function set_inc_extfilter($arrlist){
			$isnotinc_ext = false;//!!!not!!!
			$this->inc_ext=$arrlist;
		}
		public function set_exc_extfilter($arrlist){
			$this->exc_ext=$arrlist;
		}
		/**
    	* @param $array [inc]=array(".inc",".htm",".old")[exc]=array(".htaccess")
     	*/
     	public function setfilter($arr){
     		if (isset($arr['inc'])){
     			$this->inc_ext=$arr['inc'];
     		}
     		if (isset($arr['exc'])){
     			$this->inc_ext=$arr['exc'];
     		}
		}
		public function getdirs(){
			return $this->dirs;
		}
		public function getfils(){
			return $this->files;
		}
		private function test(){
			print "<br><br>print dirs<br>";
			print_r($this->dirs);
			print "<br><br>print files<br>";
			print_r($this->files);
		}
		private function test2($test){
			print property_exists($test ,$this->exc_ext);
			print($test);
			//print "<pre>";
			print_r($this->exc_ext);
			//print "</pre>";
		}
}
?>