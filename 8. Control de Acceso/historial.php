<?php
$i = 0;
//Capturo los valores contenidos en la URL
if (isset($_GET['uid'])) {
	$uid = $_GET['uid'];
	//Creo una consulta que me devuelva los últimos 10 registros de la tabla iot_th
	$qy = 'SELECT id_historial, uid, his.mac, dispositivo, alias, his.ct FROM historial as his INNER JOIN iot_macs as mac WHERE mac.mac = his.mac AND uid = "'.$uid.'" ORDER BY his.ct DESC;';
}
if (isset($_GET['mac'])) {
	$mac = $_GET['mac'];
	//Creo una consulta que me devuelva los últimos 10 registros de la tabla iot_th
	$qy = 'SELECT id_historial, uid, his.mac, dispositivo, alias, his.ct FROM historial as his INNER JOIN iot_macs as mac WHERE mac.mac = his.mac AND his.mac = "'.$mac.'" ORDER BY his.ct DESC;';
}

//Creo una conexión a la base de datos
// LOCALHOST
$cn = new mysqli('localhost', 'iot_admin', '12345678', 'iot');
// ONLINE
//$cn = new mysqli('localhost', 'id10260302_iot_admin', '12345678', 'id10260302_iot');

//Realizo la consulta y la asigno a un recordset
$rs = $cn->query($qy);
$str = '';
while ($rw = $rs->fetch_assoc()) {
	$i += 1;
	$str .= '<tr>';
	$str .= '<td>'.$i.'</td>';
	$str .= '<td>'.$rw['id_historial'].'</td>';
	$str .= '<td><a href="historial.php?mac='.$rw['mac'].'">'.$rw['alias'].'</a></td>';
	$str .= '<td><a href="historial.php?uid='.$rw['uid'].'">'.$rw['uid'].'</a></td>';
	$str .= '<td>'.$rw['ct'].'</td>';
	$str .= '</tr>';
}
$rs->free();
$cn->close();

?>
<!doctype html>
<html>
<head>
    <meta charset="utf-8">
		<meta http-equiv="refresh" content="10">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>RFID - Control de Acceso</title>
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
	    <th colspan="5"><h1>historial</h1></th>
    </tr><tr>
   			<th>#</th>
	  		<th><a href="select.php?by=id_empleado">ID</a></th>
        <th><a href="select.php?by=mac">MAC</a></th>
        <th><a href="select.php?by=uid">UID</a></th>
        <th><a href="select.php?by=ct">CREADO EN</a></th>
    </tr>
	<?php echo($str); ?>
    <tr>
	    <th colspan="5">&nbsp;</th>
    </tr>
</table>
</body>
</html>
