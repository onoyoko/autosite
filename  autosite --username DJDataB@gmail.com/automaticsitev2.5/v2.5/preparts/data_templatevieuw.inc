<?php
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Vieuw data>>>>>>>>>>>>>>>>
	if($formsdata[$formname]['vieuw']==true&& is_file($autosite['templates'].$formname.".Qtemplate")){
		$string = (string)file_get_contents($autosite['templates'].$formname.".Qtemplate");
		$vieuw = new Qvieuw($string,$translatedata);
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