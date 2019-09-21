<?php
//Capturo los valores contenidos en la URL
$mac = $_GET['mac'];
$tmp = $_GET['tmp'];
$hmd = $_GET['hmd'];

//Creo una conexión a la base de datos
// LOCALHOST
$cn = new mysqli('localhost', 'iot_admin', '12345678', 'iot');
// ONLINE
//$cn = new mysqli('localhost', 'id10260302_iot_admin', '12345678', 'id10260302_iot');

//Creo una consulta conteniendo los valores que quiero guardar
$qy = 'INSERT INTO iot_th (id_th, mac, tmp, hmd) VALUES (UUID(), "'.$mac.'", "'.$tmp.'", "'.$hmd.'");';

//Realizo la consulta
$cn->query($qy);

//Cierro la conexion
$cn->close();

//Redirecciono a select.php
header('location: select.php');
?>
