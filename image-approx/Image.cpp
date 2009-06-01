#include "Image.h"

Image::Image(){
    assert(false);
}
Image::Image(unsigned char ***image, int width, int height)
{
	assert(width>0&&height>0);
    w=width;
    h=height;
    img=new unsigned char**[h];
    intensidades=new unsigned char*[h];
    for(int i=0;i<h;i++){
    	intensidades[i]=new unsigned char[w];
    	img[i]=new unsigned char*[w];
    	for(int j=0; j<w;j++){
    		img[i][j]=new unsigned char[3];
    		for(int k=0;k<3;k++)
    			img[i][j][k]=image[i][j][k];
    	}
    }
    intensity_calculated=false;
}
Image::Image(int width, int height)
{
	assert(width>0&&height>0);
	w=width;
	h=height;
	img=new unsigned char**[h];
	intensidades=new unsigned char*[h];
	for(int i=0;i<h;i++){
		intensidades[i]=new unsigned char[w];
		img[i]=new unsigned char*[w];
		for(int j=0; j<w;j++){
			img[i][j]=new unsigned char[3];
			for(int k=0;k<3;k++)
				img[i][j][k]=0;
		}
	}
	intensity_calculated=false;
}
 Image::~Image(){

    for(int i=0;i<h;i++){
        delete[] intensidades[i];
        delete[] img[i];
    }
    delete[] intensidades;
    delete[] img;
}
void Image::calc_intensity(){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
        	assert( 0<=img[i][j][0] && img[i][j][0]<256 &&
        			0<=img[i][j][1] && img[i][j][1]<256 &&
        			0<=img[i][j][2] && img[i][j][2]<256 );

        	intensidades[i][j]=(unsigned char)((img[i][j][0]+img[i][j][1]+img[i][j][2])/3);
        }
    }
    intensity_calculated=true;
}
void Image::setPixel(const unsigned char color[3], const int i,const int j){
    assert(i>=0 && j>=0 && i<w && j<h);
    for(int k=0;k<3;k++)
        img[j][i][k]=color[k];
    intensity_calculated=false;
}
void Image::setPixel(const unsigned char color[3], const int absolute_index){
    assert(absolute_index>=0 && absolute_index<w*h);
    setPixel(color,absolute_index/w,absolute_index%w);
}
unsigned char Image::getRed(int absolute_index){
    assert(absolute_index>=0 && absolute_index<w*h);
    return getRed(absolute_index/w,absolute_index%w);
}
unsigned char Image::getBlue(int absolute_index){
    assert(absolute_index>=0 && absolute_index<w*h);
    return getBlue(absolute_index/w,absolute_index%w);
}
unsigned char Image::getGreen(int absolute_index){
    assert(absolute_index>=0 && absolute_index<w*h);
    return getGreen(absolute_index/w,absolute_index%w);
}
unsigned char Image::getRed(int i, int j){
    assert(i>=0 && j>=0 && i<w && j<h);
    return img[j][i][0];
}
unsigned char Image::getGreen(int i, int j){
    assert(i>=0 && j>=0 && i<w && j<h);
    return img[j][i][1];
}
unsigned char Image::getBlue(int i, int j){
    assert(i>=0 && j>=0 && i<w && j<h);
    return img[j][i][2];
}
int Image::width(){
    return w;
}
int Image::height(){
    return h;
}
unsigned char Image::intensity(int absolute_index){
    assert(absolute_index<w*h);
    return intensity(absolute_index/w,absolute_index%w);
}
unsigned char Image::intensity(int i,int j){
    assert(i<w && j<h);
    if(!intensity_calculated){
        calc_intensity();
    }
    assert(intensity_calculated);
    return intensidades[j][i];
}
unsigned char ***Image::getImage(){
	return img;

}
/*
Image Image::operator=(Image image){
    w=image.width();
    h=image.height();
    img=image.img;
    intensidades=image.intensidades;
    intensity_calculated=image.intensity_calculated;

}
*/
