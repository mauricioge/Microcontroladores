<?php

//Capturo los valores contenidos en la URL
if (isset($_GET['uid'])) {
	$uid = strtoupper($_GET['uid']);
}
if (isset($_GET['mac'])) {
	$mac = $_GET['mac'];
}

//Creo una conexión a la base de datos
// LOCALHOST
$cn = new mysqli('localhost', 'iot_admin', '12345678', 'iot');
// ONLINE
//$cn = new mysqli('localhost', 'id10260302_iot_admin', '12345678', 'id10260302_iot');

//Creo una consulta que me devuelva los últimos 10 registros de la tabla iot_th
$qy = 'SELECT * FROM empleados WHERE uid = "'.$uid.'";';

//Realizo la consulta y la asigno a un recordset
if($rs = $cn->query($qy)) {
	$str = '';
	while ($rw = $rs->fetch_assoc()) {
		$str .= '<tr>';
		$str .= '<td>'.$rw['id_empleado'].'</td>';
		$str .= '<td>'.$rw['nombre'].'</td>';
		$str .= '<td>'.$rw['apellidos'].'</td>';
		$str .= '<td><a href="historial.php?uid='.$rw['uid'].'">Historial</a></td>';
		$str .= '<td>'.$rw['ct'].'</td>';
		$str .= '</tr>';
	}
	$rs->free();
	$cn->close();

	//Creo un nuevo registro con id_tag en el historial
	$cn2 = new mysqli('localhost', 'iot_admin', '12345678', 'iot');
	$qy2 = 'INSERT INTO historial (id_historial, mac, uid) values (uuid(), "'.$mac.'", "'.$uid.'");';
	$cn2->query($qy2);
	$cn2->close();
}
/* else {
	//Redirecciono a noexiste.php
	header('location: noexiste.php');
}*/
?>
<!doctype html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Arduino - PHP - DB</title>
    <style>
		a:link, a:visited {color:orange; text-decoration:none}
		a:hover, a:active {color:orange; text-decoration:underline}
		body {font-family:Segoe, "Segoe UI", "DejaVu Sans", "Trebuchet MS", Verdana, sans-serif}
		table {margin-left:auto; margin-right:auto}
		th {background-color:#666666;color:#FFF}
		td {text-align:center}
		table, th, tr, td {border:1px solid #000; border-collapse: collapse; padding:5px}
    </style>
</head>
<body>
<table>
    <tr>
	    <th colspan="5"><h1>empleados</h1></th>
    </tr><tr>
        <th><a href="select.php?by=id_empleado">ID</a></th>
        <th><a href="select.php?by=nombre">NOMBRE</a></th>
        <th><a href="select.php?by=apellidos">APELLIDOS</a></th>
				<th><a href="select.php?by=uid">HISTORIAL</a></th>
        <th><a href="select.php?by=ct">CREADO EN</a></th>
    </tr>
	<?php echo($str); ?>
    <tr>
	    <th colspan="5"><a href="agregar_empleado.php">Agregar empleado</a></th>
    </tr>
    <tr>
	    <th colspan="5">Esta tabla se actualiza cada 10 segundos</th>
    </tr>
</table>
</body>
</html>
