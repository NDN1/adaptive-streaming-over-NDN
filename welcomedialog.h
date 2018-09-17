#ifndef WELCOMEDIALOG_H
#define WELCOMEDIALOG_H

#include <QDialog>
#include <QPaintEvent>
#include "aboutdialog.h"

namespace Ui {
class welcomeDialog;
}

class welcomeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit welcomeDialog(QWidget *parent = 0);
    ~welcomeDialog();
    aboutDialog *ad;
    void paintEvent(QPaintEvent *event);

private slots:
    void on_toolButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::welcomeDialog *ui;
};

#endif // WELCOMEDIALOG_H
