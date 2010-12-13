#ifndef CENA_H
#define CENA_H

#include <QWidget>

#include <QList>
#include <QPointF>
#include <QPainter>
#include <QRect>
#include <QString>
#include <QMap>

#include <stdlib.h>

#include "circulo.h"
#include "quadrilatero.h"
#include "seta.h"

class Cena : public QWidget
{
    Q_OBJECT
public:
    explicit Cena(QWidget *parent = 0);
    void mudaPC(char identificador, bool pinta);
    void mudaValor(QString registrador, int valor);

private:
    QList<Circulo *> circulos;
    QList<Quadrilatero *> quadrilateros;
    QList<Seta *> setas;
    QList<QRect> retTexto;
    QList<QRect> posReg;
    QList<QString> stringTexto;
    QMap<QString, int> valorReg;

protected:
    void paintEvent(QPaintEvent *);


signals:

public slots:

};

#endif // CENA_H
