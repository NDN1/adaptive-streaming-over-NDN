#include "opentxtdialog.h"
#include "ui_opentxtdialog.h"
#include <QPainter>
#include <QPalette>
#include <QTextEdit>

opentxtDialog::opentxtDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::opentxtDialog)
{
    ui->setupUi(this);
    QPalette pl = ui->textEdit->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    //palette.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->textEdit->setPalette(pl);
}

opentxtDialog::~opentxtDialog()
{
    delete ui;
}
void opentxtDialog::paintEvent(QPaintEvent *event){

    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap(":/new/about.png"));
}
