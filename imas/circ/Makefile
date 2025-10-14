PACKAGES=
#PACKAGES+=imas-$(FCOMPILER)
PACKAGES+=al-fortran
#PACKAGES+=libxml-2.0
PACKAGES+=xmllib

F90LIB=
F90INC=

F90DEF=-D'GIT_URL="$(GIT_URL)"'
F90DEF+=-D'GIT_COMMIT_ID="$(GIT_COMMIT_ID)"'
F90DEF+=-D'GIT_VERSION="$(GIT_VERSION)"'

F90FLAGS=-fPIC -w
# COMPILER-SPECIFIC FLAGS
ifeq ($(FCOMPILER), ifort)
  F90FLAGS+=-fpp
  F90FLAGS+=-real-size 64 -assume no2underscores -extend_source
else ifeq ($(FCOMPILER), gfortran)
  F90FLAGS+=-cpp
  F90FLAGS+=-freal-4-real-8 -fno-second-underscore -ffree-line-length-none
else
  $(error Unsupported Fortran compiler)
endif

DEBUG = -g -O0
ifeq ($(TARGET), DEBUG)
  F90FLAGS += $(DEBUG)
endif

F90FLAGS+=$(F90DEF)

F90=$(FCOMPILER)

# FLAGS OF PACKAGES
F90LIB+=`pkg-config $(PACKAGES) --libs`
F90INC+=`pkg-config $(PACKAGES) --cflags`


F90FLAGS+=$(F90INC)


TARGETS += dina_imas_circ.a test_dina test_circ

DINADIR := ../../src/scenario/


LIB_SOURCE1 += dina_circ.a dina_imas_circ.o n_dina_imas3.o test_dina_imas.o



all: $(TARGETS)

#--------------------- gfortran ------------------------
test_dina: test_dina_imas.o dina_imas_circ.a ../interface/kmc.a
	@echo "   * $^ -> $@"
	$(F90) -o $@ $^ $(F90LIB)

test_circ: test_dina_circ.o dina_imas_circ.a
	@echo "   * $^ -> $@"
	$(F90) -o $@ $^ $(F90LIB)

%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90) $(F90FLAGS) -c -o $@ $^

dina_imas_circ.o: dina_imas_circ.f90
	@echo "   * $^ -> $@"
	$(F90) $(F90FLAGS) -c -o $@ $^

n_dina_imas3.o: n_dina_imas3.f 
	$(F90) $(F90FLAGS) -c n_dina_imas3.f

dina_imas_circ.a: $(LIB_SOURCE1)
	@echo "   * $^ -> $@"
	@cp dina_circ.a dina_imas_circ.a
	ar -rcs dina_imas_circ.a n_dina_imas3.o dina_imas_circ.o

dina_circ.a:
	make -f Makefile_circ

clean:
	rm -f *.o
	rm -f *.a
	rm -f test_circ
	rm -f test_dina
	make -f Makefile_circ clean
