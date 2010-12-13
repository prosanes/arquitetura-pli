#include "cena.h"

Cena::Cena(QWidget *parent) :
    QWidget(parent)
{

    // UC
    quadrilateros.append(new Quadrilatero(QPointF(930, 320), 300, 300, 3));
    retTexto.append( QRect(QPoint(1030, 300), QPoint(1200, 320)) );
    stringTexto.append( QString("Unidade de Controle"));
    quadrilateros.append(new Quadrilatero(QPointF(1070, 350), 140, 140, 4));
    retTexto.append( QRect(QPoint(1090, 330), QPoint(1210, 350)) );
    stringTexto.append( QString("Memória de Controle"));
    quadrilateros.append(new Quadrilatero(QPointF(990, 370), 60, 30, 4));
    retTexto.append( QRect(QPoint(1000, 350), QPoint(1060, 370)) );
    stringTexto.append( QString("REnd UC"));
    quadrilateros.append(new Quadrilatero(QPointF(950, 430), 80, 80, 4));
    retTexto.append( QRect(QPoint(960, 445), QPoint(1005, 505)) );
    stringTexto.append( QString("Gerador de Endereço"));
    quadrilateros.append(new Quadrilatero(QPointF(1010, 530), 60, 20, 4));
    retTexto.append( QRect(QPoint(1030, 550), QPoint(1050, 570)) );
    stringTexto.append( QString("End"));
    quadrilateros.append(new Quadrilatero(QPointF(1070, 530), 150, 20, 4));
    retTexto.append( QRect(QPoint(1110, 550), QPoint(1155, 570)) );
    stringTexto.append( QString("Controle"));
    retTexto.append( QRect(QPoint(1075, 510), QPoint(1195, 530)) );
    stringTexto.append( QString("Registro de Controle"));
    quadrilateros.append(new Quadrilatero(QPointF(1070, 570), 150, 20, 4));
    retTexto.append( QRect(QPoint(1100, 575), QPoint(1220, 590)) );
    stringTexto.append( QString("Circuitos de Controle"));
    retTexto.append( QRect(QPoint(1100, 605), QPoint(1110, 615)) );
    stringTexto.append( QString("a"));
    retTexto.append( QRect(QPoint(1120, 605), QPoint(1130, 615)) );
    stringTexto.append( QString("b"));
    retTexto.append( QRect(QPoint(1140, 605), QPoint(1150, 615)) );
    stringTexto.append( QString("c"));
    retTexto.append( QRect(QPoint(1160, 605), QPoint(1170, 615)) );
    stringTexto.append( QString("d"));
    retTexto.append( QRect(QPoint(1180, 605), QPoint(1190, 615)) );
    stringTexto.append( QString("..."));
    retTexto.append( QRect(QPoint(1200, 605), QPoint(1210, 615)) );
    stringTexto.append( QString("w"));

    // Memória
    quadrilateros.append(new Quadrilatero(QPointF(50, 350), 200, 250, 2));
    retTexto.append( QRect(QPoint(125, 470), QPoint(200, 500)) );
    stringTexto.append( QString("Memória"));

    // ULA
    retTexto.append( QRect(QPoint(570, 460), QPoint(600, 490)) );
    stringTexto.append( QString("ULA"));
    retTexto.append( QRect(QPoint(495, 405), QPoint(510, 425)) );
    stringTexto.append( QString("A"));
    retTexto.append( QRect(QPoint(655, 405), QPoint(670, 425)) );
    stringTexto.append( QString("B"));

    // MUX
    /* MUX */
        quadrilateros.append(new Quadrilatero(QPointF(80, 70), QPointF(230, 70), QPointF(205, 120), QPointF(105, 120), 0));
        retTexto.append( QRect(QPoint(130, 120), QPoint(150, 140)) );
        stringTexto.append( QString("MUX"));
    /* MUX A */
        quadrilateros.append(new Quadrilatero(QPointF(325, 260), QPointF(475, 260), QPointF(450, 310), QPointF(350, 310), 0));
        retTexto.append( QRect(QPoint(375, 310), QPoint(425, 330)) );
        stringTexto.append( QString("MUX A"));
    /* MUX B */
        quadrilateros.append(new Quadrilatero(QPointF(725, 260), QPointF(875, 260), QPointF(850, 310), QPointF(750, 310), 0));
        retTexto.append( QRect(QPoint(775, 310), QPoint(825, 330)) );
        stringTexto.append( QString("MUX B"));

    // Registradores e seus "Retângulos de Texto" (um retângulo que é onde o texto/label vai ficar)
    /* R0 */
        quadrilateros.append(new Quadrilatero(QPointF(300, 80), 60, 30, 1));
        retTexto.append( QRect(QPoint(325, 110), QPoint(350, 130)) );
        stringTexto.append( QString("R0") );
        valorReg.insert(QString("R0"), 0);
        posReg.append( QRect(QPoint(305, 85), QPoint(355, 105)) );
    /* R1 */
        quadrilateros.append(new Quadrilatero(QPointF(380, 80), 60, 30, 1));
        retTexto.append( QRect(QPoint(405, 110), QPoint(430, 130)) );
        stringTexto.append( QString("R1") );
        valorReg.insert(QString("R1"), 0);
        posReg.append( QRect(QPoint(385, 85), QPoint(435, 105)) );
    /* RA */
        quadrilateros.append(new Quadrilatero(QPointF(460, 80), 60, 30, 1));
        retTexto.append( QRect(QPoint(485, 110), QPoint(510, 130)) );
        stringTexto.append( QString("RA") );
        valorReg.insert(QString("RA"), 0);
        posReg.append( QRect(QPoint(465, 85), QPoint(515, 105)) );
    /* R2 */
        quadrilateros.append(new Quadrilatero(QPointF(620, 80), 60, 30, 1));
        retTexto.append( QRect(QPoint(645, 110), QPoint(670, 130)) );
        stringTexto.append( QString("R2") );
        valorReg.insert(QString("R2"), 0);
        posReg.append( QRect(QPoint(625, 85), QPoint(675, 105)) );
    /* R3 */
        quadrilateros.append(new Quadrilatero(QPointF(700, 80), 60, 30, 1));
        retTexto.append( QRect(QPoint(725, 110), QPoint(750, 130)) );
        stringTexto.append( QString("R3"));
        valorReg.insert(QString("R3"), 0);
        posReg.append( QRect(QPoint(705, 85), QPoint(755, 105)) );
    /* R4 */
        quadrilateros.append(new Quadrilatero(QPointF(780, 80), 60, 30, 1));
        retTexto.append( QRect(QPoint(805, 110), QPoint(830, 130)) );
        stringTexto.append( QString("R4"));
        valorReg.insert(QString("R4"), 0);
        posReg.append( QRect(QPoint(785, 85), QPoint(835, 105)) );
    /* RB */
        quadrilateros.append(new Quadrilatero(QPointF(860, 80), 60, 30, 1));
        retTexto.append( QRect(QPoint(885, 110), QPoint(910, 130)) );
        stringTexto.append( QString("RB"));
        valorReg.insert(QString("RB"), 0);
        posReg.append( QRect(QPoint(865, 85), QPoint(915, 105)) );
    /* PC */
        quadrilateros.append(new Quadrilatero(QPointF(960, 80), 60, 30, 1));
        retTexto.append( QRect(QPoint(985, 110), QPoint(1010, 130)) );
        stringTexto.append( QString("PC"));
        valorReg.insert(QString("PC"), 0);
        posReg.append( QRect(QPoint(965, 85), QPoint(1015, 105)) );
    /* RDados */
        quadrilateros.append(new Quadrilatero(QPointF(150, 200), 60, 30, 1));
        retTexto.append( QRect(QPoint(160, 230), QPoint(200, 250)) );
        stringTexto.append( QString("RDados"));
        valorReg.insert(QString("RDados"), 0);
        posReg.append( QRect(QPoint(160, 205), QPoint(200, 225)) );
    /* REnd */
        quadrilateros.append(new Quadrilatero(QPointF(300, 625), 60, 30, 1));
        retTexto.append( QRect(QPoint(310, 655), QPoint(350, 675)) );
        stringTexto.append( QString("REnd"));
        valorReg.insert(QString("REnd"), 0);
        posReg.append( QRect(QPoint(310, 630), QPoint(350, 655)) );
    /* IR */
        quadrilateros.append(new Quadrilatero(QPointF(840, 625), 60, 30, 1));
        retTexto.append( QRect(QPoint(865, 655), QPoint(890, 675)) );
        stringTexto.append( QString("IR"));
        valorReg.insert(QString("IR"), 0);
        posReg.append( QRect(QPoint(845, 630), QPoint(895, 650)) );

    // Fim Registradores


    // Pontos de Controle (posições aleatórias. A Convenção de raio é 5.0)
        circulos.append( new Circulo(QPointF(350, 40), 5.0, 'a') );
        retTexto.append( QRect(QPoint(360, 35), QPoint(370, 50)) );
        stringTexto.append( QString("a"));
        circulos.append( new Circulo(QPointF(430, 40), 5.0, 'b') );
        retTexto.append( QRect(QPoint(440, 35), QPoint(450, 50)) );
        stringTexto.append( QString("b"));
        circulos.append( new Circulo(QPointF(510, 40), 5.0, 'c') );
        retTexto.append( QRect(QPoint(520, 35), QPoint(530, 50)) );
        stringTexto.append( QString("c"));
        circulos.append( new Circulo(QPointF(670, 40), 5.0, 'd') );
        retTexto.append( QRect(QPoint(680, 35), QPoint(690, 50)) );
        stringTexto.append( QString("d"));
        circulos.append( new Circulo(QPointF(750, 40), 5.0, 'e') );
        retTexto.append( QRect(QPoint(760, 35), QPoint(770, 50)) );
        stringTexto.append( QString("e"));
        circulos.append( new Circulo(QPointF(830, 40), 5.0, 'f') );
        retTexto.append( QRect(QPoint(840, 35), QPoint(850, 50)) );
        stringTexto.append( QString("f"));
        circulos.append( new Circulo(QPointF(910, 40), 5.0, 'g') );
        retTexto.append( QRect(QPoint(920, 35), QPoint(930, 50)) );
        stringTexto.append( QString("g"));
        circulos.append( new Circulo(QPointF(1010, 40), 5.0, 'h') );
        retTexto.append( QRect(QPoint(1020, 35), QPoint(1030, 50)) );
        stringTexto.append( QString("h"));
        circulos.append( new Circulo(QPointF(350, 585), 5.0, 'i') );
        retTexto.append( QRect(QPoint(360, 580), QPoint(370, 595)) );
        stringTexto.append( QString("i"));
        circulos.append( new Circulo(QPointF(200, 160), 5.0, 'j') );
        retTexto.append( QRect(QPoint(210, 155), QPoint(220, 170)) );
        stringTexto.append( QString("j"));
        circulos.append( new Circulo(QPointF(890, 585), 5.0, 'k') );
        retTexto.append( QRect(QPoint(900, 580), QPoint(910, 595)) );
        stringTexto.append( QString("k"));
        circulos.append( new Circulo(QPointF(220, 30), 5.0, 'l') );
        retTexto.append( QRect(QPoint(230, 25), QPoint(240, 40)) );
        stringTexto.append( QString("l"));
        circulos.append( new Circulo(QPointF(520, 275), 5.0, 'm') );
        retTexto.append( QRect(QPoint(530, 270), QPoint(540, 285)) );
        stringTexto.append( QString("m"));
        circulos.append( new Circulo(QPointF(520, 295), 5.0, 'n') );
        retTexto.append( QRect(QPoint(530, 290), QPoint(540, 305)) );
        stringTexto.append( QString("n"));
        circulos.append( new Circulo(QPointF(680, 270), 5.0, 'o') );
        retTexto.append( QRect(QPoint(660, 265), QPoint(670, 280)) );
        stringTexto.append( QString("o"));
        circulos.append( new Circulo(QPointF(680, 285), 5.0, 'p') );
        retTexto.append( QRect(QPoint(660, 280), QPoint(670, 295)) );
        stringTexto.append( QString("p"));
        circulos.append( new Circulo(QPointF(680, 300), 5.0, 'q') );
        retTexto.append( QRect(QPoint(660, 295), QPoint(670, 310)) );
        stringTexto.append( QString("q"));
        circulos.append( new Circulo(QPointF(60, 640), 5.0, 'r') );
        retTexto.append( QRect(QPoint(70, 635), QPoint(80, 515)) );
        stringTexto.append( QString("r"));
        circulos.append( new Circulo(QPointF(740, 410), 5.0, 's') );
        retTexto.append( QRect(QPoint(750, 405), QPoint(760, 420)) );
        stringTexto.append( QString("s"));
        circulos.append( new Circulo(QPointF(740, 435), 5.0, 't') );
        retTexto.append( QRect(QPoint(750, 430), QPoint(760, 445)) );
        stringTexto.append( QString("t"));
        circulos.append( new Circulo(QPointF(740, 460), 5.0, 'u') );
        retTexto.append( QRect(QPoint(750, 455), QPoint(760, 470)) );
        stringTexto.append( QString("u"));
        circulos.append( new Circulo(QPointF(740, 485), 5.0, 'v') );
        retTexto.append( QRect(QPoint(750, 480), QPoint(760, 495)) );
        stringTexto.append( QString("v"));
        circulos.append( new Circulo(QPointF(740, 510), 5.0, 'w') );
        retTexto.append( QRect(QPoint(750, 505), QPoint(760, 520)) );
        stringTexto.append( QString("w"));
    // Fim Pontos de Controle

    // Flags
        quadrilateros.append(new Quadrilatero(QPointF(400, 430), 10, 10, 5));
        retTexto.append( QRect(QPoint(370, 430), QPoint(390, 450)) );
        stringTexto.append( QString("Zero"));
        quadrilateros.append(new Quadrilatero(QPointF(400, 460), 10, 10, 5));
        retTexto.append( QRect(QPoint(365, 460), QPoint(390, 480)) );
        stringTexto.append( QString("Carry"));
        quadrilateros.append(new Quadrilatero(QPointF(400, 490), 10, 10, 5));
        retTexto.append( QRect(QPoint(345, 490), QPoint(390, 510)) );
        stringTexto.append( QString("Negativo"));
    // Fim Flags


    // Caminhos
    // Portas Lógicas -> Portas Lógicas
    // R0 -> MUX A
        setas.append( new Seta(QPointF(350, 111), QPointF(350, 260-1-12), true, 0) );
    // R1 -> MUX A
        setas.append( new Seta(QPointF(430, 111), QPointF(430, 150), false, 0) );
        setas.append( new Seta(QPointF(430, 150), QPointF(370, 150), false, 0) );
        setas.append( new Seta(QPointF(370, 150), QPointF(370, 260-1-12), true, 0) );
    // RA -> MUX A
        setas.append( new Seta(QPointF(510, 111), QPointF(510, 170), false, 0) );
        setas.append( new Seta(QPointF(510, 170), QPointF(390, 170), false, 0) );
        setas.append( new Seta(QPointF(390, 170), QPointF(390, 260-1-12), true, 0) );
    // RDados -> MUX A
        setas.append( new Seta(QPointF(211, 215), QPointF(330, 215), false, 0) );
        setas.append( new Seta(QPointF(330, 215), QPointF(330, 260-1-12), true, 0) );
    // RDados -> Memória
        setas.append( new Seta(QPointF(231, 215), QPointF(231, 350-1-12), true, 0) );

    // R2 -> MUX B
        setas.append( new Seta(QPointF(670, 111), QPointF(670, 150), false, 0) );
        setas.append( new Seta(QPointF(670, 150), QPointF(730, 150), false, 0) );
        setas.append( new Seta(QPointF(730, 150), QPointF(730, 260-1-12), true, 0) );
    // R3 -> MUX B
        setas.append( new Seta(QPointF(750, 111), QPointF(750, 260-1-12), true, 0) );
    // R4 -> MUX B
        setas.append( new Seta(QPointF(830, 111), QPointF(830, 150), false, 0) );
        setas.append( new Seta(QPointF(830, 150), QPointF(770, 150), false, 0) );
        setas.append( new Seta(QPointF(770, 150), QPointF(770, 260-1-12), true, 0) );
    // RB -> MUX B
        setas.append( new Seta(QPointF(910, 111), QPointF(910, 170), false, 0) );
        setas.append( new Seta(QPointF(910, 170), QPointF(790, 170), false, 0) );
        setas.append( new Seta(QPointF(790, 170), QPointF(790, 260-1-12), true, 0) );
    // PC -> MUX B
        setas.append( new Seta(QPointF(970, 111), QPointF(970, 190), false, 0) );
        setas.append( new Seta(QPointF(970, 190), QPointF(810, 190), false, 0) );
        setas.append( new Seta(QPointF(810, 190), QPointF(810, 260-1-12), true, 0) );

    // MUX A -> ULA
        setas.append( new Seta(QPointF(420, 311), QPointF(420, 350), false, 0) );
        setas.append( new Seta(QPointF(420, 350), QPointF(450+42, 350), false, 0) );
        setas.append( new Seta(QPointF(450+42, 350), QPointF(450+42, 400-1-12), true, 0) );
    // MUX B -> ULA
        setas.append( new Seta(QPointF(820, 311), QPointF(820, 350), false, 0) );
        setas.append( new Seta(QPointF(820, 350), QPointF(700-42, 350), false, 0) );
        setas.append( new Seta(QPointF(700-42, 350), QPointF(700-42, 400-1-12), true, 0) );

    // Memória -> MUX
        setas.append( new Seta(QPointF(60, 349), QPointF(60, 10), false, 0) );
        setas.append( new Seta(QPointF(60, 10), QPointF(120, 10), false, 0) );
        setas.append( new Seta(QPointF(120, 10), QPointF(120, 70-1-12), true, 0) );

    // ULA -> TUDO!
        setas.append( new Seta(QPointF(575, 525), QPointF(575, 700), false, 0) );

        //Direita
        setas.append( new Seta(QPointF(575, 700), QPointF(1300, 700), false, 0) );
        setas.append( new Seta(QPointF(1300, 700), QPointF(1300, 10), false, 0) );
        setas.append( new Seta(QPointF(1300, 10), QPointF(190, 10), false, 0) );
        // -> IR
        setas.append( new Seta(QPointF(850, 700), QPointF(850, 655+12+1), true, 0) );
        // -> MUX
        setas.append( new Seta(QPointF(190, 10), QPointF(190, 70-1-12), true, 0) );
        // -> PC
        setas.append( new Seta(QPointF(980, 10), QPointF(980, 80-1-12), true, 0) );
        // -> RB
        setas.append( new Seta(QPointF(880, 10), QPointF(880, 80-1-12), true, 0) );
        // -> R4
        setas.append( new Seta(QPointF(800, 10), QPointF(800, 80-1-12), true, 0) );
        // -> R3
        setas.append( new Seta(QPointF(720, 10), QPointF(720, 80-1-12), true, 0) );
        // -> R2
        setas.append( new Seta(QPointF(640, 10), QPointF(640, 80-1-12), true, 0) );
        // -> RA
        setas.append( new Seta(QPointF(480, 10), QPointF(480, 80-1-12), true, 0) );
        // -> R1
        setas.append( new Seta(QPointF(400, 10), QPointF(400, 80-1-12), true, 0) );
        // -> R0
        setas.append( new Seta(QPointF(320, 10), QPointF(320, 80-1-12), true, 0) );

        //Esquerda
        setas.append( new Seta(QPointF(575, 700), QPointF(350, 700), false, 0) );
        // -> REnd
        setas.append( new Seta(QPointF(350, 700), QPointF(350, 655+1+12), true, 0) );



    // Pontos de Controle
    //PC 'a' -> R0
        setas.append( new Seta(QPointF(350, 45), QPointF(350, 80), false, 1) );
    //PC 'b' -> R1
        setas.append( new Seta(QPointF(430, 45), QPointF(430, 80), false, 1) );
    //PC 'c' -> RA
        setas.append( new Seta(QPointF(510, 45), QPointF(510, 80), false, 1) );

    //PC 'd' -> R2
        setas.append( new Seta(QPointF(670, 45), QPointF(670, 80), false, 1) );
    //PC 'e' -> R3
        setas.append( new Seta(QPointF(750, 45), QPointF(750, 80), false, 1) );
    //PC 'f' -> R4
        setas.append( new Seta(QPointF(830, 45), QPointF(830, 80), false, 1) );
    //PC 'g' -> RB
        setas.append( new Seta(QPointF(910, 45), QPointF(910, 80), false, 1) );

    //PC 'h' -> PC
        setas.append( new Seta(QPointF(1010, 45), QPointF(1010, 80), false, 1) );

    //PC 'j' -> RDados
        setas.append( new Seta(QPointF(200, 165), QPointF(200, 200), false, 1) );

    //PC 'i' -> REnd
        setas.append( new Seta(QPointF(350, 590), QPointF(350, 625), false, 1) );

    //PC 'k' -> IR
        setas.append( new Seta(QPointF(890, 590), QPointF(890, 625), false, 1) );

    //PC 'l' -> MUX
        setas.append( new Seta(QPointF(220, 35), QPointF(220, 70), false, 1) );

    //PC 'm' -> MUXA
        setas.append( new Seta(QPointF(515, 275), QPointF(470, 275), false, 1) );
    //PC 'n' -> MUXA
        setas.append( new Seta(QPointF(515, 295), QPointF(460, 295), false, 1) );

    //PC 'o' -> MUXB
        setas.append( new Seta(QPointF(685, 270), QPointF(730, 270), false, 1) );
    //PC 'p' -> MUXB
        setas.append( new Seta(QPointF(685, 285), QPointF(737, 285), false, 1) );
    //PC 'q' -> MUXB
        setas.append( new Seta(QPointF(685, 300), QPointF(745, 300), false, 1) );

    //PC 's' -> ULA
        setas.append( new Seta(QPointF(735, 410), QPointF(700, 410), false, 1) );
    //PC 't' -> ULA
        setas.append( new Seta(QPointF(735, 435), QPointF(685, 435), false, 1) );
    //PC 'u' -> ULA
        setas.append( new Seta(QPointF(735, 460), QPointF(680, 460), false, 1) );
    //PC 'v' -> ULA
        setas.append( new Seta(QPointF(735, 485), QPointF(675, 485), false, 1) );
    //PC 'w' -> ULA
        setas.append( new Seta(QPointF(735, 510), QPointF(670, 510), false, 1) );

    //PC 'r' -> Memória
        setas.append( new Seta(QPointF(60, 635), QPointF(60, 600), false, 1) );


    // Fim Caminhos

    retTexto.append( QRect(QPoint(1080, 360), QPoint(1200, 380)) );
    stringTexto.append( QString("Memoria de Controle"));


    this->setMinimumSize(1800, 1600);

}

void Cena::paintEvent(QPaintEvent *)
{
    QPainter pintor(this);

    // [!] Pintando Quadriláteros (Registradores, Memória, UC, ULA, ...)
    int tam = quadrilateros.size();

    for(int i = 0; i < tam; i++)
    {
        QPointF pontoA = quadrilateros[i]->getPontoA();
        QPointF pontoB = quadrilateros[i]->getPontoB();
        QPointF pontoC = quadrilateros[i]->getPontoC();
        QPointF pontoD = quadrilateros[i]->getPontoD();

        QPointF pontos[] = { pontoA, pontoB, pontoC, pontoD };

        QBrush brush = quadrilateros[i]->getBrush();
        QPen pen = quadrilateros[i]->getPen();

        pintor.setBrush(brush);
        pintor.setPen(pen);

        pintor.drawPolygon(pontos, 4);

        pintor.setBrush(QBrush(Qt::white));
        pintor.setPen(QPen());
    }
    // FIM
    // [X] Pintando Quadriláteros (Registradores, Memória, UC, ULA, ...)


    // [!] Pintando Pontos de Controle
    tam = circulos.size();

    for(int i = 0; i < tam; i++)
    {
        QPointF centro = circulos[i]->getCentro();
        double raio = circulos[i]->getRaio();

        if( circulos[i]->getFlag() )
        {
            pintor.setBrush(Qt::red);
        }

        pintor.drawEllipse(centro, raio, raio);

        pintor.setBrush(Qt::white);
    }
    // FIM
    // [X] Pintando Pontos de Controle

    // [!] Pintando Ligações
    tam = setas.size();

    for(int i = 0; i < tam; i++)
    {
        // indicador = 0 -> Porta Lógica - Porta Lógica
        // indicador = 1 -> Ponto de Controle - Porta Lógica
        // Só muda a grossura da linha
        if( setas[i]->getIndicador() == 0 )
        {
            pintor.setPen(QPen(Qt::black, 3));
        }
        else
        {
            pintor.setPen(QPen(Qt::black, 1));
        }

        QPointF inicial = setas[i]->getInicial();
        QPointF final = setas[i]->getFinal();

        pintor.drawLine(inicial, final);

        if( setas[i]->getTriangulo() )
        {
            QPointF ponto1, ponto2, ponto3;

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

            QPointF pontos[] = { ponto1, ponto2, ponto3 };

            pintor.setBrush(QBrush(Qt::black));
            pintor.drawPolygon(pontos, 3);

            pintor.setBrush(QBrush(Qt::white));
        }
    }
    // FIM
    // [X] Pintando Ligações

    // [!] Pintando ULA
        int largura = 250, altura = 125, espacamento = 30;
        QPointF pontoA = QPointF(450, 400);
        QPointF pontoB = pontoA + QPointF(espacamento, altura);
        QPointF pontoC = pontoB + QPointF(largura-2*espacamento, 0);
        QPointF pontoD = pontoA + QPointF(largura, 0);
        QPointF pontoE = pontoD - QPointF(largura/2 - 3*espacamento/2, 0);
        QPointF pontoF = pontoD - QPointF(largura/2, -3*espacamento/2);
        QPointF pontoG = pontoD - QPointF(largura/2 + 3*espacamento/2, 0);
        QPointF pontos[] = { pontoA, pontoB, pontoC, pontoD, pontoE, pontoF, pontoG };

        pintor.setBrush(QBrush(QColor(205, 150, 205)));
        pintor.setPen(QPen(QColor(139, 102, 139), 3, Qt::SolidLine));

        pintor.drawPolygon(pontos, 7);

        pintor.setBrush(QBrush(Qt::white));
        pintor.setPen(QPen(Qt::black, 1));
    // FIM
    // [X] Pintando ULA

    // [!] Pintando Labels
    tam = retTexto.size();

    for(int i = 0; i < tam; i++)
    {
        pintor.drawText( retTexto[i], stringTexto[i] );
    }
    // FIM
    // [X] Pintando Labels

    // [!] Pintando Valores de Registradores
    int j = 0;
    foreach(int valor, valorReg)
    {
        char *exibir = "0";
        itoa(valor, exibir, 10);

        pintor.drawText(posReg[j], QString(exibir));
        j++;
    }
    // FIM
    // [X] Pintando Valores de Registradores

}

void Cena::mudaPC(char identificador, bool pinta)
{
    int tam = circulos.size();

    for(int i = 0; i < tam; i++)
    {
        if( circulos[i]->getIdentificador() == identificador )
        {
            circulos[i]->setFlag(pinta);
        }
    }

    update();
}

void Cena::mudaValor(QString registrador, int valor)
{
    valorReg.insert(registrador, valor);

    update();
}
