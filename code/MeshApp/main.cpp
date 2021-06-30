#include "MeshApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MeshApp w;
    w.show();
    return a.exec();
}
