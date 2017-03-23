#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QtCore>
#include "grid_radar.h"
#include "generator.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    grid_radar Grid;
    generator Generator;

protected:
 void paintEvent(QPaintEvent *event);

public slots:
    void OnTimer();

private slots:
    void Generat_Object();

};

#endif // WIDGET_H
