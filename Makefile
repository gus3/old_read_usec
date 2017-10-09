INCLUDE=/opt/vc/include
LIBS=/opt/vc/lib
CFLAGS=-O2 -I$(INCLUDE) -L$(LIBS)
TARGET = read_usec
OBJS = main.o read_usec.o

$(TARGET): $(OBJS)
	gcc -o $@ -L$(LIBS) -lbcm_host $^

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $(CFLAGS) $<

clean:
	-rm -fv *.o $(TARGET) cscope*
