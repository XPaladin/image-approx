#ifndef IMAGE_H
#define IMAGE_H
#include <assert.h>
class Image
{
protected:
	unsigned char **intensidades;
	unsigned char ***img;
    int w;
    int h;
    bool intensity_calculated;
    void calc_intensity();
    Image();
public:
    Image(unsigned char ***img,int height,int width);
    Image(int height,int width);
    ~Image();
    void setPixel(const unsigned char color[3], const int i, const int j);
    void setPixel(const unsigned char color[3], const int absolute_index);
    unsigned char getRed(int absolute_index);
    unsigned char getBlue(int absolute_index);
    unsigned char getGreen(int absolute_index);
    unsigned char getRed(int i, int j);
    unsigned char getGreen(int i, int j);
    unsigned char getBlue(int i, int j);
    int width();
    int height();
    unsigned char intensity(int absolute_index);
    unsigned char intensity(int i,int j);
    unsigned char*** getImage();
    //Image operator=(Image image);
};

#endif // IMAGE_H
