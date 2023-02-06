#include <QCoreApplication>
#include <my.h>

int main(int argc, char *argv[]){

    QCoreApplication a(argc, argv);

    setlocale(0,"Russian");

    my m;

    return a.exec();
}
