<!DOCTYPE html>
<html lang="en">
<head>                              
  <title>Car Parking</title>
  <meta charset="utf-8">
  <meta http-equiv="refresh" content="2">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  
</head>
<body>
<nav class="navbar navbar-default">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand text-center" href="#">SMART Car Parking System by Mirzana Jannat Piya - 1704018</a>
    </div>
  </div>
</nav>


<div class="container">
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
    


        ?>



<div class="container-lg">
        <div class="row">
        <div class="col-sm-4">
          <div class="card">
            <div class="card-body">
              <h3 class="card-title">Parking Slot 1</h5>
              
              <a href="#" class="btn btn-primary"><?php echo $slot1?></a>
            </div>
          </div>
        </div>
        <div class="col-sm-4">
          <div class="card">
            <div class="card-body">
              <h3 class="card-title">Parking Slot 2</h5>
             
              <a href="#" class="btn btn-primary"><?php echo $slot2?></a>
            </div>
          </div>
        </div>
        <div class="col-sm-4">
          <div class="card">
            <div class="card-body">
              <h3 class="card-title">Parking Slot 3</h5>
              
              <a href="#" class="btn btn-primary"> <?php echo $slot3?> </a>
            </div>
          </div>
        </div>
      </div>
    </div>




        <?php
    
        //echo "<strong> Id:</strong> " . $row["id"]. " &nbsp <strong>val:</strong> " . $slot1. " &nbsp <strong>val2:</strong> " . $slot2. " &nbsp <strong>val3:</strong> " . $slot3. "<p>";
    


}
} else {
    echo "0 results";
}

echo "</center>";

$conn->close();



?>
</div>


<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
</body>
</html>