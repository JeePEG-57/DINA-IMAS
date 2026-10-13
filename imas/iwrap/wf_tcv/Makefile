.PHONY: validate test_dina.exe

FC?=gfortran


PACKAGES=
#PACKAGES+=imas-$(FC)
PACKAGES+=al-fortran
#PACKAGES+=libxml-2.0
PACKAGES+=xmllib


F90DEF=-D'GIT_URL="$(GIT_URL)"'
F90DEF+=-D'GIT_COMMIT_ID="$(GIT_COMMIT_ID)"'
F90DEF+=-D'GIT_VERSION="$(GIT_VERSION)"'

F90FLAGS=-fPIC -w
# COMPILER-SPECIFIC FLAGS
ifeq ($(FC), ifort)
  F90FLAGS+=-fpp
  F90FLAGS+=-real-size 64 -assume no2underscores -extend_source
else ifeq ($(FC), gfortran)
  F90FLAGS+=-cpp
  F90FLAGS+=-freal-4-real-8 -fno-second-underscore -ffree-line-length-none
else
  $(error Unsupported Fortran compiler)
endif

DEBUG = -g -O0 -fbacktrace 
ifeq ($(TARGET), DEBUG)
  F90FLAGS += $(DEBUG)
else ifeq ($(TARGET), RELEASE)
  F90FLAGS += -O2 -g -march=native -funroll-loops -fno-inline -fbacktrace
endif

F90FLAGS+=`pkg-config $(PACKAGES) --cflags`
F90FLAGS+=$(F90DEF)

LDFLAGS=`pkg-config $(PACKAGES) --libs` -mcmodel=large -Wl,--no-relax

F90INC+=-I../dina_green
F90INC+=-I../dina_imas
F90INC+=-I../tcv_controller


DINA_LIBS =  ../dina_imas/dina_imas.a ../dina_green/dina_green.a\
	      	 ../tcv_controller/tcv_controller.a
MATLAB_LIB = ../tcv_controller/codegen_dina/hybctrl_step_IDS.a
		 
all: dina_wf.exe

dina_wf.exe: dina_wf.o $(DINA_LIBS)
	@echo "   * $^ -> $@"
	$(FC) -o $@ $^ $(MATLAB_LIB) $(LDFLAGS)

%.o: %.f90
	@echo "   * $^ -> $@"
	$(FC) $(F90FLAGS) $(F90INC) -c -o $@ $^

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

