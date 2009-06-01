#include "Shape.h"

Shape::Shape()
{
}
void Shape::setColor(const unsigned char color[3]){
	for(int i=0;i<3;i++){
		rgb[i]=color[i];
	}

}
