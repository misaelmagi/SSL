/* Conversion.c
 * Programa de Conversion de Temperatura
 * Equipo 3
 * 20180529
 */
#include "Conversion.h"
#include <stdio.h>
double Celsius(double fahr){
	return 5*(fahr-32)/9;
};
double Farenheit(double cel){
	return cel*1.8+32;
};
