<?php
// Include checkin, config and authorization file
require_once "checkin.php";
require "auth_admin.php";
require_once "config.php";

// Processing form data when form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $title = trim($_POST["title"]);

    $description = trim($_POST["description"]);

    $status = trim($_POST["status"]);

    $log_date = date("Y-m-d H:i:s");

    // Prepare an insert statement
    $sql = "INSERT INTO projects (title, description, status, log_date, log_login) VALUES (?,?,?,?,?)";

    if ($stmt = mysqli_prepare($connection, $sql)) {
        // Bind variables to the prepared statement as parameters
        mysqli_stmt_bind_param($stmt, "ssiss", $title, $description, $status, $log_date, $log_login);

        // Set parameters
        $log_login = $_SESSION['login'];
        // Attempt to execute the prepared statement
        if (mysqli_stmt_execute($stmt)) {
            // Project created and log saved successfully. Redirect to landing page
            header("location: index.php");
            exit();
        } else {
            header("location: error.php?number=10");
            exit();
        }
    }

    // Close statement
    mysqli_stmt_close($stmt);

    // Close connection
    mysqli_close($connection);
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta title="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>Create Project</title>
    <!-- library css -->
    <link rel='shortcut icon' href='GG_Management_Solutions_Icon.png'>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.css">
    <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta1/dist/css/bootstrap.min.css">
    <style>
        a {
            text-decoration: none !important;
            border: none !important;
        }

        .dropdown-menu>li>a:hover {
            background-color: rgba(0, 0, 0, 0.8) !important;
        }

        #exit:hover {
            background-color: crimson !important;
            opacity: 0.8;
        }

        .dropdown>a:hover {
            background-color: rgba(0, 0, 0, 0.8) !important;
        }
    </style>
</head>

<body>
    <div class="container-fluid min-vh-100 d-flex flex-column">
        <div class="row flex-grow-1">
            <div class="col bg-dark text-light" style="border-right:solid #24242c; border-right-width:10px">
                <br>
                <div class="dropdown">
                    <a class="btn bg-dark text-light dropdown" role="button" id="dropdownList" text-center style="font-size: 22px" data-bs-toggle="dropdown" aria-expanded="false">
                        <span class='material-icons float-start' style='font-size: 30px' aria-hidden='true'>account_circle</span>&nbsp;<?php echo $_SESSION['login'] ?></a>
                    <ul class="dropdown-menu bg-dark text-light" style="border:none !important; box-shadow: none;" aria-labelledby="dropdownList">
                        <li><a class="dropdown-item bg-dark text-light" href="index.php"><span class='material-icons float-start' aria-hidden='true'>assignment</span>&nbsp;Projects</a></a></li>
                        <?php if($_SESSION['user_profile'] == 1){ ?>
                            <li><a class="dropdown-item bg-dark text-light" href="evidences.php"><span class='material-icons float-start' aria-hidden='true'>folder</span>&nbsp;Evidences</a></a></li>
                            <li><a class="dropdown-item bg-dark text-light" href="users.php"><span class='material-icons float-start' aria-hidden='true'>folder_shared</span>&nbsp;Users</a></li>
                        <?php } ?>
                        <li><a id ="exit" class="dropdown-item bg-dark text-light" href="index.php?logout=1"><span class='material-icons float-start' aria-hidden='true'>power_settings_new</span>&nbsp;Logout</a></li>
                    </ul>
                </div>
            </div>
            <div class="col-10 bg-light">
                <br>
                <h3 class="titulo-tabla">
                    Register Project
                </h3>
                <hr class="bg-dark">
                <form action="<?= htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
                    <div class="form-group">
                        <label>Title</label>
                        <input type="text" name="title" class="form-control" required>
                    </div>
                    <div class="form-group">
                        <label>Description</label>
                        <input type="text" name="description" class="form-control"required>
                    </div>
                    <div class="form-group">
                        <label>Status<div class="text-danger">(Note: If Closed is selected, no more evidences can be created or updated in this project)</div></label>
                        <select id="status" name="status" class="form-control">
                            <option value="1">In progress</option>
                            <option value="2">In validation</option>
                            <option value="3">Closed</option>
                        </select>
                    </div>
                    <br>
                    <input type="submit" class="btn btn-success" value="Submit">
                    <a href="index.php" class="btn btn-default" style="color:crimson">Cancel</a>
                </form>
            </div>
        </div>
    </div>

    <!-- library js -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta1/dist/js/bootstrap.bundle.min.js"></script>
    <script src="https://code.jquery.com/jquery-3.5.1.js"></script>
    <script src="https://cdn.datatables.net/1.10.22/js/jquery.dataTables.min.js"></script>
    <script src="https://cdn.datatables.net/1.10.22/js/dataTables.bootstrap4.min.js"></script>
    <script src="https://cdn.datatables.net/buttons/1.6.4/js/dataTables.buttons.min.js"></script>
    <script src="https://cdn.datatables.net/buttons/1.6.4/js/buttons.bootstrap4.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jszip/3.1.3/jszip.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.53/pdfmake.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.53/vfs_fonts.js"></script>
    <script src="https://cdn.datatables.net/buttons/1.6.4/js/buttons.html5.min.js"></script>
    <script src="https://cdn.datatables.net/buttons/1.6.4/js/buttons.print.min.js"></script>
    <script src="https://cdn.datatables.net/buttons/1.6.4/js/buttons.colVis.min.js"></script>


    <!-- internal script -->
    <script src="javascript.js"></script>
</body>

</html>