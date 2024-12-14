all:
	clear
	gcc -g -Wall *.c -lm -lglut -lGL

runP:
	make all
	./a.out "4" "in/pendulum4.txt" 

runB:
	make all
	./a.out "11" "in/billiards11.txt"

runD:
	make all
	./a.out "200" "in/diffusion200.txt"

clean:
	rm -f *.o a.out pq
