<?php
/**
 * @author Lieven Roegiers
 * @copyright 2009
 * @CMS autosite
 */
//function killsessionuser(){
	
//}
/**
 * @param mixed $user
 * @return void
 */
function setsessionuser($user){
	$_SESSION['user']=serialize($user);
}
/**
 * getsessionuser()
 * @return object User
 */ 
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
	/**
	 * @return void
	 */
	function User(){
		session_start();
	}
	//<<<<<<<<<<<<<<<<<<<<<<<FUNCTIONS>>>>>>>>>>>>>>>>>>>>>>>>>
	/**
	 * @param string $username
	 * @param string $path 
	 * @param string $kkey
	 */
	function setUser($username,$path,$kkey){
		//$username=(isset($username)&& $username!="")?$username:$_SESSION['login'];
		//parent:: wil go to extends
 		parent::__construct($username,$kkey);
		$this->name =$username;
		$this->userpath =$path.substr($username, 0, 1)."/".$username."/";
		$this->isuser=(is_dir($this->userpath)&& $username!="")? true:false;
	}
	/**
	 * @param string $pasword
	 * @param string $kkey
	 * @param null $c
	 * @return bool
	 */
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
	/**
	 * @return bool
	 */
	function islogin(){
		return (isset($this->name)&& isset($this->releasetime) && $this->releasetime > time()&&$this->isenabled());//$this->isRemoteip());
	}
	/**
	 * @param string $username
	 * @return bool
	 */
	function is_User($username){
		return $this->isuser;
	}
	/**
	 * @return int
	 */
	function getlevel(){
		return($this->islogin())?$this->level:112;// !login = lowerst level 
	}
	/** 
	 * @param int $level
	 * @return bool
	 */
	function ispermitlevel($level){
		return ($level<$this->level);
	}
	/**
	 * @return string do not print it
	 */
	public function getpath(){
		return ($this->islogin())?$this->userpath:"ERROR not login";
	}
  	/**
  	 * @return bool
  	 */
  	private function isenabled(){
  		return true;
  	}
  	//set not public security
	/**
	 * @return bool
	 */
	private function isReleasetime(){
		return ($this->releasetime > time());	
	}
	/**
	 * @return bool
	 */
	private function isRemoteip(){
		if($this->remoteip === $_SERVER['REMOTE_ADDR']){
			return true;
		}else{
			@session_unset();
			return false;
		}
	}
	//<<<<<<<<<<<<<<<<<<<<<<<Setters>>>>>>>>>>>>>>>>>>>>>>>>>
	/**
	 * @return void
	 */
	private function setReleasetime(){
		$this->releasetime = time() + (1 * 1 * 60 * 60);	
	}
	/**
	 * @return void
	 */
	private function setRemoteip(){
		$this->remoteip = $_SERVER['REMOTE_ADDR'];
	}
	/** 
	 * @param string $oldpwx
	 * @return 
	 */
	public function setpassword($oldpwx){
		
	}
	/**
	 * @return string
	 */
	public function __tostring(){
		return "Welkom ".$this->name."releasetime".(($this->releasetime -time() )/60)."min";
	}
	/**
	 * @return testfunction void
	 */
	private function __toprintsession(){
		print_r($_SESSION);
	}
}
?>