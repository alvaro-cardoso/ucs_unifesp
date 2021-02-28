<?php
require_once "config.php";

$login    = $password    = $username    = $profile     = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $login = trim($_POST["login"]);
    $password = trim($_POST["password"]);
    $username = trim($_POST["username"]);
    $profile = trim($_POST["profile"]);

    $sql = "INSERT INTO users (login, password, username, profile) VALUES (?,?,?,?)";

    if ($stmt = mysqli_prepare($connection, $sql)) {
        mysqli_stmt_bind_param($stmt, "sssi", $login, $password, $username, $profile);
        echo $stmt->sqlstate;

        if (mysqli_stmt_execute($stmt)) {
            header("location: usersel.php");
            exit();
        } else {
            echo "Algo deu errado. Tente Novamente!";
        }
    }

    mysqli_stmt_close($stmt);
    mysqli_close($connection);
}
?>

<!DOCTYPE html>
<html lang="pt">

<head>
    <meta charset="UTF-8">
    <title>Criar Usuário</title>
</head>

<body>
    <div>
        <h3 class="titulo">Registrar Usuário</h3>
        <form action="<?= htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
            <div>
                <label>Login: </label><br>
                <input type="text" name="login" value="<?= $login; ?>">
            </div>
            <br>
            <div>
                <label>Senha: </label><br>
                <input type="text" name="password" value="<?= $password; ?>">
            </div>
            <br>
            <div>
                <label>Username: </label><br>
                <input type="text" name="username" value="<?= $username; ?>">
            </div>
            <br>
            <div>
                <label>Permissão: </label><br>
                <select id="profile" name="profile" value="<?= $profile; ?>">
                    <option value="1">Admin</option>
                    <option value="2">Comum</option>
                </select>
            </div>
            <br>
            <input type="submit" value="Criar" style="background-color: lime; color: black; padding: 8px 20px;">
            <a href="usersel.php" style="color: crimson; text-decoration: none !important; border-style: solid !important; border-color: crimson !important; padding: 6px 20px;">Cancel</a>
        </form>
    </div>

</body>

</html>