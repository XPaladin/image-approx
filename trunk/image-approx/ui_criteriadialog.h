/********************************************************************************
** Form generated from reading ui file 'criteriadialog.ui'
**
** Created: Sun 3. May 03:28:57 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CRITERIADIALOG_H
#define UI_CRITERIADIALOG_H

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

class Ui_CriteriaDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *spinBox;
    QSpinBox *MaxDifSpinBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *CriteriaDialog)
    {
        if (CriteriaDialog->objectName().isEmpty())
            CriteriaDialog->setObjectName(QString::fromUtf8("CriteriaDialog"));
        CriteriaDialog->resize(188, 88);
        buttonBox = new QDialogButtonBox(CriteriaDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(100, 10, 81, 71));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(CriteriaDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 10, 91, 71));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBox = new QSpinBox(gridLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(3);
        spinBox->setMaximum(400);
        spinBox->setValue(100);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        MaxDifSpinBox = new QSpinBox(gridLayoutWidget);
        MaxDifSpinBox->setObjectName(QString::fromUtf8("MaxDifSpinBox"));
        MaxDifSpinBox->setMinimum(1);
        MaxDifSpinBox->setMaximum(255);
        MaxDifSpinBox->setValue(100);

        gridLayout->addWidget(MaxDifSpinBox, 2, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);


        retranslateUi(CriteriaDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CriteriaDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CriteriaDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CriteriaDialog);
    } // setupUi

    void retranslateUi(QDialog *CriteriaDialog)
    {
        CriteriaDialog->setWindowTitle(QApplication::translate("CriteriaDialog", "Crear Malla", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CriteriaDialog", "Min Size", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CriteriaDialog", "Max Dif", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(CriteriaDialog);
    } // retranslateUi

};

namespace Ui {
    class CriteriaDialog: public Ui_CriteriaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRITERIADIALOG_H
