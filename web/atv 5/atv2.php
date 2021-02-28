<html>
<head>
<meta charset="UTF-8">
<title>COVID 19 Resultado</title>    
</head>
<body>


<h2 style="color: crimson">Atividade 5 - COVID 19</h2>

<?php
$comp = $_POST['comp'];
$larg = $_POST['larg'];
$area = $comp*$larg;
$res = floor($area/2.25);
echo "A sala comporta ". $res ." alunos."
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
