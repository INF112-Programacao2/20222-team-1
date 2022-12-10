#include "Graphics/Splash/splash.h"
#include "Graphics/Login/login.h"
//#include "Graphics/Dashboard/dashboard.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Splash *splashScreen = new Splash;
    Login *login = new Login;

    splashScreen->show();

    QTimer::singleShot(5000, splashScreen, SLOT(close()));
    QTimer::singleShot(5000, login, SLOT(show()));

    app.exec();

    delete splashScreen;
    delete login;
}
