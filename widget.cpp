#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include "grid_radar.h"
#include "generator.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer* timer = new QTimer(this);                          //Create Timer
    connect(timer, SIGNAL(timeout()), this, SLOT(OnTimer()));  //Connect signal at timer with our slot
    timer->start(100);                                         //Start Timer
}

Widget::~Widget()
{
    delete ui;
}

void Widget::OnTimer()
{
    Generator.move_object();
    update();
}

void Widget::Generat_Object()
{
    Generator.generate_new_object();
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.translate(rect().center());
    painter.setRenderHint(QPainter::Antialiasing);
    Grid.draw_grid(&painter);


    QPainter painter2(this);
    painter2.translate(rect().center());
    painter2.setRenderHint(QPainter::Antialiasing);
    Generator.show_object(&painter2);

}


