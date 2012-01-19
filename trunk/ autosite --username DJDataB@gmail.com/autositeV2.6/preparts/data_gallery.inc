<?php
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Vieuw data>>>>>>>>>>>>>>>>
	print("<div class='gallery'>");	
	if($formsdata[$formname]['vieuw']==true&& is_file($autosite['templates'].$formname.".Qtemplate")){
		$string = (string)file_get_contents($autosite['templates'].$formname.".Qtemplate");
		if (!isset($properties)){
			$properties = getpropertiefile($autosite['translations'],$autosite['lang'],"forms");
			$translatedata =$properties->getproperties($formsdata[$formname]['totranslate']);
		}	
	    $vieuw = new Qvieuw($string,$translatedata);
		if(isset($overroletemplate[$formname])&&is_array($overroletemplate[$formname])){
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
	print("</div>");
?>
