<?php
class Popup{
    private $title;
    private $style;
    private $content;
    private $action;
    function Popup($title){
        $this->title = $title;
        
	}
    public function getPopup ($content) {
        return"<html> \n \t<head> \n \t\t<title> \n \t\t\t".$this->title."\n \t\t</title>".
        "\n \t\t".'<link href="'.$this->style.'" rel="stylesheet" type="text/css" />'.
        "\n \t\t<script langauge=\"javascript\">\n \t\t\tfunction LetsDoIt(){".
        "\n \t\t\t\topener.doWYSIWYG('".$this->action."',false,getReturn());".
        "\n \t\t\t\twindow.close();\n \t\t\t}\n \t\t</script>\n \t</head>".
        "\n \t<body>\n \t\t<h3>".$this->title."</h3>".$content.
        "<div class=\"popup actions\"><a href=\"javascript:LetsDoIt();\" class=\"OK\">ok</a>\n \t\t</div>".
        "\n \t</body></html>";
    }
    public function getPopupWithreturnval($returntohtmlid,$content) {
        return"<html> \n \t<head> \n \t\t<title> \n \t\t\t".$this->title."\n \t\t</title>".
        "\n \t\t".'<link href="'.$this->style.'" rel="stylesheet" type="text/css" />'.
        "\n \t\t<script langauge=\"javascript\">\n \t\t\tfunction LetsDoIt(){".
        "\n \t\t\t\topener.document.getElementById('".$returntohtmlid."').value=getReturn());".
        "\n \t\t\t\twindow.close();\n \t\t\t}\n \t\t</script>\n \t</head>".
        "\n \t<body>\n \t\t<h3>".$this->title."</h3>".$content.
        "<div class=\"popup actions\"><a href=\"javascript:LetsDoIt();\" class=\"OK\">ok</a>\n \t\t</div>".
        "\n \t</body></html>";
    }
    
    
    
}