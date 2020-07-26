# Makefile for hw4, EECS22 Fall 2017 fall 
# Author: Huan Chen
# Modified by: Mason Harlan
# Modification: Ali Nickparsa 11/11/2018
# Date:   11/01/2017
CC     = gcc
DEBUG  = -g -DDEBUG
CFLAGS = -ansi -std=c99 -Wall -c
LFLAGS = -ansi -std=c99 -Wall

OBJS = MovieLab.o FileIO.o Image.o Movie.o MovieIO.o IterativeFilter.o ImageList.o
DEBUG_OBJS = MovieLab_DEBUG.o FileIO_DEBUG.o Image_DEBUG.o Test_DEBUG.o
DEPS = IterativeFilter.h Image.h FileIO.h DIPs.h ImageList.h Movie.h MovieIO.h

DESIGN = MovieLab #MovieLabTest
all: $(DESIGN)
MovieLab: $(OBJS) libFilter.a
	$(CC) $(LFLAGS) $(OBJS) -L. -lFilter -o MovieLab -lm 
MovieLabTest: $(DEBUG_OBJS) libFilter.a
	$(CC) $(LFLAGS) $(DEBUG) $(DEBUG_OBJS) -lm -L. -lFilter -o MovieLabTest

libFilter.a: DIPs.o 
	ar rc libFilter.a  DIPs.o
	ranlib libFilter.a

MovieLab.o: MovieLab.c $(DEPS)
	$(CC) $(CFLAGS) MovieLab.c -o MovieLab.o
FileIO.o: FileIO.c $(DEPS)
	$(CC) $(CFLAGS) FileIO.c -o FileIO.o
DIPs.o: DIPs.c $(DEPS)
	$(CC) $(CFLAGS) DIPs.c -o DIPs.o
Image.o: Image.c $(DEPS)
	$(CC) $(CFLAGS) Image.c -o Image.o
Test.o: Test.c Test.h $(DEPS)
	$(CC) $(CFLAGS) Test.c -o Test.o
Movie.o: Movie.c $(DEPS)
	$(CC) $(CFLAGS) Movie.c -o Movie.o
ImageList.o: ImageList.c $(DEPS)
	$(CC) $(CFLAGS) ImageList.c -o ImageList.o
MovieIO.o: MovieIO.c $(DEPS)
	$(CC) $(CFLAGS) MovieIO.c -o MovieIO.o
IterativeFilter.o: IterativeFilter.c $(DEPS)
	$(CC) $(CFLAGS) IterativeFilter.c -o IterativeFilter.o



#MovieLab_DEBUG.o: MovieLab.c $(DEPS)
#	$(CC) $(CFLAGS) $(DEBUG) MovieLab.c -o MovieLab_DEBUG.o
#FileIO_DEBUG.o: FileIO.c FileIO.h Image.h
#	$(CC) $(CFLAGS) $(DEBUG) FileIO.c -o FileIO_DEBUG.o
#DIPs_DEBUG.o: DIPs.c DIPs.h Image.h
#	$(CC) $(CFLAGS) $(DEBUG) DIPs.c -o DIPs_DEBUG.o
#Advanced_DEBUG.o: Advanced.c Advanced.h Image.h
#	$(CC) $(CFLAGS) $(DEBUG) Advanced.c -lm -o Advanced_DEBUG.o
#Image_DEBUG.o: Image.c Image.h
#	$(CC) $(CFLAGS) $(DEBUG) Image.c -o Image_DEBUG.o
#Test_DEBUG.o: Test.c Test.h $(DEPS)
#	$(CC) $(CFLAGS) $(DEBUG) Test.c -o Test_DEBUG.o

clean:
	rm -f *.o *.a $(DESIGN)
	rm -f *.yuv
