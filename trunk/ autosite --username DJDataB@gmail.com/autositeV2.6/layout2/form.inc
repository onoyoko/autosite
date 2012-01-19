<center>
	<table  class="Aform" cellpadding=0 cellspacing=0 >
		<tr>
			<th height='32' width='28' background='<?php print $autosite['layout']; ?>img/general/form_brown_LH.jpg'></th>
			<th height='32' width='28' background='<?php print $autosite['layout']; ?>img/general/form_brown_MH.jpg'><center><?php print " "; ?></center></th>
			<th  height='32' width='28' background='<?php print $autosite['layout']; ?>img/general/form_brown_RH.jpg'></th>
		</tr>
		<tr>
			<td  width='28' background='<?php print $autosite['layout']; ?>img/general/form_brown_LM.jpg'>
			</td>
			<td background='<?php print $autosite['layout']; ?>img/general/form_brown_SP.jpg'>			
				<form method='post' action='<?php print $_SERVER['PHP_SELF'].$attributen;?>' name="upForm" enctype="multipart/form-data" >
					<input type='hidden' name='content' value='<?php print $content; ?>'/>
					<input type='hidden' value='submitted' name='action' />
					<?php print $formtemplate; ?>				
				</form>
			</td>
			<td  width='28' background='<?php print $autosite['layout']; ?>img/general/form_brown_RM.jpg'>
			</td>
		</tr>
		<tr>
			<td height='32' width='28' background='<?php print $autosite['layout']; ?>img/general/form_brown_LF.jpg'>
			</td>
			<td height='32' background='<?php print $autosite['layout']; ?>img/general/form_brown_MF.jpg'>
			</td>
			<td height='32' width='30' background='<?php print $autosite['layout']; ?>img/general/form_brown_RF.jpg'>			   </td>
		</tr>
	</table>
</center>

