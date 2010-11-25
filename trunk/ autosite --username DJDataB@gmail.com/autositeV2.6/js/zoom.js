//really not important (the first two should be small for Opera's sake)
PositionX = 10;
PositionY = 10;
defaultWidth  = 600;
defaultHeight = 400;

//kinda important
var AutoClose = true;

//don't touch
function popImage(imageURL,imageTitle){
	var imgWin = window.open('','_blank','scrollbars=no,resizable=1,width='+defaultWidth+',height='+defaultHeight+',left='+PositionX+',top='+PositionY);
	if( !imgWin ) { return true; } //popup blockers should not cause errors
	imgWin.document.write('<html><head><title>'+imageTitle+'<\/title><script type="text\/javascript">\n'+
		'function resizeWinTo() {\n'+
		'if( !document.images.length ) { document.images[0] = document.layers[0].images[0]; }'+
		'var oH = document.images[0].height, oW = document.images[0].width;\n'+
		'if( !oH || window.doneAlready ) { return; }\n'+ //in case images are disabled
		'window.doneAlready = true;\n'+ //for Safari and Opera
		'var x = window; x.resizeTo( oW + 200, oH + 200 );\n'+
		'var myW = 0, myH = 0, d = x.document.documentElement, b = x.document.body;\n'+
		'if( x.innerWidth ) { myW = x.innerWidth; myH = x.innerHeight; }\n'+
		'else if( d && d.clientWidth ) { myW = d.clientWidth; myH = d.clientHeight; }\n'+
		'else if( b && b.clientWidth ) { myW = b.clientWidth; myH = b.clientHeight; }\n'+
		'if( window.opera && !document.childNodes ) { myW += 16; }\n'+
		'x.resizeTo( oW = oW + ( ( oW + 200 ) - myW ), oH = oH + ( (oH + 200 ) - myH ) );\n'+
		'var scW = screen.availWidth ? screen.availWidth : screen.width;\n'+
		'var scH = screen.availHeight ? screen.availHeight : screen.height;\n'+
		'if( !window.opera ) { x.moveTo(Math.round((scW-oW)/2),Math.round((scH-oH)/2)); }\n'+
		'}\n'+
		'<\/script>'+
		'<\/head><body onload="resizeWinTo();"'+(AutoClose?' onblur="self.close();"':'')+'>'+
		(document.layers?('<layer left="0" top="0">'):('<div style="position:absolute;left:0px;top:0px;display:table;">'))+
		'<img src='+imageURL+' alt="Loading image ..." title="" onload="resizeWinTo();" onclick="self.close();">'+
		(document.layers?'<\/layer>':'<\/div>')+'<\/body><\/html>');
	imgWin.document.close();
	if( imgWin.focus ) { imgWin.focus(); }
	return false;
}
