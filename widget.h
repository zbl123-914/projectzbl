#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btninsert_clicked();
    void on_btnquery_clicked();
    void on_btndelete_clicked();
    void on_btnupdate_clicked();
    void on_btnperform_clicked();  // 新增槽函数声明，原来是on_btnshow_clicked

private:
    Ui::Widget *ui;
    void perform();  // 将原show函数名改为perform
    void Query(const QString &name, const QString &pwd);
};

#endif // WIDGET_H
