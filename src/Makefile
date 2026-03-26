platform=$(shell uname -s)
UNAME_MACHINE=$(shell uname -m)

ifeq ($(platform),Darwin)
# macOS
	ifeq ($(UNAME_MACHINE),arm64)
		HOMEBREW_PREFIX=/opt/homebrew
	else
		HOMEBREW_PREFIX=/usr/local
	endif
else
# linux
	HOMEBREW_PREFIX=/home/linuxbrew/.linuxbrew
endif

CFLAGS=-O2 -Wno-deprecated
CC=cc

INCS=-I$(HOMEBREW_PREFIX)/include -I../include
ifeq ($(platform),Darwin)
# macOS
GLLIBS=-framework GLUT -framework OpenGL
else
GLLIBS=-lglut -lGL -lGLU
endif
LIBS=-L$(HOMEBREW_PREFIX)/lib ${GLLIBS} -lm
OBJS=subdivide.o file.o
SOURCE=subdivide.c file.c
BIN=../bin/subdivide

$(BIN): $(OBJS)
	@echo "Linking $(BIN)"
	$(CC) $(OBJS) $(LIBS) -o $(BIN)

.c.o:
	$(CC) $(CFLAGS) $(INCS) -c $*.c
clean:
	rm -rf $(OBJS) $(BIN)

# DO NOT DELETE
