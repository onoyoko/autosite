<?PHP
 /**
 * @author Lieven Roegiers
 * @copyright 2007 refactor 2009
 * @CMS autosite
 * opensource http://code.google.com/p/autosite/
 */
if (!function_exists('csv_plus')){//include_once its when it is include in the php lib
class csv_plus implements tosave{
	private	$Delimiter=',';
	private $maxfilesize=1000;
	private $filelocation;
    private $minlivetime =0;
	private $file;
	private $errornr;
	/** 
	 * @param mixed $pathname
	 * @param mixed $filelocation
	 * @param integer $lifetime
	 * @return
	 */
	public function __construct($pathname,$filelocation,$lifetime = 0){
		$this->filelocation=$pathname.$filelocation;
		$this->minlivetime = $lifetime;//(1 * 1 * 60 * 60);
	}
	/**
	 * @param string $mode
	 * @return
	 */
	private function open($mode='a+'){
		return($this->is_readytouse()&& $this->file = fopen($this->filelocation,$mode)); //File!found E53 
	}
	/**
	 * @param mixed $arrData
	 * @param bool $del_oldlines
	 * @return
	 */
	function save_line($arrData,$del_oldlines=true){
		if ($del_oldlines){
			$this->del_oldlines();
		}
		$timestamp = ($this->minlivetime>0)?(time()+$this->minlivetime).$this->Delimiter:"";
		$datastring =" ".$timestamp.implode($this->Delimiter,$arrData);//space on the front is for search
		$datastring = $this->Aln2br($datastring)."\n";
		return ($this->open()&& fputs($this->file, $datastring));
	}
	/**
	 * @return bool
	 */
    private function Aln2br($txt){
        return strtr($txt, array("\r\n" => '<br/>', "\r" => '<br/>', "\n" => '<br/>'));
    }
    private function Abr2ln($txt){
        return strtr($txt, array("<br />" => "\n", "<br/>" => "\n"));
    }
	public function is_readytouse(){
		return(isset($this->filelocation)&& is_file($this->filelocation));
	}
	/**
	 * @param mixed $source fname
	 * @param string $destprefix
	 * @return bool
	 */
	private function bakup($source,$destprefix=".BAK"){
		return (is_file($source) && (filesize($source)>0)&& !copy($source, $source.$destprefix));
	}
    /**
	 * @return void
	 */
 	private function add($source,$destprefix=".BAK"){
		return (is_file($source) && (filesize($source)>0)&& !copy($source, $source.$destprefix));
	}
    /**
	 * @return void
	 */
	private function del_oldlines(){
		if ($this->is_readytouse()&& filesize($this->filelocation)>$this->maxfilesize){
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
	/**
	 * @param mixed $Fname
	 * @return
	 */
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
	/**
	 * @param mixed $findstring
	 * @param integer $resul
	 * @return string line
	 */
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
    	/**
	 * @param mixed $findstring
	 * @param integer $resul
	 * @return string line
	 */
	private function pos_line($findstring,$resul=1){
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
	/**
	 * @return
	 */
	function __destruct(){
		//fclose ($this->file);
	}	 	
}
}
?>