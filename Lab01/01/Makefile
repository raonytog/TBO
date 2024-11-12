size = 100000

# ---------------- INT ----------------
memInt:
	clear
	gcc  tipos/int.c main.c -o prog
	valgrind ./prog $(size)

timeInt:
	clear
	gcc  tipos/int.c main.c -o prog
	./prog $(size)


# ---------------- CHAR ----------------
memChar:
	clear
	gcc  tipos/char.c main.c -o prog
	valgrind ./prog $(size)

timeChar:
	clear
	gcc  tipos/char.c main.c -o prog
	./prog $(size)


# ---------------- BIT ----------------
memBit:
	clear
	gcc tipos/bit.c tipos/bitmap.c main.c -o prog
	valgrind ./prog $(size)

timeBit:
	clear
	gcc tipos/bit.c tipos/bitmap.c main.c -o prog
	./prog $(size)







