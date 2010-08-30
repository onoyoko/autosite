<?php
	class Qtable{
		private $tablehead;
		private $tablefoot;
		private $tableX =0;
		private $tableY =0;
		Public function preset($head,$foot){
			$this->tablehead =  $head;
			$this->tablefoot =  $foot;
		}
		private function tableheaders($title,$arr){
		    print"<script type='text/javascript' src='/webtoolkit.sortabletable.js'></script>";
			print"<table><thead><tr><th colspan='$tableY'>$title</th></tr><tr>";
			foreach ($arr as $value){
			   print"<th class='c$tableY++'>$value</th>";
		    }
			print"</tr></thead>";		
		}
		public function addtagitem($key,$value){
			$this->htmltag->addtagitem($key,$value);
		}
		public function print_tablefrom($file,$datamap,$codeprettify = false){
			if ($this->save == true){
				$formkeys =  array_keys($this->formitemlist);
		    	tableheaders("title",$datamap);
		    	trlineprinter($formkeys);
	  			   $gbfile = @fopen ($this->file,'r');
	    		   while (!feof($gbfile)){
						$datamap = filelineto_aso_array(fgets($gbfile,1024),$formkeys);
						trlineprinter($datamap,true);
					}
				tablefooters("title",$datamap);
				fclose($gbfile);
				
	    	}
	    }
	    private function tablefooters($title,$arr){
		    print"<tfoot><tr>";
			foreach ($arr as $value ){
			   print"<th class='c$tableY++'>$value</th>";
		    }
			print"</tr><tr><th colspan='$tableY'>$title</th></tr></tfoot></table>";
		}
		private function trlineprinter($arr,$addtags = false){
			if($tableX%2 == 1){
				$returnval ="<tr class='r1''>";
			}else{
				$returnval ="<tr>";
			}
			$tableX++;
	    	if($addtags){//!important! sneller als je geen de if niet in de foreach plaatst
		        foreach ($arr as $value){
				   $returnval .="<td>";
			       tagmaker($value[0],$value[1]);
				   $returnval .="</td>";
			    }
	    	}else{
	    		foreach ($arr as $value){
				   $returnval .="<td>$value</td>" ;
			    }
	    	}
			$returnval .="</tr>";
			return $returnval;
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

	    }
   }
?>