#include "welcomedialog.h"
#include "ui_welcomedialog.h"
#include <QPainter>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QUrl>
#include <QDesktopServices>

welcomeDialog::welcomeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::welcomeDialog)
{
    ui->setupUi(this);
    //ui->pushButton->setStyleSheet("color:white");
}

welcomeDialog::~welcomeDialog()
{
    delete ui;
}

void welcomeDialog::on_toolButton_clicked()
{
     accept();
}

void welcomeDialog::on_pushButton_clicked()
{
    ad = new aboutDialog(this);
    ad->show();
}
void welcomeDialog::paintEvent(QPaintEvent *event){

    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap(":/new/welcomebj.png"));
}

void welcomeDialog::on_pushButton_2_clicked()
{
    QString filepath="/home/ubuntu/ndnSIM/ns-3/dash-output.txt";
    QString local=QString("file:///%1").arg(filepath);
    QUrl url(local);
    QDesktopServices::openUrl(QUrl::fromLocalFile(filepath));

}
