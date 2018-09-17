#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QPaintEvent>

namespace Ui {
class aboutDialog;
}

class aboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit aboutDialog(QWidget *parent = 0);
    ~aboutDialog();
    void paintEvent(QPaintEvent *event);

private:
    Ui::aboutDialog *ui;
};

#endif // ABOUTDIALOG_H
