all:
	make comp
	@ bin/prog

comp:
	clear
	@ gcc *.c -o bin/prog

val:
	make comp
	valgrind bin/prog