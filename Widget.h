#ifndef WIDGET_H
#define WIDGET_H

#include <QTimer>
#include <QWidget>
#include <QPixmap>
#include <QPainter>

class Widget : public QWidget
{
    Q_OBJECT

public :
    Widget(QWidget *parent = 0);
    ~Widget();
    void run();
    void paintEvent(QPaintEvent *);
    //void LoadingBar(QPainter &paint);
    void Loading(QPainter &paint);

public slots :
    void ProgressBar();
    void Text();

private :
    int width = 0;
    int counter = 1;
    int text_x = 330;

    QTimer* timer = new QTimer;
    QTimer* text = new QTimer;
    QTimer* fps = new QTimer;

    QPixmap Background{":/LoadingWindow/Background.jpg"};
    QPixmap Progressbar{":/LoadingWindow/progressbar.gif"};
    QPixmap Title{":/LoadingWindow/SNAKE_TITLE.png"};
    QPixmap Snake{":/LoadingWindow/Snake.png"};

    QString stage_1{"LOADING"};
    QString stage_2{""};
    QString stage_3{"COMPLETED"};
    QString LOADING = stage_1;

};

#endif // WIDGET_H
