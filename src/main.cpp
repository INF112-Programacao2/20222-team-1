#include "Graphics/Splash/splash.h"
#include "Graphics/Login/login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Splash w;
    Login l;
    l.show();
    //w.show();
    a.exec();
    
    return 0;
}
