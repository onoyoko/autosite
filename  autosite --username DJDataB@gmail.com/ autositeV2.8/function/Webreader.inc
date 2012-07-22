<?php

class Webreader{
    private $loc;
    /** 
	 * @param mixed $pathname
	 * @param mixed $filelocation
	 * @param integer $lifetime
	 * @return
	 */
	public function __construct($url){
		$this->loc=file('http://www.example.com/');
	}
    public function tostring(){
        foreach ($lines as $line_num => $line) {
            echo "Line #<b>{$line_num}</b> : " . htmlspecialchars($line) . "<br />\n";
        }
    }
    public function save($fname){
        $html = implode('', file('http://www.example.com/'));
        $trimmed = file('somefile.txt', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
    }
}
?>