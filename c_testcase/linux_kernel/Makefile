SRCS=$(wildcard *.c)
RULE_SRCS=$(wildcard *.cxx)
OBJS=$(patsubst %.c,%.o,$(SRCS))
RULE_OBJS=$(patsubst %.cxx,%.o,$(RULE_SRCS))
VS=$(patsubst %.c,%.v,$(SRCS))
OBJS_DIR=objects
VS_DIR=vs

.SUFFIXES: .c .cxx .o

.PHONY: all clean

all: clean scan

.c.o: 
		@-mkdir -p $(OBJS_DIR)
		xvsa -json -noinline -xfa -o $(OBJS_DIR)/$@ -c $<
.cxx.o:
		@-mkdir -p $(OBJS_DIR)
		xvsa -json -noinline -xfa -o $(OBJS_DIR)/$@ -c $<

scan: $(OBJS) $(RULE_OBJS)
		@-mkdir -p $(VS_DIR)
		cd $(OBJS_DIR);  xvsa -json -noinline -xfa $^; mv *.v ../$(VS_DIR)/. 

clean:
		rm -fr $(OBJS_DIR) $(VS_DIR) 
		rm -f $(RULE_OBJS) $(OBJS) $(VS)
