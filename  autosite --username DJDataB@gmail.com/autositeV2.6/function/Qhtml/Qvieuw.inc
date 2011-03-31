<?php
	/**
	* @author Lieven Roegiers
	* @revisite 30 day
	* @copyright 2009
	* @CMS autosite
	*/
	include($autosite['functions']."Qhtml/Qtemplate.inc");
	include($autosite['functions']."Qhtml/Qhtml.inc");
	class Qvieuw{
		private $template;
		private $i;
		/**
 		* @param var $Qtemplate
 		*/
 		function __construct(&$Qtemplate,$asoarrkeytranslations){
 			print("<!-- Qvieuw locale translator by autosite -->");
 	    	$this->template=new Qtemplate($Qtemplate);
	    	$this->template->translate($asoarrkeytranslations);
		}
		public function addtagitems($asoarr){
			foreach ($asoarr as $key => $value){	
				$this->template->addtagitem($key,$value);
		  	}
		}
		function getfrom_DB($tabelname,$taglist){
			mysql_connect('localhost',$username,$password);
			@mysql_select_db($database) or die( "Unable to select database");
			$tableselection=(isset($taglist)&&is_array($taglist))?implode(",",array_keys($taglist)):"*";
			$queryschema="SELECT $tableselection FROM schema WHERE date > NOW() ORDER BY date ASC LIMIT 5";
			$resultschema = mysql_query($queryschema);
			$numschema = mysql_num_rows($resulschema);
			mysql_close();
 			$inieuws=0;
			while ($ischema < $numschema) {
				$titelschema=mysql_result($resultschema,$ischema,"titre");
				$textschema=mysql_result($resultschema,$inschema,"details");
				$idschema=mysql_result($resultschema,$ischema,"id");
				$dagschema=mysql_result($resultschema,$ischema,"dag");
				 	$this->printdata($datamap); 
					$ischema++;
				}
		}
		function getfrom_XML(){
			
		}
		function getfrom_csv($filename,$taglist,$from=0,$steplen=20){
			$row = 1;
			$gbfile = fopen($filename,'r');
			//TODO if no template print table
            $to = $from + $steplen;
			while (!feof($gbfile)){
				$fileline=fgets($gbfile,1024);
                if($row>$from &&$row<$to||$to==0){
                    $this->rowhandel(array_keys($taglist),explode(',',$fileline));
                }
                $row++;
			}
			fclose($gbfile);
            return $row;
		}
        function rowhandel($keys,$line){
    				try{
    					$datamap = $this->array_aso_merge($keys,$line);
    				}catch(Exception $e){
    					print(".vars are not correctly".$e);
                        exit;
    				}
    				$this->printdata($datamap);
        }
		function search_csv($filename,$taglist,$tofind,$from=0,$step=20){
			$row = 1;
			$gbfile = fopen($filename,'r');
			//TODO if no template print table
			while (!feof($gbfile)){
				$fileline=fgets($gbfile,1024);
                 if($this->find_AND($fileline,$tofind)){ 
                    if($row>$from && $to== 0 || $row<$to){
                        $this->rowhandel(array_keys($taglist),explode(',',$fileline));
                    }
                    $row++;
                }
			}
			fclose($gbfile);
            return $row;
		}
        function find_OR(&$data,$tofind){
            if(is_array($tofind)){
                foreach($tofind as $value){
				    if(strpos($data, $value)){
				        return true;
				    }
                }
                return false;
            }else{
                return strpos($data, $tofind);
            }
        }
        function find_AND(&$data,$tofind){
             if($tofind == ""){return true;}
             if(is_array($tofind)){
                foreach($tofind as $value){
				    if(!strpos($data, $value)){
				        return false;
				    }
                }
                return true;
            }else{
                return strpos($data, $tofind);
            }
        }
		function settoolbar($toolbar,$link){
			$this->template;
		}
		private function printdata($asoarr){
			$temp = clone $this->template;
			$adds = array("i"=>++$this->i);
			$asoarr += $adds;
			$temp->setvalues($asoarr);
			print $temp->gethtml();
		}
		private function array_aso_merge($arrkey,$arrvalue){
			$x1=count($arrkey);
			$x2=count($arrvalue);
			//aanvullen van arr
			if($x1>$x2){			
				for ($i = $x2; $i <= $x1-1; $i++){
    				$arrvalue[$i]="";
				}
			}else{
				for ($i = $x1; $i <= $x2-1; $i++){
    				$arrkey[$i]="%".$i."%";
				}
			}
			return array_combine($arrkey,$arrvalue);
		}   
	}
?>