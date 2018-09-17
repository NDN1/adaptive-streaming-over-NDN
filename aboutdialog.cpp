#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QPainter>
#include <QPalette>

aboutDialog::aboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDialog)
{
    ui->setupUi(this);
    QPalette pl = ui->textEdit->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    //palette.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->textEdit->setPalette(pl);
    ui->textEdit->append("ndn adaptive multimedia player, version 1.0 \n developed by ndn-AMUS team");
}

aboutDialog::~aboutDialog()
{
    delete ui;
}
void aboutDialog::paintEvent(QPaintEvent *event){

    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap(":/new/about.png"));
}
