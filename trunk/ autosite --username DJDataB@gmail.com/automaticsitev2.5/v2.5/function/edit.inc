<!--  // Include other files  -->
<!-- css     .Editorpanel   { contentEditable:true; backgroundColor = '#FFFFFF';
    border:'thin inset';
    width:'100%';
    height:'100%';
    overflow:'auto';
    wordWrap:'break-word'}-->
<?php
  /**
  * @author Lieven Roegiers
  * @copyright 2008->
  * @CMS autosite
  * @deprecated UNDER CONSTRUCTION
  * @todo sending to server
  * when people like to help it can.
  */
	?>
<meta name="robots" content="noindex, nofollow" />
<link href="<?php print $autosite['layout']?>css/editor.css" rel="stylesheet" type="text/css" />
<div id="xx" class="ERROR">
	UNDERCONSTRUCT.use at own risk. NOT WORKING EDITION
</div>
<div id="editERROR" class="ERROR">
You must use Internet Explorer 5.5 or later.or mozila \n\nThe used function wil not works
</div>
<div id="editor">
	<form action="test" method="get" enctype="text/plain" >
    	<!-- ********************** EDITORMENU *********************-->
		<div class="editormenu">
	     	<?php include($autosite['functions']."editor/actionstoolbar.inc")?>
		</div>
       	<div class="editormenu">
	     	<div class="editorbtn" align="left">
			   	Layoutfromcss: 
	        	<select name="Layoutface" >
	          		<option value="css1" selected="selected" >css1</option>
	        	</select>
        		<a class="editorbtn"		href="javascript:SelectClass()" 					id="make it">make it</a> 
        	</div>
        	<div class="editorbtn">
        		<a class="editorbtn"	href="javascript:gotoOtherView('source');" 	id="tosource">toHTMLsource</a>
      			<a class="editorbtn"	href="javascript:gotoOtherView('WYSIWYG');" 	id="tosource">toWYSIWYG</a> 
        	</div>
            <div class="editorbtn" align="right">
            	Name:<input type="text" name="title"  value="newpage" />
        	</div>
		</div>
        <!-- ********************** EDITORPANEL *********************-->
	    <div id="Editorpanel" contenteditable="true" onmouseout="selection=window.getSelection();">
	  		<div id="Editorpanel" contenteditable="true" onmouseout="selection=window.getSelection();">
					<?php include($autositelang[$autosite['lang']].$id.".dat");?>
			</div>
		</div>
	    <!-- ********************** EDITORFOOTER *********************-->
		<div class="Editorfoot">
			<b>Editor Size: 
			<input onchange="javascript:doresize()" type="text" id="width" size="4" value="70%" />
			<input onchange="javascript:doresize()" type="text" id="height" size="4" value="350" />
			<input onclick="javascript:gotoOtherView('source');" type="button" name="tocode" value="toCode" />
      		</b>
       </div>
       <div class="Editor foot">
	   </div>
   </form>
</div>
		<div class="editorpanels">
	     	<?php include($autosite['functions']."editor/panels.inc")?>
		</div>
<script>
  var editorpanelname = document.getElementById("Editorpanel");//(-- W3C correction OK! --)
  function doWYSIWYG(command, condition, arg){
    //editorpanelname.focus();
    if(!condition) condition=false;
    document.execCommand(command, condition, arg);
  }
  function doifupload(){
  	
  }
  function senddata(){
    
  }
  function doselect(){
  		if(window.getSelection) {
			s.removeAllRanges();
			s.addRange(rng);
		} else {
			rng.select();
		}
  }
  function doresize(){
    var Y = document.getElementById('height').value;
    var X = document.getElementById('width').value;
    if(issize(X,Y)) { 
		alert("One or more of the dimensions entered cannot be supported. Setting defaults.");
		X="98%"; Y="350";
	}
	replacevalue("width",X);
	replacevalue("height",Y);
	editorpanelname.width=X;
	editorpanelname.height=Y;
  }
  //todo delete _moz_dirty if mozila
  function isbrowserok(){
		if(window.navigator.appName == "Microsoft Internet Explorer"){
			var IEversion = window.navigator.appVersion
			return (IEversion.substring(IEversion.indexOf("MSIE") + 5, IEversion.indexOf("MSIE") + 8) >= 5.5)
		}else if(window.navigator.appName == "Netscape"){
		  	return true;	
		}else{//geen ondersteunde browser
			return false;
		}
   }
  	function issize(X,Y){
		var xlen = X.length;
		var xsub = X.substring(0,xlen-1);
		//-- take last char and lie %--&&-- max100 min50
		if((X.substring(xlen-1,xlen))=="%"&&(xsub>100||xsub<50)||X>screen.width||X<200||isNaN(xsub-1)){
			 return false;
		}
		var ylen = Y.length;
		if((Y.substring(ylen-1,ylen))=="%"||Y<200||isNaN(Y.substring(0,ylen-1))) {
			return false;
		}		
	}
	function replacevalue(id,value){
			  document.getElementById(id).value=value;
	}
	function setclass(id,value){
			  document.getElementById(id).className=value;
	}
	var oldpanel;
	var selection ="";
	if (isbrowserok()){
		setclass("editERROR",'ERROR hidden');
	}else {
		setclass("editor",'');
	}
</script>
<link rel="StyleSheet" type="text/css" href="<?php print $autosite['layout']?>css/style_syntax_highlite.css" />
