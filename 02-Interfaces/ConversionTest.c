#include <assert.h>
#include "Conversion.h"
int main(){
	assert(Celsius(18.5)==-7.5)
	assert(Celsius(0.0)==-17.77)
	assert(Celsius(32.0)==0);
	assert(Farenheit(0.0)==32.0);
	assert(Farenheit(100.0)==212.0);
	assert(Farenheit(-17.77)==0);
	
}