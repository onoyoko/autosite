<?php
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<Vieuw data>>>>>>>>>>>>>>>>
		print '<?xml version="1.0" ?>'."\n";
		print '<rss version="2.0">'."\n  <channel>\n<title>".$formname."</title>\n";
        $attributen="?";
		$attributen.=(isset($content))? "content=".$content : "";
		$attributen.=(isset($autosite['lang']))? "&lang=".$autosite['lang'] : "";
        $attributen.=(isset($_GET['viewas']))? "&viewas=".$_GET['viewas'] : "";
        print '<link>'.$_SERVER['PHP_SELF'].$attributen.'</link>';
        print '<description>Autosite contentgenerator rss</description>';
        print "<language>$lang</language>\n";
        print "<pubDate>".date(DATE_RFC822)."</pubDate>\n";//     "D, d M j G:i:s e"
        print "<lastBuildDate>".date(DATE_RFC822)."</lastBuildDate>\n";//     "D, d M j G:i:s e"
        print "<docs>http://blogs.law.harvard.edu/tech/rss</docs>\n";
        print "<generator>Weblog Editor 2.0</generator>\n";
        print '<webMaster>webmaster@example.com</webMaster>';
        print '<managingEditor>editor@example.com</managingEditor>';
		include_once($autosite['functions']."Qhtml/Qvieuw.inc");
        $string = " ";
        $formfields = $formsdata[$formname]['items'];
        $rssfields = $formsdata[$formname]['rss'];
		if(is_array($rssfields)){
			foreach($rssfields as $key => $value){
				$string .=  "%".$value."->value% ";
				$overroletemplate[$formname][$key]="<".$key."> %value% </".$key.">";
			}
		}
		if($formsdata[$formname]['vieuw']==true){
			$vieuw = new Qvieuw($string,null);
			if(is_array($overroletemplate[$formname])){
				$vieuw->addtagitems($overroletemplate[$formname]);
			}
			if(is_file($autosite['private'].$formsdata[$formname]['name'].".csv")){
				$vieuw->getfrom_csv($autosite['private'].$formsdata[$formname]['name'].".csv",$formsdata[$formname]['items']);	
			}else{
				print"<!-- NO DATA -->";
			}
		}else{
			print "<!-- NO VIEWS -->";
		}
		print "<!-- preparts=>RSS -->";
		print "</channel></rss>";
?>