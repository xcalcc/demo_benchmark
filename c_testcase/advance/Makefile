OBJS = uiv.o npd.o aob.o msf.o dbf.o uaf.o main.o global.o asm_uiv_npd.o wp_eg_npd_ctx.o wp_eg_npd.o wp_eg_obj_sensitive.o xplatform_32_64.o main.o
TARGET = program
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS)
