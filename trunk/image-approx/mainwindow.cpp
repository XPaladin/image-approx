#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "QuadTreeAlgorithm.h"
#include "MaxDifIntensityCriterio.h"
#include "Algorithmdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    algorithm=0;
}

MainWindow::~MainWindow()
{
    delete ui;
    if(algorithm!=0)
    	delete algorithm;
}

void MainWindow::on_actionCargar_Imagen_triggered()
{
    QString imageFileName = QFileDialog::getOpenFileName(this, "Cargar Imagen");
    if (!imageFileName.isEmpty()){
        QImage qimage;
        qimage.load(imageFileName);
        unsigned char ***img=new unsigned char**[qimage.height()];
        QRgb color;

        for(int i=0;i<qimage.height();i++){
        	img[i]=new unsigned char*[qimage.width()];
        	for(int j=0;j<qimage.width();j++){
        		img[i][j]=new unsigned char[3];
        		color=qimage.pixel(j,i);
        		assert(qimage.valid(j,i));

        		img[i][j][0]=(unsigned char)qRed(color);
        		img[i][j][1]=(unsigned char)qGreen(color);
        		img[i][j][2]=(unsigned char)qBlue(color);
        		//   printf("aca i=%d,j=%d,r=%d\n",i,j,img[i][j][0]);
        	}
        }
        image= new Image(img, qimage.width(), qimage.height());
        paintW = new PaintWidget(image,this);
        this->setCentralWidget(paintW);
        paintW->setFixedSize(qimage.size());

    }
/*
    this->centralWidget.render(&image);
    this->centralWidget.setVisible(true);
    this->centralWidget.repaint();
*/
    /*
    this->setCentralWidget(image);
    this->centralWidget()->
    */
}

void MainWindow::exec(AlgorithmFactory::AlgorithmEnum AlgoType,
		CriterioFactory::CriterioEnum CritType, int minSize,
		int max, int ignore ){
    //image.convertToFormat(QImage::Format_RGB32);
        //printf("asdad Aca\n");
    algorithm=AlgorithmFactory::getInstance()->createAlgorithm(AlgoType,
    		CriterioFactory::createCriterio(CritType,
    				image, max, ignore),
    		image->width(),image->height(),minSize);
    paintW->setIterator(NetIteratorFactory::getInstance()->createNetLeafIterator(
    		(QuadTree *)algorithm->exec()));


    //delete algor;
}
void MainWindow::on_actionAplicar_Algoritmo_triggered()
{
    AlgorithmDialog::AlgorithmDialog(this).exec();

}

void MainWindow::on_actionGuardar_Imagen_triggered()
{
    QImage imagen = paintW->grabFrameBuffer(true);

    QString filename = QFileDialog::getSaveFileName(
                this,
                "Elije un archivo previo o ingresa uno nuevo",
                "/"
                );
        if (filename != NULL){
                imagen.save(filename);
        }



}

void MainWindow::on_actionMalla_triggered()
{
    paintW->malla();
}

void MainWindow::on_actionAproximacion_triggered()
{
    paintW->aproximacion();
}
