<html>
<head>
    <title>Compare Integers</title>
</head>
<body>
    <form method="POST" action="<?php echo $_SERVER['PHP_SELF'];?>">
    <input type="number" step="1" name="n" placeholder="Number" />
    <button>Fibonacci</button>
    </form>
    <?php
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $n = $_POST['n'];
            for($i=1;$i<=$n;$i++){
                for($j=0;$j<$i;$j++){
                    echo "*";
                }
                echo "<br>";
            }
        }
    ?>
</body>
</html>
