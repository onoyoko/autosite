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
<div id="editERROR" class="ERROR">
You must use Internet Explorer 5.5 or later.or mozila \n\nThe used function wil not works
</div>


	<form id="editor" action="<?php print$_SERVER["PHP_SELF"].(isset($attributen)?$attributen."&handeling=save":"handeling=save");?>" method="POST" enctype="multipart/form-data" >
	   	<!-- ********************** EDITORMENU *********************-->
		<div class="editormenu">
	     	<?php include($autosite['functions']."editor/actionstoolbar.inc")?>
            <?php include($autosite['functions']."editor/linktoolbar.inc")?>
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
       		      			
        	</div>
            <div class="editorbtn" align="right">
            	Name:<input type="text" name="title"  value="newpage" />
        	</div>
                                    <!-- hidden" align="right"-->
            <div id="return" class="ERROR"> return </div>
		</div>
        <!-- ********************** SOURCEPANEL *********************-->
		<div id="Sourcepanel" class="Apanel hidden">
			<textarea id="Source" name="html" wrap="VIRTUAL" class="Source">
				<?php include($autositelang[$autosite['lang']].$content.".dat");?>
			</textarea>
		</div>

        <!-- ********************** EDITORPANEL *********************-->
		<!-- removed onmouseout="selection=window.getSelection();" for boring IE-->		
	    <div id="Editorpanel" contenteditable="true" class="Apanel"  ><?php include($autositelang[$autosite['lang']].$content.".dat");?></div>
	    <!-- ********************** EDITORFOOTER *********************-->
		<div id="Editorfoot" class="Apanel" >
			<!--Editor Size: 
			<input onchange="javascript:doresize()" type="text" id="width" size="4" value="70%" />
			<input onchange="javascript:doresize()" type="text" id="height" size="4" value="350" />
			<input onclick="javascript:gotoOtherView('source');" type="button" name="tocode" value="toCode" />
			-->
			<a href="javascript:tosource();//gotoOtherView('source');" 	id="tosource">TOsource</a>&bull;
			<a href="javascript:totexteditor();//gotoOtherView('WYSIWYG');" id="tosource">TOeditor</a>&bull;
			<a href="javascript:senddata();//gotoOtherView('WYSIWYG');" id="tosource">SAVE</a>&bull;
		</div>
       <div id="spacing">
	   </div>
   </form>

		<div class="editorpanels">
	     	<?php include($autosite['functions']."editor/panels.inc")?>
		</div>
<script >
  var editorpanelname = document.getElementById("Editorpanel");//(-- W3C correction OK! --)
  doWYSIWYG('underline')
  function doWYSIWYG(command, condition, arg){
    //editorpanelname.focus();
    if(!condition) condition=false;
    document.execCommand(command, condition, arg);
  }
  function doWYSIWYG2(command, condition, arg){
   editorpanelname.focus();
   addPTag(editorpanelname, command);
  }
  function doWYSIWYG3(){

  }
  function getselectedtext(){
    var txt = '';
    if (window.getSelection){
        txt = window.getSelection();
    }else if (document.getSelection){
        txt = document.getSelection();
    }else if (document.selection){
        txt = document.selection.createRange().text;
    }else
	  return;
    return txt;
  } 
  var issource =false;
  function tosource(){
  	if (!issource){
  		document.getElementById("Source").value = editorpanelname.innerHTML;
  		issource = true;
  	}
  	
  	//switch to other vieuw
    setclass("Editorpanel",'hidden Apanel');
  	setclass("Sourcepanel",'Apanel');
  }
  function totexteditor(){
  	if (issource){
  		editorpanelname.innerHTML = document.getElementById("Source").value;
  		issource = false;
  	}  	
 	//switch to other vieuw
	setclass("Editorpanel",'Apanel');
  	setclass("Sourcepanel",'hidden Apanel');
  }
  function senddata(Field){
	tosource();
	document.getElementById("editor").submit();
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
  		if (navigator.userAgent.indexOf("Firefox")!=-1){
  			return true;
  		}else if(window.navigator.appName == "Microsoft Internet Explorer"){//you must use a better browser
			var IEversion = window.navigator.appVersion;
			alert(window.navigator.appName + "you must use a better browser for this function");
			return (IEversion.substring(IEversion.indexOf("MSIE") + 5, IEversion.indexOf("MSIE") + 8) >= 5.5)
		}else if(window.navigator.appName == "Netscape"){//&&(parseInt(appVersion)==4
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
		return true;		
	}
	function replacevalue(id,value){
			  document.getElementById(id).value=value;
	}
	function setclass(id,value){
			  document.getElementById(id).className=value;
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
<div id="spacing">
</div>
<div id="spacing">
</div>


<link rel="StyleSheet" type="text/css" href="<?php print $autosite['layout']?>css/style_syntax_highlite.css" />
