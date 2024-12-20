#ifndef GAMEPANELWINDOW_H
#define GAMEPANELWINDOW_H

#include "qsoundeffect.h"
#include <QMainWindow>
#include <QSoundEffect>
#include<QMediaPlayer>
#include<QAudioOutput>

namespace Ui {
class gamepanelWindow;
}

class gamepanelWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit gamepanelWindow(QWidget *parent = nullptr);
    ~gamepanelWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();
    // 实现重绘
    void updateWindow();


private:
    Ui::gamepanelWindow *ui;
    QSoundEffect *tap = new QSoundEffect();
    QSoundEffect *refresh=new QSoundEffect();
    QSoundEffect *boom=new QSoundEffect();
    QSoundEffect *countdown=new QSoundEffect();
    QSoundEffect *start=new QSoundEffect();
    QSoundEffect *gotEquipment=new QSoundEffect();
    QSoundEffect *bgm=new QSoundEffect();
    QSoundEffect*failToExchange=new QSoundEffect();
    QMediaPlayer player;
    QAudioOutput *audioOutput=new QAudioOutput();
    QTimer *timer;  // 定义 QTimer 为类的成员变量

    // 图片成员变量
    QPixmap pic_mine1;
    QPixmap pic_mine2;
    QPixmap pic_mine3;
    QPixmap pic_mine4;
    QPixmap pic_mine5;
    QPixmap pic_mine6;
    QPixmap pic_mine7;
    QPixmap pic_mine8;

    // 图片数组
    std::vector<QPixmap> pic_mines;

    void picInitial();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // GAMEPANELWINDOW_H
