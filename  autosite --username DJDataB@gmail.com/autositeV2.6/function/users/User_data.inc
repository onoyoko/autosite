<?php	

class User_data{
	private $userdata;
	 /**
	 * @author Lieven Roegiers
	 * @copyright 2007
	 * @CMS autosite
	 *-->UNDER construction
	 */
    private $path;
	private $encripty;
	private $kkey;
	private $hasguestbook = false;
	private $hasuserimg = false;
	private $haspublicvieuw = false;
	private $has = false;
	public function __construct($username,$kkey,$path){
	    $this->path=$path;
	    $this->userdata['name']=$username;
        $this->setuserpath($path);
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
		  for( $i = 0; $i < $lengte; $i++ ){  
		  	$string .= $tekens{ rand( 0, ( strlen( $tekens ) - 1 ) ) };
		  }
		  return $string;
	}
     function getdata(){
            $this->initdata(777);	
			return $this->userdata;
    }
	public function getuserdata($user){
            $this->initdata($user->getlevel());	
			return $this->userdata;
    }
    private function initdata($level){
        switch ($level){
            
        	case 100:
            break;   
        	default :
            $this->userdata['pic']=$this->getuserimg();
            $this->userdata['guestbook']=$this->getguestbook();
            break;
        }
    }
    /**
     * @param $username name of user
     * Not session but hard database or 
     **/
    function saveuserdata(){
    	//TODO generate stuf
    }
    private function setuserpath($path){
        $this->userdata['path']=$path.substr($this->userdata['name'], 0, 1)."/".$this->userdata['name']."/";  	 
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
    	print_r($userdata);
    }
    /**
	 * @return string
	 */
    function getguestbook(){
    	return "here comes the guestbook";
    }
    private function isguestbook(){
    	return $this->hasguestbook;//TODO generate stuf 
    }
    public function getuserimg(){//!!!security!!! return only the data of the img include("imagename.gif");
  		if($this->isuserimg($imgname)){
  		    $img = new IMGmasker();
    		return $img->__getimg($this->userdata['path'],$this->userdata['name'].".jpg");//TODO generate stuf
    	}else{
    	   print "img nog avalable";
    	}
    	//return ;//TODO generate stuf
    }
    private function isuserimg($imagename){
    	return is_dir($this->userdata['path'])&& is_file($this->userdata['path'].$this->userdata['name'].".jpg");//TODO generate stuf
    }
    
    function setnewuser(){
    	if($this->cansetuser()){
    		//TODO generate stuf
    	}
    }
    private function cansetnewuser(){//!!!security!!! set not higher level of current user level
    	return false;//TODO generate stuf
    }
    function getAvatar(){
    	return "here comes the avatar";
    }
    
    private function getpublicvieuw(){
    	if($this->ispublicvieuw()){
    		//TODO generate stuf
    	}
    }
    private function ispublicvieuw(){
		return false;//TODO generate stuf
    }
}
?>