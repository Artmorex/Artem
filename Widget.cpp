#include <Widget.h>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(800,500);
    setWindowTitle("SnakeGame");
}

void Widget::run()
{
    QWidget::show();

    text->start(400);
    timer->start(18);
    fps->start(5);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(ProgressBar()));
    QObject::connect(text, SIGNAL(timeout()), this, SLOT(Text()));
    QObject::connect(fps, SIGNAL(timeout()), this, SLOT(update()));
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    paint.setRenderHint(QPainter::Antialiasing, true);
    //Малюємо фон, назву, зміюку по центру
    paint.drawPixmap(0, 0, 800, 500, Background);
    paint.drawPixmap(60, 170, 650, 150, Snake); //x, y, width, height
    paint.drawPixmap(260, 20, 280, 68, Title);
    //Малюємо смужку завантаження
    Loading(paint);
    //Малюємо "LOADING"
    paint.setPen(QColor(Qt::black));
    paint.setFont(QFont("Helvetica [Cronyx]",20,QFont::Bold,true));
    paint.drawText(text_x, 410, LOADING); // 340 420
}

void Widget::Loading(QPainter &paint)
{
    paint.setPen(QPen(Qt::black,5));
    paint.setRenderHint(QPainter::Antialiasing, true);
    paint.drawPixmap(250, 430, width, 40, Progressbar);
    paint.drawRect(250, 430, 300, 40);
}

void Widget::ProgressBar()
{
    width++;
    if(width > 300)
    {
        timer->stop();
        text->stop();
        text_x = 312;
        LOADING = stage_3;
    }
}

void Widget::Text()
{
    if(counter == 2){LOADING = stage_1; counter = 0;}
    if(counter == 1)LOADING = stage_2;
    counter++;
}


Widget::~Widget()
{
}
