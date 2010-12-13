#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
{

}

MainWindow::MainWindow(char *endereco, QWidget *parent)
    : QMainWindow(parent)
{
    inicializa(endereco);

    quantidade = 0;

    QVBoxLayout *layout = new QVBoxLayout;

    // Botões
    proxInst = new QPushButton( QString("Próxima &Instrução") );
    connect(proxInst, SIGNAL(clicked()), this, SLOT(proximaInstrucao()));
    layout->addWidget(proxInst);

    proxMicro = new QPushButton( QString("Próxima &Micro") );
    connect(proxMicro, SIGNAL(clicked()), this, SLOT(proximaMicro()));
    layout->addWidget(proxMicro);

    diretoBotao = new QPushButton( QString("&Execução Direta") );
    connect(diretoBotao, SIGNAL(clicked()), this, SLOT(diretoSlot()));
    layout->addWidget(diretoBotao);
    // Fim Botões

    cena = new Cena();
    scroll = new QScrollArea;
    scroll->setWidget(cena);

    layout->addWidget(scroll);


    QWidget *widget = new QWidget;

    widget->setLayout(layout);

    setCentralWidget(widget);

    this->setGeometry(5, 25, 1200, 600);
}

void MainWindow::changeFlag()
{
    circulo->setFlag(flagCheck->isChecked());
}

void MainWindow::proximaInstrucao()
{
    next_inst(UC, memoria, ula, mux, muxA, muxB, RA, RB, R0, R1, R2, R3, R4, PC, Rdados, Rend, IR);

    atualizaValores();
}

void MainWindow::proximaMicro()
{
    next_micro(UC, memoria, ula, mux, muxA, muxB, RA, RB, R0, R1, R2, R3, R4, PC, Rdados, Rend, IR);

    atualizaValores();
}

void MainWindow::diretoSlot()
{
    direto(UC, memoria, ula, mux, muxA, muxB, RA, RB, R0, R1, R2, R3, R4, PC, Rdados, Rend, IR);

    atualizaValores();
}

void MainWindow::inicializa(char *endereco)
{
    UC = Unidade_Controle(0);

    //Carrega programa
    Parser parser(&memoria, endereco);
    parser.parse();

    for (int i = 0; i < 60; i++) printf ("%d: %d\n", i, memoria.acesso(false, i, 0));
    PC.sinal(1);
    PC = 0;
    PC.sinal(0);

    UC.start(ula.get_flags());


    // fim do init doido
}

void MainWindow::atualizaValores()
{
    cena->mudaValor(QString("RA"), RA.get());
    cena->mudaValor(QString("RB"), RB.get());
    cena->mudaValor(QString("R0"), R0.get());
    cena->mudaValor(QString("R1"), R1.get());
    cena->mudaValor(QString("R2"), R2.get());
    cena->mudaValor(QString("R3"), R3.get());
    cena->mudaValor(QString("R4"), R4.get());
    cena->mudaValor(QString("IR"), IR.get());
    cena->mudaValor(QString("PC"), PC.get());
    cena->mudaValor(QString("RDados"), Rdados.get());
    cena->mudaValor(QString("REnd"), Rend.get());
}

MainWindow::~MainWindow()
{

}
