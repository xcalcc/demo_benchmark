SUBDIRS = advance basic misc rules java_poc

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: $(SUBDIRS)

clean:
	cd advance; make clean
	cd basic; make clean
	cd misc; make clean
	cd rules; make clean
