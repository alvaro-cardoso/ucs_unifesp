<html>
<head>
<meta charset="UTF-8">
<title>Triângulos</title>    
</head>
<body>


<h2 style="color: crimson">Triângulos</h2>

<?php
$ld_a = $_POST['ld_a'];
$ld_b = $_POST['ld_b'];
$ld_c = $_POST['ld_c'];
	if($ld_a == $ld_b && $ld_a == $ld_c){
         echo "Triângulo Equilátero.";
        }
        elseif($ld_a != $ld_b && $ld_a != $ld_c){
        	if($ld_b != $ld_c){
            	echo "O Triângulo Escaleno.";
        	}
        	else{
        		echo "Triângulo Isóceles.";
        	}
        }
    else{
       	echo "Triângulo Isóceles.";
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
