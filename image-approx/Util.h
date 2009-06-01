#ifndef UTIL_H
#define UTIL_H

#endif // UTIL_H
#include <math.h>
#include "Rectangle.h"
#include <QRGB>
#include <QImage>



/*
static int max(int x, int y){
    return x>y?x:y;
}
*/
/*
static float square(float x){
    return x*x;
}
*/
//Funcion de distancia entre 2 colores
static float distance(QRgb x,QRgb y){
    return fabs( ((qBlue(x)+qRed(x)+qGreen(x))/3.0f) -
                ((qBlue(y)+qRed(y)+qGreen(y))/3.0f) );
  //  printf("r=%d,g=%d,b=%d\n",qRed(x),qGreen(x),qBlue(x));
    /*
    return max(abs(qBlue(x)-qBlue(y)),
            max(abs(qRed(x)-qRed(y)),
                abs(qGreen(x)-qGreen(y))));
*/
}

static bool different(QImage img, Rectangle::Rectangle r,int maxDif){
    /*
    QImage img;
    assert(!imgfn.isEmpty());
   // printf("%s\n", imgfn.toAscii().constData() );
    img.load(imgfn);
    */
    assert(!img.isNull());
    QRgb rgb1,rgb2;
    for(int i=r.getSO().getX();
        i<r.getNE().getX();
        i++){
        for(int j=r.getSO().getY();
            j<r.getNE().getY();
            j++){
            assert(img.valid(i,j));
            rgb1=img.pixel(i,j);
            for(int ii=r.getSO().getX();
                ii<r.getNE().getX();
                ii++){
                for(int jj=r.getSO().getY();
                    jj<r.getNE().getY();
                    jj++){
                    assert(img.valid(ii,jj));
                    rgb2=img.pixel(ii,jj);
                   // float d=distance(rgb1,rgb2);
                   // if(d>0)printf("d=%f\n",d);
                    if(distance(rgb1,rgb2)>maxDif){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
static QRgb average(QImage img, Rectangle::Rectangle rec){
    float r=0;
    float g=0;
    float b=0;
    QRgb rgb;
    for(int i=rec.getSO().getX();
        i<rec.getNE().getX();
        i++){
        for(int j=rec.getSO().getY();
            j<rec.getNE().getY();
            j++){
            assert(img.valid(i,j));
            rgb=img.pixel(i,j);
            r+=qRed(rgb)*1.0/(rec.getNE().getX()-rec.getSO().getX())/(rec.getNE().getY()-rec.getSO().getY());
            g+=qGreen(rgb)*1.0/(rec.getNE().getX()-rec.getSO().getX())/(rec.getNE().getY()-rec.getSO().getY());
            b+=qBlue(rgb)*1.0/(rec.getNE().getX()-rec.getSO().getX())/(rec.getNE().getY()-rec.getSO().getY());
        }
    }
    printf("r=%d,g=%d,b=%d\n",(int)r,(int)g,(int)b);
    return qRgb( (int)r,(int)g,(int)b);
}

