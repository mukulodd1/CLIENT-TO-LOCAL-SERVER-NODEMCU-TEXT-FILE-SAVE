<?php
$Temp = $_GET["value1"];
$Humidity = $_GET["value2"];
$Write = "Temperature : ".$Temp." Celcius"."   Humidity: ".$Humidity;
file_put_contents('data.txt',$Write);
echo "Humidity: ".$Humidity." Temperature: ".$Temp;
?>
