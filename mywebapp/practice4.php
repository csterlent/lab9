<html>
<head>
<h1>EECS 348 Lab Seven</h1>
<link rel="stylesheet" href="style.css">
</head>
<body>
Practice Four: PHP Multiplication Table<br>

<?php
echo "<table>";

$n = $_GET["n"];
// echo a row of the table at a time
for ($i = 0; $i < $n+1; $i++) {
	echo "<tr>";
	// echo each entry of the table at a time
	for ($j = 0; $j < $n+1; $j++) {
		$col = 'White';
		if ($i == 0 || $j == 0) {
			$col = 'Gray';
		}
		echo "<td style='background-color:";
		echo $col;
		echo "'>";
		if ($i == 0) {
			echo $j;
		}
		else if ($j == 0) {
			echo $i;
		}
		else {
			echo $i * $j;
		}
		echo "</td>";
	}
	echo "</tr>";
}
echo "</table>";
?>

</body>
</html>
