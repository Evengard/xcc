<form action="." name=f>
	<table>
		<tr>
			<td><input type=text name=q value="<?=htmlspecialchars($search)?>">
			<td><input type=submit value=Search>
			<td><a href="logins.php?pname=<?=urlencode($search)?>">Logins</a>
			<td><a href="players.php?a=xbl">Black List</a>
			<td><a href="hof_checks.html">HoF Checks</a>
			<td><a href="?a=messages">Messages</a>
			<td><a href="players.php?a=washers">Washers</a>
	</table>
</form>