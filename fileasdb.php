<?php
 extract($_POST);
 $file_name = "db.txt";
 if(isset($submit_r)) {
  $new_array = 'array("bloco"=>"'.$blocoid.'", "deficiencia"=>"'.$deftipo.'", "reclamacao"=>"'.$reclamacaotext.'"),';
  $current = file_get_contents($file_name);
  $current .= $new_array;
  file_put_contents($file_name, $current);
 }
?>
<!DOCTYPE html>
<html>
 <head>
   <title>Ouvidoria - Universidade Federal de Alagoas</title>
 </head>
 <body>
  <style>
   input,textarea{width:350px; height: 150px}
   input[type=submit]{width:150px; height: 30px}
  </style>
  <div align="center">
   <form method="POST">
    <table width="250" border="0">
     <tr>
      <td>
       <select name="blocoid">
        <option>Bloco 1</option>
        <option>Bloco 2</option>
        <option>Bloco 3</option>
        <option>Bloco 4</option>
        <option>Bloco 5</option>
        <option>Bloco 6</option>
        <option>Bloco 7</option>
       </select>
      </td>
     </tr>
     <tr>
      <td>
       <select name="deftipo">
        <option>Amputação</option>
        <option>Hemiparesia</option>
        <option>Hemiplegia</option>
        <option>Monoparesia</option>
        <option>Monoplegia</option>
        <option>Ostomia</option>
        <option>Paralisia Cerebral</option>
        <option>Paraparesia</option>
        <option>Paraplegia</option>
        <option>Tetraparesia</option>
        <option>Tetraplegia</option>
        <option>Triparesia</option>
        <option>Triplegia</option>
       </select>
      </td>
     </tr>
     <tr>
      <td><textarea placeholder="Reclamação..." name="reclamacaotext"></textarea></td>
     </tr>
     <tr>
      <td align="center">
       <input type="submit" value="Enviar Reclamação" name="submit_r">
      </td>
     </tr>
    </table>
   </form>
  </div>
 </body>
</html>
