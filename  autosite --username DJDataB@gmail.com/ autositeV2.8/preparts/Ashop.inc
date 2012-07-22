<?php
	    function setsessionshopcard($card){
	   $_SESSION['shop']['card']=serialize($card);
    }
    function getsessionshopcard(){
	   return(isset($_SESSION['shop'])&&isset($_SESSION['shop']['card']))?unserialize($_SESSION['shop']['card']):null;
    }
?>