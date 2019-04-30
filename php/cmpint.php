>
<head>
    <title>Compare Integers</title>
</head>
<body>
    <form method="POST" action="<?php echo $_SERVER['PHP_SELF'];?>">
    <input type="number" step="1" name="n1" placeholder="First" />
    <input type="number" step="1" name="n3" placeholder="Second" />
    <input type="number" step="1" name="n2" placeholder="Third" />
    <button>Compare</button>
    </form>
    <?php
        function cmp($num1, $num2){
            return $num1 > $num2 ? $num1 : $num2;
        }
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $n1 = $_POST['n1'];
            $n2 = $_POST['n2'];
            $n3 = $_POST['n3'];

            $big = cmp($n1, $n2);
            $bigger = cmp($n3, $big);
            echo "The biggest number is " . $bigger;
        }
    ?>
</body>
</html>
