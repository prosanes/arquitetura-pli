#ifndef CIRCULO_H
#define CIRCULO_H

#include <QWidget>
#include <QPointF>
#include <QPainter>

class Circulo : public QWidget
{
    Q_OBJECT
public:
    explicit Circulo(QWidget *parent = 0);
    Circulo(QPointF centro, double raio, char identificador, QWidget *parent = 0);
    void setFlag(bool flag);
    bool getFlag();
    QPointF getCentro();
    double getRaio();
    char getIdentificador();

private:
    QPointF centro;
    double raio;
    bool flag;
    char identificador;

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:

};

#endif // CIRCULO_H
