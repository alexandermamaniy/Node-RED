# Node Red

trabajo practico del segundo parcial de la materia Arquitectura de computadores 2, donde mediante la
plataforma de Node-RED interactuamos con el protocolo MQTT y el gestor de base de datos MySQL

Por motivos de portabilidad se uso docker y docker-compose

# Pasos

- Tener instalado Docker y Docker-compose

- moverse al mismo nivel en donde esta el docker-compose

`cd Node-RED`

- generar un archvo .env para las variables phpmyadmin y mysql a la misma altura que el docker-compose

`MYSQL_ROOT_PASSWORD=contraseñaRoot`

`MYSQL_USER=user`

`MYSQL_PASSWORD=passwordUser`

`MYSQL_DATABASE=nombreBaseDeDatos`

`PMA_HOST=db                   # nombre del contendor de mysql`



- crear la imagenes definidas en el docker-compose

`docker-compose build`

- levantar los contendores

`docker-compose up -d`

Los puertos expuestos son los siguientes

- localhost:8080  phpmyadmin
- localhost:1880  node-red
- localhost:1883  protocolo mqtt del server mosquitto
- localhost:9001  protocolo websocket del server mosquitto


# NODECMU(ESP8266) 

  exites 2 clientes ESP8266
  uno que envia la temperatura del ambiente
  y otro que recibe y enciende un LED
  ambos esta bajo el topico temp


 el codigo de ambos clientes se encuentra en la carpeta  ESP8266
 
 colocar la RED, CONTRASEÑA , IP o HOSTNAME del server mqtt y PUERTO
 
`const char* ssid = "mi_red";`

`const char* password = "mi_contraseña";`

`const char* mqttServer = "server_mqtt"; `

`const int mqttPort = 1883; `
