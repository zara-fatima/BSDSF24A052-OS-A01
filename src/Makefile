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
