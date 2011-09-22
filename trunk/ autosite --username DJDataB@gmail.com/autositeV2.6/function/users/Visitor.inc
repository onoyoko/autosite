
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
    private $brower;
	private $remoteip;
	private $enabled;
	private $isheajack;
	function Visitor(){
		session_start();
	}
	//<<<<<<<<<<<<<<<<<<<<<<<FUNCTIONS>>>>>>>>>>>>>>>>>>>>>>>>>
	private function isRemoteip(){
		if($this->remoteip === $_SERVER['REMOTE_ADDR']){
			return true;
		}else{
			@session_unset();
			return false;
		}
	}
	//<<<<<<<<<<<<<<<<<<<<<<<Setters>>>>>>>>>>>>>>>>>>>>>>>>>

	private function setRemoteip(){
		$this->remoteip = $_SERVER['REMOTE_ADDR'];
	}
    public function setBrowser($browername){
		$this->brower= $browername;
	}
    public function setLanguage($langname){
		$this->lang= $langname;
	}

	private function __toprintsession(){
		print_r($_SESSION);
	}
	//<<<<<<<<<<<<<<<<<<<<<<<Getters>>>>>>>>>>>>>>>>>>>>>>>>>
    public function getBrowser(){
		return $this->brower;
	}
    public function getLanguage(){
		return $this->lang;
	}    
}
?>