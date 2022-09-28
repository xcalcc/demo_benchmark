OBJS = uiv.o npd.o aob.o msf.o dbf.o uaf.o main.o global.o main.o
TARGET = program
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS)
