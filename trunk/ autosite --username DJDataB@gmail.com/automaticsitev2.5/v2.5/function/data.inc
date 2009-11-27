<?php
	/**
	 * @author Lieven Roegiers
	 * @copyright 2009
	 * @CMS autosite
	 */
    include($autosite['functions']."interfaces/tosave.inc");
	include($autosite['functions']."data/valid.inc");
	include($autosite['functions']."data/csv_plus.inc");//databaseconection
	include($autosite['functions']."data/db_source.inc");
	class data{
		private $faze;
		private $DS_ref;
		private $FILE_ref;
		private $forminf;
		private $type;
		private $opslagplaats;
		private $validationmsg;
		private $errormsgs;
		private $isopslagplaats =false;
		/**
		* @param $forminf array(items=>array(""=>""),valid=>array(""=>""))
		* @param $type "database","filesystem"
		*/
		function __construct(&$forminf){
			if (is_array($forminf)&&is_array($forminf['items'])){
				$this->forminf =$forminf;
			}
		}
		/**
	 	* @param $arraso_arr array [0]array(key=>value)[1]array(key=>value) 
	 	* @param 
		*/
		public function save_lines($arraso_arr,$dovalidation = true){
			if($dovalidation){
				array_walk($arraso_arr,'save_line');
			}else{
				array_walk($arraso_arr,'save_line',$dovalidation);
			}
		}
		/**
		 * @param $aso_arr array key=>value
		 * @param $key always 0 this is for a use with array_walk
		*/
		public function save_line(&$aso_arr,$key,$dovalidation = true ){
			if($this->isopslagplaats){
				if($dovalidation){
					$validator = new valid();
					$data = $validator->dovalidation($aso_arr,$this->forminf);
					//$this->test($data);
					if($validator->is_valid()){
						if ($this->opslagplaats->save_line($aso_arr)){
							return "saved";
						}						
					}else{
						//only if there is a error
						return $validator->geterrors();
						if(isset($this->validationmsg)){
							while (list($key, $val) = each($this->errormsgs)){
			    				print "key".$this->validationmsg[$key];
								print "value".$this->validationmsg[$value];
							}
						}
						return "some errors";
					}
				}else{
					return "must not validate";
				}
			}else{
				return "[error]DATA.inc place to save data not ready";
			}
		}
		/**
		 * @param $aso_arr byrefence
		*/
		public function setvalidationmsg(&$aso_arr){
    		$this->validationmsg=$aso_arr;
		}
		/**
		 * @param $DS_filename data resource file
		 * @param $faze  vb DB_source::DEVELOPMENT,
		*/
		public function initdatabase($DS_filename,$faze){
			$this->opslagplaats = new DB_source($faze,$DS_filename);
			$this->isopslagplaats = $this->opslagplaats->CON_Startup($this->forminf['name']);
		}
		/**
		* @param $FILE_ref referention to the file
		*/
		public function initfile($FILE_ref){
			$this->opslagplaats = new csv_plus($FILE_ref,$this->forminf['name'].$faze.".csv");
			$this->isopslagplaats = $this->opslagplaats->is_readytouse();
			$this->$FILE_ref=$FILE_ref;
		}
		function __deconstruct(){
			//fclose ($this->file);
		}
		private function test($data){
			print"  isarray forminf".(is_array($this->forminf)?"1":"0") ."<br />";
			print"  isarray forminf[items]".is_array($this->forminf['items'])."<br />";
			print"  isarray forminf[tovalid]".is_array($this->forminf['tovalid'])."<br />";
			print"===>";
			print_r($data);
		}

	}
?>