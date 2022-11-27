#include "Graphics/Splash/splash.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Splash w;
    w.show();
    return a.exec();
}
