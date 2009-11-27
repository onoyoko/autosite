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
function userlog($info,$path="./",$file="log.log"){
		$csvingelogd = new csv_plus($path,$file);
		$array = array((string)time(),$info);
    	$csvingelogd->save_line($array);
}
/*for object saving in a session*/
session_start();
$user=(isset($_SESSION['user']))?unserialize($_SESSION['user']):null;
$selection=(isset( $_GET['id'] ) ) ? addslashes($_GET['id'] ) : '' ;									
$handeling = (isset($_GET['handeling'])) ? addslashes($_GET['handeling']) : "beheer";
$autosite['lang']	= ( isset( $_GET['lang'] ) ) ? $_GET['lang'] : 'NL';
/*$clog->is_login_ok('',$kkey)&& isset($Gfile)||*/
$attributen="?";
$attributen.=(isset($selection)) ? "id=".$selection : "";
$attributen.=(isset($load)) ? "&upload=".$load : "&upload=0";
//<<<<<<<<<<<<<<<<<<<<<<<!!!!!!!!!!!!!!!!!!!>>>>>>>>>>>>>>>>>>>>>>>>>
if(isset($user)&& $user->islogin()){
 	include_once($autosite['layout']."head.inc");
 	userlog($handeling."=>".$Gfile,$user->getpath());
	//$menu2 = new Menu("Users.dat", $autosite['users'],false);//write menu 
	//include($autosite['layout']."menusettings.inc");
	include_once($autosite['layout']."head.inc");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>
		include_once("./preparts/Amenu.inc");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<TOOLBAR sidebar>>>>>>>>>>>>>>>>
		include_once ($autosite['layout']."toolbar.inc");
	print'<div id="container">';
	if ($selection){
		include_once ($autosite['users'].".dat");
	}else {
	    include_once ($autosite['home'].".dat");
	}
	print'</div>';
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Toolbar by login>>>>>>>>>>>>>>>>>>>
	include_once ($autosite['layout']."toolbar.inc");
    //include_once ($autosite['users']."toolbar.inc");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<end >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	include_once ($autosite['layout']."foot.inc");
}else{
	redirect($autosite['installoc'].$option2location['Login'][0].$attributen);
}
?>
<!-- @OVERRIDE STYLE -->
<link rel='stylesheet' href='<?php print $autosite['layout'] ?>css/style.css' type='text/css' />
<!-- @AUTHOR Lieven Roegiers @CMS autosite V2.1 automaticsite -->


