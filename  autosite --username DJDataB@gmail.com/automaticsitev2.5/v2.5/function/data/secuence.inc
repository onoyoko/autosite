<?php 
class secuence{
         /**
		 * @author Lieven Roegiers
		 * @copyright 2010
		 * @CMS autosite
		 */
	private $name;
	function __construct($name){
		$this->name = name;
		session_start();
	}
	function setvars($page,$asoarr){
		$_SESSION['secuence'][$this->name][$page][$asoarr];
	}
	function getvars($page,$asoarr){
		return $_SESSION['secuence'][$this->name][$page];
	}
}
?>