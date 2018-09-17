#include "executefile.h"
#include "ui_executefile.h"
#include "qfiledialog.h"
#include "qmessagebox.h"
#include "qdesktopservices.h"
#include "qprocess.h"
#include "qdebug.h"
#include "qmessagebox.h"
Executefile::Executefile(QWidget *parent) :
    QDialog(parent),npr(new QProcess),
    ui(new Ui::Executefile)
{

    ui->setupUi(this);

}

Executefile::~Executefile()
{
    delete ui;
}



void Executefile::on_browse1_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open .pacp"), ".", tr("Pcap Files(*.svc *.img *.txt *.mpd *.pcapng)"));
        if (path.length() == 0)
        {
            QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        }
        else
        {
            ui->textEdit->setText(path);
        }

}

void Executefile::on_browse2_clicked()
{

    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        if (dir.length() == 0)
        {
            QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
        }
        else
        {
            ui->textEdit2->setText(dir);
        }
}

void Executefile::on_check_clicked()
{
    QString str=ui->textEdit2->toPlainText();

QDesktopServices::openUrl(QUrl::fromLocalFile(str));
}

void Executefile::on_start_clicked()
{
    QString text1=ui->textEdit->toPlainText();
    QString text2=ui->textEdit2->toPlainText();
    if(text1.length()==0)
    {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select file path"));
    }
    else if(text2.length()==0)
    {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select output file path"));
    }
    else{
          int first = text1.lastIndexOf ("/");
          QString title = text1.right (text1.length ()-first-1);
          QString cmd="./waf --run \"scratch/test2 --filepath="+text1;
          QString cmd2=" --outputfile="+text2;
          QString s1="/";
          QString s2=title+"\"";
          cmd=cmd+cmd2+s1+s2;
          char*  ch;
          QByteArray ba = cmd.toLatin1();
          ch=ba.data();
          connect(npr, SIGNAL(readyRead()), this, SLOT(readPro()));
          npr->start(ch);
          //system(ch);


//          QProcess process;
//          process.start("./waf --run tt1");
//          process.waitForFinished();
//          QString output=process.readAll();

//           qDebug()<<output;
//           ui->textEdit_2->append(output);



          //qDebug("readString = %s",qPrintable(title));

//          QProcess *process =new QProcess;
//          process->start("./waf --run test2");
//        process.waitForFinished();
//        process.start("./waf --run ndn-file-simple-example3-enhanced");
//        process.waitForFinished();

    }

}void Executefile::readPro(){
    re=npr->readAll();
      if(re!=""){
          emit(rtr(re));
      }



 }


