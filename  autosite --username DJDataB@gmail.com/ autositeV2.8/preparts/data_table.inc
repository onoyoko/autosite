<?php
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Vieuw data>>>>>>>>>>>>>>>>
    if($formsdata[$formname]['vieuw']==true){
		$formfields = $formsdata[$formname]['items'];
		print"<script type='text/javascript' src='".$autosite['javascript']."table.sort.js'>
		</script>";
 		print"<script type='text/javascript'>image_path=".$autosite['layout']."img/general</script>";
		print"<div>$formname</div><table class='sortable' id='anyid'><tr>";
            if(!isset($translatedata)){
				$translatedata = $properties->getproperties($formsdata[$formname]['totranslate']);
			}else{
			  $translatedata =$formfields;
			}
		$tableY=0;
		if(is_array($formfields)){
            foreach ($formfields as $key=>$value){
    		   print"<th class='c".$tableY++."'>". $translatedata[$key]."</th>";
    	    }
        }else{
            print"<th class='c".$tableY++."'>NO KEYS: implementation</th>";
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
			if(isset($overroletemplate[$formname])&& is_array($overroletemplate[$formname])){
				$vieuw->addtagitems($overroletemplate[$formname]);
			}
			if(is_file($autosite['private'].$formsdata[$formname]['name'].".csv")){
				$count = $vieuw->getfrom_csv($autosite['private'].$formsdata[$formname]['name'].".csv",$formsdata[$formname]['items'],$step,$steplen);
                $i = $count/$steplen;
                print '<div class"paginato">';
                
                for($i=1;$i==0;--$i){
                    print" <a href='".$_SERVER['SELF'].$attributen."&viewas=$key' class='viewsitem'>-[$key]-</a>";
                }
                print '</div>';
			}else{
				print"<!--NO DATA-->";
			}
		print("</table>");
	}else{
		print "<!-- NO VIEUWS -->";
	}
	print "<!-- preparts=>tablevieuw -->";
?>