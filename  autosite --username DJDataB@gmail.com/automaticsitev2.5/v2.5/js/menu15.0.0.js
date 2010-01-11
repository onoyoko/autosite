/*javascript*/
var cl;
var menu;
var pos2="div";
var pos="span";
document.write('<script>var m_select="topid0"; var m_topselect="topid0"; </script><!--Lieven Roegiers __djdb__-->');//zorgen dat het laaste element geselecteert is ;//geselecteerde item by id
function menu_start(){
	//document.write("<table> <tr><td>\r\n");
	document.write("<div class='mnutop' id='menu'>\r\n");
	var m_navtop;//
	for(var i=0;(i<Items.length&&typeof(Items[i])!="undefined");i++){	
		if (Items[i][0].charAt(cl)=="^"){
			//Items[i][2]=Items[i][2].substring(1,Items[i][2].length);
			
			m_sub+= M_item("subid"+ i + "",Items[i],pos,m_navtop+"=&gt;"+Items[i][3]);
		}else{
			m_sub+="</div>\r\n";
			m_top2+=M_item('topid'+i,Items[i],pos,Items[i][3]);
			m_sub+="<div class='mnu hidden' id='topid"+i+"link'>\r\n";
			m_navtop = Items[i][3];
		}
	};
	document.write(m_top2);
	document.write("</div><br/>\r\n");
	document.write(m_sub);
	//document.write("</td></tr><tr><td> \r\n");
	document.write("</div><br/><div class='nav' id='nav' >=>home</div><br />");//navigator
	//document.write("</tr></td></table> \r\n");	
	M_out('topid0');
};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<functies>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    
function M_over(id){
	if (id == m_select){
		document.getElementById(id).className = 'mnuitem click';		
	}else{
		document.getElementById(id).className = 'mnuitem hover';			
	}
	if (id.substring(0,3)=="top" =="top"&&!(id==m_topselect)){
	 	document.getElementById(id+"link").className = 'mnu';
	 	document.getElementById(m_topselect+"link").className = 'mnu hidden';
		m_topselect = id;	
	}
}  
function M_out(id){
	if (id == m_select){
		document.getElementById(id).className = 'mnuitem click';
	}else{
		document.getElementById(id).className = 'mnuitem out';	
	}
}
function M_click(id){// submenu beschikbaar
if (id.substring(0,3)=="top"&&!(id==m_topselect)){
		document.getElementById(m_topselect+"link").className = 'mnu hidden';
		document.getElementById(m_topselect).className = 'mnuitem out';
		var m_top2=document.getElementById("menu").clientHeight + m_subtop ;
	    document.getElementById(id+"link").style.top = m_top2  + 5 + 'px';
	    document.getElementById(id+"link").className = 'mnu';
		m_topselect=id;
		document.getElementById(m_select).className = 'mnuitem out';
	}else{
		document.getElementById(m_select).className = 'mnuitem out';
	}
	document.getElementById(id).className = 'mnuitem click';
	m_select=id;
}
function M_clickb(id){//geen submenu beschikbaar
if (id.substring(0,3)=="top"&&!(id==m_topselect)){
		document.getElementById(m_topselect).className = 'mnuitem out';
		document.getElementById(m_topselect+"link").className = 'mnu hidden';
		document.getElementById(m_select).className = 'mnuitem out';
		m_topselect=id;
	}else{
		if (m_select.substring(0,3)=="sub"){
			document.getElementById(m_select).className = 'mnuitem out';
		}
	}
	document.getElementById(id).className = 'mnuitem click';
	m_select=id;
}
function M_nav(label){
	document.getElementById('nav').innerHTML=label;
}
function M_item(id,label,pos,nav,location){//subitem printen
	var V_return="";
	if (typeof(label[2])!="undefined" && label[2]!=""){
		V_return+="<a href='"+label[1]+'?'+label[2]+"' target='"+m_target+"'";
		V_return+= " id='"+ id + "' class='mnuitem out '  ";
		V_return+="onmouseover=M_over('"+ id + "') ";
		V_return+="onmouseout=M_out('"+ id + "') ";
		V_return+="onClick=M_clickb('"+ id + "'),M_nav('"+M_replace(nav," ")+"')>";
		V_return+=" "+label[3];
		V_return+="</a> \r\n";
	} else{
	    V_return+="<a id='"+ id + "' class='mnuitem out '  ";
		V_return+="onmouseover=M_over('"+ id + "') ";
		V_return+="onmouseout=M_out('"+ id + "') ";
		V_return+='onClick=M_click("'+ id + '"),M_nav("'+M_replace(nav," ")+'")>\r\n';
		V_return+=label[1]+"</a> \r\n";
	}
	return V_return;	
}   
function M_replace(string,tag) {
	var leter;
	while (string.indexOf(tag)!=-1){
			string = string.replace(tag,"&#160;");
	}
	return string;
}
