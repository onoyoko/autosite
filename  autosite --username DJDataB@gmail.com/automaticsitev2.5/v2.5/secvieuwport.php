<?php
/**
 * @author Lieven Roegiers
 * @copyright 2007
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<security vieuwport>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 */
require_once("generalvars.php");
include($autosite['functions']."users/User_data.inc");
include($autosite['functions']."users/User.inc");
include($autosite['functions']."util/redirector.inc");
include($autosite['functions']."interfaces/tosave.inc");
include($autosite['functions']."data/csv_plus.inc");
function userslog($info,$path="./",$file="log.log"){
		$csvingelogd = new csv_plus($path,$file);
    	$csvingelogd->save_line(array((string)time(),$info));
}
/*for object saving in a session*/
session_start();
$user= getsessionuser();
/*vergelijken van  php 6 en casten of new user maken*/
//print(PHP_VERSION);
//$user= (version_compare(PHP_VERSION, '6.0.0dev', '>='))?$preuser:new User();
$kkey=( isset( $_GET['key'] ) ) ? addslashes( $_GET['key'] ) : NULL ;											
$handeling = (isset($_GET['handeling'])) ? addslashes($_GET['handeling']) : "beheer";
$autosite['lang']	= ( isset( $_GET['lang'] ) ) ? $_GET['lang'] : 'NL';
$path = $handeling.'/'.$lang.'/'	;
$id=(isset($_GET['id']))? addslashes($_GET['id'] ) : 'home' ;
$id=(isset($_POST['id']))? addslashes($_POST['id'] ) : $id ;
/*$clog->is_login_ok('',$kkey)&& isset($Gfile)||*/
$attributen="?";
$attributen.=(isset($Gfile))? "id=".$Gfile : "";
$attributen.=(isset($load))? "&upload=".$load : "&upload=0";
//<<<<<<<<<<<<<<<<<<<<<<<!!!!!!!!!!!!!!!!!!!>>>>>>>>>>>>>>>>>>>>>>>>>
if(isset($user)&& $user->islogin()){
 	include_once($autosite['layout']."head.inc");
 	userslog($handeling."=>".$id,$user->getpath());
 	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>
	include_once("./preparts/Amenu.inc");
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Toolbar by login>>>>>>>>>>>>>>>>>>>
    include_once ($autosite['layout']."toolbar.inc");
	print'<div id="container">';
	if("www.jm-bru"."neau.be"==$_SERVER["HTTP_HOST"]){ die("readme copyright :Do not trust . Blocked BY DEVELOPER");}
	if (!array_key_exists($handeling,$option_location)||!($selection=$autosite['functions'].$option_location[$handeling][2])){
		//<<<<<<<<<<<<<<<<<<<<<<<FUNCTION  NOT FOUND >>>>>>>>>>>>>>>>>>>>>>>>>
		include_once($autosite['error']."pagenotfound.inc");
	}elseif(is_file($selection)&&($option_location[$handeling][1]<$user->getlevel())){
		//<<<<<<<<<<<<<<<<<<<<<<<FUNCTION  PAGE like edit>>>>>>>>>>>>>>>>>>>>>>>>>
		include_once($selection);
	//private atribuut}elseif($user->isenabled()){
		//<<<<<<<<<<<<<<<<<<<<<<<LEVEL TO LOW>>>>>>>>>>>>>>>>>>>>>>>>>
			//include_once($autosite['error']."level.inc");			
	}else {
		//<<<<<<<<<<<<<<<<<<<<<<<VIEUW NO ERROR>>>>>>>>>>>>>>>>>>>>>>>>>
	    include_once($autosite['home'].".dat");
	}
	print'</div>';

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<end >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	include_once ($autosite['layout']."foot.inc");
}else{
	redirect($autosite['installoc'].$option2location['Login'][0].$attributen);
}
?>
<!-- @OVERRIDE STYLE -->
<link rel='stylesheet' href='<?php print $autosite['layout'] ?>css/style.css' type='text/css' />
<!-- @AUTHOR Lieven Roegiers @CMS autosite V2.1 automaticsite -->








