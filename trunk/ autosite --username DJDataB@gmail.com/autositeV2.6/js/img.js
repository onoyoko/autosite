 function findIMG(ByIdname) { 
   var url=""; 
   var table = document.getElementById(ByIdname);
   var allIMGs = table.getElementsByTagName("img");
   for (i = 0; i < allIMGs.length; i++){
   	document.write(allIMGs.item(i).alt);
    url="<?php print $autosite['layout']?>"+"/img/" + allIMGs.item(i).alt;
    allIMGs.item(i).src=url;
   } 
 }