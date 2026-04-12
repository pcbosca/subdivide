platform=$(shell uname -s)
UNAME_MACHINE=$(shell uname -m)

ifeq ($(platform),Darwin) # macOS
	ifeq ($(UNAME_MACHINE),arm64)
		HOMEBREW_PREFIX=/opt/homebrew
	else
		HOMEBREW_PREFIX=/usr/local
	endif
else # linux
	HOMEBREW_PREFIX=/home/linuxbrew/.linuxbrew
endif

CC=cc
CFLAGS=-O2 -Wno-deprecated

INCS=-I$(HOMEBREW_PREFIX)/include -I../include
ifeq ($(platform),Darwin) # macOS
GLLIBS=-framework GLUT -framework OpenGL
else
GLLIBS=-lglut -lGL -lGLU
endif
LIBS=-L$(HOMEBREW_PREFIX)/lib $(GLLIBS) -lm

SOURCE=subdivide.c file.c
OBJS=$(SOURCE:.c=.o)
BIN=../bin/subdivide

$(BIN): $(OBJS)
	@echo "Linking $(BIN)"
	$(CC) $(OBJS) $(LIBS) -o $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJS) $(BIN)

# DO NOT DELETE
