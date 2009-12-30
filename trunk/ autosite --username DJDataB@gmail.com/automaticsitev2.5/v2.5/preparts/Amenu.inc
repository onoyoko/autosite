<?php
include_once($autosite['functions']."menu2.inc");
$menu = new Menu($autosite['lang'], $autositelang[$autosite['lang']]);
if($autosite['hasclientjs']){
	?>
		<!-- @MENU [key,value] -->
			<script type="text/javascript">
    		<?php
    	$exts['inc']= array(".dat");
		print("var Items = [");
		if(!$menu->getif_menu_exist(true)){
			$menu->createMNUitemsfrom_filesystem($autositelang[$autosite['lang']],"vieuwport.php",$exts);
			$menu->createMNUitemsfrom_filesystem($autosite['forms'],"datavieuwport.php",array("from"));
			$menu->Generate_menu(true);
		}
		print("];\n ");
		include($autosite['layout']."menusettings.inc");
		print("M_nav(M_replace('".$Gfile."',' '));\n</script>");
}else {
		$exts['inc']= array(".dat");
		print("<div id='menuERROR' class='ERROR'>[ERROR:JS NOT FOUND]</div>\r\n");
		print("<div  id='menu' class='mnutop'>\r\n");
		if(!$menu->getif_menu_exist($hasclientjs)){
			$menu->createMNUitemsfrom_filesystem($autositelang[$autosite['lang']],"vieuwport.php",$exts);
			$menu->createMNUitemsfrom_filesystem($autosite['forms'],"datavieuwport.php",array("from"));
			$menu->Generate_menu(false);
		}
		print("</div>\r\n");
}
