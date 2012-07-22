var m_top=7;
if (navigator.javaEnabled() < 1) {
    var m_subtop = 60;
}
if (navigator.javaEnabled() == 1) {
    
} 
if (navigator.appName !== 'Microsoft Internet Explorer'){
    	m_subtop=m_subtop - 10;
}  
var m_target="_self";
var m_vieuw ="<?php  print $_SERVER['SCRIPT_NAME'] ?>";//request handeler 
var m_sub="";//sub menu
var m_top2="";//menu top 
var m_topcl=""; //menu top klokline
menu_start();