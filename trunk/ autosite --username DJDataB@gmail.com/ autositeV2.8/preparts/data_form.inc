<?php
		if(is_file($autosite['forms'].$formname.".Qform")){
			//<<<<<<<<<<<<<<<<<<<<<<<<<<<<take the template >>>>>>>>>>>>>>>>
			$string = (string)file_get_contents($autosite['forms'].$formname.".Qform");
			$template = new Qtemplate($string);
			//<<<<<<<<<<<<<<<<<<<<<<<<<<<<translate>>>>>>>>>>>>>>>>			
			$template->translate($translatedata);
			//print_r($formsdata[$formname]['items']);
			//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Vieuw form>>>>>>>>>>>>>>>>
			$formtemplate = $template->gethtml();
			include($autosite['layout']."form.inc");
		}
?>
