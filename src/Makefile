CC = gcc
CFLAGS = -Wall -I../include
OBJDIR = ../obj
BINDIR = ../bin
SOURCES = mystrfunctions.c myfilefunctions.c main.c
OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)
TARGET = $(BINDIR)/client

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
LIBDIR = ../lib
LIBNAME = $(LIBDIR)/libmyutils.a
STATIC_TARGET = $(BINDIR)/client_static

.PHONY: static

static: $(STATIC_TARGET)

$(LIBNAME): $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o
	ar rcs $(LIBNAME) $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o

$(STATIC_TARGET): $(OBJDIR)/main.o $(LIBNAME)
	$(CC) $(OBJDIR)/main.o -L$(LIBDIR) -lmyutils -o $(STATIC_TARGET)
DYNLIBNAME = $(LIBDIR)/libmyutils.so
DYNAMIC_TARGET = $(BINDIR)/client_dynamic

.PHONY: dynamic

dynamic: $(DYNAMIC_TARGET)

$(DYNLIBNAME): mystrfunctions.c myfilefunctions.c
	$(CC) $(CFLAGS) -fPIC -c mystrfunctions.c -o $(OBJDIR)/mystrfunctions.o
	$(CC) $(CFLAGS) -fPIC -c myfilefunctions.c -o $(OBJDIR)/myfilefunctions.o
	$(CC) --shared -o $(DYNLIBNAME) $(OBJDIR)/mystrfunctions.o $(OBJDIR)/myfilefunctions.o

$(DYNAMIC_TARGET): $(OBJDIR)/main.o $(DYNLIBNAME)
	$(CC) $(OBJDIR)/main.o -L$(LIBDIR) -lmyutils -o $(DYNAMIC_TARGET)
