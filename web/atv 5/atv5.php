<html>
<head>
<meta charset="UTF-8">
<title>Fibonacci</title>    
</head>
<body>


<h2 style="color: crimson">Fibonacci</h2>

<?php
$fib = $_POST['fib'];
$i = 0;

echo "Série de Fibonacci até o termo ". $fib ." : ";
while ($i <= $fib):
    echo " ".fibo($i);
    $i = $i + 1;
endwhile;
echo "<br><br>O ". $fib ."º termo da série gerada é: ".fibo($i-1);

function fibo($fib){
  if($fib <= 1){
    return $fib;
   }
  else{
    return fibo($fib - 1) + fibo($fib - 2);
  }
  }
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
