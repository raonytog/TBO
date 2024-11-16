size = 100000000

compBst:
	clear
	gcc *.c -o bst

runBst:
	make compBst
	./bst $(size)

timeBst:
	make compBst
	time ./bst $(size)

memBst:
	make compBst
	valgrind ./bst $(size)