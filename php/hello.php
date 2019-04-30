<html>
<head><title>Say Hello</title></head>
<body>
<form action="hello.php" method="post">
    <select name="drop">
        <option value="1">English</option>
        <option value="2">German</option>
        <option value="3">Spanish</option>
        <option value="4">French</option>
    </select>
    <input type="submit" value="Submit"/>
</form>
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $val = $_POST['drop'];
    switch($val){
    case 1:
        echo "Hello";
        break;
    case 2:
        echo "Hallo";
        break;
    case 3:
        echo "Hola";
        break;
    case 4:
        echo "Bonjour";
        break;
    }
}
?>
</body>
</html>
