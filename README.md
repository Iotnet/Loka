Loka
====

-   	[Introducción](#introduccion)

-   	[CONSIDERACIONES](#consideraciones)

-   	[Requerimientos](#requirimientos)

-   	[Compilar Proyecto](#compilar-proyecto)

-   	[Cargar Firmware](#cargar-firmware)

-	[Ejemplo](#ejemplo)



Introducción
------------
Este proyecto tiene como finalidad el mostrar paso por paso como compilar y subir un firmware nuevo al dispositivo Loka.   

CONSIDERACIONES
---------------
Para poder compilar el proyecto en el Code Composer Studio, necesitaremos la libreria "loka-lib-rc.lib" la cual puede ser solicitada en support@loka-systems.com

Requerimientos
--------------
-   [Code Composer Studio](http://www.ti.com/tool/ccstudio)
-   [Firmware Loader](http://www.thought-creator.com/wp-content/uploads/2015/03/FemtoFirmwareLoader.zip)
-   [Cable FTDI](https://github.com/Iotnet/Loka/blob/master/imagenes/ftdi.jpeg)

Pinout
------
A continuación se muestra el pinout.

![ccs1](https://github.com/Iotnet/Loka/blob/master/imagenes/pinout_loka.png?raw=true)

El pinout anterior se conserva para la nueva version 1.2. Los pines importantes para este proyecto, son TX, RX y la entrada analógica A0.

![ccs1](https://github.com/Iotnet/Loka/blob/master/imagenes/lokapinout.jpeg?raw=true)

Compilar Proyecto
-----------------
Una vez descargado e instalado el programa Code Composer Studio, abrimos el programa y vamos a File->Open Projects from File Systems.

![ccs1](https://github.com/Iotnet/Loka/blob/master/imagenes/ccs1.png?raw=true)

seleccionamos la carpeta de nuestro proyecto y damos click en "Finish". 

![ccs2](https://github.com/Iotnet/Loka/blob/master/imagenes/ccs2.png?raw=true)

Damos click en el boton de compilar. Si nuestro codigo no tiene ningun error, nos generará el archivo .TXT que subiremos a nuestro dispositivo.

![ccs3](https://github.com/Iotnet/Loka/blob/master/imagenes/ccs3.png?raw=true)

Cargar Firmware
---------------

Conectamos el cable FTDI a la computadora y abrimos el administrador de dispositivos.

![puerto](https://github.com/Iotnet/Loka/blob/master/imagenes/puerto.png?raw=true)

Abrimos las propiedades del puerto y cambiamos la frecuencia del puerto COM de 9600 a 115200 bits por segundo.

![puerto](https://github.com/Iotnet/Loka/blob/master/imagenes/puerto2.png?raw=true)

Abrimos el programa FemtoFirmwareLoader y seleccionamos el COM abierto por el cable FTDI. Buscamos el archivo .txt dentro de la carpeta "debug" contenida en la carpeta del proyecto.

![femto](https://github.com/Iotnet/Loka/blob/master/imagenes/femto.png?raw=true)

Quitamos la alimentación del Loka y conectamos nuestro cable FTDI. Conectamos TX(Loka)->RX(cable) y RX(Loka)->TX(cable)

![prog](https://github.com/Iotnet/Loka/blob/master/imagenes/prog.jpeg?raw=true)

Damos click en "Program Firmware" y se nos pedirá encender nuestro dispositivo.

![prog](https://github.com/Iotnet/Loka/blob/master/imagenes/loka10.png?raw=true)

Al poner las baterías o restablecer la alimentación de la tarjeta (3.3 V), empezará a borrar la memoria

![prog](https://github.com/Iotnet/Loka/blob/master/imagenes/loka11.png?raw=true)

después de unos segundos, empezará a cargar el nuevo firmware. Esto puede tardar, debido a que se programa por medio del protocolo serial

![prog](https://github.com/Iotnet/Loka/blob/master/imagenes/loka12.png?raw=true)

una vez terminado, nos aparecerá un cuadro de dialogo de que el nuevo Firmware a sido cargado exitosamente.

![prog](https://github.com/Iotnet/Loka/blob/master/imagenes/loka13.png?raw=true)

Ejemplo
-------

Para este ejemplo se añadirá el sensor TMP36 como sensor de temperatura externo. Se seleccionó el sensor TMP36 para este ejemplo por la compensación que trae por defecto para lecturas por debajo de los 0 ºC, es decir, el sensor tiene un offset de 500 mV por lo que  a 25 ºC el voltaje de salida es de 750 mV. Gracias a esto es posible medir valores negativos de temperatura sin necesidad de un arreglo extra, ya que los ADCs del Loka solo aceptan voltajes entre 0V y 2.5V. 

Compilar el proyecto de ejemplo [code](https://github.com/Iotnet/Loka/tree/master/sensor_analog) y cargar el nuevo firmware con el método anterior.


