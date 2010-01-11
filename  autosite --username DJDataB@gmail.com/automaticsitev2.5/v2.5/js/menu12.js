/*javascript*/
var m_sub="";//sub menu
var m_top2="";//menu top 
var m_topcl=""; //menu top klokline
var cl;
var menu;
var pos2="div";
var pos="span";
var m_font="font-size:17px;";
var m_texta = "text-align : center;" ;
document.write('<script>var m_select="topid0"; var m_topselect="topid0"; </script><!--Lieven Roegiers __djdb__-->');//zorgen dat het laaste element geselecteert is ;//geselecteerde item by id
if (navigator.appName == 'Microsoft Internet Explorer'){
	//document.write("u ziet niet alles download firefox ")
	var optie="&nbsp;";
	var optie2="&nbsp;";
}else{
	var optie="><button";
	var optie2="</button>";
}
function menu_css(){
	var I ='width:80%;' ;
	document.write("<style type=text/css>");
	document.write(" .mnu_click{top:10px;"+m_texta + m_cur+ m_font + " background:"+ m_Fcolor+ ";}");
	document.write(" .mnu_out{"+m_texta+m_cur+ m_font+" background: "+ m_Bcolor +" }") ;
	document.write(" .hidden{visibility:hidden;}");
	document.write(" .mnu_hover{"+m_texta+m_cur+ m_font+" background:"+m_Hcolor +" }");
	document.write(" .mnu{"+m_texta+ I +"position:absolute;width:80%;"+ m_cur+" top:"+m_top+"px; "+ m_just+" background:"+m_Bcolor+"; border-left:"+m_rand2+"border-right:"+m_rand2+"border-top:"+m_rand+"border-bottom: "+m_rand2+ ";  z-index:2}");
		document.write(" .nav{"+m_texta+ I +"position:absolute;width:80%;"+ m_cur+" top:0px; "+ m_just+" background:"+m_Bcolor+";  z-index:2}");
	document.write(" .mnutop{position:absolute;"+m_Margin+m_texta+" width:80%;" + m_cur + "background:"+m_Bcolor+ m_just +"}border-bottom: "+m_rand +"z-index:2");
	document.write(" body{font-family:Arial,Helvetica,sans-serif; font-size:80%; font-size-adjust:none;}");
	document.write(" </style>");
}
function menu_start(){
	//document.write("<table> <tr><td>\r\n");
	document.write("<"+pos2+" class='mnutop' id='menu'>\r\n");
	var m_navtop;
	for(var i=0;(i<Items.length&&typeof(Items[i])!="undefined");i++)
		{	
		if (Items[i][0].charAt(cl)=="^")
		{	Items[i][0]=Items[i][0].substring(1,Items[i][0].length);
			m_sub+= M_item("subid"+ i + "",Items[i],pos,m_navtop+"=&gt;"+Items[i][0]);
		} else {
			m_sub+="</"+pos2+">\r\n";
			m_top2+=M_item('topid'+i,Items[i],pos,Items[i][0]);
			m_sub+="<"+pos2+" class='mnu hidden' id='topid"+i+"link'>\r\n";
			m_navtop = Items[i][0];
		}
	};
	document.write(m_top2);
	document.write("</"+pos2+" >\r\n");
	document.write(m_sub);
	//document.write("</td></tr><tr><td> \r\n");
	document.write("</"+pos2+" ><div class='nav' id='nav' >=>home</div><br />");//navigator
	//document.write("</tr></td></table> \r\n");	
	M_out('topid0');
};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<functies>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    
function M_over(id){
	if (id == m_select){
		document.getElementById(id).className = 'mnu_click';		
	} else{
		document.getElementById(id).className = 'mnu_hover';			
	}
	if (id.substring(0,3)=="top" =="top"&&!(id==m_topselect)){
	 	document.getElementById(id+"link").className = 'mnu';
	 	document.getElementById(m_topselect+"link").className = 'mnu hidden';
		m_topselect = id;	
	}
}  
function M_out(id){
	if (id == m_select){
		document.getElementById(id).className = 'mnu_click';
	} else{
		document.getElementById(id).className = 'mnu_out';	
	}
}
function M_click(id){// submenu beschikbaar
if (id.substring(0,3)=="top"&&!(id==m_topselect)){
		document.getElementById(m_topselect+"link").className = 'mnu hidden';
		document.getElementById(m_topselect).className = 'mnu_out';
		var m_top2=document.getElementById("menu").clientHeight + m_subtop ;
	    document.getElementById(id+"link").style.top = m_top2  + 5 + 'px';
	    document.getElementById(id+"link").className = 'mnu';
		m_topselect=id;
		document.getElementById(m_select).className = 'mnu_out';
	}else{
		document.getElementById(m_select).className = 'mnu_out';
	}
	document.getElementById(id).className = 'mnu_click';
	m_select=id;
}
function M_clickb(id){//geen submenu beschikbaar
if (id.substring(0,3)=="top"&&!(id==m_topselect)){
		document.getElementById(m_topselect).className = 'mnu_out';
		document.getElementById(m_topselect+"link").className = 'mnu hidden';
		document.getElementById(m_select).className = 'mnu_out';
		m_topselect=id;
	}else{
		if (m_select.substring(0,3)=="sub"){
			document.getElementById(m_select).className = 'mnu_out';
		}
	}
	document.getElementById(id).className = 'mnu_click';
	m_select=id;
}
function M_nav(label){
	document.getElementById('nav').innerHTML=label;
}
function M_item(id,label,pos,nav){//subitem printen
	var V_return="";
	if (typeof(label[1])!="undefined"){
		V_return+="|<a href='/vieuw.php5?file="+label[1]+"' target='"+m_target+"'";
		V_return+= " id='"+ id + "' class='mnu_out '  ";
		V_return+="onmouseover=M_over('"+ id + "') ";
		V_return+="onmouseout=M_out('"+ id + "') ";
		V_return+="onClick=M_clickb('"+ id + "'),M_nav('"+M_replace(nav," ")+"')>";
		V_return+=" "+label[0];
		V_return+="</a> \r\n";
	} else{
	    V_return+="|<a id='"+ id + "' class='mnu_out '  ";
		V_return+="onmouseover=M_over('"+ id + "') ";
		V_return+="onmouseout=M_out('"+ id + "') ";
		V_return+='onClick=M_click("'+ id + '"),M_nav("'+M_replace(nav," ")+'")>\r\n';
		V_return+=label[0]+"</a> \r\n";
	}
	return V_return;	
}   
function M_replace(string,tag) {
	var leter;
	while (string.indexOf(tag)!=-1)
		{
			string = string.replace(tag,"&#160;");
		}
	return string
}
