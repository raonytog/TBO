expressao = "(5*(((9+8)*(4*6))+7))"

compStack:
	clear
	gcc *.c -o pilha

timeStack:
	clear
	gcc *.c -o pilha
	time ./pilha $(expressao)

memStack:
	clear
	gcc *.c -o pilha
	valgrind ./pilha $(expressao)