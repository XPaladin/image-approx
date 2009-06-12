#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "paintwidget.h"
#include "Image.h"
#include <assert.h>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void exec(int minSize,int maxDif);

private:
    PaintWidget *paintW;
    Image *image;
    Ui::MainWindow *ui;
    void loadImageFile();


private slots:
    void on_actionAproximacion_triggered();
    void on_actionMalla_triggered();
    void on_actionGuardar_Imagen_triggered();
    void on_actionAplicar_Algoritmo_triggered();
    void on_actionCargar_Imagen_triggered();
};

#endif // MAINWINDOW_H
