<html>
<head>
<meta charset="UTF-8">
<title>Trapézio/Pirâmide</title>    
</head>
<body>
<style>
.button {
  background-color: crimson;
  color: black;
  padding: 15px 32px;
  font-size: 16px;
}
</style>

<h2 style="color: crimson">Atividade 5 - Trapézio</h2>

<form action="atv3br.php" method="post">
<h3>Área trapézio</h3>
<label for="base_a">Base B</label><br>
<input type="number" id="base_a" name="base_a">
<label for="base_b">Base b</label><br>
<input type="number" id="base_b" name="base_b">
<label for="altura">Altura</label><br>
<input type="number" id="altura" name="altura"><br><br>
<input type="submit" class="button" value="Enviar">
<input type="reset" class="button" value="Limpar">
</form>

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
