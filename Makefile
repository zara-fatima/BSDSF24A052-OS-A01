# Macros
SUBDIR = src

.PHONY: all clean

all:
	$(MAKE) -C $(SUBDIR)

clean:
	$(MAKE) -C $(SUBDIR) clean
	rm -f bin/client
