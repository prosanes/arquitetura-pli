#include "quadrilatero.h"

Quadrilatero::Quadrilatero(QWidget *parent) :
    QWidget(parent)
{
}

Quadrilatero::Quadrilatero(QPointF pontoA, QPointF pontoB, QPointF pontoC, QPointF pontoD, int indicador, QWidget *parent)
{
    this->pontoA = pontoA;
    this->pontoB = pontoB;
    this->pontoC = pontoC;
    this->pontoD = pontoD;
    this->indicador = indicador;

    // indicador = 0 -> MUX
    // indicador = 1 -> Registradores
    // indicador = 2 -> Memória
    // indicador = 3 -> UC
    setaCoisas(indicador);
}

Quadrilatero::Quadrilatero(QPointF pontoA, int largura, int altura, int indicador, QWidget *parent)
{
    this->pontoA = pontoA;
    this->pontoB = pontoA + QPointF(0, altura);
    this->pontoC = pontoB + QPointF(largura, 0);
    this->pontoD = pontoA + QPointF(largura, 0);

    this->indicador = indicador;

    setaCoisas(indicador);
}

void Quadrilatero::setaCoisas(int indicador)
{
    // Aqui a gente seta a cor de preenchimento (Brush) e
    // o estilo de contorno (Pen) de cada tipo de Quadrilátero
    if(indicador == 0)
    {
        brush = QBrush(QColor(255, 165, 79));
        pen = QPen(QColor(238, 118, 33), 3, Qt::SolidLine);
    }
    else if(indicador ==1)
    {
        brush = QBrush(QColor(193, 205, 205));
        pen = QPen(QColor(131, 111, 255), 3, Qt::SolidLine);
    }
    else if(indicador == 2)
    {
        brush = QBrush(QColor(193, 255, 193));
        pen = QPen(QColor(124, 205, 124), 3, Qt::DashLine);
    }
    else if(indicador == 3)
    {
        brush = QBrush(QColor(255, 218, 185));
        pen = QPen(QColor(255, 140, 105), 3, Qt::DashLine);
    }
    else if(indicador == 4)
    {
        brush = QBrush(QColor(255, 255, 255));
        pen = QPen(QColor(255, 140, 105), 3, Qt::SolidLine);
    }
    else
    {
        brush = QBrush(Qt::white);
        pen = QPen(QColor(255, 140, 105), 3, Qt::SolidLine);
    }
}

void Quadrilatero::paintEvent(QPaintEvent *)
{
    QPainter pintor(this);

    QPointF pontos[4] = { pontoA, pontoB, pontoC, pontoD };

    pintor.drawPolygon(pontos, 4);
}

QPointF Quadrilatero::getPontoA()
{
    return pontoA;
}

QPointF Quadrilatero::getPontoB()
{
    return pontoB;
}

QPointF Quadrilatero::getPontoC()
{
    return pontoC;
}

QPointF Quadrilatero::getPontoD()
{
    return pontoD;
}

QBrush Quadrilatero::getBrush()
{
    return brush;
}

QPen Quadrilatero::getPen()
{
    return pen;
}

void Quadrilatero::setFlag(bool flag)
{
    this->flag = flag;
}
bool Quadrilatero::getFlag()
{
    return flag;
}
