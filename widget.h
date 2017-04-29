#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QtCore>
#include "grid_radar.h"
#include "generator.h"
#include <QMouseEvent>
#include <QRubberBand>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    float scale = 1;
    int new_center_x=0, new_center_y=0, x_start=0, y_start=0, x_finish=0, y_finish=0;
    QPoint origin;

private:
    Ui::Widget *ui;
    grid_radar Grid;
    generator Generator;
    QRubberBand* rubberBand = new QRubberBand(QRubberBand::Rectangle, this);

protected:
 void paintEvent(QPaintEvent *event);
 void mousePressEvent(QMouseEvent * event);
 void mouseMoveEvent(QMouseEvent * event);
 void mouseReleaseEvent(QMouseEvent * event);
 void keyPressEvent(QKeyEvent *event);

public slots:
    void OnTimer();

private slots:
    void Generat_Object();

};

#endif // WIDGET_H
