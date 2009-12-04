<?php
	if(!session_start()){
		print "session error";
	}
	include('./generalvars.php');
	include('./generaldatavars.php');
	include($autosite['functions'].'data.inc');
	include($autosite['functions'].'upload.inc');
	$formname=(isset($_GET['id']))?addslashes($_GET['id']):'djs';
	$formname=(isset($_POST['id']))?addslashes($_POST['id']):$formname;
	$autosite['lang'] = (isset( $_GET['lang'] ) ) ? $_GET['lang'] : 'NL';
	$steplen = (isset ($_POST['steplen']))?addslashes($_POST['steplen']):10;//staplengte split in
	$step = (isset ($_POST['step']))?addslashes($_POST['step']):1;//stap
	$DS_filename = "./".$autosite['path']."databaseconection_ymlds2.xml";
	$Errmsg['NL']['empty']="Het %errkey% veld werd niet ingevuld";
	$Errmsg['NL']['fatal']="geen juiste data/Form doorgestuurd kijk form velden na!";
	$datatosave = $_POST;
	$datatosave["date"] = date("l j F Y");
	if(is_file($autosite['forms'].$formname.".vars")){
		include($autosite['forms'].$formname.".vars");//print_r($formsdata[$formname]);
	}
	if (isset($_POST['action']) && $_POST['action'] == 'submitted'){
		print'<div id="container">';
		//print("opslagruimte");
		print("<pre>");
		//print_r($autosite);
		//	print_r($formsdata[$formname]);
		print("</pre>");
			$uploader = new upload($_FILES,$formsdata[$formname],$autosite['trueext'],$autosite['uploads'].$formname."/");
			print_r($uploader->getlinks());
			//$uploadlinks = $uploader->getlinks();
			//array_merge($datatosave,$uploadlinks);		
		try{
			$opslagruimte = new data($formsdata[$formname]);
			$opslagruimte->setvalidationmsg($Errmsg['NL']);
			//$opslagruimte->initdatabase($DS_filename,DB_source::DEVELOPMENT);
			//$opslagruimte->initdatabase($DS_filename,DB_source::TEST);
			//$opslagruimte->initdatabase($DS_filename,DB_source::PRODUCTION);
			$opslagruimte->initfile($autosite['private']);
			print $opslagruimte->save_line($datatosave,0,true);
		}catch(Exception $e){
			print_r($e);
			//print $e->getMessage();
			//array_merge(array("Form"=>"FORMname:".$formname),)
		}
		print($autosite['private']);
		print'</div>';
	}elseif(isset($_GET['form']) && $_POST['form'] == 'submitted'){
	}else{
		include_once($autosite['layout']."head.inc");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>
		include_once("./preparts/Amenu.inc");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<TOOLBAR sidebar>>>>>>>>>>>>>>>>
		include_once ($autosite['layout']."toolbar.inc");
		include_once ($autosite['layout']."aditudes.inc");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Container>>>>>>>>>>>>>>>>
		switch ($vieuwas){
				case "formanddata":
					include_once("./preparts/data_formanddata.inc");
					break;
				case "gallery":
					break;
				case "table":
					break;
				default :
					include_once("./preparts/data_formanddata.inc");
		}	
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<end >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			include_once ($autosite['layout']."foot.inc");
	}
?>
<!-- @OVERRIDE STYLE -->
<link rel='stylesheet' href='<?php print $autosite['layout'];?>css/style.css'  type='text/css' />
<!-- @AUTHOR Lieven Roegiers @CMS autosite V2.5 automaticsite -->