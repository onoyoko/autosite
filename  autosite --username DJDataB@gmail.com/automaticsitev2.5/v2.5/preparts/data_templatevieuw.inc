<?php
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Vieuw data>>>>>>>>>>>>>>>>
if($formsdata[$formname]['vieuw']==true&& is_file($autosite['templates'].$formname.".Qtemplate")){
	$string = (string)file_get_contents($autosite['templates'].$formname.".Qtemplate");
	if(!isset($translatedata)){
		$translatedata =$properties->getproperties($formsdata[$formname]['totranslate']);
	}
	$vieuw = new Qvieuw($string,$translatedata);
	if(is_array($overroletemplate[$formname])){
		$vieuw->addtagitems($overroletemplate[$formname]);
	}
	if(is_file($autosite['private'].$formsdata[$formname]['name'].".csv")){
            $BROL =$step*$steplen;
            $count = $vieuw->getfrom_csv($autosite['private'].$formsdata[$formname]['name'].".csv",$formsdata[$formname]['items'],$BROL,$steplen+1);
            print '<div class="paginator"><h2>';
            for($i=0;$i<ceil($count/$steplen);$i++){
                print" <a href='".$_SERVER['SELF'].$attributen."&step=$i&steplen=$steplen' class='viewsitem'>[$i]</a>";
            }
            print '<h2></div>';	
	}else{
		print"<!--NO DATA-->";
	}
    
}else{
	print "<!--NO VIEUWS-->";
}
?>