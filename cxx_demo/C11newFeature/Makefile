SUBDIRS = ./lambda/Src/EXP61-CPP_lambda ./nullptr_constexpr/Src ./template/Src/templ_fun3  ./template/Src/templ_fun2  ./template/Src/templ_spec1 ./template/Src/templ_parm1 ./template/Src/templ_fun1 ./template/Src/templ_class1 ./lambda/Src/decl_lambda1 ./lambda/Src/nest_lambda1 ./lambda/Src/call_lambda1 ./lambda/Src/decl_lambda3 ./lambda/Src/decl_lambda2 ./decl_type/Src/decl_type ./decl_type/Src/decl_type1 ./objectSensitive/Src ./FileIO ./foreach
all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: $(SUBDIRS)

clean:
	cd ./lambda/Src/EXP61-CPP_lambda; make clean
	cd ./template/Src/templ_fun3; make clean
	cd ./template/Src/templ_fun2; make clean
	cd ./template/Src/templ_spec1; make clean
	cd ./template/Src/templ_parm1; make clean
	cd ./template/Src/templ_fun1; make clean
	cd ./template/Src/templ_class1; make clean
	cd ./lambda/Src/decl_lambda1; make clean
	cd ./lambda/Src/nest_lambda1; make clean
	cd ./lambda/Src/call_lambda1; make clean
	cd ./lambda/Src/decl_lambda3; make clean
	cd ./lambda/Src/decl_lambda2; make clean
	cd ./decl_type/Src/decl_type; make clean
	cd ./decl_type/Src/decl_type1; make clean
	cd ./nullptr_constexpr/Src; make clean
	cd ./objectSensitive/Src; make clean
	cd ./FileIO; make clean
	cd ./foreach; make clean
