<?php
//Creo una conexión a la base de datos
// LOCALHOST
$cn = new mysqli('localhost', 'iot_admin', '12345678', 'iot');
// ONLINE
//$cn = new mysqli('localhost', 'id10260302_iot_admin', '12345678', 'id10260302_iot');

//Creo una consulta para eliminar TODOS los registros de la tabla iot_th
$qy = 'DELETE FROM iot_th;';

//Realizo la consulta
$cn->query($qy);

//Cierro la conexión
$cn->close();

//Redirecciono a select.php
header('location: select.php');
?>
