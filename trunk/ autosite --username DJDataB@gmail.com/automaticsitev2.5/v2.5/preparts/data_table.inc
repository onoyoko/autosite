<?php
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Vieuw data>>>>>>>>>>>>>>>>
    if($formsdata[$formname]['vieuw']==true){
		$formfields = $formsdata[$formname]['items'];
		print"<script type='text/javascript' src='".$autosite['javascript']."table.sort.js'>
		</script>";
 		print"<script type='text/javascript'>image_path=".$autosite['layout']."img/general</script>";
		print"<div>$title<div><table class='sortable' id='anyid'><tr>";
			if(!isset($translatedata)){
				$translatedata = $properties->getproperties($formsdata[$formname]['totranslate']);
			}
		$tableY=0;
		foreach ($formfields as $key=>$value){
		   print"<th class='c".$tableY++."'>".$translatedata[$key]."</th>";
	    }
		print"</tr>";
  		$string = "<tr>";
		
		if(is_array($formfields)){
				foreach($formfields as $key => $value){
					$string .=  "<td> %".$key."->value% </td>";
				}
		}
		$string .= "</tr>";

			$vieuw = new Qvieuw($string,$translatedata);
			if(is_array($overroletemplate[$formname])){
				$vieuw->addtagitems($overroletemplate[$formname]);
			}
			if(is_file($autosite['private'].$formsdata[$formname]['name'].".csv")){
				$vieuw->getfrom_csv($autosite['private'].$formsdata[$formname]['name'].".csv",$formsdata[$formname]['items']);	
			}else{
				print"<!--NO DATA-->";
			}
		print("</table>");
	}else{
		print "<!-- NO VIEUWS -->";
	}
	print "<!-- preparts=>tablevieuw -->";

?>