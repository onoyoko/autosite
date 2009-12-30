<?php
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<take the template >>>>>>>>>>>>>>>>
			$string = (string)file_get_contents($autosite['forms'].$formname.".Qform");
			$template = new Qtemplate($string);
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<take the properties >>>>>>>>>>>>>>>>		
			$properties = getpropertiefile($autosite['translations'],$autosite['lang'],"forms");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<translate>>>>>>>>>>>>>>>>			
			$translatedata =$properties->getproperties($formsdata[$formname]['totranslate']);
			$template->translate($translatedata);
			//print_r($formsdata[$formname]['items']);
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Vieuw form>>>>>>>>>>>>>>>>
			$formtemplate = $template->gethtml();
			include($autosite['layout']."form.inc");
?>
