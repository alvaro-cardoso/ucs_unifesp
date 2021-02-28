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

<h2 style="color: crimson">Atividade 5 - Pirâmide</h2>

<form action="atv3ar.php" method="post">
<h3>Volume Pirâmide</h3>
<label for="p_base">Base</label><br>
<input type="number" id="p_base" name="p_base">
<label for="p_alt">Altura</label><br>
<input type="number" id="p_alt" name="p_alt"><br>
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
