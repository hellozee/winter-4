<html>
<head><title> Count Birthday </title></head>
<body>
<form action='bday.php' method='post'>
<input type="date" name="d"/>
<input type='submit' value='Send'>
</form>
<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $raw_date = $_POST['d'];
        $now = time();
        $date = strtotime($raw_date);
        $datediff = $date - $now ;
        echo round($datediff / (60 * 60 * 24)) . " days left.";
    }
?>
</body>
</html>
