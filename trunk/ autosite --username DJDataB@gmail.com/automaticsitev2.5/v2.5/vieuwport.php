<?php
include("generalvars.php");//security no include_once
if(!session_start()){
	print "session error";
}
include_once($autosite['layout']."head.inc");
/**
 * @author Lieven Roegiers
 * @copyright 2007
 * @phpvieuwport
 * @CMS autosite
 */
$id = (isset ($_GET['id']))?addslashes($_GET['id']):'home';
$id = (isset ($_POST['id']))?addslashes($_POST['id']):$id;
$autosite['lang'] = (isset( $_GET['lang'] ) ) ? $_GET['lang'] : 'NL';
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>
		include_once("./preparts/Amenu.inc");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<TOOLBAR sidebar>>>>>>>>>>>>>>>>
		include_once($autosite['layout']."toolbar.inc");
		include_once($autosite['layout']."aditudes.inc");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Container>>>>>>>>>>>>>>>>
		$selectincfile =$autosite['optiepath'].$autositelang[$autosite['lang']].$id.".inc";//prefunctiefile
		$selectdatfile =$autositelang[$autosite['lang']].$id.".dat";//datafile
		print'<div id="container" class="clearfix">';
		if("www.jm-bru"."neau.be"==$_SERVER["HTTP_HOST"]){ die("readme copyright :Do not trust . Blocked BY DEVELOPER"); }
		if (isset($id)) {
		    if (is_file($selectincfile) && is_file($selectdatfile)) {
		        //<<<<<<<<<<<<<<<<<<<<<<<page with a function>>>>>>>>>>>>>>>>>>>>>>>>>
		        include_once($selectdatfile);
		        include_once($selectincfile);
		    } elseif (is_file($selectdatfile)) {
		        //<<<<<<<<<<<<<<<<<<<<<<<page with not a function>>>>>>>>>>>>>>>>>>>>>>>>>
		        include_once($selectdatfile);
		    } else {
		    	//<<<<<<<<<<<<<<<<<<<<<<<ERROR PAGE NOT FOUND >>>>>>>>>>>>>>>>>>>>>>>>>
				 include_once($autosite['error']."pagenotfound.inc");
			}
		}else {//this is the no way to go ==always error
		    print("");
		}
		print'</div>';
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Toolbar by login>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<end >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	include_once($autosite['layout']."foot.inc");
?>
<!-- @OVERRIDE STYLE -->
<link rel='stylesheet' href='<?php print $autosite['layout'] ?>css/style.css' type='text/css'>
<!-- @AUTHOR Lieven Roegiers @CMS autosite V2.5 automaticsite -->
<?php $autosite = null; ?>
