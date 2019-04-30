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
        function even($num){
            for($i=1; $i <=$num; $i+=2){
                echo $i . " ";
            }
        }
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $n = $_POST['n'];
            even($n);
        }
    ?>
</body>
</html>
