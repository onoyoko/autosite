<?php
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Vieuw data>>>>>>>>>>>>>>>>
if($formsdata[$formname]['vieuw']==true&& is_file($autosite['templates'].$formname.".Qtemplate")){
	$string = (string)file_get_contents($autosite['templates'].$formname.".Qtemplate");
	if(!isset($translatedata)){
		$translatedata =$properties->getproperties($formsdata[$formname]['totranslate']);
	}
	$vieuw = new Qvieuw($string,$translatedata);
	if(isset($overroletemplate[$formname])&&is_array($overroletemplate[$formname])){
		$vieuw->addtagitems($overroletemplate[$formname]);
	}
    $BROL =$step*$steplen;
    $count= 1 ;
	if(isset($formsdata[$formname]['type']['file'])&& is_file($autosite['private'].$formsdata[$formname]['name'].".csv")){
            $count = $vieuw->getfrom_csv($autosite['private'].$formsdata[$formname]['name'].".csv",$formsdata[$formname]['items'],$BROL,$steplen+1);
	}elseif(isset($formsdata[$formname]['type']['db'])){
	   print"<-- -->test";
	   $count = $vieuw->getfrom_DB($formsdata[$formname]['name'],$formsdata[$formname]['items']);
    }else{
		print"<--NO DATA-->";
	}
    print '<div class="paginator"><h2>';
            for($i=0;$i<ceil($count/$steplen);$i++){
                print" <a href='".$_SERVER['PHP_SELF'].$attributen."&step=$i&steplen=$steplen' class='viewsitem'>[$i]</a>";
            }
            print '<h2></div>';	
}else{
	print "<!--NO VIEUWS-->";
}
?>