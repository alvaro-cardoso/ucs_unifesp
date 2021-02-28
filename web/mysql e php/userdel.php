<?php
if (isset($_POST['id']) && !empty($_POST['id'])) {

    include_once 'config.php';

    $sql = "DELETE FROM users WHERE id =?";
    if ($stmt = mysqli_prepare($connection,  $sql)) {
        mysqli_stmt_bind_param($stmt, "i", $param_id);

        $param_id = trim($_POST['id']);

        if (mysqli_stmt_execute($stmt)) {

            header("location:usersel.php");
            exit();
        } else {
            echo "Algo deu errado. Tente Novamente!";
        }
    }

    mysqli_stmt_close($stmt);

    mysqli_close($connection);
} else {

    if (empty(trim($_GET['id']))) {
        echo "erro";
        exit();
    }
}

?>

<!DOCTYPE html>
<html lang="pt">

<head>
    <meta charset="UTF-8">
    <title>Delete Usuário</title>
</head>

<body>
    <div>
        <br>
        <h3 class="titulo">Delete Usuário </h3>
        <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
            <input type="hidden" name="id" value="<?php echo trim($_GET["id"]); ?>" />
            <p>Realmente deseja apagar esse usuário?</p>
            <p>
                <input type="submit" value="SIM" class="button" style="background-color: lime; color: black; padding: 8px 20px;">
                <a href="usersel.php" style="color: crimson; text-decoration: none !important; border-style: solid !important; border-color: crimson !important; padding: 6px 20px;"> NÃO</a>
            </p>
        </form>
    </div>

</html>