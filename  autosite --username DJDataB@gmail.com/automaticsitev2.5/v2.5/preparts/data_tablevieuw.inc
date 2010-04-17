<?php
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Vieuw data>>>>>>>>>>>>>>>>
	if($formsdata[$formname]['vieuw']==true){
		if(!isset($translatedata)){
			$translatedata =$properties->getproperties($formsdata[$formname]['totranslate']);
		}
		$table = new Qtable($string,$translatedata);
		if(is_array($overroletemplate[$formname])){
			$vieuw->addtagitems($overroletemplate[$formname]);
		}
		if(is_file($autosite['private'].$formsdata[$formname]['name'].".csv")){
			$vieuw->getfrom_csv($autosite['private'].$formsdata[$formname]['name'].".csv",$formsdata[$formname]['items']);	
		}else{
			print"<!--NO DATA-->";
		}
	}else{
		print "<!--NO VIEUWS-->";
	}
?>