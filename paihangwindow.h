#ifndef PAIHANGWINDOW_H
#define PAIHANGWINDOW_H

#include <QMainWindow>

namespace Ui {
class paihangWindow;
}

class paihangWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit paihangWindow(QWidget *parent = nullptr);
    ~paihangWindow();

private:
    Ui::paihangWindow *ui;
};

#endif // PAIHANGWINDOW_H
