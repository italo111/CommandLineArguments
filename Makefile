all: minicalc
minicalc: activity.o
	gcc activity.o -o minicalc
activity.o: activity.c
	gcc -c activity.c -o activity.o
clean:
	rm -f minicalc activity.o core *~

