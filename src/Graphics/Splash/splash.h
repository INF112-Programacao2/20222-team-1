#ifndef SPLASH_H
#define SPLASH_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Splash; }
QT_END_NAMESPACE

class Splash : public QMainWindow
{
    Q_OBJECT

public:
    Splash(QWidget *parent = nullptr);
    ~Splash();

private:
    Ui::Splash *ui;
};
#endif // SPLASH_H
