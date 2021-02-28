<!DOCTYPE html>
<html lang="pt">

<head>
    <meta charset="UTF-8">
    <title>Lista de Usuários</title>
</head>

<body>
        <div>
            <h3 class="titulo">Lista de Usuários</h3>
            <a href="usercreate.php"><button style="background-color: lime; color: black; padding: 8px 20px;">Novo Usuário</button></a>
        </div>
        <br>
        <?php
        require_once "config.php";
        $sql = "SELECT * FROM users";
        if ($result = mysqli_query($connection, $sql)) {
            if (mysqli_num_rows($result) > 0) {
        ?>
                <table id="users" class="table">
                    <thead>
                        <tr>
                            <th>ID</th>
                            <th>Login</th>
                            <th>Username</th>
                            <th>Permissão</th>
                            <th>Ações</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php

                        while ($row = mysqli_fetch_array($result)) {
                        ?>
                            <tr>
                                <td><?= $row['id']; ?></td>
                                <td><?= $row['login']; ?></td>
                                <td><?= $row['username']; ?></td>
                                <td><?php switch ($row['profile']) {
                                        case "1":
                                            echo "Admin";
                                            break;
                                        case "2":
                                            echo "Comum";
                                            break;
                                    }
                                    ?>
                                </td>
                                <td>
                                    <?php
                                    echo "<a href='userup.php?id=" . $row['id'] . "' title='Update User'><button style='background-color: aquamarine; color: black; padding: 8px 20px;'>Atualizar</button></a> ";
                                    echo "<a href='userdel.php?id=" . $row['id'] . "' title='Delete User'><button style='background-color: crimson; color: black; padding: 8px 20px;'>Deletar</button></a>";
                                    ?>
                                </td>
                            </tr>
                        <?php
                        }
                        ?>
                    </tbody>
                </table>
        <?php
                mysqli_free_result($result);
            } else {
                echo "<p><em>Nenhum Usuário Emcontrado.</em></p>";
            }
        } else {
            echo "ERROR: $sql. " . mysqli_error($connection);
        }

        mysqli_close($connection);
        ?>

    </div>
</body>

</html>