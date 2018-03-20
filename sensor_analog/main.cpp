#include <SigfoxProtocol.h>
#include <rtos.h>
#include <timer.h>
#include <Loka.h>

void setup()
{
    Loka::disableWatchdog(); //Deshabilitamos el watchdog
    SigfoxProtocol::init(RCZ2); //Libreria para zona 2
    Board::pinMode(LED, OUTPUT); //declaramos el GPIO del led como salida
}

void loop()
{
    //leemos el valor de nuestro sensor y lo convertimos a voltaje.
    float volt=Loka::analogRead(A0)*0.0024438;
    //convertimos el voltaje a su equivalente en temperatura. Restamos el offset de 0.5
    float temp=(volt-0.5)*100;
    //enviamos el dato por sigfox
    SigfoxProtocol::sendAnalogValue(0,temp);
    //dormimos la tarjeta por 10 min (600 segundos)
    Board::setLowPowerMode(600);
}
int main(void)
{
    tc_rtos_init(1);
    setup();
    //bucle infinito
    for(;;)
        loop();
}
