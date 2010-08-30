
 <?php
 /**
 * @author Lieven Roegiers
 * @copyright 2010 
 * @CMS autosite
 * opensource http://code.google.com/p/autosite/
 */
//function killsessionuser(){
	
//}
function setsessionvisitor($user){
	$_SESSION['visitor']=serialize($user);
}
function getsessionvisitor(){
	return(isset($_SESSION['visitor']))?unserialize($_SESSION['visitor']):null;
}
class Visitor {
	private $remoteip;
	private $enabled;
	private $isheajack;
	private $releasetime=0;
	function Visitor(){
		session_start();
	}
	//<<<<<<<<<<<<<<<<<<<<<<<FUNCTIONS>>>>>>>>>>>>>>>>>>>>>>>>>
	function setVisitor($kkey){
		//$username=(isset($username)&& $username!="")?$username:$_SESSION['login'];
		//parent:: wil go to extends
 		parent::__construct($username,$kkey);
		$this->isuser=(is_dir($this->userpath)&& $username!="")? true:false;
	}
	private function isenabled(){
  		return true;
  	}
  	//set not public security
	private function isReleasetime(){
		return ($this->releasetime > time());	
	}
	private function isRemoteip(){
		if($this->remoteip === $_SERVER['REMOTE_ADDR']){
			return true;
		}else{
			@session_unset();
			return false;
		}
	}
	//<<<<<<<<<<<<<<<<<<<<<<<Setters>>>>>>>>>>>>>>>>>>>>>>>>>

	private function setReleasetime(){
		$this->releasetime = time() + (1 * 1 * 60 * 60);	
	}
	private function setRemoteip(){
		$this->remoteip = $_SERVER['REMOTE_ADDR'];
	}
	public function setpassword($oldpwx){
		
	}
	public function __tostring(){
		return "Welkom ";
	}
	private function __toprintsession(){
		print_r($_SESSION);
	}
}
?>