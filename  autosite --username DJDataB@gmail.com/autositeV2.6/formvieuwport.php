<?php
	if(!session_start()){
		print "session error";
	}
	include('./generalvars.php');
	include('./generaldatavars.php');
	include($autosite['functions'].'data.inc');
	$formname=(isset($_GET['content']))?addslashes($_GET['content']):'';
	$formname=(isset($_POST['content']))?addslashes($_POST['content']):$formname;
	$autosite['lang'] = (isset( $_GET['lang'] ) ) ? $_GET['lang'] : 'NL';
	$step = (isset($_GET['step']))?addslashes($_GET['step']):0;//staplengte split in         
	$steplen = (isset($_GET['steplen']))?addslashes($_GET['steplen']):25;//staplengte split in
	//$step = (isset ($_POST['step']))//stap
	$DS_filename = "./".$autosite['path']."databaseconection_ymlds2.xml";
	$Errmsg['NL']['empty']="Het %errkey% veld werd niet ingevuld";
	$Errmsg['NL']['fatal']="geen juiste data/Form doorgestuurd kijk form velden na!";
	$datatosave = $_POST;
	//print_r($_POST);
	//print_r($_FILES);
	$datatosave["date"] = date("l j F Y");
	if(is_file($autosite['forms'].$formname.".vars")){
		include($autosite['forms'].$formname.".vars");//print_r($formsdata[$formname]);
	}
    $isdata= is_file($autosite['private'].$formsdata[$formname]['name'].".csv");
	$content = "".$formname;
	include($autosite['functions']."users/User_data.inc");
	include($autosite['functions']."users/User.inc");
	session_start();
	$user= getsessionuser();
	$formlevel = isset($formsdata[$formname]['loginniveau'])?$formsdata[$formname]['loginniveau']:1;
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<    SAVE DATA       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<(public vieuw |or| permited vieuw)>>>>>>>>>>>>>>>>
	//$_errors.= "to:".$formname."<br />id:".$_POST['id']."<br />formlevel:".$formlevel."<br />userlogin".((isset($user))?$user->islogin():"0")."<br />levels:formlevel(".$formlevel."&lt ".((isset($user))?$user->getlevel():"0").")userlevel<br />";
	if ($formlevel<101 ||(isset($user)&& $user->islogin()&& $user->ispermitlevel($formlevel))){
		//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<use only post>>>>>>>>>>>>>>>>>>>>>
		//$_errors.= "LOGIN OR FORMLEVEL FREE<br />";
		if(isset($_POST['action']) && $_POST['action'] == 'submitted'){
				try{//<<<<<<<<<<<<<<<<<<<<<<<<<<<<fileupload>>>>>>>>>>>>>>>>
				    addfilesatlink($datatosave,$autosite['uploads'].$formname."/",$formsdata[$formname]);
					$opslagruimte = new data($formsdata[$formname]);
					$opslagruimte->setvalidationmsg($Errmsg['NL']);
					//$opslagruimte->initdatabase($DS_filename,DB_source::DEVELOPMENT);
					//$opslagruimte->initdatabase($DS_filename,DB_source::TEST);
					//$opslagruimte->initdatabase($DS_filename,DB_source::PRODUCTION);
					$opslagruimte->initfile($autosite['private']);
                    
					$_errors.= $opslagruimte->save_line($datatosave,0,true);
				}catch(Exception $e){
					//print_r($e);
					//print $e->getMessage();
					//array_merge(array("Form"=>"FORMname:".$formname),)
					//print($autosite['private']);
				}
		}elseif(isset($_POST['action']) && $_POST['action'] == 'edit'){
                    $opslagruimte = new data($formsdata[$formname]);
					$opslagruimte->setvalidationmsg($Errmsg['NL']);
					//$opslagruimte->initdatabase($DS_filename,DB_source::DEVELOPMENT);
					//$opslagruimte->initdatabase($DS_filename,DB_source::TEST);
					//$opslagruimte->initdatabase($DS_filename,DB_source::PRODUCTION);
					$opslagruimte->initfile($autosite['private']);
					//$_errors.= "".print_r(
					$opslagruimte->update_line($datatosave,0,true);//."";
		}elseif(isset($_POST['action']) && $_POST['action'] == 'delete'){
			
		}else{
		  
		}
	}elseif(isset($_POST['action']) && $_POST['action'] == 'submitted'){
		$_errors .= "%nopermission%";//nopermissiondenied DATA sendoptions not availeble:
	}
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<    VIEUW DATA      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<(public vieuw |or| permited vieuw)>>>>>>>>>>>>>>>>
		include_once($autosite['layout']."head.inc");
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>
			include_once("./preparts/Amenu.inc");
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<TOOLBAR sidebar>>>>>>>>>>>>>>>>
			include_once ($autosite['layout']."toolbar.inc");
			include_once ($autosite['layout']."aditudes.inc");
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Container>>>>>>>>>>>>>>>>
            print'<div id="container" class="clearfix">';
            if ($formlevel<101 ||(isset($user)&& $user->islogin()&& $user->ispermitlevel($formlevel))){
                	include($autosite['functions']."Qhtml/Qtemplate.inc");
                    include($autosite['functions']."Qhtml/Qhtml.inc");
                    $properties = getpropertiefile($autosite['translations'],$autosite['lang'],"forms");
                    $translatedata = $properties->getproperties($formsdata[$formname]['totranslate']);
            		include_once("./preparts/data_form.inc");
            }
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<end >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            print'</div>';
	        include_once ($autosite['layout']."foot.inc");
?>
<!-- @OVERRIDE STYLE -->
<link rel='stylesheet' href='<?php print $autosite['layout'];?>css/style.css'  type='text/css' />
<!-- @AUTHOR Lieven Roegiers @CMS autosite V2.5 automaticsite -->