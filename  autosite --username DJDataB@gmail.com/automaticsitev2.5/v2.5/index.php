		<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Frameset//EN" "http://www.w3.org/TR/html4/frameset.dtd">
		<!-- style -->
<?php
$underconstruct = false;
include_once("./generalvars.php");
$lang = ( isset( $_GET['lang'] ) ) ? $_GET['lang'] : $autosite['lang'];
if(!$underconstruct){
	?>
	<frameset frameborder='0' framespacing='0' framepadding='0'>
	 	<frame src="vieuwport.php?file=home&lang=<?php print $autosite['lang'] ?>" name="Werkplaats" scrolling='yes'>
	</frameset>
	<?php
	print"<body>";
	print"<noframes>";
	include($autosite['error']."ernoframes.inc");
	print "</noframes>\n";
}else{
	include_once($autosite['layout']."head.inc");
	print"<div id='container'>";
	include($autosite['error']."underconstruct.inc");
	print"</div>";
}
include_once($autosite['layout']."foot.inc");
?>
<!-- @OVERRIDE STYLE -->
<link rel='stylesheet' href='<?php print $autosite['layout'] ?>css/style.css' type='text/css' />
<!-- @AUTHOR Lieven Roegiers @CMS autosite V2.5 automaticsite -->