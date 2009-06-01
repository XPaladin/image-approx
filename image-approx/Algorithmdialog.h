#ifndef ALGORITHMDIALOG_H
#define ALGORITHMDIALOG_H

#include <QtGui/QDialog>
#include "mainwindow.h"
namespace Ui {
    class AlgorithmDialog;
}

class AlgorithmDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(AlgorithmDialog)
public:
    explicit AlgorithmDialog(QWidget *parent = 0);
    virtual ~AlgorithmDialog();

protected:
    virtual void changeEvent(QEvent *e);
    MainWindow *father;

private:
    Ui::AlgorithmDialog *m_ui;

private slots:
    void on_buttonBox_accepted();
};

#endif // ALGORITHMDIALOG_H
