<form action="secvieuwport.php" method="GET">
	<select name="lang">
		<?php
			function langadd($item, $key){
				print("<option value='$key'>$item</option>");
			}	
			array_walk($autositelangname,'langadd');
		?>
	</select>
	<input type="text" value="Englise" size="25"  name="Gfile" />
	<input class="btnedit" type="submit" name="handeling" value="edit" />
</form>