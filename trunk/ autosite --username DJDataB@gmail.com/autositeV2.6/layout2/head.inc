<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
	<!-- 
    /**
     * @author Lieven Roegiers
     * @copyright 2003->
	 * @CMS autosite
	 */
	 -->
	<title><?php print $autosite['title']?></title>
	<meta http-equiv="content-type" content="text/html; charset=UTF-8" />
	<meta name="GENERATOR" content="PHP Designer 2009 profesional, @CMS autosite By Lieven Roegiers" />
	<meta name="ROBOTS" content="INDEX" />
	<meta name="DESCRIPTION" content="<?php print $autosite['title']?>" />
	<meta name="KEYWORDS" content="content,dynamic site" />
	<meta name="TITLE" content="keyword1, keyword2" />
	<meta name="LANGUAGE" content="nederlands" />
	<meta name="revisit-after" content="10 days" />
	<meta name="rating" content="General" />
	<meta name="REPLY-TO" content="info@djdb.be" />
	<meta name="WEB_AUTHOR" content="Lieven Roegiers" />
	<link rel="SHORTCUT ICON" href="<?php print $autosite['layout']?>logo.ico">
	<!--[if lt IE 7]>
      <style type="text/css">
          div#footer { bottom: expression((document.body.clientHeight % 2) ? "-1px" : "0" ); }
          body { height: 100%; }
      </style>
    <![endif]-->
    <!--[if IE]><style>
        .Aproductitem span, .Aproductitem div {zoom: 1;}
</style><![endif]-->
<!--[if lt IE 5.5000]><style>
.Aproducitem span, .Aproductitem div {
	height: 0;
	vertical-align: bottom;
}
</style><![endif]-->
    
</head>
	<!-- @STYLE --> 
	<link rel='stylesheet' href='<?php print $autosite['layout']?>css/style.css' type='text/css' />

	<!--link media = 'screen'type = 'text/css'rel = 'stylesheet'href = '".$layout."/css/webtoolkit.shadow.css.php' />
	<link rel = 'stylesheet'href = '".$layout."css/edit.css.php'type = 'text/css' /-->
	<!-- @AUTHOR Lieven Roegiers @CMS autosite V2.6 automaticsite -->
	<script language='JavaScript' src='<?php print $autosite['javascript']?>menu15.0.0.js'></script>
	<script type="text/javascript"> 
		//if (parent.frames.length <1)
		//window.location.replace("<?php print $autosite['self']?>")//TODO make your site not offline avaleble
	</script>
    <?php 
		if(isset($user)&& $user->islogin()){
			print '<script language="JavaScript" src="'.$autosite['javascript'].'onclose.js"></script>';
	    	//print '<body onunload="javascript:onclose()">'
	    	print '<body>';
	    }else{
	    	print '<body>';
	    }
	    $attributen="?";
		$attributen.=(isset($content))? "content=".$content : "";
		$attributen.=(isset($load))? "&upload=".$load : "&upload=0";
		$attributen.=(isset($autosite['lang']))? "&lang=".$autosite['lang'] : "";
	?>
	<div id="topimg"></div>