<?php
/**
 * @author Lieven Roegiers
 * @copyright 2007->
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Datasource connection>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * 
 * CREATE DATABASE `testdb` ;
CREATE USER 'drupal'@'localhost' IDENTIFIED BY '***';
GRANT ALL PRIVILEGES ON * . * TO 'drupal'@'localhost' IDENTIFIED BY '***' WITH GRANT OPTION MAX_QUERIES_PER_HOUR 0 MAX_CONNECTIONS_PER_HOUR 0 MAX_UPDATES_PER_HOUR 0 MAX_USER_CONNECTIONS 0 ;
GRANT ALL PRIVILEGES ON `drupal` . * TO 'drupal'@'localhost';
 */

class DB_source implements tosave{//initialize = !important!security
	  private $DSfilename;//datasourcefilename
	  private $datasource;
	  private $DB_adapter;
      private $DB_connection;
      private $DB_hosturl;
      private $DB_name;
      private $DB_user;
      private $DB_pwx;
      private $DB_port;
      private $DB_table;
      private $DB_is_connect = false;
      private static $illegalQsubstring =array("drop table","select * form users");
      const DEVELOPMENT = 1;
      const TEST = 2;//posible data and iligal data
      const PRODUCTION = 3;//real database
       /**
 		*@param DEVELOPMENT; TEST; PRODUCTION;   , "./test_ymlds2.xml"
 		*@name Dataconnect
        */
	 public function __construct($selection,$ymlDS2filename){
	 	    $this->DSfilename = $ymlDS2filename;
	 	    //print DEBUG? "test debug":"";
			switch($selection){ 
				case self::DEVELOPMENT : 
				 	$this->datasource=$this->get_datasource()->development;
				    break;
				case self::TEST :
					$this->datasource=$this->get_datasource()->test;
				     break;
				case self::PRODUCTION : 
					$this->datasource=$this->get_datasource()->production;
				    break;
 				default:
  					throw new InvalidArgumentException("Selection ERROR not found".$selection);
  					break;
			}
			if($this->datasource->adapter!=null){
				$this->DB_adapter = (string)$this->datasource->adapter;
      			$this->DB_hosturl = (string)$this->datasource->hosturl;
      			$this->DB_name = (string)$this->datasource->database;
      			$this->DB_user = (string)$this->datasource->username;
      			$this->DB_pwx = (string)$this->datasource->password."";
      			$this->DB_port = (string)$this->datasource->port;
			}
      }
     /**
 	  *@return
     */
      private function IS_conneced(){
      			return $this->DB_is_connect;
      }
	  public function CON_Startup(){
            try{
            	if (!$this->IS_conneced()){
            		switch ($this->DB_adapter){ 
						case "mysql":
						case "MYSQL":
						$this->DB_connection = 	mysql_connect($this->DB_hosturl,$this->DB_user,$this->DB_pwx);
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
 /*
 * CREATE TABLE contacts (id int(6) NOT NULL auto_increment,firstname varchar(15) NOT NULL,PRIMARY KEY (id),UNIQUE id (id),KEY id_2 (id))
 * INSERT INTO contacts VALUES ('','yourfirstname')
 * SELECT * FROM contacts
 */
        private function DoQuery($query){
			@mysql_query($query);
        }
        public function settable($table){
        	$this->DB_table=$table;
        }
        public function save_line($arr,$bykey = true){
        	$query ="INSERT INTO ".$this->DB_table;
        	if($bykey){
        		$query .= "('".array_keys($arr)."') VALUES ('".array_values($arr)."')";
        	}else{
        		$query .= " VALUES ('".array_values($arr)."')";
        	}
        	$this->DoQuery($query);
        	print($query);
        }
        public function Q_print($query){
			 $res = mysql_query($query);		
			 $isfirst=true;
			 while ($arr = mysql_fetch_array($res, MYSQL_ASSOC)) {
			 	if ($isfirst){
			 		print"<tr>";
  						array_walk($arr,'printth');
  					print"</tr>";
  					$isfirst=false;
			 	}
			 	print"<tr>";
  					array_walk($arr,'printtd');
  				print"</tr>";
			 }
             mysql_free_result($res); 
        }
        private function printtd($item, $key){
        	print"<td>".$item."</td>";
        }
        private function printth($item, $key){
        	print"<th>".$key."</th>";
        }
        public function CON_Closse(){
      	    if ($this->DB_is_connect){
                mysql_close($this->DB_connection);
                $this->DB_is_connect = false;
            }
        }
        public function __destruct(){
  			if ($this->DB_is_connect){
                mysql_close($this->DB_connection);
                $this->DB_is_connect = false;
            }
		}
					/*
			<?xml version="1.0" encoding="UTF-8"?>
			<datasources>  
				<development>
					    <adapter>mysql</adapter>
					    <hosturl>localhost</hosturl>
					    <port>3306</port>
					    <database>testDB</database>
					    <!-- only for java -->
					    <driver-class>com.mysql.jdbc.Driver</driver-class>
					    <username>root</username>
					    <password>password</password>
					    <exceptionSorterClassName>
						org.jboss.resource.adapter.jdbc.vendor.MySQLExceptionSorter</exceptionSorterClassName>
					    <metadata>
					       <type-mapping>mySQL</type-mapping>
					    </metadata>
				</development>
				<test>
						<adapter>mysql</adapter>
					    <hosturl>localhost</hosturl>
					    <port>3306</port>
					    ...
			 	</test>
				<production>
						<adapter>mysql</adapter>
					    ...
				</production>
			</datasources>
			*/
		private function get_datasource(){
			return new SimpleXMLElement(file_get_contents($this->DSfilename));
		}

      }
?>


