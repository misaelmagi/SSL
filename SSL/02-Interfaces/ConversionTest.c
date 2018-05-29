/* ConversionTest.c
 * Programa de Prueba de Conversion de Temperatura
 * Equipo 3
 * 20180529
 */
#include <assert.h>
#include "Conversion.h"
int main(){
	assert(Celsius(18.5)==-7.5);
	assert(Celsius(0.0)==32.0);
	assert(Farenheit(0.0)==-17.77);
	assert(Farenheit(30.66)==-0.74);
	
}