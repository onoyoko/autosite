<center>
	<table  class="Aform" cellpadding=0 cellspacing=0 >
		<tr>
			<th height='32' width='28' background='<?php print $autosite['layout']; ?>img/general/form_brown_LH.jpg'></th>
			<th background='<?php print $autosite['layout']; ?>img/general/form_brown_MH.jpg'><center><?php print " "; ?></center></th>
			<th background='<?php print $autosite['layout']; ?>img/general/form_brown_RH.jpg'></th>
		</tr>
		<tr>
			<td background='<?php print $autosite['layout']; ?>img/general/form_brown_LM.jpg'>
			</td>
			<td background='<?php print $autosite['layout']; ?>img/general/form_brown_SP.jpg'>
				<h1>[ERROR]:UNDER CONSTRUCTION</h1><br />
				<form method='post' action='<?php print $_SERVER['PHP_SELF'].$attributen;?>' enctype="multipart/form-data">
					<input type='hidden' name='id' value='<?php print $formname; ?>'/>
					<input type='hidden' value='submitted' name='action' />
					<?php print $formtemplate; ?>				
				</form>
			</td>
			<td background='<?php print $autosite['layout']; ?>img/general/form_brown_RM.jpg'>
			</td>
		</tr>
		<tr>
			<td background='<?php print $autosite['layout']; ?>img/general/form_brown_LF.jpg'>
			</td>
			<td background='<?php print $autosite['layout']; ?>img/general/form_brown_MF.jpg'>
			<center></center>
			</td>
			<td height='32' width='30' background='<?php print $autosite['layout']; ?>img/general/form_brown_RF.jpg'>			   </td>
		</tr>
	</table>
</center>