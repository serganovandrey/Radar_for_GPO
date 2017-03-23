#include "grid_radar.h"
#include<QPainter>

grid_radar::grid_radar(QWidget *parent) : QWidget(parent)
{

}

void grid_radar::draw_grid(QPainter *painter)
{
   painter->setPen(QPen(Qt::white, 1, Qt::SolidLine));
   painter->setRenderHint(QPainter::Antialiasing);
   painter->setBrush(QBrush(QColor("black")));

   painter->drawEllipse(QPoint(), 350, 350);
   painter->drawEllipse(QPoint(), 300, 300);
   painter->drawEllipse(QPoint(), 250, 250);
   painter->drawEllipse(QPoint(), 200, 200);
   painter->drawEllipse(QPoint(), 150, 150);
   painter->drawEllipse(QPoint(), 100, 100);
   painter->drawEllipse(QPoint(), 50, 50);
   painter->drawLine(0, -350, 0, 350);
   painter->drawLine(-350, 0, 350, 0);
   painter->drawText(5,15,"0");
   painter->drawText(5,-35,"50");
   painter->drawText(5,-85,"100");
   painter->drawText(5,-135,"150");
   painter->drawText(5,-185,"200");
   painter->drawText(5,-235,"250");
   painter->drawText(5,-285,"300");
   painter->drawText(5,-335,"350");

}

