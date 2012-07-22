<?php
/**
* @author Lieven Roegiers
* @copyright 2007
*/
$test = new timetostring();
$temp = 1304277549 ; //$topicinfo['datumtijd'];
print $test->convertdate($temp,1);
class timetostring{
    function convertdate($sqltime,$br){
        $temp = $sqltime;
        //$sqltime = strtotime($sqltime);//use the date.timezone setting or the date_default_timezone_set() function
        $datumtijd = "";//strftime('%d-%B-%Y  %H:%M', $sqltime);//It is not safe to rely on the system's timezone settings. You are *required* to use the date.timezone setting or the date_default_timezone_set() function.
        $suffix= $this->getmytime($sqltime);
        if($br==0){
            return $datumtijd . ", " . $suffix;
        }elseif($br==1){
            return $datumtijd . "<br/>" . $suffix;
        }else{
            return $suffix;
        }
    }
    function getmytime($stamp){
            $time = time();
            $diff = $time - $stamp;
            print $diff ."=". $time ."-".$stamp."<br>";
            if($this->isjaar($diff)){
                $count = floor($diff/31556926);
                return ($count == 1)? "Een jaar geleden": $count." jaren geleden";
            }
            if($this->ismaand($diff)){
                $count = floor($diff/2629743);
                return ($count == 1)? "Een maand geleden": $count." maanden geleden";
            }
            if($this->isdag($diff)){
                $count = floor($diff/86400);
                return ($count == 1)? "Een dag geleden": $count." dagen geleden";
            }
            if($this->isuur($diff)){
                $count = floor($diff/3600);
                return ($count == 1)? "Een uur geleden": $count." uren geleden";
            }
            if($this->isminuut($diff)){
                $count = floor($diff/60);
                return ($count == 1)? "Een minuut geleden": $count." minuten geleden";
            }
            if($this->isseconde($diff)){
                $count = $diff;
                if($count == 0){
                    return  "Een moment geleden";
                }else{
                    return ($count == 1)? "Eén seconde geleden": $count." secondes geleden";
                }
            } 
    }
    function isjaar($stamp){
        return $stamp > 31556926;
    }
    function ismaand($stamp){
        return $stamp > 2629743 && $stamp < 31556926;
    }
    function isdag($stamp){
        return $stamp > 86400 && $stamp < 2629743;
    }
    function isuur($stamp){
        return $stamp > 3600 && $stamp < 86400;
    }
    function isminuut($stamp){
        return $stamp > 60 && $stamp < 3600;
    }
    function isseconde($stamp){
        return $stamp < 60;
    }
}
?>