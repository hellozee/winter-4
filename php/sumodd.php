
<html>
<head>
    <title>Compare Integers</title>
</head>
<body>
    <form method="POST" action="<?php echo $_SERVER['PHP_SELF'];?>">
    <input type="number" step="1" name="n" placeholder="Number" />
    <button>Odd N</button>
    </form>
    <?php
        function sum($num){
            $sum = 0;
            for($i=1; $i <=$num; $i+=2){
                $sum += $i;
            }
            return $sum;
        }
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $n = $_POST['n'];
            echo sum($n);
        }
    ?>
</body>
</html>
