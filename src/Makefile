platform=$(shell uname -s)

GLUT_LIB_LOCATION=/usr/local/lib
GLUT_INC_LOCATION=/usr/local/include

CFLAGS=-O2 -Wno-unused-value -Wno-deprecated
CC=cc

INCS=-I${GLUT_INC_LOCATION} -I../include
ifeq ($(platform),Darwin)
# OSX
GLLIBS=-L${GLUT_LIB_LOCATION} -framework GLUT -framework OpenGL
else
GLLIBS=-L${GLUT_LIB_LOCATION} -lglut -lGL -lGLU
endif
LIBS=${GLLIBS} -lm
OBJS=subdivide.o file.o
SOURCE=subdivide.c file.c
BIN=../bin/subdivide

$(BIN): $(OBJS)
	@echo "Linking $(BIN)"
	$(CC) $(OBJS) $(LIBS) -o $(BIN)

.c.o:
	$(CC) $(CFLAGS) $(INCS) -c $*.c
clean:
	rm -rf *.o $(BIN)

# DO NOT DELETE
