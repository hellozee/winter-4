<html>
<form action='menu.php' method='post'>
<h3>OPERATIONS</h3>                                                                                                                    
<input type='radio' name='a' value='1'>Remove Whitespace<br>
<input type='radio' name='a' value='2'>Check if contains<br>
<input type='radio' name='a' value='3'>Check all lowercase<br>
<input type='radio' name='a' value='4'>Change The to That<br>
Text : <input type='textbox' name='text'><br>
Search Text : <input type='textbox' name='text2'><br>
<input type='submit' value='Send'>
</form>
<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $val =  $_POST['text'];
        $val2 =  $_POST['text2'];
        $op = $_POST['a'];
        
        switch ($op){
        case 1:
            echo preg_replace('/\s+/', '', $val);
            break;
        case 2:
            if (strpos($val,$val2 ) !== false) {
                echo 'True';
            }else{
                echo 'False';
            }
            break;
        case 3:
            if (ctype_lower($val)) {
                echo "The string $val consists of all lowercase letters.\n";
            } else {
                echo "The string $val does not consist of all lowercase letters.\n";
            }
            break;
        case 4:
            echo preg_replace('/The/', 'That', $val, 1);
            break;
        }

    }
?>
</body>
</html>
