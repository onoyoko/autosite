<?php
/**
 * @author Lieven Roegiers
 * @copyright 2007
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<security vieuwport>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 */
require_once("generalvars.php");
include('./generaldatavars.php');

$autosite['TranslateKeys']= array('user.name'=>"",'tools'=>"",'user.view'=>"");

include($autosite['functions']."users/User_data.inc");
include($autosite['functions']."Users.inc");
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
$handeling = (isset($_GET['handeling'])) ? addslashes($_GET['handeling']) : "Users";
$handeling = (isset($_GET['action'])) ? addslashes($_GET['action']) : "";
if ($handeling == "Users"){
	$get=(isset( $_GET['content'] ) ) ?  addslashes($_GET['content'] ) : 'A' ;
	$handeling ="";
}else{
	$get=(isset( $_GET['content'] )) ? addslashes($_GET['content'] ) : 'A' ;
}
$content = $get;
$autosite['lang']	= ( isset( $_GET['lang'] ) ) ? $_GET['lang'] : 'NL';
/*$clog->is_login_ok('',$kkey)&& isset($Gfile)||*/
$attributen="?";
$attributen.=(isset($get)) ? "content=".$get : "";
$attributen.=(isset($load)) ? "&upload=".$load : "&upload=0";

if(isset($user)&& $user->islogin()){
    $option_location['NewUser']= array($_SERVER["PHP_SELF"].$attributen."&action=newuser",999,'');//
    $option_location['EditUser']= array($_SERVER["PHP_SELF"].$attributen."&action=edituser",999,'');//
 	include_once($autosite['layout']."head.inc");
 	userlog($handeling."=>".$attributen,$user->getpath());
	//$menu2 = new Menu("Users.dat", $autosite['users'],false);//write menu 
	//include($autosite['layout']."menusettings.inc");
    $content=(strlen($get)>1)?"User ".$get:"Users =>".$get;
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>
		include_once("./preparts/Amenu.inc");
        include_once("./preparts/Atranslate.inc");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<TOOLBAR sidebar>>>>>>>>>>>>>>>>
		include_once ($autosite['layout']."toolbar.inc");
	print'<div id="container" class="clearfix"> <br /><br />';
			  $tekens = 'ABCDEFGHIJKLMNOPQRSTUWXYZ';
			  for( $i = 0; $i < strlen($tekens); $i++ ){
			  	$char = $tekens{$i};
			  	print '[<a href="'.$_SERVER["PHP_SELF"].'?content='.$tekens{$i}.'" target="_self">'.$tekens{$i}.'</a>]';
			  }
		//<<<<<<<<<<<<<<<<<<<<<<<!!!!!!!!!!!!!!!!!!!>>>>>>>>>>>>>>>>>>>>>>>>>
		print'<br /><br />';
		if (strlen($get)>1){
			print "Get User ".$get;
			$user= new User($get,$autosite['users']," ");
            include_once($autosite['layout']."tooltip.inc");
            print '<link rel="stylesheet" href="'.$autosite['layout'].'css/data.css"  type="text/css" />';
            $template = (string)file_get_contents($autosite['templates']."user.Qtemplate");
            $user->viewUserAndTranslate($template,$autosite['TranslateKeyValue']);            
		}else{
			$users= new Users($autosite['users']);
            include_once($autosite['layout']."tooltip.inc");
            print '<link rel="stylesheet" href="'.$autosite['layout'].'css/data.css"  type="text/css" />';
            $template = (string)file_get_contents($autosite['templates']."users.Qtemplate");
                  
			$users->vieuwusers($get,$_SERVER['PHP_SELF']."?content=",$user,$template,$autosite['TranslateKeyValue']);
			print  "Users => list  ccccccccccccccc".$get.print_r($autosite['TranslateKeyValue'])."xxxxxxxxxxxxx";
		}	
		if ($content > 2){
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
<!-- @AUTHOR Lieven Roegiers @CMS autosite V2.7 automaticsite -->