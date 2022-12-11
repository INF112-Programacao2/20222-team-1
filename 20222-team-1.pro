QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/Graphics/Add/AddDoacao/adicionardoacao.cpp \
    src/Graphics/Add/AddConsumo/adicionarconsumo.cpp \
    src/Graphics/Add/AddReceptor/cadastrarreceptor.cpp \
    src/Graphics/ItemView/itemview.cpp \
    src/main.cpp \
    src/Banco/banco.cpp \
    src/Consumo/consumo.cpp \
    src/Doacao/doacao.cpp \
    src/Doador/Doador.cpp \
    src/Instituicao/instituicao.cpp \
    src/ProfissionalSaude/profissionalSaude.cpp \
    src/Receptor/receptor.cpp \
    src/Sangue/sangue.cpp \
    src/Graphics/AlertDialog/alertdialog.cpp \
    src/Graphics/Dashboard/dashboard.cpp \    
    src/Graphics/Login/login.cpp \
    src/Graphics/Register/registerinstituicao.cpp \
    src/Graphics/Register/registerprofissionalsaude.cpp \
    src/Graphics/Splash/splash.cpp

HEADERS += \
    src/Graphics/Add/AddDoacao/adicionardoacao.h \
    src/Graphics/Add/AddConsumo/adicionarconsumo.h \
    src/Graphics/Add/AddReceptor/cadastrarreceptor.h \
    src/Graphics/ItemView/itemview.h \
    src/main.cpp \
    src/Banco/Banco.h \
    src/Consumo/consumo.h \
    src/Doacao/doacao.h \
    src/Doador/Doador.h \
    src/Instituicao/instituicao.h \
    src/Pessoa/pessoaIF.h \
    src/ProfissionalSaude/profissionalSaude.h \
    src/Receptor/receptor.h \
    src/Sangue/sangue.h \
    src/Graphics/AlertDialog/alertdialog.h \
    src/Graphics/Dashboard/dashboard.h \
    src/Graphics/Login/login.h \
    src/Graphics/Register/registerinstituicao.h \
    src/Graphics/Register/registerprofissionalsaude.h \
    src/Graphics/Splash/splash.h

FORMS += \
    src/Graphics/Add/AddDoacao/adicionardoacao.ui \
    src/Graphics/Add/AddConsumo/adicionarconsumo.ui \
    src/Graphics/Add/AddReceptor/cadastrarreceptor.ui \
    src/Graphics/AlertDialog/alertdialog.ui \
    src/Graphics/Dashboard/dashboard.ui \
    src/Graphics/ItemView/itemview.ui \
    src/Graphics/Login/login.ui \
    src/Graphics/Register/registerinstituicao.ui \
    src/Graphics/Register/registerprofissionalsaude.ui \
    src/Graphics/Splash/splash.ui

RESOURCES += \
    resouces.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
