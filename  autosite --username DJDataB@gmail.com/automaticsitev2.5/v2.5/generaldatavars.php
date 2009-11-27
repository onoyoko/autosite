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
$autosite['trueext']=array(".doc",".jpg",".txt");
/**
 * $formsdata['formname']
 * 		['items']=the items form the form
 * 		['tovalid']=the items form the form that must be valid
 * 		['type']=file or datatable
 * 		['title']=@deprecated
 * 		['vieuw']= vieuw the data on the page yes/no
*/
$today=date("l j F Y");

$formsdata['nota']['items']=array("naam"=>"","mail"=>"","date"=>"","msg"=>"","submit"=>"");
$formsdata['nota']['tovalid']=array("naam","mail","msg");
$formsdata['nota']['type']="file";
$formsdata['nota']['name']="guestbook";
$formsdata['nota']['title']="sign here";
$formsdata['nota']['vieuw']=true;
$formsdata['nota']['loginniveau']=111;

$xmlplugs['xmlcv']['items']=array("test"=>"");
$xmlplugs['xmlcv']['tovalid']=array("test"=>"");
$xmlplugs['xmlcv']['vieuw']=false;//sollicitant can not sea others
$xmlplugs['xmlcv']['name']="cv";
$xmlplugs['xmlcv']['type']="file";
$xmlplugs['xmlcv']['dtd']="???";
$xmlplugs['xmlcv']['loginniveau']=0;

$xmlplugs['rss']['items']=array("test"=>"");
$xmlplugs['rss']['tovalid']=array("test"=>"");
$xmlplugs['rss']['vieuw']=false;//do not vieuw new data
$xmlplugs['rss']['name']="rssin";
$xmlplugs['rss']['type']="file";
$xmlplugs['rss']['dtd']="???";
$xmlplugs['rss']['loginniveau']=222;

$A_vmbridge['j2ee'];
$A_vmbridge['j2ee'];

?>