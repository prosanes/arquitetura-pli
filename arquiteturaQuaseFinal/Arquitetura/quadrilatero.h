#ifndef QUADRILATERO_H
#define QUADRILATERO_H

#include <QWidget>
#include <QPainter>
#include <QPointF>
#include <QPen>
#include <QBrush>
#include <QColor>

class Quadrilatero : public QWidget
{
    Q_OBJECT
public:
    explicit Quadrilatero(QWidget *parent = 0);
    Quadrilatero(QPointF pontoA, QPointF pontoB, QPointF pontoC, QPointF pontoD, int indicador, QWidget *parent = 0);
    Quadrilatero(QPointF pontoA, int largura, int altura, int indicador, QWidget *parent = 0);
    QPointF getPontoA();
    QPointF getPontoB();
    QPointF getPontoC();
    QPointF getPontoD();
    QPen getPen();
    QBrush getBrush();
    bool getFlag();
    void setFlag(bool flag);

private:
    QPointF pontoA, pontoB, pontoC, pontoD;
    QPen pen;
    QBrush brush;
    int indicador;
    bool flag;

protected:
    void paintEvent(QPaintEvent *);
    void setaCoisas(int indicador);

signals:

public slots:

};

#endif // QUADRILATERO_H
