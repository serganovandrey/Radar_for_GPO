#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include "grid_radar.h"
#include "generator.h"
#include <QPainter>
#include <QDebug>
#include <QRubberBand>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(OnTimer()));
    timer->start(100);
}

Widget::~Widget()
{
    delete ui;
}

//=========================================================
//                     ДВИЖЕНИЕ ЦЕЛЕЙ                    ==
//=========================================================

void Widget::OnTimer()
{
    Generator.move_object();
    update();
}

//=========================================================
//                    ГЕНЕРАЦИЯ ЦЕЛЕЙ                    ==
//=========================================================

void Widget::Generat_Object()
{
    Generator.generate_new_object();
}

//=========================================================
//                  ОТОБРАЖЕНИЕ ЦЕЛЕЙ                    ==
//=========================================================

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
//=========================================================
//                    МАСШТАБИРОВАНИЕ                    ==
//=========================================================

void Widget::mousePressEvent(QMouseEvent * event)
{
    x_start = event->x(); y_start = event->y();

    origin = event->pos();

    rubberBand->setGeometry(QRect(origin, QSize()));
    rubberBand->show();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
 {
     rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
 }

void Widget::mouseReleaseEvent(QMouseEvent * event)
{
    x_finish = event->x(); y_finish = event->y();

    rubberBand->hide();

    if (event->button() == Qt::RightButton)
    {
        int center_x, center_y, start_coordinate_x, start_coordinate_y, finish_coordinate_x, finish_coordinate_y, widht_my, height_my;

        QPoint centerr = rect().center();
        center_x = centerr.x(); center_y = centerr.y();
        start_coordinate_x = x_start - center_x; start_coordinate_y = center_y - y_start;
        finish_coordinate_x = x_finish - center_x; finish_coordinate_y = center_y - y_finish;

        widht_my = abs(finish_coordinate_y - start_coordinate_y);
        height_my = abs(finish_coordinate_x - start_coordinate_x);

        if (height()/height_my <= width()/widht_my) scale = height()/height_my;
        else scale = width()/widht_my;

        if (start_coordinate_x <= finish_coordinate_x) new_center_x = widht_my/2 + start_coordinate_x;
        else new_center_x = widht_my/2 + finish_coordinate_x;

        if (start_coordinate_y <= finish_coordinate_y) new_center_y = height_my/2 + start_coordinate_y;
        else new_center_y = height_my/2 + finish_coordinate_y;

        Grid.set_value(scale, new_center_x, new_center_y);
        Generator.set_value(scale, new_center_x, new_center_y);

        //qDebug() << "Scale = " << scale << ", new center X = " << new_center_x <<  ", new center Y = " << new_center_y;
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_Escape)
        {
        Grid.set_value(1, 0, 0);
        Generator.set_value(1, 0, 0);
    }
}
//=========================================================
//                                                       ==
//=========================================================
