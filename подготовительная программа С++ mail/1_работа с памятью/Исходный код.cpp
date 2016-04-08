#include <stdio.h>
#include <conio.h>
#define DEBUG 10
#include "debug.h"

//#define PDEBUG(format,...)\
	//printf("%s:%d " format " \n", __FUNCTIONW__, __LINE__, __VA_ARGS__);

int main(void){
	int i = 0;
	while (i < 6){
		PDEBUG(1, "i=%d",i);
		i++;
	}
	/*PDEBUG("value 1 = %d", 10);
	PDEBUG("value 1 = %d; value 2 = %d", 10, 100);
	PDEBUG("value 1 = %d; value 2 = %d; value 3 = %s", 10, 100, "hello");*/

	_getch();
	return 0;
}