#ifndef SETA_H
#define SETA_H

#include <QWidget>
#include <QPointF>
#include <QPainter>

class Seta : public QWidget
{
    Q_OBJECT
public:
    explicit Seta(QWidget *parent = 0);
    Seta(QPointF inicial, QPointF final, bool triangulo, int indicador, QWidget *parent = 0);
    int getIndicador();
    QPointF getInicial();
    QPointF getFinal();
    bool getTriangulo();

private:
    QPointF inicial, final;
    QPointF ponto1, ponto2, ponto3;
    bool triangulo;
    int quantidade, indicador;

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:

};

#endif // SETA_H
