<?php
/**
 * @author Lieven Roegiers
 * @copyright 2009 
 * @CMS autosite
 * opensource http://code.google.com/p/autosite/
 * @underconstruction	
 */
    include("./mail.inc");
 	class htmlmail extends Amail{
 		private $html;
 		private $backcolor;
 		private $admin = "info@djdb.be";
 		private $subject;
 		private $headers;
 		private $issend;
 		private $layout;
 		function __construct($from){
			parent::__construct($from);
			parent::setheader();			
		}
		/**
 		* @param var $bcolor backgroundcolor 	vb:#FFFFFF
 		* @param int $Tsize  Textsize(pt) 		vb:12
 		* @param str $Tfont  Textfont 			vb:arial
 		* @param var $Tcolor Textcolor 		vb:#000000
 		*/
		function layout($bcolor,$Tsize,$Tfont,$Tcolor){
			$this->layout ="bgcolor=".$bcolor;
			$this->layout .="FONT-SIZE= ".$Tsize."pt;";
			$this->layout .="FONT-FAMILY=".$Tfont."pt;MARGIN: 0px 10px 10px;";
			$this->layout .="text=".$Tcolor.";";				
		}

		
	}


?>
