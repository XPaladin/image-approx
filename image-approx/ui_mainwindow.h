/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sun 31. May 23:36:44 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCargar_Imagen;
    QAction *actionAplicar_Algoritmo;
    QAction *actionGuardar_Imagen;
    QAction *actionMalla;
    QAction *actionAproximacion;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuEdicion;
    QMenu *menuMostrar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(283, 290);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionCargar_Imagen = new QAction(MainWindow);
        actionCargar_Imagen->setObjectName(QString::fromUtf8("actionCargar_Imagen"));
        actionAplicar_Algoritmo = new QAction(MainWindow);
        actionAplicar_Algoritmo->setObjectName(QString::fromUtf8("actionAplicar_Algoritmo"));
        actionGuardar_Imagen = new QAction(MainWindow);
        actionGuardar_Imagen->setObjectName(QString::fromUtf8("actionGuardar_Imagen"));
        actionMalla = new QAction(MainWindow);
        actionMalla->setObjectName(QString::fromUtf8("actionMalla"));
        actionMalla->setCheckable(true);
        actionMalla->setChecked(true);
        actionAproximacion = new QAction(MainWindow);
        actionAproximacion->setObjectName(QString::fromUtf8("actionAproximacion"));
        actionAproximacion->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 283, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuEdicion = new QMenu(menuBar);
        menuEdicion->setObjectName(QString::fromUtf8("menuEdicion"));
        menuMostrar = new QMenu(menuBar);
        menuMostrar->setObjectName(QString::fromUtf8("menuMostrar"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy1);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuEdicion->menuAction());
        menuBar->addAction(menuMostrar->menuAction());
        menuArchivo->addAction(actionCargar_Imagen);
        menuArchivo->addAction(actionGuardar_Imagen);
        menuEdicion->addAction(actionAplicar_Algoritmo);
        menuMostrar->addAction(actionMalla);
        menuMostrar->addAction(actionAproximacion);

        retranslateUi(MainWindow);
        QObject::connect(actionMalla, SIGNAL(changed()), centralWidget, SLOT(repaint()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ImageApprox", 0, QApplication::UnicodeUTF8));
        actionCargar_Imagen->setText(QApplication::translate("MainWindow", "Cargar Imagen..", 0, QApplication::UnicodeUTF8));
        actionAplicar_Algoritmo->setText(QApplication::translate("MainWindow", "Aplicar Algoritmo..", 0, QApplication::UnicodeUTF8));
        actionGuardar_Imagen->setText(QApplication::translate("MainWindow", "Guardar Imagen", 0, QApplication::UnicodeUTF8));
        actionMalla->setText(QApplication::translate("MainWindow", "Malla", 0, QApplication::UnicodeUTF8));
        actionAproximacion->setText(QApplication::translate("MainWindow", "Aproximacion", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
        menuEdicion->setTitle(QApplication::translate("MainWindow", "Edicion", 0, QApplication::UnicodeUTF8));
        menuMostrar->setTitle(QApplication::translate("MainWindow", "Mostrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
