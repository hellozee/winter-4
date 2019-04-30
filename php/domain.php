<html>
<head>
    <title>Check Domain</title>
</head>
<body>
    <form method="POST" action="<?php echo $_SERVER['PHP_SELF'];?>">
    <input type="text" name="mail" placeholder="Enter EMail" />
    <button>Check EMail</button>
    </form>
    <?php
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $conn = new mysqli("localhost", "root", "root", "test");
            if($conn->connect_error){
                echo "Can't connect";
                exit(0);
            }
            $mail = $_POST['mail'];
            $syntax='/^[^@]+@[^@]+$/';
            if (preg_match($syntax, $mail)){
                $domain_name = substr(strrchr($mail, "@"), 1);
                $result = $conn->query("select id from dtable where domain='" . $domain_name . "'");
                if($result->num_rows == 1){
                    echo "Valid Email";
                }else{
                    echo "Try Again";
                }
            }else{
                echo "Thats not a mail";
            }
            $conn->close();
        }
    ?>
</body>
</html>
