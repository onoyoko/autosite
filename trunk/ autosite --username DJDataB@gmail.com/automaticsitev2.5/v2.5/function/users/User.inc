<?php
/**
 * @author Lieven Roegiers
 * @copyright 2009
 * @CMS autosite
 */
//function killsessionuser(){
	
//}
function setsessionuser($user){
	$_SESSION['user']=serialize($user);
}
function getsessionuser(){
	return(isset($_SESSION['user']))?unserialize($_SESSION['user']):null;
}
class User extends User_data{
	private $userpath;
	private $name;
	private $pasword;
	private $level;
	private $isuser;//
	private $kkey;
	private $remoteip;
	private $enabled;
	private $hashList =array();
	private $releasetime = 0 ;
	function User(){
		session_start();
	}
	//<<<<<<<<<<<<<<<<<<<<<<<FUNCTIONS>>>>>>>>>>>>>>>>>>>>>>>>>
	function setUser($username,$path,$kkey){
		//$username=(isset($username)&& $username!="")?$username:$_SESSION['login'];
		//parent:: wil go to extends
 		parent::__construct($username,$kkey);
		$this->name =$username;
		$this->userpath =$path.substr($username, 0, 1)."/".$username."/";
		$this->isuser=(is_dir($this->userpath)&& $username!="")? true:false;
	}
	function login($pasword,$kkey,$c){
		if ($this->isuser)include $this->userpath."data.php";
	    if(isset($this->name)&&isset($incpass)&& $incpass != "" && ishash("md5",$kkey.$incpass,$pasword)){
			$this->setReleasetime();
			$this->setRemoteip();
			$this->level = $loginniveau;
			$this->enabled = $hasaccess;//login enabled or disabled
			return true;
			//$_SERVER["HTTP_ACCEPT"
		} else { 
			return false;
		}
  	}
  	//<<<<<<<<<<<<<<<<<<<<<<<Getters>>>>>>>>>>>>>>>>>>>>>>>>>
	function islogin(){
		return (isset($this->name)&& isset($this->releasetime) && $this->releasetime > time()&&$this->isenabled());//$this->isRemoteip());
	}
	function is_User($username){
		return $this->isuser;
	}
	function getlevel(){
		return ($this->islogin())?$this->level:112;// !login = lowerst level 
	}
	public function getpath(){
		return ($this->islogin())?$this->userpath:"ERROR not login";
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
		return "Welkom ".$this->name."releasetime".(($this->releasetime -time() )/60)."min";
	}
	private function __toprintsession(){
		print_r($_SESSION);
	}
}
?>