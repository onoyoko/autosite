<?php
	class Payment{
       private $Pay_types = array("Visa","Mastercard","Paypal");
	   private $PAY_type;
       private $istype;
       private $PAY_TOTAL;
       private $ispay;   
       public function gettypes(){
            return $this->Pay_types;
       }
       public function settype($type){
        $this->istype = true;
       }
       public function pay(){
        $this->istype = true;
       }
       public function ispay(){  
        $this->ispay = true;
       }
       
	}
?>