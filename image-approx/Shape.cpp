#include "Shape.h"
#include <stdio.h>
#include <stdlib.h>

Shape::Shape()
{
	rgb[0]=rgb[1]=rgb[2]=0;
}
void Shape::setColor(const unsigned char color[3]){
	for(int i=0;i<3;i++){
		rgb[i]=color[i];
	}
}
char *Shape::getColorCode()const{

	char *newstr = new char[9];
	char *cpnew = newstr;
	cpnew[0]='0';
	cpnew[1]='x';
	cpnew+=2;
	for(int i=0;i<3;i++) {
	sprintf(cpnew, "%02X", rgb[i]);
	cpnew+=2;
	}
	*(cpnew) = '\0';
	return(newstr);

}
/*
	char hex[6], *stop;
	hex[0] = '0';
	hex[1] = 'x';
	hex[2] = rgb[0];
	hex[3] = rgb[1];
	hex[4] = rgb[2];
	hex[5] = '\0';
	return strtol(hex, &stop, 16);
	*/


