<html>
<head>
    <title>Compare Integers</title>
</head>
<body>
    <form method="POST" action="<?php echo $_SERVER['PHP_SELF'];?>">
    <input type="number" step="1" name="n" placeholder="Number" />
    <button>Compare</button>
    </form>
    <?php
        function factorial($num){
            return $num > 1 ? $num * factorial($num-1) : $num;
        }
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $n = $_POST['n'];
            echo "The factorial of ". $n . " is " . factorial($n);
        }
    ?>
</body>
</html>
