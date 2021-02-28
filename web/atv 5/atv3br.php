<html>
<head>
<meta charset="UTF-8">
<title>Trapézio</title>    
</head>
<body>


<h2 style="color: crimson">Atividade 5 - Trapézio</h2>

<?php
$base_a = $_POST['base_a'];
$base_b = $_POST['base_b'];
$altura = $_POST['altura'];
$res = (($base_a+$base_b)*$altura)/2;
echo "Área do trapézio: ". $res ." m²."
?>
<br><br>
<button style="background-color: lime; color: black; padding: 15px 32px; font-size: 16px;" onclick="goBack()">Back</button>
<br><br>
<a href="atv5php.html">Atividade 5</a>
<script>
function goBack() {
  window.history.back();
}
</script>
</body>
</html>
