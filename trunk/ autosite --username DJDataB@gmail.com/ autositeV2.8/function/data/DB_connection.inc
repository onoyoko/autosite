<?php
/**
 * As of PHP 5.1.0
 * DB_connection as singleton
 * 
 * @package autosite2.6
 * @author Lieven Roegiers
 * @copyright 2011
 * @version $Id$
 * @access public
 * @CMS autosite
 *
 */
class DB_connection{
    private static $instance;
    private $count = 0;
    private $DB_connection;
    private $IS_connect;
    
    public function __construct(){
        $className = __CLASS__;
        if (!isset(self::$instance)) {
             self::$instance = new $className;
        }
    }
    public function get(){
        return self::$instance;
    }
    /**
     * You must now what you do
     * Is for to mutch visitors This is better for processor but you lost memmoryspace.
    */
    private function GlobalMeConnection(){
        global $DB_connection;
    }

      //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<singelton function>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
    
    public function __clone(){
        trigger_error('Clone is not allowed.', E_USER_ERROR);
    }
    public function __wakeup(){
        trigger_error('Unserializing is not allowed.', E_USER_ERROR);
    }
    public static function singleton(){
        
    }
    public function increment(){
        return $this->count++;
    }
    
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<connection>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        public function CON_Startup(){
                
            try{
        	if (!$this->IS_connect()){
        		switch ($this->DB_adapter){ 
					case "mysql":
					case "MYSQL":
					$this->DB_connection = 	mysql_connect($hosturl,$user,$pwx);
					//! important!security
  			    	@mysql_select_db($this->DB_name) or die( "MySQL DB Error: Unable to select database");
  			    	$this->DB_is_connect = true;
					
					break;
					default :
  			    print $this->getfullconnectionstring();
			}
		    }
        }catch (Exception $e){
            //echo $e->getMessage();//do not unescape this !important! security
        }
        return $this->DB_is_connect;
    }
    private function getfullconnectionstring(){//!important!security do not set it public
    	//jdbc:mysql://domein.be:port/databasename
    	return $this->DB_adapter."://".$this->DB_hosturl.":".$this->DB_port."/".$this->DB_name." ";
    }
}
?>

  
