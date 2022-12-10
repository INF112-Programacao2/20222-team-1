#ifndef ALERTDIALOG_H
#define ALERTDIALOG_H

#include <QDialog>
#include <string>

namespace Ui {
class AlertDialog;
}

class AlertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AlertDialog(QWidget *parent = nullptr);
    void SetMessage(std::string message);
    ~AlertDialog();

private:
    Ui::AlertDialog *ui;
};

#endif // ALERTDIALOG_H
