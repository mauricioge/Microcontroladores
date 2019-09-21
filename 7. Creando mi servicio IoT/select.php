<?php
$by = 'ct';
$i = 0;
$limit = ' LIMIT 10';
$regs = '<a href="select.php?limit=0">VER TODOS LOS REGISTROS</a>';

//Capturo los valores contenidos en la URL
if (isset($_GET['by'])) {
	$by = $_GET['by'];
}
if (isset($_GET['limit'])) {
	$limit = '';
	$regs = '<a href="select.php">VER LOS ÚLTIMOS 10 REGISTROS</a>';
}

//Creo una conexión a la base de datos
// LOCALHOST
$cn = new mysqli('localhost', 'iot_admin', '12345678', 'iot');
// ONLINE
//$cn = new mysqli('localhost', 'id10260302_iot_admin', '12345678', 'id10260302_iot');

//Creo una consulta que me devuelva los últimos 10 registros de la tabla iot_th
$qy = 'SELECT * FROM iot_th ORDER BY '.$by.' DESC'.$limit.';';

//Realizo la consulta y la asigno a un recordset
$rs = $cn->query($qy);
$str = '';

while ($rw = $rs->fetch_assoc()) {
	$i += 1;
	$str .= '<tr>';
	$str .= '<td>'.$i.'</td>';
	$str .= '<td>'.$rw['id_th'].'</td>';
	$str .= '<td>'.$rw['mac'].'</td>';
	$str .= '<td>'.$rw['tmp'].'</td>';
	$str .= '<td>'.$rw['hmd'].'</td>';
	$str .= '<td>'.$rw['ct'].'</td>';
	$str .= '</tr>';
}

//Libero el recordset
$rs->free();

//Cierro la conexion
$cn->close();
?>
<!doctype html>
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="refresh" content="10">
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
	    <th colspan="6"><h1>iot_th</h1></th>
    </tr><tr>
	    <th colspan="6"><?php echo($regs); ?></th>
    </tr><tr>
        <th>#</th>
        <th><a href="select.php?by=id_th">ID</a></th>
        <th><a href="select.php?by=mac">MAC</a></th>
        <th><a href="select.php?by=tmp">TMP &deg;C</a></th>
        <th><a href="select.php?by=hmd">HMD %</a></th>
        <th><a href="select.php?by=ct">CREADO EN</a></th>
    </tr>
	<?php echo($str); ?>
    <tr>
	    <th colspan="6"><a href="iot.php?mac=AA:BB:CC:DD:EE:FF&tmp=00.00&hmd=00.00">AGREGAR REGISTRO</a> | <a href="del.php">BORRAR TODOS LOS REGISTROS</a></th>
    </tr>
    <tr>
	    <th colspan="6">Esta tabla se actualiza cada 10 segundos</th>
    </tr>
</table>
</body>
</html>
