#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include "qmediaplayer.h"
#include "QMediaPlaylist"
#include "qvideowidget.h"
#include <Python.h>

#include <string>

namespace Ui {
class VideoWidget;
}

class VideoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWidget(QWidget *parent = 0);
    ~VideoWidget();

private slots:
    void revurl(QString);
    void on_pushButton_clicked();

signals:
    void sendurl(QString);
private:
    Ui::VideoWidget *ui;
    QString fileName;

    QMediaPlayer *player; //语音播放
    QMediaPlaylist *playList; //播放文件列表
    QVideoWidget *videoWidget;//播放控件

};

#endif // VIDEOWIDGET_H
