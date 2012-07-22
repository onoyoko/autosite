<?php
/**
 * @author Lieven Roegiers
 * @copyright 2006
 * @CMS autosite
 */
include("generalvars.php");
include('./generaldatavars.php');
$username =(isset($_POST['username']))? addslashes($_POST['username']) : null;
$pass=(isset($_POST['password']))? addslashes($_POST['password']) : null;
$kkey=(isset($_POST['key']))? addslashes($_POST['key']) : null;
$content=(isset($_GET['content']))?addslashes($_GET['content']):'home';
$content=(isset($_POST['content']))?addslashes($_POST['content']):$content;
$autosite['lang'] =(isset($_GET['lang']))? $_GET['lang'] : 'NL';
$load =(isset($_GET['upload']))? addslashes($_GET['upload']) : 0;
$handeling = (isset($_POST['handeling'])) ? addslashes($_POST['handeling']) : "Home";
include($autosite['functions']."interfaces/tosave.inc");
include($autosite['functions']."data/csv_plus.inc");
include($autosite['functions']."users/User_data.inc");
include($autosite['functions']."util/istime.inc");
include($autosite['functions']."util/hash.inc");
include($autosite['functions']."users/User.inc");
$csvfile = new csv_plus($autosite['users'],"KKey.dat",time()+60);//time() + (24 * 60 * 60);24 hours; 60 mins; 60secs
$Sessionid =0;
$user= new User($username,$kkey,$autosite['users'],$Sessionid);
//$user->setUser($username,$autosite['users'],$kkey);
$attributen="?";
$attributen.=(isset($content)) ? "content=".$content : "";
$attributen.=(isset($load)) ? "&upload=".$load : "&upload=0";
$attributen.=(isset($load)) ? "&lang=".$autosite['lang'] : "&upload=0";
$formsdata['login']['items']=array("username"=>"","password"=>"","login!2"=>"");
$formsdata['login']['tovalid']=array("name");
$formsdata['login']['loginniveau']=0;
if(isset($kkey)&& $kkey!=""){
	include($autosite['functions']."util/redirector.inc");
	//||islogin()
	$resline = $csvfile->find_line($kkey);
	$istime = new istime();
	if($kkey==$resline[2]&&$istime->is_notpasse($resline[0])){
		if($user->login($pass,$resline[2],$resline[3])){//login ok
            session_start();
		     $csvingelogd = new csv_plus($autosite['users'],"ILOG.dat");
		     $data = array($kkey,$user,"L0G1N",$_SERVER['REMOTE_ADDR']);
			 $csvingelogd->save_line($data);
			 $attributen.=(isset($kkey)) ? "&key=".$kkey : "";//<<<<<<<<<<<<<<<<<<
			 /*for object saving in a session*/
			 $_SESSION['user']=serialize($user);
			 redirect($autosite['installoc'].$option_location[$handeling][0]."".$attributen);
			 die("ingeloged");	 
		}
	}//not login or pasword
	redirect($autosite['installoc'].$option2location['Login'][0]."".$attributen);
	die("not login"); //security
	//$data = array("p",time()+(1 * 1 * 60 * 60),$kkey,$user,$pass,$ecript,"test");
	//$csvfile->save_line($data);//TODO generalvars
}else {
	$cripty = funrandencript();
	$kkey =$user->getkkey();
	$user = null;
 	$data = array("pre",$kkey,$cripty,"ERROR",$_SERVER['REMOTE_ADDR']);
 	$csvfile->save_line($data);
	include_once($autosite['layout']."head.inc");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>
	include_once("./preparts/Amenu.inc");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<TOOLBAR sidebar>>>>>>>>>>>>>>>>
	//include_once ($autosite['layout']."toolbar.inc");
	include_once ($autosite['layout']."aditudes.inc");
	//$formname=$id;
	print "<script type='text/javascript' src='".$autosite['javascript']."webtoolkit.".$cripty.".js'></script>";
			print'<div id="container">';
			include_once($autosite['functions']."Qhtml/Qvieuw.inc");
			include_once($autosite['functions']."data/properties.inc");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<take the template >>>>>>>>>>>>>>>>
			$string = (string)file_get_contents($autosite['-forms']."login.Qform");
			$template = new Qtemplate($string);
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<take the properties >>>>>>>>>>>>>>>>
			if(isexist_propertiefile($autosite['translations'],$autosite['lang'],"forms")){
				print"<!-- @LANGlocale:".$autosite['lang']." IS used -->";
				$properties = new properties($autosite['translations'],"_".$autosite['lang'],"forms");
			}else{
				print"<!-- @LANGlocale:".$autosite['lang']." IS NOT EXIST -->";
				$properties = new properties($autosite['translations'],"","forms");
			}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<take the properties >>>>>>>>>>>>>>>>			
			$formfields = $formsdata['login']['items'];
			$template->translate($properties->getproperties($formsdata['login']['items']));
			$formtemplate = $template->gethtml();
			$formtemplate .= "<input type='hidden' name='handeling' value='$handeling' />";
			$formtemplate .= "<input type='hidden' name='upload' value='$load' />";
			$formtemplate .= "<input type='hidden' name='key' id='Key' value='$kkey' />";
			include($autosite['layout']."form.inc");
			print'</div>';
		 ?>

    <script type="text/javascript">
		var returntext;   
		function login(parpwx){<?php //TODO replace  ?>
	  		var User = document.getElementById("User");
	  		var Key = document.getElementById("Key");
	  		var Password = document.getElementById("Password");
	  		Password.value =<?php print"$cripty"; ?>(Key.value+Password.value);
	  		if( User != "" && Password != "" ){
	  			document.forms[0].submit();
	  		} else { 
		  		alert( "Er is geen gebruikersnaam en/of wachtwoord ingevoerd!" );
			}
			return Password.value;
		}
	</script> 
<?php } include_once ($autosite['layout']."foot.inc");
 ?>

	       
<!-- @OVERRIDE STYLE -->
<link rel='stylesheet' href='<?php print$autosite['layout']?>css/style.css' type='text/css'/>
<!-- @AUTHOR Lieven Roegiers @CMS autosite V2.5 automaticsite -->
