#include "paihangwindow.h"
#include "ui_paihangwindow.h"
#include <QTableWidget>
paihangWindow::paihangWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::paihangWindow)
{
    ui->setupUi(this);
}

paihangWindow::~paihangWindow()
{
    delete ui;
}
