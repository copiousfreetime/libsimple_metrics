SRCS  = simple_metrics.c
OBJS  = simple_metrics.o
DOTSO = dylib
SOLIB = libsimple_metrics.$(DOTSO)
CC    = gcc
SHLD  = gcc -dynamiclib -single_module -undefined dynamic_lookup -install_name $@

all: $(SOLIB)
clean: 
	rm $(OBJS) $(SOLIB)

.c.o:
	$(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) -c $<

$(SOLIB): $(OBJS)
	$(SHLD) -o $(SOLIB) $(OBJS) 

demo: $(OBJS) test_sm.o
	$(CC) -o $@ $(OBJS) test_sm.o 
