SUBDIRS = advance basic misc rules crossFuncFile ./sensitive/Src/DataCtlContext/ ./sensitive/Src/EnvSensitive/ 

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: $(SUBDIRS)

clean:
	cd advance; make clean
	cd basic; make clean
	cd misc; make clean
	cd rules; make clean
	cd crossFuncFile; make clean
	cd ./sensitive/Src/DataCtlContext; make clean
	cd ./sensitive/Src/EnvSensitive; make clean
