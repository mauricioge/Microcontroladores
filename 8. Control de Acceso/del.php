<?php
//Creo una conexión a la base de datos
$cn = new mysqli('localhost', 'iot_admin', '12345678', 'iot');

//Creo una consulta para eliminar TODOS los registros de la tabla iot_th
$qy = 'DELETE FROM historial;';

//Realizo la consulta
$cn->query($qy);

//Cierro la conexión
$cn->close();

//Redirecciono a select.php
header('location: select.php');
?>
