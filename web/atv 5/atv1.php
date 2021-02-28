<html>
<head>
<meta charset="UTF-8">
<title>Combustível Resultado</title>    
</head>
<body>


<h2 style="color: crimson">Atividade 5 - Consumo médio de Combustível</h2>

<?php
$kms = $_POST['kms'];
$liters = $_POST['liters'];
$cost = $kms/$liters;
echo "O consumo médio foi de ". $cost ." km/L."
?>
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
