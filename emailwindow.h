#ifndef EMAILWINDOW_H
#define EMAILWINDOW_H

#include <QMainWindow>

namespace Ui {
class emailWindow;
}

class emailWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit emailWindow(QWidget *parent = nullptr);
    ~emailWindow();

private slots:
    void on_makesureInputEmail_clicked();

private:
    Ui::emailWindow *ui;
};

#endif // EMAILWINDOW_H
