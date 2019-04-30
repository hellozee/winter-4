<html>
<head>
    <title>Test Page</title>
</head>
<body>
    <form method="POST" action="<?php echo $_SERVER['PHP_SELF'];?>">
    <input type="text" name="name" placeholder="Enter Name" />
    <button>Enter</button>
    </form>
    <?php
        $conn = new mysqli("localhost", "root", "root", "test");

        if($conn->connect_error){
            echo "Can't connect";
        }

        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $sql = $conn->prepare('insert into temp (name) values(?);'); 
            $sql->bind_param('s',$_POST['name']);
            $sql->execute();
            $sql->close();
        }

        $statement = "select id,name from temp";
        $result = $conn->query($statement);
        echo "<table><tr><th>ID</th><th>NAME</th></tr>";
        while($row = $result->fetch_assoc()){
            echo "<tr><td>".$row["id"] . "</td><td>" . $row["name"] . "</td></tr>";
        }
        echo "</table>";

        $conn->close();
    ?>
</body>
</html>
