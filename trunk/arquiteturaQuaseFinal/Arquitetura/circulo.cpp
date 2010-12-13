#include "circulo.h"

Circulo::Circulo(QWidget *parent) :
    QWidget(parent)
{
}

Circulo::Circulo(QPointF centro, double raio, char identificador, QWidget *parent)
{
    this->centro = centro;
    this->raio = raio;
    this->identificador = identificador;
    this->flag = false;
}

void Circulo::paintEvent(QPaintEvent *)
{
    QPainter pintor(this);

    if(flag)
    {
        pintor.setBrush(QBrush(Qt::red));
    }
    else
    {
        pintor.setBrush(QBrush(Qt::white));
    }

    pintor.drawEllipse(centro, raio, raio);
}

void Circulo::setFlag(bool flag)
{
    this->flag = flag;
    update();
}

bool Circulo::getFlag()
{
    return flag;
}

QPointF Circulo::getCentro()
{
    return centro;
}

double Circulo::getRaio()
{
    return raio;
}

char Circulo::getIdentificador()
{
    return identificador;
}
