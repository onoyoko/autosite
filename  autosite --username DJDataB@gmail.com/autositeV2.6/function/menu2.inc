<?php
/**
 * @author Lieven Roegiers
 * @copyright 2009
 * @CMS autosite
 * @info write a variabele Items (path items)[key,value]
 */
include($autosite['functions']."data/FileScanner.inc");
include_once($autosite['functions']."data/properties.inc");
class Menu{
	private $lang;
    private $filename;
    private $strmenu;
    private $entry;
    private $items =array();
    private $jsvarname = "Items";
    private $id=0;
    private $properties;
    private $translations;
    private $translatprefix="menu.";
    /**
     * public function Menu($lang) {//./Layout is for security
    *	$this->lang = $lang;
	*    $this->filename = "Menu.".$lang.".dat";
	*	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<take the properties vb(forms_NL.properties)>>>>>>>>>>>>>>>>		
	*	$this->properties = getpropertiefile($autosite['translations'],$this->lang,"forms");
    * 
    * MARK=> keys begins with menu.
	*    print"<!-- menu -->";
	}*/
    public function Menu($lang,$translationslocation) {//./Layout is for security
    	$this->lang = $lang;
	    $this->filename = "Menu.".$lang.".dat";
				//<<<<<<<<<<<<<<<<<<<<<<<<<<<<take the properties vb(forms_NL.properties)>>>>>>>>>>>>>>>>		
		$this->properties = getpropertiefile($translationslocation,$this->lang,"forms");
	    print"<!-- menu constructor -->";
	}
    /**
     * @param $arr [menuitem1, menuitem2],$tolocation targetlocation 
     * @return null
     */
	public function additems($arr,$tolocatie){
 		 foreach($arr as $key){
 		 	$this->additem($key,$tolocatie);
 		 }
 	}
 	/**
    * @param $arr [menuitem1, menuitem2],$tolocation targetlocation 
    * @return null
    */
 	public function addsubitems($attlabel,$arr,$tolocatie){
 		 foreach($arr as $key){
 		 	$this->addsubitem($attlabel,$key,$tolocatie);
 		 }
 	}
 	private function additem($label,$tolocatie){
 		$pos = strpos($label, ".");
	    $name = substr($label, 0, $pos);
        if ($name !=""){
            $this->items[$name]=$tolocatie;
        }	
 	}
    private function addsubitem($attlabel,$label,$tolocatie){
    	$pos = strpos($label, ".");
	    $name = substr($label, 0, $pos);
 		$this->items[$attlabel][$name]=$tolocatie;
 	}
 	public function getif_menu_exist($has_clientjs=true){
 		if(!is_writable($this->filename)){
            return false;
        }elseif(!$has_clientjs){
        	$menu = file_get_contents($this->filename);
        	//Todo replays
        	//print '<ul>';
        	$menu = str_replace("'],['",'',$menu);//</li><li>
        	$menu = str_replace("','?",'?',$menu);
        	$menu = str_replace("-','",'--><a class="mnuitem out" href="',$menu);
        	$menu = str_replace("','-",'</a><!--',$menu);
        	$menu = str_replace("','",'">',$menu);
        	$menu = str_replace('[','<!--',$menu);//<li>
        	print str_replace(']','-->',$menu);//</li>
			print '';//</ul>
			return true;
        }else {
            print file_get_contents($this->filename);
            return true;
        }
 	}
	public function Generate_menu($has_clientjs=true){
	       $this->translations =$this->gettranslations($this->items);          
        	foreach($this->items as $page => $to){	
			   if(is_array($to)){
			   		$this->save_Item(++$this->id,$page);
			   		foreach($to as $page2 => $to){
			   			$this->save_Item("^".$this->id,$to."","content=".$page."/".$page2."&amp;lang=".$this->lang,$page2);
			   			$this->save_robotitem($to,"content=".$page."/".$page2."&amp;lang=".$this->lang);
	  		 		}
	  		 	}else{
	  		 		$this->save_Item(++$this->id,$to,"content=".$page."&amp;lang=".$this->lang,$page);	
	  		 	}
		 	}
		  return $this->getif_menu_exist($has_clientjs);
    }
    /**
    * @info write a variabele Items (path items)[key,value]
    * @param $dir to search dir
    * @param $tolocation the link to go
    * @param $array[inc]=array(".inc",".htm",".old")[exc]=array(".htaccess")
    */
    public function createMNUitemsfrom_filesystem($dir,$tovieuwport,$filter){
    	//print "<br><br>menu start<br>";
    	$FileScanner = new FileScanner();
    	$FileScanner->setfilter($filter);
    	$FileScanner->scandir($dir);
    	$this->additems($FileScanner->getdirs(),"");
    	$this->additems($FileScanner->getfils(),$tovieuwport);
    	$submenus = $FileScanner->getdirs();
        foreach($submenus as $key){
        	$FileScanner->scandir($dir."/".$key);
        	$this->addsubitems($key,$FileScanner->getfils(),$tovieuwport);
        }
    }
    private function sethomeatfirst(){
    }
    private function test(){
    	  print "<br><br>print start<div class='ERROR'><pre>";
		  print_r($this->items);
		  print "</pre><br></div>print start<br>";
    }
    private function save_Item($content,$to,$attributen=null,$label){
    	$toloc=(isset($to))?",'".$to."'":"";
		$this->save_line($this->filename,"['".$content."-'".$toloc.",'".$attributen."','".((isset($this->translations[$this->translatprefix.$label]))?$this->translations[$this->translatprefix.$label]:"%"$this->translatprefix.$label."%")."','-'],");
 	}
 	private function save_robotitem($to,$attributen){
        if (!$file2 = fopen("robots.txt", 'a+')) {
            return false;
            exit ;
        }
        if (!fwrite($file2, "Allow: /".$to.$attributen."\n")) {
            return false;
            exit ;
        }
        return true;
 	}
    private function save_line($Fname, $data) {
        //print "printdata '".$data."'naar $Fname";
        if (!$file = fopen($Fname, 'a+')) {
            return false;
            exit ;
        }
        if (!fwrite($file, $data)) {
            return false;
            exit ;
        }
        return true;
    }
    function Menu_bakup() {
        if (is_file($this->filename) && (filesize($this->filename) > 0)) {
            rename($this->filename, $this->filename.".bak");
        }
    }
    public function Menu_refrech() {
        if (unlink($file3)) {
            $this->menu_write();
        }
    }
    private function gettranslations($keys){
      	    $translations = array();
            foreach($keys as $item => $delme){	
                $translations[$this->translatprefix.$item]="";
		 	} 
        	if (isset($this->properties)){
        	    //print("gettranslations");
     		    return $this->properties->getproperties($translations,$this->translatprefix);
            }else {
                return null;
            }
    }
}
?>
