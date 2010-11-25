<?PHP
 /**
 * @author Lieven Roegiers
 * @copyright 2009 
 * @CMS autosite
 * opensource http://code.google.com/p/autosite/
 */
if (!function_exists('LOG')){//include_once its when it is include in the php lib
class LOG {
	private	$Delimiter=',';//see save_line ?? date(Y,m,d)
	private $maxfilesize=1000;
	private $filelocation;
    private $minlivetime =0;
	private $file;
	private $errornr;
	public function __construct($pathname,$filelocation,$lifetime = 0){
		$this->filelocation=$pathname.$filelocation;
		$this->minlivetime = $lifetime;//(1 * 1 * 60 * 60);
	}
	private function open($mode='a+'){
		return($this->is_ReadyToUse()&& $this->file = fopen($this->filelocation,$mode)); //File!found E53 
	}
	function save_line($arrData,$del_oldlines=true){
		if ($del_oldlines){
			$this->del_oldlines();
		}
		$datastring =" ".date(Y,m,d).$this->Delimiter.implode($this->Delimiter,$arrData)."\n";//space on the front is for search
		return ($this->open()&& fputs($this->file, $datastring));
	}
	public function is_ReadyToUse(){
		return(isset($this->filelocation)&& is_file($this->filelocation));
	}
	/**
	* 
	*/
	private function del_oldlines(){
		if ($this->is_ReadyToUse()&& filesize($this->filelocation)>$this->maxfilesize){
			if ($this->bakup($this->filelocation)){//rename($path.$file, $path.$bakfile);
				unlink ($this->filelocation);
			}
			$lines = file($this->filelocation.".BAK");
			if (!$this->open()) {
				foreach ($lines as $line_num => $line){
					$kkey=explode(',', $line);
					if((time() > $kkey[0])){//releastijd
					}elseif(fputs($file,$line)){//infileplaatsen
					}else {//echo "error write bakup";
					}
				}		
			}
		}	
	}
	function HTML_listvieuw($Fname){
		$row = 1;
		$fp = fopen ($fname,"r");
		while ($data = fgetcsv($Fname,1000,",")) {
		    $num = count ($data);
		    print "<p> $num velden in regel $row: <br>\n";
		    $row++;
		    for ($c=0; $c < $num; $c++) {
		        print $data[$c] . "<br>\n";
		    }
		}	
	}
	/*function HTML_table($Fname){
		$row = 1;
		$fp = fopen ($fname,"r");
		while ($data = fgetcsv($Fname,1000,",")) {
		    $num = count ($data);
		    print "<p> $num velden in regel $row: <br>\n";
		    $row++;
		    for ($c=0; $c < $num; $c++) {
		        print $data[$c] . "<br>\n";
		    }
		}	
	}*/
	function find_line($findstring,$resul=1){
		if ($this->open()){
			while (!feof($this->file))
	    		{$line = fgetcsv($this->file,1024,",");
	    			if(is_array ($line)){
						if (!$pos = array_search($findstring,$line )){ 
	     				//print_r($line); //niet gekozen items	
	     				}else{
	     					return  $line ;
	     					exit;	
						}
	     			}else{
						//fun_error(381);//Invalid array
					}
	 		$line=""; 
			}
		}
	}
	function __destruct(){
		//fclose ($this->file);
	}	 	
}
}
?>