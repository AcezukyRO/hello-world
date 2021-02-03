<?php

if(isset($_GET["bang"])&&($_GET['bang'])=="=") {
$a = $_GET['a'];
$b = $_GET['b'];
$c = $_GET['c'];



echo "a = ".$a."<br>";
echo "b = ".$b."<br>";
echo "b = ".$c."<br>";


$delta = $b * $b - 4 * $a * $c;

if ($delta < 0) {
	echo "Do delta < 0, phương trình vô nghiệm";
}
else {

	$x1 = (-$b - sqrt($delta)) / (2 * $a);
	$x2 = (-$b + sqrt($delta)) / (2 * $a);

	echo "Kết quả: "."<br>";
	echo "x1 = ".$x1."<br>";
	echo "x2 = ".$x2."<br>";

}

}

?>