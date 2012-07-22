<?php
include_once($autosite['functions']."data/properties.inc");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<take the properties vb(forms_NL.properties)>>>>>>>>>>>>>>>>		
$properties = getpropertiefile($autosite['translations'],$autosite['lang'],"forms");
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<the keys to translate>>>>>>>>>>>>>>>>
$autosite['TranslateKeyValue'] = $properties->getproperties($autosite['TranslateKeys']);

?>