#include "mainwindow.h"
#include <QApplication>
#include "welcomedialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    welcomeDialog wd;


    if(wd.exec()== welcomeDialog::Accepted)
         w.show();

    return a.exec();
}
