<?php
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Vieuw data>>>>>>>>>>>>>>>>
		$attributen="?";
		$attributen.=(isset($content))? "content=".$content : "";
		//$attributen.=(isset($autosite['lang']))? "&lang%3D".$autosite['lang'] : "";
        //$attributen.=(isset($_GET['viewas']))? "&viewas%3D".$_GET['viewas'] : "";
        
        	print '<?xml version="1.0" encoding="ISO-8859-15"?>'."\n";
			print '<AUTOSITE><CONTENTTYPE>'.$formname.'</CONTENTTYPE>';
			print '<URL>'.$_SERVER['PHP_SELF']. $attributen.'</URL>';
			print '<DATA>';
			include_once($autosite['functions']."Qhtml/Qvieuw.inc");
    $string = " ";
    $formfields = $formsdata[$formname]['items'];
		if(is_array($formfields)){
				foreach($formfields as $key => $value){
					$string .=  "%".$key."->value% ";
					$overroletemplate[$formname][$key]="<".$key."> %value% </".$key.">";
				}
		}
	if($formsdata[$formname]['vieuw']==true){
		$vieuw = new Qvieuw($string,null);
		if(is_array($overroletemplate[$formname])){
			$vieuw->addtagitems($overroletemplate[$formname]);
		}
		if(is_file($autosite['private'].$formsdata[$formname]['name'].".csv")){
			$vieuw->getfrom_csv($autosite['private'].$formsdata[$formname]['name'].".csv",$formsdata[$formname]['items']);	
		}else{
			print"<!-- NO DATA -->";
		}
	}else{
		print "<!-- NO VIEUWS -->";
	}
	print "<!-- preparts=>XML -->";
	print '</DATA></AUTOSITE>';
?>