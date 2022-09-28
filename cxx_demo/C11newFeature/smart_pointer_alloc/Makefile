SUBDIRS = ./test_enable_shared_from_this  ./test_pointer_traits ./test_weak_ptr ./test_unique_ptr ./test_shared_ptr
all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: $(SUBDIRS)

clean:
	cd ./test_enable_shared_from_this; make clean
	cd ./test_pointer_traits; make clean
	cd ./test_weak_ptr; make clean
	cd ./test_unique_ptr; make clean
	cd ./test_shared_ptr; make clean
