<?php
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Vieuw data>>>>>>>>>>>>>>>>
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
?>