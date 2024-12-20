#ifndef HELPINGWINDOW_H
#define HELPINGWINDOW_H

#include <QMainWindow>

namespace Ui {
class helpingWindow;
}

class helpingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit helpingWindow(QWidget *parent = nullptr);
    ~helpingWindow();

private:
    Ui::helpingWindow *ui;
};

#endif // HELPINGWINDOW_H
