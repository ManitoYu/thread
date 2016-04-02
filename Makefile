src = $(wildcard *.cpp)
obj = $(patsubst %.cpp, %.o, $(src))
LDFLAGS = -lpthread
CFLAGS = -Wall
target = app
CC = g++

$(target): $(obj)
	$(CC) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf ${target}
