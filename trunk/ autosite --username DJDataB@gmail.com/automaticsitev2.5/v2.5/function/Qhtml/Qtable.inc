<?php
	class Qtable{
		/** list of posible tags
	    *@param array("naam" => "","mail" => "","date" => "","inf" => "","status" => "","phone" => "",)
	    *@param $codeprettify wil make tag mail => <a href='mailto:%value%'>%value%</a>";
		**/
		public function print_tablefrom($file,$datamap,$codeprettify = false){
			if ($this->save == true){
				$formkeys =  array_keys($this->formitemlist);
		    	print"<table >";
		    	trlineprinter($formkeys);
	  			   $gbfile = @fopen ($this->file,'r');
	    		   while (!feof($gbfile)){
						$datamap = filelineto_aso_array(fgets($gbfile,1024),$formkeys);
						trlineprinter($datamap,true);
					}
				print"</table></div>";
				fclose($gbfile);
	    	}
	    }
		private trlineprinter($arr,$addtags = false){
	    	$returnval ="<tr>";
	    	if ($addtags){//!important! sneller als je geen de if niet in de foreach plaatst
		        foreach ($arr as $value){
				   $returnval .="<td>";
			       tagmaker($value[0],$value[1]);
				   $returnval .="</td> ";
			    }
	    	}else{
	    		foreach ($arr as $value){
				   $returnval .="<td>$value</td>" ;
			    }
	    	}
			$returnval .="</tr>";
	    }
	    private function filelineto_aso_array($fileline,$keys,$delemiter="[]",$lineend="_."){
	    	$pos = strpos ($fileline,$lineend); // einde bepalen van T4 taging
			$lijntje = substr($gbline, 0, $pos);
	    	$output=split($delemiter,$lijntje);
	    	return array_map(null,$keys,$output);
	    }
	    private function stuff(){
	    	                    if ($i >= $cols+1){
	                print"</tr><tr>";
	                $i=0  ;
	            	}          
			$i++; 
                  endif;
	    }
   }
?>