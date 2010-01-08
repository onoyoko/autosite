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
		/**
 		* @param var $Qtemplate
 		*/
 		function __construct(&$Qtemplate,$asoarrkeytranslations){
 			print("<!--Qvieuw locale translator by autosite-->");
	    	$this->template=new Qtemplate($Qtemplate);
	    	$this->template->translate($asoarrkeytranslations);
		}
		public function addtagitems($asoarr){
			foreach ($asoarr as $key => $value){	
				$this->template->addtagitem($key,$value);
		  	}
		}
		function getfrom_DB(){
			
		}
		function getfrom_XML(){
			
		}
		function getfrom_csv($filename,$taglist){
			$row = 1;
			$gbfile = fopen($filename,'r');
			while (!feof($gbfile)){
				$fileline=fgets($gbfile,1024);
				$output= split(',',$fileline);
				//array_shift($output);
				$datamap = $this->array_aso_merge(array_keys($taglist),$output);
				$this->printdata($datamap);
			}
			fclose($gbfile);
		}
		function settoolbar($toolbar,$link){
			$this->template;
		}
		private function printdata($asoarr){
			$temp = clone $this->template;
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