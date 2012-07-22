<?php
class InternalMsg{
    private $msgXML;
    public function vieuw(&$filename){
        $msgID = "test";
        $this->msgXML=$this->getSource(&$filename)->$msgID;
        print $this->msgXML->from;
        print $this->msgXML->subject;
        print $this->msgXML->body;
    }
    private function getSource(&$filename){
        return new SimpleXMLElement(file_get_contents($filename));
    }
}
?>