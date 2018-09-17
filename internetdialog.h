#ifndef INTERNETDIALOG_H
#define INTERNETDIALOG_H

#include <QDialog>
#include <QPaintEvent>
#include <QProcess>
#include <QString>

namespace Ui {
class internetDialog;
}

class internetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit internetDialog(QWidget *parent = 0);
    ~internetDialog();

    void paintEvent(QPaintEvent *event);
    QString getOutPut(){
        return shellOutput;
    }
signals:
    void readyToRead(QString content);
public slots:
     void readProcess();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::internetDialog *ui;
    QString shellOutput;
    QProcess *pro;
};

#endif // INTERNETDIALOG_H
