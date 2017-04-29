#include "grid_radar.h"
#include "widget.h"
#include<QPainter>

grid_radar::grid_radar(QWidget *parent) : QWidget(parent)
{

}

void grid_radar::set_value(float scale_setter, int center_x_setter, int center_y_setter)
{
    scl = scale_setter;
    center_x = center_x_setter;
    center_y = center_y_setter;

    center_ellipce_x = 0 - (center_x*scl);
    center_ellipce_y = 0 + (center_y*scl);
}

void grid_radar::draw_grid(QPainter *painter)
{
   painter->setPen(QPen(Qt::white, 1*scl, Qt::SolidLine));
   painter->setRenderHint(QPainter::Antialiasing);
   painter->setBrush(QBrush(QColor("black")));

   for(i=350; i>=50; i=i-50)
   {
   painter->drawEllipse(center_ellipce_x-(i*scl), center_ellipce_y-(i*scl), i*2*scl, i*2*scl);
   }

   painter->drawLine(0*scl-(scl*center_x), -350*scl + (scl*center_y), 0*scl-(scl*center_x), 350*scl + (scl*center_y));
   painter->drawLine(-350*scl -(scl*center_x), 0*scl + (scl*center_y), 350*scl -(scl*center_x), 0*scl + (scl*center_y));

   for(i=15; i>=-335; i=i-50)
   {
       QFont font("Arial", 8*scl);
       painter->setFont(font);
       painter->drawText(5*scl-(scl*center_x),i*scl + (scl*center_y), str.setNum(abs(i-15)));
   }

}

