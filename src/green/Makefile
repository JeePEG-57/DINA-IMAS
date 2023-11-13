# Makefile for compilation of DINA components

AR = ar
ARFLAGS = -ru
FC = $(FCOMPILER)

INCDIR=../include

FFLAGS = -w -I$(INCDIR) -ffixed-line-length-none -fd-lines-as-comments -fno-automatic -fPIC -freal-4-real-8

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
	$(FC) $(FFLAGS) -c $<

clean:
	-rm -f *.o
	-rm -f *.a
	-rm *.exe
