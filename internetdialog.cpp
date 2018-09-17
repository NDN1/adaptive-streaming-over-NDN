#include "internetdialog.h"
#include "ui_internetdialog.h"
#include <QString>
#include <QDebug>
#include <QProcess>
#include <QPainter>
#include<mainwindow.h>

internetDialog::internetDialog(QWidget *parent) :
    QDialog(parent),pro(new QProcess),
    ui(new Ui::internetDialog)
{
    pro=new QProcess;

    ui->setupUi(this);
}

internetDialog::~internetDialog()
{
    delete ui;
}

void internetDialog::on_pushButton_clicked()
{
    QString str;
    QString forward,adaptive,topology;

    if(ui->comboBox->currentText()=="BestRoute Strategy")
        forward="best";
    if(ui->comboBox->currentText()=="NCC Strategy")
        forward="ncc";
    if(ui->comboBox->currentText()=="Multicast Strategy")
        forward="multicast";
    if(ui->comboBox->currentText()=="Client-control Strategy")
        forward="client";

    if(ui->comboBox_2->currentText()=="Buffer-Based Adaptation")
        adaptive="buffer";
    if(ui->comboBox_2->currentText()=="Buffer-Based AdaptationLogicAggressive")
        adaptive="bufferAggressive";
    if(ui->comboBox_2->currentText()=="Buffer-Based AdaptationLogicNormal")
        adaptive="buffernormal";
    if(ui->comboBox_2->currentText()=="No AdaptationLogic")
        adaptive="no";
    if(ui->comboBox_2->currentText()=="AlwaysLowest AdaptationLogic")
        adaptive="always";
    if(ui->comboBox_2->currentText()=="Rate-Based AdaptationLogic")
        adaptive="ratebased";

    if(ui->comboBox_4->currentText()=="10 nodes topology")
        topology="1";
    if(ui->comboBox_4->currentText()=="50 nodes topology")
        topology="2";

    str=forward+"-"+ui->comboBox_3->currentText()+"-"+adaptive+"-"+topology+".sh";
    qDebug()<<str;
    //QProcess *pro = new QProcess;
    QString program;
    program = "/home/ubuntu/shell/"+str;

    connect(pro, SIGNAL(readyRead()), this, SLOT(readProcess()));
    pro->start(program);
    qDebug()<<program;
    this->close();
}

void internetDialog::on_pushButton_2_clicked()
{
    this->close();
}
void internetDialog::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    painter.drawPixmap(0,0,width(),height(),QPixmap(":/new/welcomebj.png"));
}
void internetDialog::readProcess(){
   shellOutput=pro->readAll();
     if(shellOutput!=""){
         emit(readyToRead(shellOutput));
     }
     qDebug()<<shellOutput;

     //do something
}
