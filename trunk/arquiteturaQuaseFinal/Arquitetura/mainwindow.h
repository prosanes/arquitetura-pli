#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QCheckBox>
#include <QGraphicsView>
#include <QPushButton>

#include "quadrilatero.h"
#include "circulo.h"
#include "seta.h"
#include "cena.h"
#include "unidade_controle.h"
#include "memoria.h"
#include "multiplexador.h"
#include "registrador.h"
#include "parser.h"
#include "executa.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    MainWindow(char *endereco, QWidget *parent = 0);
    ~MainWindow();

private:
    Quadrilatero *quad;
    Circulo *circulo;
    Seta *seta;
    QGraphicsView *view;
    QCheckBox *flagCheck;
    QPushButton *proxInst, *proxMicro, *diretoBotao;
    QScrollArea *scroll;
    Cena *cena;
    int quantidade;

    Unidade_Controle UC;
    Memoria memoria;
    ULA ula;
    Multiplexador mux, muxA, muxB;
    Registrador RA, RB, R0, R1, R2, R3, R4, PC, Rdados, Rend, IR;

    void inicializa(char *endereco);
    void atualizaValores();

private slots:
    void changeFlag();
    void proximaInstrucao();
    void proximaMicro();
    void diretoSlot();
};

#endif // MAINWINDOW_H
