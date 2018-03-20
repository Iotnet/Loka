/*
 * vending.h
 *
 *  Created on: 06/05/2015
 *      Author: Dev
 */

#ifndef PROGRAMS_LOKA_LOKA_H_
#define PROGRAMS_LOKA_LOKA_H_

#include "GeoWifiManager.h"

#include <Loka.h>


#include <Console.h>
#include <SigfoxProtocol.h>

#include <interruptions.h>
#include <drivers/LIS3DE.h>
#include <drivers/InputOutput.h>

#include <string.h>




#define PROGRAM_LOKA_WEIGHT	2
#define PROGRAM_LOKA_START_ORDER		1


#define TEMPERATURE_MAX_INTERVAL			86400
#define VCC_MAX_INTERVAL 				86400
#define TEMPERATURE_VAR_INTERVAL			5
#define VCC_ANALOG_PORT					103
#define MOVE_ANALOG_PORT					101


//Interrupt function and vars
int deviceShakeEvt = 0;


static void deviceShakeInt(void);
static void buttonPressInt(void);





#endif /* PROGRAMS_LOKA_LOKA_H_ */




