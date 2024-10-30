CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: task1 task2 task3 task4

task1: task1.c
	$(CC) $(CFLAGS) -o task1 task1.c

task2: task2.c 
	$(CC) $(CFLAGS) -o task2 task2.c

task3: task3.c
	$(CC) $(CFLAGS) -o task3 task3.c

task4: task4.c
	$(CC) $(CFLAGS) -o task4 task4.c

run_task1: task1
	./task1

run_task2: task2
	./task2

run_task3: task3
	./task3

run_task4: task4
	./task4

run: run_task1 run_task2 run_task3 run_task4
