/*
 * Rectangle.cpp
 *
 *  Created on: 01-05-2009
 *      Author: Pablo
 */

#include "Rectangle.h"
#include <stdio.h>

Rectangle::Rectangle(Point _SO,Point _NE){
        NE=_NE;
        SO=_SO;
}
Rectangle::Rectangle() {
	// TODO Auto-generated constructor stub
        NE=Point(0,0);
        SO=Point(1,1);
}

Rectangle::~Rectangle() {
/*
    delete NE;
    delete SO;
*/	// TODO Auto-generated destructor stub
}

bool Rectangle::invariante()const{
	return
        NE.getX()>=SO.getX() &&		//NE es el este
        SO.getY()<=NE.getY();		//SO es el sur

}
bool Rectangle::operator!=(const Rectangle r) const{
	assert(invariante()&& r.invariante());
	return !(*this==r);
}
bool Rectangle::operator==(const Rectangle r) const{
	assert(invariante()&&r.invariante());
	return
        NE.getX()== r.NE.getX() &&
        SO.getX()== r.SO.getX() &&
        NE.getY()== r.NE.getY() &&
        SO.getY()== r.SO.getY();

}
bool Rectangle::operator>(const Rectangle r) const{
	assert(invariante()&&r.invariante());
	return (*this>=r) && (*this!=r);
}
bool Rectangle::operator>=(const Rectangle r) const{
	assert(invariante()&&r.invariante());
	return
        NE.getX()>= r.NE.getX() &&
        SO.getX()<= r.SO.getX() &&
        NE.getY()>= r.NE.getY() &&
        SO.getY()<= r.SO.getY();
}
bool Rectangle::operator<(const Rectangle r) const{
	assert(invariante()&&r.invariante());
	return *this<=r && *this!=r;
}
bool Rectangle::operator<=(const Rectangle r) const{
	assert(invariante()&&r.invariante());
	return
        NE.getX()<= r.NE.getX() &&
        SO.getX()>= r.SO.getX() &&
        NE.getY()<= r.NE.getY() &&
        SO.getY()>= r.SO.getY();
}
int Rectangle::width()const {
	assert(invariante());
        return NE.getX()-SO.getX();
}
int Rectangle::height() const {
	assert(invariante());
        return NE.getY()-SO.getY();
}
Point Rectangle::getSO() const{
	assert(invariante());
	return SO;
}
Point Rectangle::getNE() const{
	assert(invariante());
	return NE;
}
Point Rectangle::getSE() const{
	assert(invariante());
        return Point(NE.getX(),SO.getY());
}
Point Rectangle::getNO() const{
	assert(invariante());
        return Point(SO.getX(),NE.getY());
}
void Rectangle::draw(Image * img)const{
	//printf("r=%d,g=%d,b=%d\n",rgb[0],rgb[1],rgb[2]);
	assert(img!=0 &&
			NE.getX() <= img->width() &&
			NE.getY() <= img->height() &&
			SO.getX() >= 0 &&
			SO.getY() >= 0
			);
	for(int i=SO.getX();
			i<NE.getX();
			i++	){
		img->setPixel(rgb,i, NE.getY()-1);
		img->setPixel(rgb,i, SO.getY());
	}
	for(int j=SO.getY();
			j<NE.getY();
			j++	){
			img->setPixel(rgb,NE.getX()-1,j);
			img->setPixel(rgb,SO.getX(),j);
	}


}
void Rectangle::fill(Image * img)const{
	assert(img!=0 &&
				NE.getX() <= img->width() &&
				NE.getY() <= img->height() &&
				SO.getX() >= 0 &&
				SO.getY() >= 0
				);
	for(int i=SO.getX();
				i<NE.getX();
				i++	){
		for(int j=SO.getY();
					j<NE.getY();
					j++	){
					img->setPixel(rgb,i,j);
		}
	}
}

	/*
	painter->setPen(color);
    printf("r %d,g %d,b %d\n",qRed(color),qGreen(color),qBlue(color));
    painter->fillRect(QRect(
            QPoint(getNO().getX(),getNO().getY() ),
            QPoint(getSE().getX(),getSE().getY() ) ),
                      Qt::SolidPattern );
	 */

Rectangle * Rectangle::clone()const{
    return new Rectangle(SO,NE);
}
void Rectangle::calcColor(Image * img){
	float r=0;
	float g=0;
	float b=0;
	for(int i=SO.getX();
		i<NE.getX();
		i++){
		for(int j=SO.getY();
			j<NE.getY();
			j++){
			r+=img->getRed(i,j)*1.0/(NE.getX()-SO.getX())/(NE.getY()-SO.getY());
			g+=img->getGreen(i,j)*1.0/(NE.getX()-SO.getX())/(NE.getY()-SO.getY());
			b+=img->getBlue(i,j)*1.0/(NE.getX()-SO.getX())/(NE.getY()-SO.getY());
		}
	}
	//printf("r=%d,g=%d,b=%d\n",(int)r,(int)g,(int)b);
	rgb[0] = (unsigned char)r;
	rgb[1] = (unsigned char)g;
	rgb[2] = (unsigned char)b;
}


