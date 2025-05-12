.PHONY: validate test_dina.exe

FCOMPILER?=gfortran
DEBUG=-g -O0

PACKAGES=
#PACKAGES+=imas-$(FCOMPILER)
PACKAGES+=al-fortran
#PACKAGES+=libxml-2.0
PACKAGES+=xmllib

F90=$(FCOMPILER)

# COMPILER-SPECIFIC FLAGS
ifeq ($(FCOMPILER), ifort)
  F90FLAGS=-fPIC -fpp -g
else ifeq ($(FCOMPILER), gfortran)
  F90FLAGS=-fPIC -cpp
else
  $(error Unsupported Fortran compiler)
endif


F90FLAGS+=-w -freal-4-real-8 -fno-second-underscore -ffree-line-length-none
F90FLAGS+=$(DEBUG)
F90FLAGS+=`pkg-config $(PACKAGES) --cflags`

LDFLAGS=`pkg-config $(PACKAGES) --libs` -mcmodel=large -Wl,--no-relax

F90INC+=-I../dina_green
F90INC+=-I../dina_imas
F90INC+=-I../kmc


DINA_LIBS =  ../dina_imas/dina_imas.a ../kmc/kav_mag_contr.a \
	     ../dina_green/dina_green.a
		 
all: dina_wf.exe

dina_wf.exe: dina_wf.o $(DINA_LIBS)
	@echo "   * $^ -> $@"
	$(F90) -o $@ $^ $(LDFLAGS)

%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90) $(F90FLAGS) $(F90INC) -c -o $@ $^

validate: ## Test the consistency of the XML and XSD files for input parameters
	xmllint --noout wfconfig.xsd wfconfig.xml
	xmllint --noout --schema wfconfig.xsd wfconfig.xml

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.exe

help :
	@grep -Eh '^[a-zA-Z0-9_%\./-]+[ ]*:.*?## .*$$' $(MAKEFILE_LIST) |sort|awk \
	'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

