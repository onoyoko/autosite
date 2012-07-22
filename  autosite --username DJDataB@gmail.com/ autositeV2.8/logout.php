<?php
$Gfile = (isset ($_GET['file']))?addslashes($_GET['file']):'home';
$Gfile = (isset ($_POST['file']))?addslashes($_POST['file']):$Gfile;
$handeling = (isset($_POST['handeling'])) ? addslashes($_POST['handeling']) : "vieuw";
include("./generalvars.php");
session_start();
include($autosite['functions']."/util/redirector.inc");
if(session_destroy())redirect($autosite['installoc'].$option_location['vieuw'][0])  ;
?>
