  path = "in/nearly_sorted/100Knearly_sorted.txt"
#  path = "in/reverse_sorted/100Kreverse_sorted.txt"
#  path = "in/sorted/10Ksorted.txt"
#  path = "in/unif_rand/100Kunif_rand.txt"

# bubble sort
bub:
	clear
	gcc client.c bubble_sort.c -o bubble
	./bubble $(path)

memBub:
	clear
	gcc client.c bubble_sort.c -o bubble
	valgrind ./bubble $(path)

# insertion sort
ins:
	clear
	gcc client.c insertion_sort.c -o insertion
	./insertion $(path)

memIns:
	clear
	gcc client.c insertion_sort.c -o insertion
	valgrind ./insertion $(path)

# selection sort
sel:
	clear
	gcc client.c selection_sort.c -o selection
	./selection $(path)

memSel:
	clear
	gcc client.c selection_sort.c -o selection
	valgrind ./selection $(path)


# shaker sort
sha:
	clear
	gcc client.c shaker_sort.c -o shaker
	./shaker $(path)

memSha:
	clear
	gcc client.c shaker_sort.c -o shaker
	valgrind ./shaker $(path)

# clean
clean:
	clear
	rm -f *.o a.out
	rm -f bubble
	rm -f insertion
	rm -f selection
	rm -f shaker
	rm -f prog