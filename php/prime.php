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
        function isPrime($num){
            for($i=2; $i < $num; $i++){
                if(!($num%$i)){
                    return " not prime";
                }
            }
            return " prime";
        }
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $n = $_POST['n'];
            echo $n . " is " . isPrime($n);
        }
    ?>
</body>
</html>
