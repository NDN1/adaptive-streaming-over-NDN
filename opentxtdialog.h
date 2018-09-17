#ifndef OPENTXTDIALOG_H
#define OPENTXTDIALOG_H

#include <QDialog>
#include <QPaintEvent>

namespace Ui {
class opentxtDialog;
}

class opentxtDialog : public QDialog
{
    Q_OBJECT

public:
    explicit opentxtDialog(QWidget *parent = 0);
    ~opentxtDialog();
    void paintEvent(QPaintEvent *event);
    Ui::opentxtDialog *ui;
};

#endif // OPENTXTDIALOG_H
