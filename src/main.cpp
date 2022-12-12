#include "Graphics/Splash/splash.h"
#include "Graphics/Login/login.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    Banco* main = new Banco();
    QApplication app(argc, argv);

    Splash *splashScreen = new Splash;
    Login *login = new Login;

    splashScreen->show();

    QTimer::singleShot(2500, splashScreen, SLOT(close()));
    QTimer::singleShot(2500, login, SLOT(show()));

    app.exec();

    delete splashScreen;
    delete login;
    delete main;
}
