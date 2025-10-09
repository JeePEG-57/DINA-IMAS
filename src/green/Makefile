# Makefile for compilation of DINA components

AR = ar
ARFLAGS = -ru
FC = $(FCOMPILER)

INCDIR=../include

DEBUG = -g -O0


FCFLAGS=-fPIC -w
# COMPILER-SPECIFIC FLAGS
ifeq ($(FCOMPILER), ifort)
  FCFLAGS+=-extend-source -nod-lines -save -init=zero -real-size 64
else ifeq ($(FCOMPILER), gfortran)
  FCFLAGS+=-ffixed-line-length-none -fd-lines-as-comments -fno-automatic -freal-4-real-8
else
  $(error Unsupported Fortran compiler)
endif


FCFLAGS += -I$(INCDIR)
FCFLAGS += $(DEBUG)



DINASRC = green_imas.f pers2.f green_br_N.f params_dat.f svd0m.f pet.f bunema.f svd2.f

DINAOBJ = $(DINASRC:.f=.o)

all: test.exe green.a

test.exe: test.o green.a
	@echo "   * $^ -> $@"
	$(FC) -o $@ $^

green.a: $(DINAOBJ)
	@echo "   * $^ -> $@"
	$(AR) $(ARFLAGS) $@ $(DINAOBJ)

%.o: %.f
	$(FC) $(FCFLAGS) -c $<

clean:
	-rm -f *.o
	-rm -f *.a
	-rm -f *.exe
