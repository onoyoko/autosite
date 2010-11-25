     var year = 2010;
     var mondnr = 2;
     var afspraken = Array();
	  afspraken[1]=Array('afspraak','met');
	  afspraken[10]=Array('nog afspraak','www');
     
     Array.prototype.exist = function(){
  		for(i in this){
  			document.write(i+"=>"+(this)+"</br>");
  			document.write("</br>");
    		if(i === arguments[0])
      		return true;
  		};
  		return false;
     }; 
     function Calprint(begin){
 			var x =0;
 			var y=0;
 			z = DaysInMond(mondnr-1);
 			var output='<form><table border="2" width="100%"><tr>';
 			for(y = begin ; y > 1; y--) {
     	    		output += Calspacer("spacer "+(z-x));
   	        }
 			y = begin;
     	    for(x = 1 ; x < DaysInMond(mondnr)+1; x++) {
				output += CalTemplate(x);
        		y++;
        		if (y == 7) {
            		output += '</tr>\n<tr>';
            		y = 0;
        		}
    		}
    		output+='</tr></table></form>';
    		document.write(output);
   	 }
   	 function DaysInMond(mond){
   	 		var days = 0;
   	 		switch (mond){
   	 			case 1 : 
   	 			case 3 :
				case 5 :
				case 7 :
				case 8 :
				case 10 :
				case 12 :
					days = 31;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					days = 30;
					break;
				case 2:
				    if (Ischrikkeljaar()) {
						days = 29; 
		    		}else {
		        		days = 28;
		    		}
		    		break;
				default :
					days = 0;
			}
   	 		return days;
   	 }
   	 function Ischrikkeljaar(){
   	 	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
   	 }
     function CalTemplate(i){
     		var inf = i+"<br><ol> ";
     		if (afspraken[i]!== undefined){
     			 for(var z=0;(z<afspraken[i].length&&typeof(afspraken[i])!="undefined");z++){
     	    	 inf += "<li>"+afspraken[i][z]+"</li><br>";
     	    	 }
 	    	}
 	    	inf+="</ol>"
     		return '<td style="overflow:hidden;width:20px;background-color:#555;">'+inf+'</td>';
     }
     function Calspacer(data){
     		return '<td style="background-color:#333;overflow:auto;" width="10">'+data+'</td>';
     }