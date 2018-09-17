#ifndef EXECUTEFILE_H
#define EXECUTEFILE_H
#include <QProcess>
#include <QDialog>

namespace Ui {
class Executefile;
}

class Executefile : public QDialog
{
    Q_OBJECT

public:
    explicit Executefile(QWidget *parent = 0);
    ~Executefile();
QProcess *npr;
QString re;
signals:
 void rtr(QString con);
private slots:


    void on_browse1_clicked();

    void on_browse2_clicked();


    void on_check_clicked();

    void on_start_clicked();
public slots:
     void readPro();

private:
    Ui::Executefile *ui;
};

#endif // EXECUTEFILE_H
