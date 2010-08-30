<?php
	if (!isset($user)&&isset($_SESSION['user'])) {
		print'  <div class="toolbar"><!-- @LOGIN -->';
		include($autosite['functions']."users/User_data.inc");
		include($autosite['functions']."users/User.inc");
		include($autosite['functions']."toolbar.inc");
		$user= getsessionuser();
		$toolbar = new toolbar($option_location);
		$toolbar->printtoolbar("&content=".$id,$user->getlevel());
		print"</div>";
	}elseif(isset($user)) {
		print'  <div class="toolbar"><!-- @LOGIN secvieuwport -->';
		include($autosite['functions']."toolbar.inc");
		$toolbar = new toolbar($option_location);
		$toolbar->printtoolbar("&content".$id,$user->getlevel());
		print"</div>";
	}else{
		?>
		<div class="toolbar"><!-- @NOT LOGIN -->
			<a id="login" class="functie login" href="<?php print $option2location['Login'][0]; ?>" >
			login</a>
		</div>
		<?php
	}
?>

