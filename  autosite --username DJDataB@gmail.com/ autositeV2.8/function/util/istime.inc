<?php
/**
* @author Lieven Roegiers
* @copyright 2007
*/
class istime{
	/**
	 *@param $timestamp;
	 *@return true/false;
	 */
	function is_notpasse($stamp){
		return (time() < $stamp);
	}
	/**
    *@param $date dmY;
	*@return true/false;
    */
	function id_datepasse($date){
 		$now = date("dmY");
		return(substr($date, 4, 2)>= substr($now, 4, 2))&& (substr($date, 2, 2)>= substr($now, 2, 2))&& (substr($date, 0, 2)>= substr($now, 0, 2));
	}
}

?>