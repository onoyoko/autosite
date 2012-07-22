<?php
	class NewUser{
        private $path;
        public function NewUser($path){
            $this->path = $path;
        }
        public function make($username){
            if (strlen($username)>1){
    			  $this->creatpath();          
    		}else{
    			$users= new Users($autosite['users']);
                include_once($autosite['layout']."tooltip.inc");
                print '<link rel="stylesheet" href="'.$autosite['layout'].'css/data.css"  type="text/css" />';
                $template = (string)file_get_contents($autosite['templates']."users.Qtemplate");
    			$users->vieuwusers($get,$_SERVER['PHP_SELF']."?content=",$user,$template);
    			print  "Users => list  ".$get;
    		}	   
    			return $this->userdata;
        }
        public function creatpath($path){
            return is_dir($path)&& mkdir($path, 0644);
        }
    }
?>