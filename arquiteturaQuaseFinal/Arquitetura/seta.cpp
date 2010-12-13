#include "seta.h"

Seta::Seta(QWidget *parent) :
    QWidget(parent)
{
}

Seta::Seta(QPointF inicial, QPointF final, bool triangulo, int indicador, QWidget *parent) :
        QWidget(parent)
{
    this->inicial = inicial;
    this->final = final;

    this->triangulo = triangulo;

    this->quantidade = 1;

    this->indicador = indicador;

    // indicador = 0 -> Porta Lógica - Porta Lógica
    // indicador = 1 -> Ponto de Controle - Porta Lógica
}

QPointF Seta::getInicial()
{
    return inicial;
}

QPointF Seta::getFinal()
{
    return final;
}

int Seta::getIndicador()
{
    return indicador;
}

bool Seta::getTriangulo()
{
    return triangulo;
}

void Seta::paintEvent(QPaintEvent *)
{
    QPainter pintor(this);

    pintor.setPen(QPen(Qt::black, 3));


    pintor.drawLine(inicial, final);


    if(triangulo)
    {

        if( (final.y() > inicial.y()) && (final.x() == inicial.x()) )
        {
            ponto1 = final - QPointF(6.0, 0.0);
            ponto2 = final + QPointF(6.0, 0.0);
            ponto3 = final + QPointF(0.0, 12.0);
        }
        else if( (final.y() < inicial.y()) && (final.x() == inicial.x()) )
        {
            ponto1 = final - QPointF(6.0, 0.0);
            ponto2 = final + QPointF(6.0, 0.0);
            ponto3 = final - QPointF(0.0, 12.0);
        }
        else if( (final.y() == inicial.y()) && (final.x() > inicial.x()) )
        {
            ponto1 = final - QPointF(0.0, 6.0);
            ponto2 = final + QPointF(0.0, 6.0);
            ponto3 = final + QPointF(12.0, 0.0);
        }
        else
        {
            ponto1 = final - QPointF(0.0, 6.0);
            ponto2 = final + QPointF(0.0, 6.0);
            ponto3 = final - QPointF(12.0, 0.0);
        }


        pintor.setBrush(QBrush(Qt::black));
        QPointF pontos[3] = { ponto1, ponto2, ponto3 };
        pintor.drawPolygon(pontos, 3);
    }

}
