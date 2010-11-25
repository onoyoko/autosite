<!--whitepace for scrolling correction -->
<div id="spacing">
</div>
<?php if($_errors){
			print"<div id='xx' class='ERROR'>$_errors</div>";
      };
?>
<div id="foot">
	<!--@layout @foot -->
	Copyright &copy; <?php echo date("Y"); ?> @content &bull;
	<a href="http://www.djdb.be/" title="Autosite"><?php print $autosite['servicename']; ?></a>&bull;
	<!--@Opensource -->
	<a href="http://code.google.com/p/autosite/" title="Automatic site">@CMS By Lieven R</a>&bull;
	<!--@CONTACT -->
	<script type="text/javascript" src="<?php print$autosite['javascript']?>skypeCheck.js"></script>
	
	<a href="mailto:<?php print $autosite['servicemail']; ?>">mailto:</a>&bull;
	<a href="skype:<?php print $autosite['servicenr']; ?>?call" class="btn_skype">
	<img src="<?php print $autosite['layout']; ?>img/skype.gif" class="btn_skype icon"  /></a>
	<a href="skype:<?php print $autosite['servicenr']; ?>?add" >-add to skype-</a>	
<?php
/**
 * <EN>watch to generalvars.php <NL>kijk naar generalvars.php
 * <a href="skype:<?php print $autosite['servicenr']; ?>?call">
 * <img src="<?php print $autosite['layout']; ?>img/call_green_white_153x63.png" alt="Skype Me™!" /></a>
 * <a href="skype:YOUR SKYPE NAME?add">
 * <img src="<?php print $autosite['layout']; ?>img/add_green_white_195x63.png"  alt="Add me to Skype" /></a>
 * <a href="skype:<?php print $autosite['servicenr']; ?>?call">
 * <img src="http://mystatus.skype.com/balloon/<?php print $autosite['servicenr']; ?>" alt="My status" /></a>
*/?>
</div>

</body>
</html>