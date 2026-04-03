CC = gcc
CFLAGS = -Wall -pthread

all: createThreads sequential parallel1 parallel2 parallel3

sequential: sequential.c
	$(CC) $(CFLAGS) -o sequential sequential.c

createThreads: createThreads.c
	$(CC) $(CFLAGS) -o createThreads createThreads.c

parallel1: parallel1.c
	$(CC) $(CFLAGS) -o parallel1 parallel1.c

parallel2: parallel2.c
	$(CC) $(CFLAGS) -o parallel2 parallel2.c

parallel3: parallel3.c
	$(CC) $(CFLAGS) -o parallel3 parallel3.c

clean:
	rm -f createThreads sequential parallel1 parallel2 parallel3
