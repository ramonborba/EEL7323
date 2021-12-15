
CC=g++

SRCDIR=src
OBJDIR=obj
OUTDIR=out


default: $(OUTDIR)/main

$(OUTDIR)/main: $(OBJDIR)/main.o
	$(CC) -o $(OUTDIR)/main $(OBJDIR)/main.o

$(OBJDIR)/main.o: src/main.cpp
	$(CC) -o $(OBJDIR)/main.o -c $(SRCDIR)/main.cpp

clean:
	rm $(OBJDIR)/* $(OUTDIR)/*