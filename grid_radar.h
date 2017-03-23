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

private:

signals:

public slots:
};

#endif // GRID_RADAR_H
