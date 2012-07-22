<?php
/**
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

		//$_SERVER['PHP_SELF']="http://localhost:8080/workspacesite";//to make a projectname autosite on your easyphp
		//print $_SERVER['PHP_SELF'];

	if ($_SERVER["HTTP_HOST"]!="www.jouwdomein.be"&&$_SERVER["HTTP_HOST"]!="localhost"){
		//print"ERROR NO access to this file";
		die("ERROR INVALID domein or copy this to generalvars =>".$_SERVER["PHP_SELF"]);//security
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
$autosite['servicename']="Your name";
$autosite['installoc']= "/myhome/automaticsitev2.6/v2.7/";//location from installation
$autosite['self']= $_SERVER['PHP_SELF'];//site path
$autosite['version']='2.7';

$autosite['gallery']= $loc."layout2/";//all gallerys from your site and global site content
$autosite['layout'] = $loc."layout2/";//all layout from your site and global site content
$autosite['webeditor']['pages'] = $loc."layout2/editor/";//all layout from your site and global site content
$autosite['preparts'] = $loc."preparts/";//all layout from your site and global site content 
$autosite['error'] = $loc."error/";//all error messages/pages
$autosite['functions'] = $loc."function/";//central place for all new functionalitie
function __autoload($class){
    require_once($autosite['functions'].$class.'.php');//ERROR1 lib/ bestand stond in root
}
$autosite['javascript'] = $loc."js/";//central place for all new functionalitie
$autosite['KEYWORDS']= array("autosite","dynamic site","cms");
/**
*to enterprised application can you also use a http://www.aplicationserver.be/yourscript?prevar=more&
*to enterprised application can you also use a http://255.255.255.255:80/yourscript?prevar=more&
*when you not remake it your data is save here you must make the same output of the file.
*ALERT you must make your firewall save for other users by ip that other users can not take the pasword
*ALERT bij next release you must output true or false by giving the pasword.i think that we make it also as that you must make a key for encription
* first we ask a key and we hash with them it make that we have always an new 
*/
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
$autosite['translations'] =$autosite['layout']."translations/";//translations
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
// error handler function

function myHandler($errno, $errstr, $errfile, $errline){
    $_errors="</div><div id='ERROR' class='ERROR'>";//$autosite['servicemail']."";
    switch ($errno) {
    case E_USER_ERROR:
        $_errors.= "<b>ERROR</b> [$errno] $errstr ERROR at $errline =>&gt; $errfile".",[PHP]".PHP_VERSION."(".PHP_OS.")<br />\n";
        //echo "Aborting...<br />\n";
        //exit(1);
        break;
    case E_USER_WARNING:
        $_errors.= "<b>WARNING</b> [$errno] $errstr at $errline =>&gt; $errfile".",[PHP]".PHP_VERSION."(".PHP_OS.")<br />\n";
        break;
    case E_USER_NOTICE:
    case E_NOTICE:
        $_errors.= "<b>NOTICE</b> [$errno] $errstr at $errline =>&gt; $errfile".",[PHP]".PHP_VERSION."(".PHP_OS.")<br />\n";
        break;
    default:
        $_errors .= "Unknown error type: [$errno] $errstr<br />\n";
        break;
    }
    $_errors .= "</div>\n";
    echo $_errors;
    /* Don't execute PHP internal error handler */
    return true;
}
//set_error_handler("myHandler");



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

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>general translations>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//$autosite['translations']= array("home","login");
$autosite['home'] = $autositelang[$autosite['lang']]."home";//home referentie
////////////////////////////////////////<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<TODO !!!!!>>>>>>>>>>>>>>>>>>>>>>
$autositepath=$autositelang[$autosite['lang']];
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

$linkbanners=$autosite['layout']."img/aditionals/";
$linkextern['left'][0]= array("http://www.freewebstuff.be","freewebstuff",'freewebstuff.gif');
$linkextern['left'][2]= array("http://www.search-belgium.com/","search-belgium",'BelgaSearch_animbadge.gif');
$linkextern['left'][5]= array("http://www.ogone.com/","ogone",'');
$linkextern['left'][6]= array("http://www.google.be/","google",'nav_logo7.png');
$linkextern['left'][7]= array("http://php.net/","php",'php.gif');
$linkextern['left'][9]= array("http://qa.php.net/","PHPCORE",'php_qa.jpg');
$linkextern['right'][10]= array("error.php",111,'');//upload of a page

// control the system
if ($offlinedebug){
	$errors =+ (is_dir($autosite['layout'])) ? "" : "path layout: not found</br>";
	$errors =+ (is_dir($autosite['layout'])) ? "" : "path layout: not found</br>";
	$errors =+ (is_dir($autosite['users'])) ? "" : "path users: not found</br>";
	$errors =+ (is_dir($autosite['path'])) ? "" : "path data: not found</br>";
	if ($errors !=""){
		print $errors;
		die("ERROR Path not found ********GOTO generalvars******** =>".$_SERVER['PHP_SELF']."==>".$autosite['path']);
	}
}else{//at onlinerun
	if (!is_dir($autosite['users']."/L/Login")){
		die("ERROR Delete pre instal Logins ***GOTO generalvars*** =>".$_SERVER['PHP_SELF']."{youruserpath}/L/Login");//security
	}
}
?>