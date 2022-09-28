OBJS = c_env33.o c_msc32.o c_pos34.o c_sig30.o c_env32.o c_err33.o c_pos30.o c_pos54.o c_str31.o

TARGET = program

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS) a.out xvsa-xfa-dummy.*
