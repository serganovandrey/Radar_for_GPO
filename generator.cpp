#include "generator.h"
#include "ui_widget.h"
#include "widget.h"
#include <QtCore>

generator::generator(QWidget *parent) : QWidget(parent)
{

}

void generator::generate_new_object()
{
  i=0;
  while (i<N)
  {
      vect_az.push_back(rand()%359+0);
      vect_range.push_back(rand()%349+0);
      vect_type.push_back(rand()%4+1);
      vect_speed.push_back(rand()%3+1);
      vect_direction.push_back(rand()%4+1);

      vect_X.push_back(0 + (vect_range[i] * sin(vect_az[i] * 3.14 / 180)));
      vect_Y.push_back(0 - (vect_range[i] * cos(vect_az[i] * 3.14 / 180)));

      i=i+1;
  }

}

void generator::show_object(QPainter *painter)
{
    if (vect_X.isEmpty()) return;

    i=0;
    while (i<N)
    {
        if (vect_type[i]==1) painter->setPen(QPen(Qt::red, 4, Qt::SolidLine));
        if (vect_type[i]==2) painter->setPen(QPen(Qt::blue, 4, Qt::SolidLine));
        if (vect_type[i]==3) painter->setPen(QPen(Qt::yellow, 4, Qt::SolidLine));
        if (vect_type[i]==4) painter->setPen(QPen(Qt::green, 4, Qt::SolidLine));

        painter->drawPoint(vect_X[i], vect_Y[i]);
        i=i+1;
    }

}

void generator::move_object()
{
    i=0;
    while (i<N)
    {
        if (vect_direction[i]==1 && (vect_X[i]*vect_X[i])+(vect_Y[i]*vect_Y[i]) >= 348*348) vect_direction[i]=3;
        else if (vect_direction[i]==2 && (vect_X[i]*vect_X[i])+(vect_Y[i]*vect_Y[i]) >= 348*348) vect_direction[i]=4;
        else if (vect_direction[i]==3 && (vect_X[i]*vect_X[i])+(vect_Y[i]*vect_Y[i]) >= 348*348) vect_direction[i]=1;
        else if (vect_direction[i]==4 && (vect_X[i]*vect_X[i])+(vect_Y[i]*vect_Y[i]) >= 348*348) vect_direction[i]=2;

        if (vect_direction[i]==1)
        {
            vect_X[i]=vect_X[i]+vect_speed[i];
            vect_Y[i]=vect_Y[i]+vect_speed[i];

        }

        if (vect_direction[i]==2)
        {
            vect_X[i]=vect_X[i]+vect_speed[i];
            vect_Y[i]=vect_Y[i]-vect_speed[i];
        }

        if (vect_direction[i]==3)
        {
            vect_X[i]=vect_X[i]-vect_speed[i];
            vect_Y[i]=vect_Y[i]-vect_speed[i];
        }

        if (vect_direction[i]==4)
        {
            vect_X[i]=vect_X[i]-vect_speed[i];
            vect_Y[i]=vect_Y[i]+vect_speed[i];
        }
        i=i+1;
    }
}

//Az
//Range
//Type (Hellicopter, Airchart, Ballistic, Drone)
//Speed
//Direction
//ID
