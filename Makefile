#OBJS		= v02.cpp
#OBJ_NAME	= v02.exe

CC			= /bin/x86_64-w64-mingw32-gcc
CFLAGS		= -Wall -O2 -s 

CPP			= /bin/x86_64-w64-mingw32-g++
CPPFLAGS	= -Wall -O2 -s 
LIB			= -lvulkan-1 -lglfw3 -lopengl32 -lm

GLLIB		= -lfreeglut -lglu32 -lglfw3 -lopengl32 -lglew32

all: gl01 gl02 gl03
	

gl01: gl01.c
	$(CC)  gl01.c $(GLLIB) -Wall -O2 -s -lm -mwindows -o gl01.exe


gl02: gl02.c
	$(CC)  gl02.c $(GLLIB) -Wall -O2 -s -lm -mwindows -o gl02.exe


gl03: gl03.c
	$(CC)  gl03.c $(GLLIB) -Wall -O2 -s -lm -mwindows -o gl03.exe


gl04: gl04.cpp
	$(CPP)  gl04.cpp $(GLLIB) -Wall -O2 -s -lm -mwindows -o gl04.exe


bmp: main.cpp
	$(CPP)  main.cpp $(GLLIB) -Wall -O2 -s -lm -mwindows -o main.exe


#v01: v01.cpp
#	$(CPP) $(OBJS) -lglfw3 -lvulkan-1 -Wall -O2 -s -lm -mwindows -o $(OBJ_NAME)	
	
#triangle: triangle.cpp
#	echo "triangle"
#	$(CPP) triangle.cpp -lvulkan-1 -Wall -O2 -s -lm -mwindows -o triangle.exe

#test:
#	echo "test"
#	touch test
	
#triangle:
#	echo "triangle"
#	touch triangle


clean:
	rm -f *.o *.exe
#	rm test.exe
#	rm triangle.exe

#clean:
#	rm test.o test.exe
#	rm triangle.o triangle.exe

#libstdc++-6.dll

#-static-libstdc++ 

