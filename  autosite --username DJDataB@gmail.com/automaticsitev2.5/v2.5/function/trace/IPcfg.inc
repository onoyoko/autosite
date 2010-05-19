<?php
	class IPcfg{
		$arr
		/**
		 * info about a IP address.
		 */
		function whois($IP){
  			$this->arr = shell_exec('whois '. escapeshellarg($IP));
		}
		/**
		 * info about the route from a server to an other server
		 * Usage:  traceroute 
		 * [-d FIlnrvx] 
		 * [-g gateway] 
		 * [-i iface] 
		 * [-f first_ttl]
		 * [-m max_ttl] 
		 * [ -p port] 
		 * [-q nqueries] 
		 * [-s src_addr] 
		 * [-t tos]
		 * [-w waittime] 
		 * [-z pausemsecs] 
		 * host [packetlen]
		 */
		function traceroute($IP){
  			$this->arr = shell_exec('traceroute '.escapeshellarg($IP));
		}
		private function cantrace(){
			return is_executable('/sbin/traceroute');//LINUX SERVER
		}
		/**
		 * removed dig provides better information
		 * DNS Record :
		 * @param $domain domainname
		 * @param $switches A,CNAME,MX,PTR,SOA,SPF,SRV,TXT
		*/
		function dnslookup($domain,$switches=""){
			$this->arr = shell_exec('dig '.escapeshellarg($switches).' '.escapeshellarg($domain) ) ;
		}
		function dnslookup2($switches,$domain){
			$this->arr = shell_exec('host '.$switches.escapeshellarg($_POST['domain'] ) ) ;
		}
	}
?>
