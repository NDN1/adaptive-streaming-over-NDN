#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_opentxtdialog.h"

#include <QFile>
#include <QString>
#include <QPainter>
#include <QDebug>
#include <QMessageBox>
#include <QTextStream>
#include <QApplication>
#include<QHBoxLayout>
#include<QVBoxLayout>

#include<QBrush>
#include<QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),np(new QProcess),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->setWindowOpacity(0.5);
  QPalette palette=ui->textEdit->palette();

    palette.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->textEdit->setPalette(palette);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

np->start("MP4Client  /home/ubuntu/multimediaData/AVC/BBB/bunny_2s_2000kbit/bunny_2000kbit_dashNonSeg.mp4");
if(np->state()==QProcess::Running){
    np->terminate();
}
}

void MainWindow::on_pushButton_2_clicked()
{

    netd=new internetDialog(this);
    netd->exec();
    connect(netd,SIGNAL(readyToRead(QString)),this,SLOT(showConsole(QString)));
   // ui->textEdit->append(netd->getOutPut());
}

void MainWindow::on_pushButton_3_clicked()
{
    QString filename="cs-trace.txt";
   // filename = QFileDialog::getOpenFileName(this,tr("files"),"",tr("text(*.txt"));
    if(!filename.isNull()){
        QFile file(filename);
        if(!file.open(QFile::ReadOnly|QFile::Text)){
            QMessageBox::warning(this,tr("Error"),tr("read file error:&1").arg(file.errorString()));
            return;
        }
        QTextStream in(&file);
        QApplication::setOverrideCursor(Qt::WaitCursor);

        otd = new opentxtDialog(this);
        otd->setModal(false);
        otd->ui->textEdit->setPlainText(in.readAll());
        QApplication::restoreOverrideCursor();
        otd->show();
    }
    else{
        qDebug()<<"cancel";
    }
}
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    painter.drawPixmap(0,0,width(),height(),QPixmap(":/new/mbj.png"));
}
void MainWindow::showConsole(QString content){
    ui->textEdit->append(content);
}

void MainWindow::on_pushButton_4_clicked()
{
    exed=new Executefile(this);
    exed->show();
    connect(exed,SIGNAL(rtr(QString)),this,SLOT(showConsole(QString)));
}
