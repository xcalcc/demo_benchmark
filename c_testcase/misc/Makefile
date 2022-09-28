OBJS=clang-false-positive.o
TARGET = misc.a 

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) crv $@ $^

clean:
	rm -f $(TARGET) $(OBJS)
