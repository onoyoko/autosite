<?php
/**
 * @author Lieven Roegiers
 * @copyright 2009
 * @CMS autosite
 * !important!ERROR
 * @underconstruction
 */
include($autosite['functions']."Qhtml/Qtemplate.inc");
include($autosite['functions']."Qhtml/Qhtml.inc");
include($autosite['functions']."GD/IMGmasker.inc");
class users{//
	private $userspath;
	public function __construct($userspath){
		$this->userspath = $userspath;
        
	}
	public function can_i_create(){
		
	}
	private function setlevel($user){
		
	}
	private function create($username){
	   $userpath = $this->userspath.'/'. $username;
	   if(!$this->isexist($userpath)){
		  return mkdir($userpath, 0656);
       }else{
          return false;
       }
	}
	private function isexist($user){
		return (is_dir($user));
	}
	private function deleteuser($username){
	   $userpath = $this->userspath.'/'. $username;
	   if($this->isexist($userpath)){
		  return rmdir($userpath);
       }else {
          return true;
       }
	}
	private function changepassword($oldpwx,$newpwx){
		
	}
	private function canmanipulate(){
		return true;
	}
	public function __tostring(){
		"";
	}
	public function vieuwusers($selectie,$link,$MyUserSelf,&$htmltemplate){
	   print("<-- $this->userspath$pathname-->");
		if(is_dir($this->userspath.$selectie)){
			$opendir = opendir($this->userspath.$selectie);
			$i = 0;
            print("<ul>");
            $template = new Qtemplate($htmltemplate);
    		$template->addtagitem("pic","<img class='userimg' src='%value%' />");
            //$template->translate($translatioons);
			while ($dir = readdir($opendir)) {
	    		$pos = strpos(" ".$dir, ".");
                if($pos == 0 && $dir !=''){
	        		if (is_dir($this->userspath.$selectie."/".$dir)){
	        		    $user = new User_data($dir,"777",$this->userspath);
                        $temp = clone $template;
                        $asoarr = $user->getuserdata($MyUserSelf);
                        $asoarr["i"]=++$i;
			            
                        $temp->setvalues($asoarr);
					    print($temp->gethtml());
	        		}
				}
			}
            print("</ul>");
		}else{
			print("<!--userspath not ready-->[ERROR]");
		}
	}
}
?>