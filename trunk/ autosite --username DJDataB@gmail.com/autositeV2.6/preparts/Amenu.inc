<?php
include_once($autosite['functions']."menu2.inc");
$menu = new Menu($autosite['lang'], $autositelang[$autosite['lang']]);
$hasclientjs = (isset($autosite['hasclientjs']))?$autosite['hasclientjs']:true;
    	$exts['inc']= array(".dat");
        $forms['inc']= array(".vars");
if($hasclientjs){
		print('<!-- @MENU [key,value] --><script type="text/javascript"> var Items = [');
}else{
    	print("<div id='menuERROR' class='ERROR'>[ERROR:JS NOT FOUND]</div>\r\n");
		print("<div  id='menu' class='mnutop'>\r\n");
}
        if(!$menu->getif_menu_exist($hasclientjs)){
			$menu->createMNUitemsfrom_filesystem($autositelang[$autosite['lang']],"vieuwport.php",$exts);
			$menu->createMNUitemsfrom_filesystem($autosite['forms'],"datavieuwport.php",$forms);
			$menu->additems($shop['prod_catogory'],"products.php");
			$menu->Generate_menu(false);
		}
if($hasclientjs){
			print("];\n ");
		include($autosite['layout']."menusettings.inc");		
		print("M_nav(M_replace('".$content."',' '));\n</script>");//set the navigation
}else{
    			print("</div>\r\n");
}
?>
