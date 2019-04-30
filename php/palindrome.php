<html>
<head>
    <title>Compare Integers</title>
</head>
<body>
    <form method="POST" action="<?php echo $_SERVER['PHP_SELF'];?>">
    <input type="text" name="n" placeholder="Enter Text" />
    <button>Odd N</button>
    </form>
    <?php
        function isPalindrome($t){
            if(strrev($t) == $t){
                return " is a palindrome.";
            }
            return " is not a palindrome";
        }
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $n = $_POST['n'];
            echo $n . isPalindrome($n);
        }
    ?>
</body>
</html>
