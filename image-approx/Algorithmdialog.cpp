#include "Algorithmdialog.h"
#include "ui_Algorithmdialog.h"
#include "mainwindow.h"
#include "CriterioFactory.h"
#include "AlgorithmFactory.h"

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
	AlgorithmFactory::AlgorithmEnum AlgoType=AlgorithmFactory::QUADTREE;
	CriterioFactory::CriterioEnum CritType=CriterioFactory::MAX_DIF;
	if(m_ui->MaxDifRadio->isChecked()){

		if(m_ui->IgnoreCheck->isChecked()){
			CritType=CriterioFactory::MAX_DIF_IGNORE_PERCENT;
		}
	}else{
		CritType=CriterioFactory::MAX_VAR;
	}

    father->exec(AlgoType, CritType, m_ui->MinSizeSpinBox->value(),
    		m_ui->MaxDifSpinBox->value(),
    		m_ui->PercentSpin->value());
}
