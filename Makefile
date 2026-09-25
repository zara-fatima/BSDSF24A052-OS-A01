# Macros
SUBDIR = src

.PHONY: all clean

all:
	$(MAKE) -C $(SUBDIR)

clean:
	$(MAKE) -C $(SUBDIR) clean
	rm -f bin/client
static:
	$(MAKE) -C $(SUBDIR) static
dynamic:
	$(MAKE) -C $(SUBDIR) dynamic
PREFIX = /usr/local

.PHONY: install

install: all
	install -d $(PREFIX)/bin $(PREFIX)/man/man3
	install -m 755 bin/client $(PREFIX)/bin/client
	install -m 644 man/man3/*.3 $(PREFIX)/man/man3/
