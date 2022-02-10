all: teste
teste: main.o funcoes_basicas.o
	gcc -o teste main.o funcoes_basicas.o
main.o: main.c header.h
	gcc -o main.o main.c -c 
funcoes_basicas.o: funcoes_basicas.c header.h
	gcc -o funcoes_basicas.o funcoes_basicas.c -c
clean:
	rm -rf *.o *~ teste