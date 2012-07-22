<script type="text/javascript">
  /**
  only for including
  */
  var browser = "&browser="+ navigator.appName ;  
  var codebrowser = "&Codebrowser="+ navigator.appCodeName ; 
  var versiebrowser = "&versieBrowser="+ navigator.appVersion; 
  var platform = "&Platform="+ navigator.platform ; 
  var linking = "&Pageviews="+ history.length ; 
  var java = "&java="+navigator.javaEnabled();
  var resol = "&resolutieY="+screen.width+"&resolutieX="screen.height; 
  var colord ="&Kleurdiepte="+window.screen.colorDepth+"-bit";
  var thisip ="&Kleurdiepte="+ip;
  send(browser+codebrowser+versiebrowser+platform+linking+java+resol+colord+thisip);
	function send(parinfo){
   	if( parinfo != "" ){
		var sender1 = createSender();
		sender.onreadystatechange = function()
		{ if(sender1.readyState == 4 && sender1.status == 200)
			{if(sender1.responseText == "ERROR")
		        { alert( "Fout" );      }
		      }
		    }
			sender1.open("GET", "<?php print$_SERVER["PHP_SELF"] ?>?action=trace"+parinfo);
			window.defaultStatus = "Your IP address is "+ip;
			document.write("<title>Your IP address is "+ip+"</title>");
		}
	}
</script>
