#ifndef USERNAMEWINDOW_H
#define USERNAMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class usernameWindow;
}

class usernameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit usernameWindow(QWidget *parent = nullptr);
    ~usernameWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::usernameWindow *ui;
};

#endif // USERNAMEWINDOW_H
