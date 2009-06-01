#include "Algorithmdialog.h"
#include "ui_Algorithmdialog.h"
#include "mainwindow.h"

AlgorithmDialog::AlgorithmDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::AlgorithmDialog)
{
    this->father=(MainWindow *)parent;
    m_ui->setupUi(this);
}

AlgorithmDialog::~AlgorithmDialog()
{
    delete m_ui;
}

void AlgorithmDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void AlgorithmDialog::on_buttonBox_accepted()
{
    father->exec(m_ui->MinSizeSpinBox->value(),m_ui->MaxDifSpinBox->value());
}
