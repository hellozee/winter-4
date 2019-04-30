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
        function fib($num){
            if($num <= 1){
                return 1;
            }
            return fib($num-1) + fib($num-2);
        }
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $n = $_POST['n'];
            for($i=0;$i<$n;$i++){
                echo fib($i) . " ";
            }
        }
    ?>
</body>
</html>
