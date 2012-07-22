<?php
/**
 * @author Lieven Roegiers
 * @copyright 2009
 * @CMS autosite
 */
class toolbar{
	private $level;
	private $locations;
	private $att;
	public function __construct(&$locations){
		$this->locations=$locations;
	}
	public function setuserlevel($level){
		$this->level=$level;
	}
	public function setatributen($att){
		$this->att=$att;
	}
	public function printtoolbar($att,$level,$link="secvieuwport.php"){
		foreach ($this->locations as $key => $value){
			if($value[1]<$level){
				if($value[1]>200){//go to secvieuwport
					//$att .= "handeling=".$value[2];
					$this->printitem($key,$value[0],$att);
				}else{
					$this->printitem($key,$value[0],$att);
				}
				
			}else {
				print"<a class='functie'>$key*</a><br />";
			}
		}
	}
	private function printitem($name,$link,$att){
		print"<a class='functie $name' href='".$link."?handeling=$name".$att."'>$name</a><br />";
	}	
}
