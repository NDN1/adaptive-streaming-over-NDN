#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPalette>
#include "internetdialog.h"
#include "opentxtdialog.h"
#include "executefile.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);


    internetDialog *netd;
    opentxtDialog *otd;
    Executefile *exed;
    QProcess *np;

public slots:
    void showConsole(QString content);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



    void on_pushButton_4_clicked();

    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
