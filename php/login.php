<html>
<head>
<title> Meh </title>
</head>
<body>
<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $conn = new mysqli("localhost", "root", "root", "test");
        if($conn->connect_error){
            echo "Can't connect";
        }
        $statement = "select password from temp where name=" . $_POST['uname'];
        $result = $conn->query($statement) or die("So sad, hush");
        if($result->fetch_object()->password == $_POST["password"]){
            echo "Successfully logged in";
        }else{
            echo "So sad, hush";
        } 
        $conn->close();
    }else{
        echo '<form target="/login.php" method="post">';
        echo 'Username:<input type="text" name="uname" /><br>';
        echo 'Password:<input type="password" name="password" /><br>';
        echo "<button>Submit</button>";
    }
?>
</form>
</body>
</html>
