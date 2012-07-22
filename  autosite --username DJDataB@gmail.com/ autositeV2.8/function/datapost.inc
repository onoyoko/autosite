<?php
/*
 define('POSTVARS', 'listID=29&request=suba&SubscribeSubmit=Subscribe&EmailAddress=');  // POST VARIABLES TO BE SENT
 
 // INITIALIZE ALL VARS
 $Email='';
 $ch='';
 $Rec_Data='';
 $Temp_Output='';
if($_SERVER['REQUEST_METHOD']==='POST') {  // REQUIRE POST OR DIE
	$formfield=(isset($_POST['field']))?addslashes($_POST['field']):"";
	curl_setopt($ch, CURLOPT_POST      ,1);
	curl_setopt($ch, CURLOPT_POSTFIELDS    ,POSTVARS.$Email);
	curl_setopt($ch, CURLOPT_FOLLOWLOCATION  ,1);
	curl_setopt($ch, CURLOPT_HEADER      ,0);  // DO NOT RETURN HTTP HEADERS
	curl_setopt($ch, CURLOPT_RETURNTRANSFER  ,1);  // RETURN THE CONTENTS OF THE CALL
	$Rec_Data = curl_exec($ch);
	ob_start();
	header("Content-Type: text/html");
	$Temp_Output = ltrim(rtrim(trim(strip_tags(trim(preg_replace ( "/\s\s+/" , " " , html_entity_decode($Rec_Data)))),"\n\t\r\h\v\0 ")), "%20");
	$Temp_Output = ereg_replace (' +', ' ', trim($Temp_Output));
	$Temp_Output = ereg_replace("[\r\t\n]","",$Temp_Output);
	$Temp_Output = substr($Temp_Output,307,200);
	echo $Temp_Output;
	$Final_Out=ob_get_clean();
	echo $Final_Out;
	curl_close($ch);
	
	*/
	
	/*
	
	$ch = curl_init();
// set URL and other appropriate options
curl_setopt($ch, CURLOPT_URL, "http://www.example.com/");
curl_setopt($ch, CURLOPT_HEADER, 0);
	*/
class Dopost_it{
		private $url;
		private $connection;
		/**
		* @param $url "http://www.uwdomein.be"
		*/
		function __construct($url){
				$this->url =$url;
		}
		/**
		* @param $postdata = array('name' => 'Foo', 'file' => '@/home/user/test.png');
		* 
		* Array([name] => Foo)
		  Array[file] => Array(
		    [name] => test.png
			[type] => image/png
            [tmp_name] => /tmp/phpcpjNeQ
            [error] => 0
            [size] => 279
        )

)
		*/
		private function  initalize($postdata){
			
			$this->connection = curl_init($this->url);//$this->url
			curl_setopt($this->connection, CURLOPT_POST ,1);
			curl_setopt($this->connection, CURLOPT_POSTFIELDS  ,$postdata);
			curl_setopt($this->connection, CURLOPT_FOLLOWLOCATION  ,1);
			curl_setopt($this->connection, CURLOPT_HEADER      ,0);  // DO NOT RETURN HTTP HEADERS
			curl_setopt($this->connection, CURLOPT_RETURNTRANSFER  ,1);  // RETURN THE CONTENTS OF THE CALL
		}
        /**
		* @param $postdata = array('name' => 'Foo', 'file' => '@/home/user/test.png');
		*/
		public function post($data){
			$this->initalize($data);
			$Rec_Data = curl_exec($this->connection);
			ob_start();
		}
		function __destruct(){
			curl_exec($this->connection);
			// close cURL resource, and free up system resources
			curl_close($this->connection);
		}
}
?>
