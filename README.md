Loka
====

-   [Introducción](#introduccion)

-   [Requerimientos](#requirimientos)

Introducción
------------
Este proyecto tiene como finalidad el mostrar paso por paso como compilar y subir un firmware nuevo al dispositivo Loka. Para esto se añadirá el sensor TMP36 como sensor de temperatura externo. Se seleccionó el sensor TMP36 para este ejemplo por la compensacion que trae por defecto para lecturas por debajo de los 0 ºC, es decir, el sensor tiene un offset de 500 mV por lo que  a 25 ºC el voltaje de salida es de 750 mV. Gracias a esto es posible medir valores negativos de temperatura sin necesidad de un arreglo extra, ya que los ADCs del Loka solo aceptan voltajes entre 0V y 2.5V.   

CONSIDERACIONES
---------------
Para poder compilar el proyecto en el Code Composer Studio, necesitaremos la libreria "loka-lib-rc.lib" la cual puede ser solicitada en support@loka-systems.com

Requerimientos
--------------
-   [Code Composer Studio](http://www.ti.com/tool/ccstudio)
-   [Firmware Loader](http://www.thought-creator.com/wp-content/uploads/2015/03/FemtoFirmwareLoader.zip)
-   Cable FTDI.
-   Sensor de temperatura TMP36.

Compilar Proyecto
-----------------
Una vez descargado el programa Code Composer Studio, abrimos el programa y seleccionamos la ruta donde tenemos la carpeta de nuestro proyecto. Damos click en el boton de compilar. Si nuestro codigo no tiene ningun error, nos generará el archivo .TXT que subiremos a nuestro dispositivo.


Conectamos el cable FTDI a la computadora y abrimos el administrador de dispositivos para cambiar la frecuencia del puerto COM de 9600 a 115200 bits por segundo.

Abrimos el programa FemtoFirmwareLoader y seleccionamos el COM abierto por el cable FTDI. Buscamos el archivo .txt dentro de la carpeta "debug" contenida en la carpeta del proyecto.

Quitamos la alimentación del Loka y conectamos nuestro cable FTDI al Loka. Conectamos TX(Loka)->RX(cable) y RX(Loka)->TX(cable)

