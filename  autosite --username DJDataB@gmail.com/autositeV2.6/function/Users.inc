<?php
/**
 * @author Lieven Roegiers
 * @copyright 2009
 * @CMS autosite
 * !important!ERROR
 * @underconstruction
 */
class users{//
	private $userspath;
	public function __construct($userspath){
		$this->userspath = $userspath;
	}
	public function can_i_create(){
		
	}
	private function setlevel($level){
		
	}
	private function create($username){
		
	}
	private function isexist(){
		
	}
	private function deleteuser($username){
		
	}
	private function changepassword($oldpwx,$newpwx){
		
	}
	private function canmanipulate(){
		return true;
	}
	public function __tostring(){
		"";
	}
	public function vieuwusers($pathname){
		if(is_file($pathname)){
			$opendir = opendir($pathname);
			$i =1;
			while ($file = readdir($opendir)) {
	    		if($file != '..' && $file !='.' && $file !=''){
	    			$pos = strpos($file, "_.");
	        		if (is_dir($file)){
					    print $file;
	        		}
				}else{
					print $file;
				}
			}
		}else{
			print("<!--userspath not ready-->");
		}
	}
}
?>