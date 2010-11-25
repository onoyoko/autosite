<?php 	if (!isset($cols)){
			$cols = 3;
		}
 		$breedte_Thumb = 150;
		if (!isset($path)){
			$path=( isset( $_GET['id'] ) ) ? addslashes($_GET['id'] ) : 'test' ;
		}
		$path_big = "layout/".$path."/pic/";
		$path_thumbs = "layout/".$path."/thump/";
		if (!is_writeable($path_thumbs)||!is_writeable($path_big)){
   die ("Error: no pic access ");
   }
?>
	<script language="JavaScript" type="text/javascript">
		var ext_doc ;
		var varwriter='';
		function popimg(url,title,iwidth,iheight,colour) {
				var pwidth=iwidth + 30;
				var	pheight=iheight + 60;
				
				ext_doc = window.open('','htmlname','width=' + pwidth +',height=' +pheight + ',resizable=1,top=50,left=10');		
	           	ext_doc.focus();
				//ext_doc.document.clear();
				ext_doc.resizeTo(pwidth, pheight);
				varwriter+='<html><head><title>'+title+'</title></head>';   
				varwriter+='<body bgcolor="'+colour+'"><center>';
				varwriter+='<img src="'+url+'" border="0">';
				varwriter+='</center></body></html>';
					ext_doc.document.writeln(varwriter);
					ext_doc.document.close();
					ext_doc.focus();
				varwriter='';
		}
</script>

<body >
<?php

//Width :$imgsize[0];
//Height : $imgsize[1];
echo "<table width=75%>
       <tr>";
$opendir =opendir($path_thumbs);
$i =1;
while ($file = readdir($opendir)) {
    if($file != '..' && $file !='.' && $file !=''){
    	$pos = strpos ($file, "_.");
        if (!is_dir($file)&& $pos<1){
	            $imgsize = getimagesize($path_big."/".$file);
	            list($title, $ext) = split('[/.-]', $file);
//strripos($file,".");
				print "<td align='center' valign='bottom'>";
				print '<a href="javascript:popimg(';     	
	        	print "'/".$path_big.$file."','$title', $imgsize[0], $imgsize[1],'#99CCFF'";
				print ')"><img src="';
				print '/'.$path_thumbs.$file;
				print '" border="0" width="150"></a><H2><hr size=1 width="150">'.$title.'<hr size=1 width="150"> </H2></td>';
	            if ($i >= $cols){
	                print"</tr><tr>";
	                $i=0  ;
	            }          
			$i++; 
        }else{
			    $name = substr ($file, 0, $pos);
                if (substr ($file, 0, 1)!= "." ){
                    list($naam , $website ) = split('[_]', $name);
                    echo "<td hight='100%' width='200' class='div2' align='left' valign='top'>\n";
                    echo "<a href='http://".$website."' target='_blank'>";
					echo "<h3>".$naam."</h3>\n";
					echo "<img src='".$path_thumbs.$file."' width='100' border='0'>\n";
                    echo "</a></td>\n";
                    if ($i >= $cols+1){
	                	print"</tr><tr>";
	                	$i=0  ;
	            	}          
					$i++; 
        		}
		}
        
	}
}
print("</center><link rel='stylesheet' href='/css/css2.css.php' type='text/css'>");

closedir($opendir);
clearstatcache();
?>