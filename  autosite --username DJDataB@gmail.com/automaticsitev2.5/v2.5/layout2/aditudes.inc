<div id="logo">
	<abbr class="abbr" title="Toevoegen aan favorieten">
	<a href="javascript:window.external.AddFavorite(' <?php print $_SERVER['PHP_SELF'].','.$autosite['title'];  ?>')">
	<img class="logo" border="0" src="<?php print $autosite['layout']; ?>logo.gif" /></a></abbr>
</div>
<div id="langbar">	
	<?php	foreach ($autositelangname as $key => $item){
				print "<a href='".$_SERVER['PHP_SELF']."?lang=$key&id=$formname$Gfile' title=".$item.">";
				print "<img border='0' src='".$autosite['layout']."lang/$key.gif'></a>";
			}
	?>
</div>
<div id="leftbar">
	<a href="mailto:<?php print $autosite['publicmail'];  ?>?subject=Ask for Publicity sitetitle<?php print $autosite['title'];  ?>-leftbar">here your site</a><br />
	<a target="_blank" href="http://www.freewebstuff.be" class="freewebstuff">freewebstuff</a><br />
	<a target="_blank" href="http://www.skype.com" class="skype">
		<img src="<?php print $autosite['layout']."img/skype_logo.png"; ?>" /></a><br />
	<a target="_blank" href="http://www.search-belgium.com/" class="search-belgium">search-belgium</a><br />
	Ecommerce<br />
	<a target="_blank" href="http://www.ogone.com/" class="ogone">ogone</a><br />
	Zoekrobots<br />
	<a target="_blank" href="http://www.google.be/" class="google">
		<img src="<?php print $autosite['layout']."img/nav_logo7.png"; ?>" /></a><br />
	PHP
	<br />
	<a target="_blank" href="http://qa.php.net/" class="PHPCORE">
		<img src="<?php print $autosite['layout']."img/php_qa.jpg"; ?>" /> </a><br />
	<a target="_blank" href="http://php.net/" class="PHP">
		<img src="<?php print $autosite['layout']."img/php.gif";  ?>" /> </a><br />
	
</div>
<div id="rightbar">
	<a href="mailto:<?php print $autosite['publicmail'];?>?subject=Ask for Publicity sitetitle<?php print $autosite['title'];  ?>-rightbar">here your site</a><br />
	your logo and links
</div>