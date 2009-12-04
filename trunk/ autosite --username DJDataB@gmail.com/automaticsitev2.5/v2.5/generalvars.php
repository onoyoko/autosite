<?php
/**
 * copyright = a right to coppy
 * @author Lieven Roegiers
 * @copyright 2004
 * @copyright 2008 
 * @CMS autosite
 * there are many variables but a good server can do it (ent construction)
 * pre=>
 * you can update more than one site in the time
 * you can use the functiondir for many sites (only for the same server)
 */
/* function test($value,$key,$add){
	print $add." [".$key."]=>".$value."<br />";	
}
array_walk($_SERVER,"test","test één");
array_walk(preg_split('/;/', $_SERVER['PATH']),"test","test twee");
*/
$offlinedebug = true;//TODO delete before upload 1==>>>
if ($offlinedebug == true){
		//$_SERVER['PHP_SELF']="http://localhost:8080/workspacesite";//to make a projectname autosite on your easyphp
		//print $_SERVER['PHP_SELF'];
}else{//<<<==1
	if ($_SERVER['PHP_SELF']!="www.jouwdomein.be"){
		//print"ERROR NO access to this file";
		die("ERROR INVALID domein or copy this to generalvars =>".$_SERVER['PHP_SELF']);//security
	}
}
//<<<<<<<<<<<<<<<<<<<<<< general vars>>>>>>>>>>>>>>>>
if(isset($loc)){
	$loc = "./".$loc;
} else {
	$loc = "./";
}
//the folow code wil initial use js and you must make a button to ask a page with no js.(no js is more server activity)
$autosite['hasclientjs']=(!isset($_GET['js'])||$_GET['js']!="false")?true : false;
//set_include_path('/inc');
$autosite['servicenr']="BE_478394081";
$autosite['servicemail']="info@djdb.be";//your service mail
$autosite['publicmail']="info@djdb.be";//reclame and else
$autosite['servicename']="Lieven Roegiers";
$autosite['installoc']= ($offlinedebug == true)?"/automaticsitev2.1/content/":"/content/";//location from installation
$autosite['self']= $_SERVER['PHP_SELF'];//site path

$autosite['gallery']= $loc."layout2/";//all gallerys from your site and global site content
$autosite['layout'] = $loc."layout2/";//all layout from your site and global site content
 
$autosite['error'] = $loc."error/";//all error messages/pages
$autosite['functions'] = $loc."function/";//central place for all new functionalitie
$autosite['javascript'] = $loc."js/";//central place for all new functionalitie
$autosite['users'] = $loc."users/";//dir from userinfo important to //TODO rename this
$autosite['forms'] = $autosite['layout']."forms/";//
$autosite['-forms'] = $autosite['layout']."-forms/";//  
$autosite['private'] = $loc."data xml/";//
$autosite['optiepath'] = $loc.'data/';//options inc to functions
$autosite['xmlpath'] = $loc.'data xml/';//options xmldata
$autosite['path'] = $loc.'data/';//real visual data original files :original ../data/

$autosite['secpath'] = $loc.'data secret/';//real visual data and manipulated files wil make that the ftp not equals of web interface
$autosite['home'] = $loc.'data/home';//home referentie
$autosite['title'] = 'automaticsite';//titel van de site
$autosite['site'] = '.';
$autosite['site2'] = '.';
$autosite['lang']='NL';//select language (replace by call)
$autosite['standartlang']='NL';//default language
$autosite['userlang']=$_SERVER["HTTP_ACCEPT_LANGUAGE"];
$autosite['mysql']=false;
$autosite['datasource']="";
$autosite['ecommerce']['in']=false;
if($autosite['ecommerce']['in']&& $own_control_selection){//make it secure
	$autosite['ecommerce']['ogone']['login']="";
	$autosite['ecommerce']['ogone']['pwx']="";
	$autosite['ecommerce']['paypal']['login']="";
	$autosite['ecommerce']['paypal']['pwx']="";
	$autosite['echop']['Uniway']['login']="";
	$autosite['echop']['Uniway']['pwx']="";
	$autosite['echop']['tnt']['login']="";
	$autosite['echop']['tnt']['pwx']="";
	//TODO de exposanten van "e-Shop Expo" ontdekken, waaronder: 
	//Ogone, Uniway, TNT, de nieuw, Neolane, EmailVision, Teleson,
	//Zanox, Coworks, Kieskeurig, BDMV, TB, E-cires, Public-Idées,
	//Paypal, Fenego, Paysafeca, Tales, De Post, Rittz, Netmark,
	//Abo, IAB, PFS, Multisafe pay, Saferpay, Mondial Relay, Destiny, Newsmaster 
}


$autositelangname['NL']="Nederlands";
$autositelang['NL']= $autosite['path']."map_NL/";
$autositelangimg['NL']="NL.gif";
$autositebeheer['NL']=$autosite['secpath']."map_NL/";

$autositelangname['FR']="Fance";
$autositelang['FR']= $autosite['path']."map_FR/";
$autositelangimg['FR']="FR.gif";

$autositelangname['EN']="Englise";
$autositelang['EN']= $autosite['path']."map_EN/";
$autositelangimg['EN']="EN.gif";

$autosite['home'] = $autositelang[$autosite['lang']]."home";//home referentie
//Read: 001 = 1
//Write: 010 = 2
//Execute: 100 = 4
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<toolbarlocations>>>>>>>>>>>>>>>>
$option_location['Home'] = array("vieuwport.php",001,'');//homelocation
$option_location['Logout']= array("logout.php",111,'');//upload of a page
$option_location['Users']= array("uservieuwport.php",111,'');//
//$option_location['vieuw']= array("vieuwport.php",111,'');//site editor
/* actions>200 go to secvieuwport !important! security one port = one problem
*(DO NOT REMAKE IT)FOR OWN SPEEDFULE DEV BY ANY REDESIGN => CLIENTS ARE NOT CONSISTENT! 
*/
$option_location['add']= array("secvieuwport.php",333,'add.inc');//page delete 
$option_location['edit']= array("secvieuwport.php",333,'edit.inc');//site editor
$option_location['delete']= array("delete.php",333,'');//page delete
$option_location['Beheer']= array("beheer.php",999,'');//
$option_location['upload']= array("upload.php",999,'');//upload of a page
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<redirectlocations>>>>>>>>>>>>>>>>
$option2location['Login']= array("login.php",333,'');//upload of a page
$option2location['ERROR']= array("error.php",111,'');//upload of a page
$option2location['uconstruct']= array("error.php",111,'');//upload of a page
// control the system
if ($offlinedebug){
	$errors =+ (is_dir($autosite['layout'])) ? "" : "path layout: not found</br>";
	$errors =+ (is_dir($autosite['layout'])) ? "" : "path layout: not found</br>";
	$errors =+ (is_dir($autosite['users'])) ? "" : "path users: not found</br>";
	$errors =+ (is_dir($autosite['path'])) ? "" : "path data: not found</br>";
	if ($errors !=""){
		print $errors;
		die("ERROR Path not found ********GOTO generalvars******** =>".$_SERVER['PHP_SELF']);
	}
}else{//at onlinerun
	if (!is_dir($autosite['users']."/L/Login")){
		die("ERROR Delete pre instal Logins ***GOTO generalvars*** =>".$_SERVER['PHP_SELF']);//security
	}
}


?>