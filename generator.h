#ifndef GENERATOR_H
#define GENERATOR_H

#include <QWidget>
#include <QtCore>
#include <QPainter>

class generator : public QWidget
{
    Q_OBJECT
public:
    explicit generator(QWidget *parent = 0);
    int N = 50, i;
    void generate_new_object();
    void show_object(QPainter * painter);
    void move_object();

private:
    QVector<int> vect_az;
    QVector<int> vect_range;
    QVector<int> vect_type;
    QVector<int> vect_speed;
    QVector<int> vect_direction;
    QVector<int> vect_X;
    QVector<int> vect_Y;

signals:

public slots:
};

#endif // GENERATOR_H
