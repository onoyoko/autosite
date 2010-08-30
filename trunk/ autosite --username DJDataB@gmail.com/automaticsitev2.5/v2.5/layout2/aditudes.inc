<div id="logo">
	<abbr class="abbr" title="Toevoegen aan favorieten">
	<a href="javascript:window.external.AddFavorite(' <?php print $_SERVER['PHP_SELF'].','.$autosite['title'];  ?>')">
	<img class="logo" border="0" src="<?php print $autosite['layout']; ?>logo.gif" /></a></abbr>
</div>

<div id="langbar">	
	<?php	foreach ($autositelangname as $key => $item){
				print "<a href='".$_SERVER['PHP_SELF']."?lang=$key&content=$formname$Gfile' title=".$item.">";
				print "<img border='0' src='".$autosite['layout']."lang/$key.gif'></a>";
			}
	?>
</div>
<div id="leftbar">
	<a href="mailto:<?php print $autosite['publicmail'];  ?>?subject=Ask for Publicity sitetitle<?php print $autosite['title'];  ?>-leftbar">here your site</a><br />
    <?php	foreach ($linkextern['left'] as $key => $item){
				print "<a href='".$item[0]."' title='".$item[1]."' target='_blank'>";
				print ($item[2]=="")?$item[1]."<!-- NO PIC -->":"<img border='0' alt='".$item[1]."' width='70' src='".$linkbanners.$item[2]."'>";
				print "</a><br />";
			}
	?>	
</div>
<div id="rightbar">
	<a href="mailto:<?php print $autosite['publicmail'];?>?subject=Ask for Publicity sitetitle<?php print $autosite['title'];  ?>-rightbar">here your site</a><br />
	your logo and links
</div>