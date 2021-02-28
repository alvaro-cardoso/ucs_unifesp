<html>
<head>
<meta charset="UTF-8">
<title>Pirâmide</title>    
</head>
<body>


<h2 style="color: crimson">Atividade 5 - Pirâmide</h2>

<?php
$p_base = $_POST['p_base'];
$p_alt = $_POST['p_alt'];
$vres = (pow($p_base,2))*$p_alt/3;
echo "Volume da pirâmide: ". $vres." m³.";
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
