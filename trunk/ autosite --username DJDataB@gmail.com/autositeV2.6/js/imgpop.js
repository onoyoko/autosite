		var ext_doc ;
		var varwriter='';
		function popimg(url,title,iwidth,iheight,colour) {
				var pwidth=iwidth+30;
				var	pheight=iheight+100;
				ext_doc = window.open('','htmlname','width=' + pwidth +',height=' +pheight + ',resizable=1,top=50,left=10');		
	           	ext_doc.focus();
				//ext_doc.document.clear();
				ext_doc.resizeTo(pwidth, pheight);
				varwriter+='<html><head><title>'+title+'</title></head>'; 
				varwriter+='<link href="/css.css" rel="stylesheet" type="text/css" />'  
				varwriter+='<body bgcolor="'+colour+'"><center>';
				varwriter+='<img src="'+url+'" border="0">';
				varwriter+='<h3>'+title+'</h3></center></body></html>';
					ext_doc.document.writeln(varwriter);
					ext_doc.document.close();
					ext_doc.focus();
				varwriter='';
		}
