all: main.obj unidade_controle.obj memoria.obj multiplexador.obj registrador.obj ULA.obj parser.obj command.obj executa.obj
	g++ -o main unidade_controle.o main.o memoria.o registrador.o multiplexador.o ULA.o parser.o command.o executa.o -DDEBUG
	main teste.as

main.obj: main.cpp
	g++ -c main.cpp -DDEBUG

unidade_controle.obj: unidade_controle.cpp unidade_controle.h
	g++ -c unidade_controle.cpp -DDEBUG

memoria.obj: memoria.cpp memoria.h
	g++ -c memoria.cpp -DDEBUG

multiplexador.obj: multiplexador.cpp multiplexador.h
	g++ -c multiplexador.cpp -DDEBUG

registrador.obj: registrador.cpp registrador.h
	g++ -c registrador.cpp -DDEBUG

ULA.obj: ULA.cpp ULA.h
	g++ -c ULA.cpp -DDEBUG

parser.obj: parser.cpp parser.h
	g++ -c parser.cpp -DDEBUG

command.obj: command.cpp command.h
	g++ -c command.cpp -DDEBUG

executa.obj: executa.cpp executa.h
	g++ -c executa.cpp -DDEBUG
