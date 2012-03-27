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
        if (isset($formsdata[$formname]['loginniveau'])){
            $formlevel=$formsdata[$formname]['loginniveau'];
        }else{
            $formlevel=777;
        }
        $isdata= is_file($autosite['private'].$formsdata[$formname]['name'].".csv");
        $formlevel = (isset($formsdata[$formname]['loginniveau']))?$formsdata[$formname]['loginniveau']:1;
    	$content = "".$formname;
    	include($autosite['functions']."users/User_data.inc");
    	include($autosite['functions']."users/User.inc");
    	//session_start();
    	$user= getsessionuser();
    	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<    VIEUW DATA      >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<(public vieuw |or| permited vieuw)>>>>>>>>>>>>>>>>
    	$viewas=(isset($_GET['viewas']))?$_GET['viewas']:'';
        
    	if ($formsdata[$formname]['vieuw']= true || (isset($user)&& $user->islogin()&& $formlevel<$user->getlevel())){
    		if($viewas === "XML"){
    		    //if(!isset($user)|| !$user->islogin()||!$user->getlevel()>50) die("[PRIVATE:USERLEVEL ASK B2B CONNECTION]");
    			include_once($autosite['functions']."Qhtml/Qvieuw.inc");
                header ("Content-Type:text/xml");
    			include_once("./preparts/data_xml.inc");
    		}elseif($viewas === "RSS"){
    		    //if(!isset($user)|| !$user->islogin()||!$user->getlevel()>50) die("[PRIVATE:USERLEVEL ASK RSS CONNECTION]");
    			include_once($autosite['functions']."Qhtml/Qvieuw.inc");
                header ("Content-Type:text/xml");
    			include_once("./preparts/data_rss.inc");
    			die();
    		}else{
    				//<<<<<<<<<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>				
    		include_once($autosite['layout']."head.inc");
    	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<MENU>>>>>>>>>>>>>>>>
    			include_once("./preparts/Amenu.inc");
    	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<TOOLBAR sidebar>>>>>>>>>>>>>>>>
    			include_once ($autosite['layout']."toolbar.inc");
    			include_once ($autosite['layout']."aditudes.inc");
    	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Container>>>>>>>>>>>>>>>>
    print'<div id="container" class="clearfix">';
        	if ($formlevel<101 ||(isset($user)&& $user->islogin()&& $user->ispermitlevel($formlevel))){
                print"<a href='./formvieuwport.php".$attributen."&viewas=$key' class='viewsitem'>%toevoegen%</a>|";
            }
    		include_once($autosite['functions']."Qhtml/Qvieuw.inc");
    		include_once($autosite['functions']."data/properties.inc");
    		if (!isset($properties)){
    				//<<<<<<<<<<<<<<<<<<<<<<<<<<<<take the properties vb(forms_NL.properties)>>>>>>>>>>>>>>>>		
    			$properties = getpropertiefile($autosite['translations'],$autosite['lang'],"forms");
    				//<<<<<<<<<<<<<<<<<<<<<<<<<<<<the keys to translate>>>>>>>>>>>>>>>>
    			$translatedata = $properties->getproperties($formsdata[$formname]['totranslate']);
    		}
    		include_once($autosite['layout']."tooltip.inc");
            print '<link rel="stylesheet" href="'.$autosite['layout'].'css/data.css"  type="text/css" />';
    		if(array_key_exists($viewas,$views)){
    			//include_once("./preparts/data_paginator.inc");
                include_once($views[$viewas]);
    		}else{
                //include_once("./preparts/data_paginator.inc");
    			include_once("./preparts/data_templatevieuw.inc");
    		}
            //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<end >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
            ?>
                </div>
                <form method="post" action="<?php print $_SERVER['PHP_SELF'].$attributen;?>" enctype="text/plain">
                    <input type="hidden" name="selecteditem"  id="selecteditem"/>
                </form>
                </div>
            <?php
            include_once ($autosite['layout']."search.inc");
            print"<div class='views'>";
        	    foreach($views as $key=>$value){
        			print" <a href='".$_SERVER["PHP_SELF"].$attributen."&viewas=$key' class='viewsitem'>$key</a>|";
        		}
            print"</div>";
    		include_once ($autosite['layout']."foot.inc");
    		?>
                <!-- @OVERRIDE STYLE -->
                <link rel='stylesheet' href='<?php print $autosite['layout'];?>css/style.css'  type='text/css' />
                <!-- @AUTHOR Lieven Roegiers @CMS autosite V2.6 automaticsite -->
            <?php
            }
    	}
   }else{//<<<<<<<<<<<<<<<<<<<<<<<<<<<<FORM NOT EXIST OR NOT JUST IMPLEMENTED>>>>>>>>>>>>>>>>				
		include_once($autosite['layout']."head.inc");
			include_once("./preparts/Amenu.inc");
			include_once ($autosite['layout']."toolbar.inc");
			include_once ($autosite['layout']."aditudes.inc");
	       $_errors="INCORRECT IMPLEMENTATION=>$formname";      
       include_once ($autosite['layout']."foot.inc");
   }
?>
