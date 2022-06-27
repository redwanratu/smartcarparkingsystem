// IOT based Car Parking System <br>
// MIRZANA JANNAT PIYA <br> 
// 1704018

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

else { echo "Connected to mysql database. <br>"; }


// Select values from MySQL database table

//$sql = "SELECT id, slot1, slot2, slot3 FROM slotstatus";  // Update your tablename here

$sql = "SELECT * FROM slotstatus ORDER BY id DESC LIMIT 1;";  // Update your tablename here

$result = $conn->query($sql);

echo "<center>";



if ($result->num_rows > 0) {

    

    // output data of each row
    while($row = $result->fetch_assoc()) {
        
        if($row["slot1"]==1){
            $slot1="EMPTY";
        }
        else
        {$slot1="BOOKED";}

        if($row["slot2"]==1){
            $slot2="EMPTY";
        }
        else
        {$slot2="BOOKED";}
    
        if($row["slot3"]==1){
            $slot3="EMPTY";
        }
        else
        {$slot3="BOOKED";}
    
    
        echo "<strong> Id:</strong> " . $row["id"]. " &nbsp <strong>val:</strong> " . $slot1. " &nbsp <strong>val2:</strong> " . $slot2. " &nbsp <strong>val3:</strong> " . $slot3. "<p>";
    


}
} else {
    echo "0 results";
}

echo "</center>";

$conn->close();



?>
