<html>
<head><title>Reverse</title></head>
<body>
<form target="/reverse.php" method="post">
    <input type="text" name="istring" />
    <button>Submit</button>
</form>
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    echo strrev($_POST['istring']);
}
?>
</body>
</html>
