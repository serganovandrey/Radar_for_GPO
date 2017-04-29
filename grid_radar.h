#ifndef GRID_RADAR_H
#define GRID_RADAR_H

#include <QWidget>
#include<QPainter>

class grid_radar : public QWidget
{
    Q_OBJECT
public:
    explicit grid_radar(QWidget *parent = 0);
    void draw_grid(QPainter * painter);
    float scl=1;
    int center_x=0, center_y=0, center_ellipce_x=0, center_ellipce_y=0, i;
    QString str;
    void set_value(float scale_setter, int center_x_setter, int center_y_setter);

private:

signals:

public slots:
};

#endif // GRID_RADAR_H
