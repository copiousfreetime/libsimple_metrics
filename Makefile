PREFIX = /usr/local
DOTSO  = dylib
SOLIB  = libsimple_metrics.$(DOTSO)

CC      = gcc
LDFLAGS = -lsimple_metrics -L.
CPPFLAGS= -I.

#SHLD  = gcc -dynamiclib -single_module -undefined dynamic_lookup -install_name 

default: demo $(SOLIB)

%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean: 
	rm -fv *.o *.$(DOTSO)
	rm -fv demo
	rm -f *~

$(SOLIB): simple_metrics.o
	$(CC) -dynamiclib -single_module -undefined dynamic_lookup -install_name $@ -o $@ $^

demo: $(SOLIB) test_sm.o
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

install: $(SOLIB) simple_metrics.h
	install -d -v -m 0755 $(PREFIX)/lib
	install -d -v -m 0755 $(PREFIX)/include
	install -v -m 0644 simple_metrics.h $(PREFIX)/include
	install -v -m 0644 $(SOLIB) $(PREFIX)/lib
