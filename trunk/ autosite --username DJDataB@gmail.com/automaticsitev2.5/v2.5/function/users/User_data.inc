<?php
class User_data{
	private $userdata;
	 /**
	 * @author Lieven Roegiers
	 * @copyright 2007
	 * @CMS autosite
	 *-->UNDER construction
	 */
	private $encripty;
	private $kkey;
	private $hasguestbook = false;
	private $hasuserimg = false;
	private $haspublicvieuw = false;
	private $has = false;
	public function __construct($username,$kkey){
		$this->kkey = (isset($kkey)&& $kkey!="")? $kkey:$this->generatekey(10);
	}
	function getkkey(){
  		return $this->kkey;
  	}  	
	private function generatekey($lengte){
			/**
			* @author By eprogrammeur
			*/
		  srand(((double) microtime() ) * 1000000 );$string = '';
// De parser doet irri met zoveel tekens zonder spaties achter elkaar, verdeeld  over meerdere regels
		  $tekens = 'abcdefghijklmnopqrstuvwxyz';
		  $tekens .= 'ABCDEFGHIJKLMNOPQRSTUWXYZ';
		  $tekens .= '01234567890123456789';
		  for( $i = 0; $i < $lengte; $i++ )
		  {  
		  	$string .= $tekens{ rand( 0, ( strlen( $tekens ) - 1 ) ) };
		  }
		  return $string;
	}
	function getuserdata($name){
		/*if(isset($userdata)){
			return $userdata[$name];
		}*/
    }
    function setuserdata($name){
    	//$this->userdata[$name];
    }
    /**
     * @param $username name of user
     * Not session but hard database or 
     **/
    function saveuserdata($username){
    	//TODO generate stuf
    }
   /**
    * @param $username name of user
    * Not session but hard database or 
    **/
    function openuserdata($username){
    	//TODO generate stuf
    	//$userdata[userpath] =$path.substr($username, 0, 1)."/".$username."/";
    	//$userdata[isuser]=(is_dir($this->userpath)&& $username!="")? true:false;
    	//if ($this->isuser)include $this->userpath."data.php";
    }
    private function __printuserdata(){//DEBUG !!!not secure!!!
    	//print_r($userdata);
    }
    
    function getguestbook(){
    	//TODO generate stuf
    }
    private function isguestbook(){
    	return $this->hasguestbook;//TODO generate stuf 
    }
    
    public function getuserimg(){//!!!security!!! return only the data of the img include("imagename.gif");
  		if($this->cansetuser()){
    		return "data:";//TODO generate stuf
    	}
    	//return ;//TODO generate stuf
    }
    private function isuserimg(){
    	return ;//TODO generate stuf
    }
    
    
    function setnewuser(){
    	if($this->cansetuser()){
    		//TODO generate stuf
    	}
    }
    private function cansetnewuser(){//!!!security!!! set not higher level of current user level
    	return false;//TODO generate stuf
    }
    
    
    private function getpublicvieuw(){
    	if($this->ispublicvieuw()){
    		//TODO generate stuf
    	}
    }
    private function ispublicvieuw(){
		return false;//TODO generate stuf
    }

	function getuserdata($name){
		/*if(isset($userdata)){
			return $userdata[$name];
		}*/
    }
    function setuserdata($name){
    	//$this->userdata[$name];
    }
    /**
     * @param $username name of user
     * Not session but hard database or 
     **/
    function saveuserdata($username){
    	//TODO generate stuf
    }
   /**
    * @param $username name of user
    * Not session but hard database or 
    **/
    function openuserdata($username){
    	//TODO generate stuf
    	//$userdata[userpath] =$path.substr($username, 0, 1)."/".$username."/";
    	//$userdata[isuser]=(is_dir($this->userpath)&& $username!="")? true:false;
    	//if ($this->isuser)include $this->userpath."data.php";
    }
    private function __printuserdata(){//DEBUG !!!not secure!!!
    	//print_r($userdata);
    }
    function getguestbook(){
    	//TODO generate stuf
    }
    private function isguestbook(){
    	//TODO generate stuf
    }
    public function getuserimg(){//!!!security!!! return only the data of the img include("imagename.gif");
    	//return ;//TODO generate stuf
    }
    private function isuserimg(){
    	//TODO generate stuf
    }
    function setnewuser(){
    	if($this->cansetuser()){
    		//TODO generate stuf
    	}
    }
    private function cansetnewuser(){
    	return false;//TODO generate stuf
    }
    private function getpublicvieuw(){
    	if($this->cansetuser()){
    		//TODO generate stuf
    	}
    }
    private function ispublicvieuw(){
		return false;//TODO generate stuf
    }
}
?>