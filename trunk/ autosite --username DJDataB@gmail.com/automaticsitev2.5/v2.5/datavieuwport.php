<?php
	if(!session_start()){
		print "session error";
	}
	include('./generalvars.php');
	include('./generaldatavars.php');
	include($autosite['functions'].'data.inc');
	$formname=(isset($_GET['id']))?addslashes($_GET['id']):'djs';
	$formname=(isset($_POST['id']))?addslashes($_POST['id']):$formname;
	$autosite['lang'] = (isset( $_GET['lang'] ) ) ? $_GET['lang'] : 'NL';
	$steplen = (isset ($_POST['steplen']))?addslashes($_POST['steplen']):10;//staplengte split in
	//$step = (isset ($_POST['step']))//stap
	$DS_filename = "./".$autosite['path']."databaseconection_ymlds2.xml";
	$Errmsg['NL']['empty']="Het %errkey% veld werd niet ingevuld";
	$Errmsg['NL']['fatal']="geen juiste data/Form doorgestuurd kijk form velden na!";
	$datatosave = $_POST;
	$datatosave["date"] = date("l j F Y");
	if(is_file($autosite['forms'].$formname.".vars")){
		include($autosite['forms'].$formname.".vars");//print_r($formsdata[$formname]);
	}
	include($autosite['functions']."users/User_data.inc");
	include($autosite['functions']."users/User.inc");
	session_start();
	$user= getsessionuser();
	$formlevel = isset($formsdata[$formname]['loginniveau'])?$formsdata[$formname]['loginniveau']:1;
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SAVE DATA       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<(public vieuw |or| permited vieuw)>>>>>>>>>>>>>>>>
	
	if ($formlevel<100 ||(isset($user)&& $user->islogin()&& $formlevel<$user->getlevel())){	
		if (isset($_POST['action']) && $_POST['action'] == 'submitted'){
				try{
					//<<<<<<<<<<<<<<<<<<<<<<<<<<<<fileupload>>>>>>>>>>>>>>>>
					addfilesatlink($datatosave);
					$opslagruimte = new data($formsdata[$formname]);
					$opslagruimte->setvalidationmsg($Errmsg['NL']);
					//$opslagruimte->initdatabase($DS_filename,DB_source::DEVELOPMENT);
					//$opslagruimte->initdatabase($DS_filename,DB_source::TEST);
					//$opslagruimte->initdatabase($DS_filename,DB_source::PRODUCTION);
					$opslagruimte->initfile($autosite['private']);
					print $opslagruimte->save_line($datatosave,0,true);
				}catch(Exception $e){
					//print_r($e);
					//print $e->getMessage();
					//array_merge(array("Form"=>"FORMname:".$formname),)
					//print($autosite['private']);
				}
		}
	}else{
			$_errors.="ERROR EN: NO PERMITION TO THIS FUNCTION";
	}
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<    VIEUW DATA      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<(public vieuw |or| permited vieuw)>>>>>>>>>>>>>>>>
	$vieuwas = (isset( $_GET['vieuwas'] ) ) ? $_GET['vieuwas'] : 'gallery';
	if ($formsdata[$formname]['vieuw']= true ||(isset($user)&& $user->islogin()&& $formlevel<$user->getlevel())){
		include_once($autosite['layout']."head.inc");
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>
			include_once("./preparts/Amenu.inc");
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<TOOLBAR sidebar>>>>>>>>>>>>>>>>
			include_once ($autosite['layout']."toolbar.inc");
			include_once ($autosite['layout']."aditudes.inc");
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Container>>>>>>>>>>>>>>>>
	print'<div id="container" class="clearfix">';
	
		include_once($autosite['functions']."Qhtml/Qvieuw.inc");
		include_once($autosite['functions']."data/properties.inc");
				switch ($vieuwas){
						case "formanddata":
							include_once("./preparts/data_form.inc");
							include_once("./preparts/data_templatevieuw.inc");
							
							break;
						case "gallery":
							include_once("./preparts/data_gallery.inc");
							break;
						case "table":
							break;
						default:
							include_once("./preparts/data_templatevieuw.inc");
				}
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<end >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	print'</div>';
			include_once ($autosite['layout']."foot.inc");
	}
?>
<!-- @OVERRIDE STYLE -->
<link rel='stylesheet' href='<?php print $autosite['layout'];?>css/style.css'  type='text/css' />
<!-- @AUTHOR Lieven Roegiers @CMS autosite V2.5 automaticsite -->