.SUFFIXES : .cc
.SUFFIXES : .c
.SUFFIXES : .cpp

INCDIR =
LIBDIR =

CC = g++

CXXFLAGS = -g

LIBS = -lm

OBJS = main.o guess.o functions.o

TARGET = 2188HW1

$(TARGET): $(OBJS)
        $(CC) -o $@ $(OBJS) $(LIBDIR) $(LIBS)

.cc.o:
        $(CC) -c $(CXXFLAGS) $(INCDIR) $<

.c.o:
        $(CC) -c $(CXXFLAGS) $(INCDIR) $<

.cpp.o:
        $(CC) -c $(CXXFLAGS) $(INCDIR) $<

clean:
        rm -f $(OBJS) $(TARGET) core



