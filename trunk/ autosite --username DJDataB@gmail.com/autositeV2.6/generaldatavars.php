<?php
/**
 * @author Lieven Roegiers
 * @copyright 2009
 * @CMS autosite
 */
if ($offlinedebug == true){
	
}
//<<<<<<<<<<<<<<<<<<<<<< general vars>>>>>>>>>>>>>>>>

if(!isset($autosite['site'])){//construction general vars before
	if(isset($loc)){
		$loc = "./".$loc;
	} else {
		$loc = "./";
	}
} 
$globalaccess=array("");
$catalogs['1e catalog']= $autosite['xmlpath']."catalog1.xml";
$catalogs['2e catalog']= $autosite['xmlpath']."catalog2.xml";
//<<<<<<<<<<<< [your formname][items](all the items that there is)>>>>
//<<<<<<<<<<<< [your formname][valid](all the items that must validate)>>>>
//<<<<<<<<<<<< [your formname][type]"file","mysql">>>>
//<<<<<<<<<<<< [your formname][name]name of database of file>>>>

$autosite['templates'] =$autosite['layout']."templates/";//
$autosite['translations'] =$autosite['layout']."translations/";//
$autosite['uploads'] =$autosite['layout']."uploads/";//
$standartform="djs";
$autosite['trueext']=array(".doc",".jpg",".txt",".gif",".png");
$views["templatevieuw"]= "./preparts/data_templatevieuw.inc";
$views["search"]= "./preparts/data_search.inc";
$views["gallery"]= "./preparts/data_gallery.inc";
$views["table"]= "./preparts/data_table.inc";
$views["XML"]= "./preparts/data_xml.inc";
$views["RSS"]= "./preparts/data_rss.inc";
/**
 * $formsdata['formname']
 * 		['items']=the items form the form
 * 		['tovalid']=the items form the form that must be valid
 * 		['type']=file or datatable
 * 		['title']=@deprecated
 * 		['vieuw']= vieuw the data on the page yes/no
*/
$today=date("l j F Y");


$xmlplugs['xmlcv']['items']=array("test"=>"");
$xmlplugs['xmlcv']['tovalid']=array("test"=>"");
$xmlplugs['xmlcv']['vieuw']=false;//sollicitant can not sea others
$xmlplugs['xmlcv']['name']="cv";
$xmlplugs['xmlcv']['type']="file";
$xmlplugs['xmlcv']['dtd']="???";
$xmlplugs['xmlcv']['loginniveau']=0;


$A_vmbridge['j2ee']="";


?>