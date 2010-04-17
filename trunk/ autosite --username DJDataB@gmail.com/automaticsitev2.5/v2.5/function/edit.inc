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
	<form action="<?php print$_SERVER["PHP_SELF"]?>" method="get" enctype="text/plain" >
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
        		
      			
        	</div>
            <div class="editorbtn" align="right">
            	Name:<input type="text" name="title"  value="newpage" />
        	</div>
		</div>
        <!-- ********************** SOURCEPANEL *********************-->
		<div id="Sourcepanel">111111
			<textarea id="Source" wrap="VIRTUAL" class="Source">
				DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
			</textarea>
		</div>
	    <div id="Centralpanel">222222<br />
			<input type="button" value="test" /><br />
			<input type="submit" value="Save" /><br />
			<a class="editorbtn"	href="javascript:tosource();//gotoOtherView('source');" 	id="tosource">SOURCE     &lt;= </a>
			<a class="editorbtn"	href="javascript:totexteditor();//gotoOtherView('WYSIWYG');" 	id="tosource">WYSIWYG   =&gt;</a> 
			
			
		</div>
        <!-- ********************** EDITORPANEL *********************-->		
	    <div id="Editorpanel" contenteditable="true" onmouseout="selection=window.getSelection();">33333
					<?php include($autositelang[$autosite['lang']].$id.".dat");?>
		</div>
	    <!-- ********************** EDITORFOOTER *********************-->
		<div id="Editorfoot">
			<b>Editor Size: 
			<input onchange="javascript:doresize()" type="text" id="width" size="4" value="70%" />
			<input onchange="javascript:doresize()" type="text" id="height" size="4" value="350" />
			<input onclick="javascript:gotoOtherView('source');" type="button" name="tocode" value="toCode" />
      		</b>
       </div>
       <div id="spacing">
	   </div>
   </form>
</div>
		<div class="editorpanels">
	     	<?php include($autosite['functions']."editor/panels.inc")?>
		</div>
<script >
  var editorpanelname = document.getElementById("Editorpanel");//(-- W3C correction OK! --)
  function doWYSIWYG(command, condition, arg){
    //editorpanelname.focus();
    if(!condition) condition=false;
    document.execCommand(command, condition, arg);
  }
  function todoifupload(){
 	//move to textarea
	 tosource();
	//senddata();
  }
  function tosource(){
  	document.getElementById("Source").value = document.getElementById("Editorpanel").innerHTML;
  }
  function totexteditor(){
  	document.getElementById("Editorpanel").innerHTML = document.getElementById("Source").value;
  }
  function senddata(Field){
	//document.form.submit();
	//document.forms[0].submit();
  }
		var returntext;   
		function replaceastring(param){
 		alert( "under construction" );
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
  			
  		}else if(window.navigator.appName == "Microsoft Internet Explorer"){//you must use a better browser
			var IEversion = window.navigator.appVersion
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
	
	var BrowserDetect = {
	init: function () {
		this.browser = this.searchString(this.dataBrowser) || "An unknown browser";
		this.version = this.searchVersion(navigator.userAgent)|| this.searchVersion(navigator.appVersion)|| "an unknown version";
		this.OS = this.searchString(this.dataOS) || "an unknown OS";
	},
	searchString: function (data) {
		for (var i=0;i<data.length;i++)	{
			var dataString = data[i].string;
			var dataProp = data[i].prop;
			this.versionSearchString = data[i].versionSearch || data[i].identity;
			if (dataString) {
				if (dataString.indexOf(data[i].subString) != -1)
					return data[i].identity;
			}
			else if (dataProp)
				return data[i].identity;
		}
	},
	searchVersion: function (dataString) {
		var index = dataString.indexOf(this.versionSearchString);
		if (index == -1) return;
		return parseFloat(dataString.substring(index+this.versionSearchString.length+1));
	},
	dataBrowser: [
		{string: navigator.userAgent,	subString: "Chrome",									identity: "Chrome"	},
		{string: navigator.userAgent,	subString: "OmniWeb",		versionSearch: "OmniWeb/",	identity: "OmniWeb"	},
		{string: navigator.vendor,		subString: "Apple",			identity: "Safari",			versionSearch: "Version"},
		{prop: window.opera,			identity: "Opera"},
		{string: navigator.vendor,		subString: "iCab",			identity: "iCab"			},
		{string: navigator.vendor,		subString: "KDE",			identity: "Konqueror"		},
		{string: navigator.userAgent,	subString: "Firefox",		identity: "Firefox"  		},
		{string: navigator.vendor,		subString: "Camino",		identity: "Camino"   		},
		{		// for newer Netscapes (6+)
			string: navigator.userAgent,	subString: "Netscape",	identity: "Netscape"		},
		{	string: navigator.userAgent,	subString: "MSIE",		identity: "Explorer",		versionSearch: "MSIE"	},
		{	string: navigator.userAgent,	subString: "Gecko",		identity: "Mozilla",		versionSearch: "rv"		},
		{ 		// for older Netscapes (4-)
			string: navigator.userAgent,	subString: "Mozilla",	identity: "Netscape",		versionSearch: "Mozilla"}
	],
	dataOS : [
		{string: navigator.platform,		subString: "Win",		identity: "Windows"		},
		{string: navigator.platform,		subString: "Mac",		identity: "Mac"			},
		{string: navigator.userAgent,	 	subString: "iPhone",    identity: "iPhone/iPod" },
		{string: navigator.platform,		subString: "Linux",		identity: "Linux"		}
	]
};
BrowserDetect.init();

	
	
</script>
<link rel="StyleSheet" type="text/css" href="<?php print $autosite['layout']?>css/style_syntax_highlite.css" />
