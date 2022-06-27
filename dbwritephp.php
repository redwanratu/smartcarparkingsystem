

<?php



    $host = "localhost";		         // host = localhost because database hosted on the same server where PHP files are hosted
    $dbname = "id19006835_parkingdb";              // Database name
    $username = "id19006835_adminuser";		// Database username
    $password = "J]WFn?3_3\qKjeao";	        // Database password


// Establish connection to MySQL database
$conn = new mysqli($host, $username, $password, $dbname);


// Check if connection established successfully
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

else { echo "Connected to mysql database. "; }

   
// Get date and time variables
    date_default_timezone_set('Asia/Dhaka');  // for other timezones, refer:- https://www.php.net/manual/en/timezones.asia.php
    $d = date("Y-m-d");
    $t = date("H:i:s");
    
// If values send by NodeMCU are not empty then insert into MySQL database table

  if(!empty($_POST['sendval']) && !empty($_POST['sendval2']) && !empty($_POST['sendval3']))
    {
		$val = $_POST['sendval'];
        $val2 = $_POST['sendval2'];
 		$val3 = $_POST['sendval3'];


// Update your tablename here
	        $sql = "INSERT INTO slotstatus (slot1,slot2,slot3) VALUES ('".$val."','".$val2."', '".$val3."')"; 
 


		if ($conn->query($sql) == TRUE) {
		    echo "Values inserted in MySQL database table.";
		} else {
		    echo "Error: " . $sql . "<br>" . $conn->error;
		}
	}


// Close MySQL connection
$conn->close();



?>
