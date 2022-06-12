<?php

  $destino = 'info@nextngnr.com';
  $nombre = $_POST['nombre'];
  $correo = $_POST['correo'];
  $mensaje = $_POST['mensaje'];
  // $headers = "From: ".$correo. "\r\n";
  // $headers .= "MIME-Version: 1.0" . "\r\n";
  // $headers .= "Content-type:text/html;charset=UTF-8" . "\r\n";

  // $contenido = "
  //   <html>
  //     <head>
  //       <title>Correo</title>
  //     </head>
  //     <body>
  //       <h2>".$nombre."</h2>
  //       <h3>".$correo."</h3>
  //       <p>".$mensaje."</p>
  //     </body>
  //   </html>
  // ";
  $contenido = 'Nombre: '.$nombre.' Correo: '.$correo.' Mensaje: '.$mensaje;


  mail($destino, 'Contacto', $contenido);