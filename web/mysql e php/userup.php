<?php
require_once "config.php";

$login      = $username    = $profile     = "";

if (isset($_POST["id"]) && !empty($_POST["id"])) {
    $id = trim($_POST['id']);
    $login = trim($_POST["login"]);
    $username = trim($_POST["username"]);
    $profile = trim($_POST["profile"]);
    $sql = "UPDATE users SET login=?, username=?, profile=? WHERE id=?";

    if ($stmt = mysqli_prepare($connection, $sql)) {
 
        mysqli_stmt_bind_param($stmt, "ssii", $login, $username, $profile, $id);

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

else {

    if (isset($_GET["id"]) && !empty(trim($_GET["id"]))) {

        $id =  trim($_GET["id"]);

        $sql = "SELECT * FROM users WHERE id = ?";
        if ($stmt = mysqli_prepare($connection, $sql)) {

            mysqli_stmt_bind_param($stmt, "i", $param_id);

            $param_id = $id;

            if (mysqli_stmt_execute($stmt)) {
                $result = mysqli_stmt_get_result($stmt);

                if (mysqli_num_rows($result) == 1) {
                    $row = mysqli_fetch_array($result, MYSQLI_ASSOC);

                    $login       = $row["login"];
                    $username     = $row["username"];
                    $profile    = $row["profile"];
                } else {
                    echo "erro";
                    exit();
                }
            } else {
                echo "Algo deu errado. Tente Novamente!";
            }
        }

        mysqli_stmt_close($stmt);

        mysqli_close($connection);
    } else {
        echo "erro";
        exit();
    }
}

?>
<!DOCTYPE html>
<html lang="pt">

<head>
    <meta charset="UTF-8">
    <title>Atualizar Usuário</title>
</head>

<body>
    <div>
        <h3 class="titulo">Atualizar Dados do Usuário <?= $_GET['id'] ?></h3>
        <form action="<?= htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
            <div>
                <label>Login</label><br>
                <input type="text" name="login" class="form-control" value="<?= $login; ?>">
            </div>
            <div>
                <label>Username</label><br>
                <input type="text" name="username" class="form-control" value="<?= $username; ?>">
            </div>
            <div>
                <label>Permissão</label><br>
                <select id="profile" name="profile" class="form-control">
                    <option value="1" <?php if ($profile == 1) echo "selected"; ?>>Admin</option>
                    <option value="2" <?php if ($profile == 2) echo "selected"; ?>>Comum</option>
                </select>
            </div>
            <input type="hidden" name="id" value="<?= $id; ?>" />
            <br>
            <input type="submit" value="Alterar" style="background-color: lime; color: black; padding: 8px 20px;">
            <a href="usersel.php" style="color: crimson; text-decoration: none !important; border-style: solid !important; border-color: crimson !important; padding: 6px 20px;">Cancel</a>
        </form>
    </div>
</body>

</html>