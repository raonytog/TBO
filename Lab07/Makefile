abra = "in/abra.txt"
tale = "in/tale.txt"
moby = "in/moby.txt"
teste = "in/teste.txt"

path = $(tale)
context = 15


all:
	make comp
	bin/prog $(path) $(context)

comp:
	clear
	@ gcc *.c -o bin/prog

val:
	make comp
	valgrind bin/prog $(path) $(context)
