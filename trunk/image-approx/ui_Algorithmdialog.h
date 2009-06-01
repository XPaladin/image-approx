/********************************************************************************
** Form generated from reading ui file 'Algorithmdialog.ui'
**
** Created: Sun 31. May 18:08:52 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ALGORITHMDIALOG_H
#define UI_ALGORITHMDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlgorithmDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *MinSizeSpinBox;
    QSpinBox *MaxDifSpinBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *AlgorithmDialog)
    {
        if (AlgorithmDialog->objectName().isEmpty())
            AlgorithmDialog->setObjectName(QString::fromUtf8("AlgorithmDialog"));
        AlgorithmDialog->resize(234, 87);
        buttonBox = new QDialogButtonBox(AlgorithmDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(150, 10, 81, 71));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(AlgorithmDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 10, 151, 71));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        MinSizeSpinBox = new QSpinBox(gridLayoutWidget);
        MinSizeSpinBox->setObjectName(QString::fromUtf8("MinSizeSpinBox"));
        MinSizeSpinBox->setMinimum(3);
        MinSizeSpinBox->setMaximum(400);
        MinSizeSpinBox->setValue(100);

        gridLayout->addWidget(MinSizeSpinBox, 0, 1, 1, 1);

        MaxDifSpinBox = new QSpinBox(gridLayoutWidget);
        MaxDifSpinBox->setObjectName(QString::fromUtf8("MaxDifSpinBox"));
        MaxDifSpinBox->setMinimum(1);
        MaxDifSpinBox->setMaximum(255);
        MaxDifSpinBox->setValue(50);

        gridLayout->addWidget(MaxDifSpinBox, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        retranslateUi(AlgorithmDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AlgorithmDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AlgorithmDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AlgorithmDialog);
    } // setupUi

    void retranslateUi(QDialog *AlgorithmDialog)
    {
        AlgorithmDialog->setWindowTitle(QApplication::translate("AlgorithmDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AlgorithmDialog", "MinSize", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AlgorithmDialog", "MaxDif", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AlgorithmDialog);
    } // retranslateUi

};

namespace Ui {
    class AlgorithmDialog: public Ui_AlgorithmDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALGORITHMDIALOG_H
