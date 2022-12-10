QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/Graphics/AlertDialog/alertdialog.cpp \
    src/main.cpp \
    src/Graphics/Splash/splash.cpp \
    src/Graphics/Login/login.cpp \
    src/Graphics/Dashboard/dashboard.cpp


HEADERS += \
    src/Graphics/AlertDialog/alertdialog.h \
    src/Graphics/Splash/splash.h \
    src/Graphics/Dashboard/dashboard.h \
    src/Graphics/Login/login.h

FORMS += \
    src/Graphics/AlertDialog/alertdialog.ui \
    src/Graphics/Splash/splash.ui \
    src/Graphics/Login/login.ui \
    src/Graphics/Dashboard/dashboard.ui

RESOURCES += \
    resouces.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


