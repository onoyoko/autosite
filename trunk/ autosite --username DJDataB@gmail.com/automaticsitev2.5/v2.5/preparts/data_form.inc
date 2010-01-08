<?php
			//<<<<<<<<<<<<<<<<<<<<<<<<<<<<take the template >>>>>>>>>>>>>>>>
			$string = (string)file_get_contents($autosite['forms'].$formname.".Qform");
			if (!isset($properties)){
				$template = new Qtemplate($string);
				//<<<<<<<<<<<<<<<<<<<<<<<<<<<<take the properties vb(forms_NL.properties)>>>>>>>>>>>>>>>>		
				$properties = getpropertiefile($autosite['translations'],$autosite['lang'],"forms")
				//<<<<<<<<<<<<<<<<<<<<<<<<<<<<the keys to translate>>>>>>>>>>>>>>>>	
				$translatedata =$properties->getproperties($formsdata[$formname]['totranslate']);
			}
			//<<<<<<<<<<<<<<<<<<<<<<<<<<<<translate>>>>>>>>>>>>>>>>			
			$template->translate($translatedata);
			//print_r($formsdata[$formname]['items']);
			//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Vieuw form>>>>>>>>>>>>>>>>
			$formtemplate = $template->gethtml();
			include($autosite['layout']."form.inc");
?>
