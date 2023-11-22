F90 ?= gfortran -w
FFLAGS ?= -O0 -fdefault-real-8 -fPIC -fno-second-underscore -ffree-line-length-none -g
FFLAGS += `pkg-config imas-ifort --cflags`
#LIBS_gfortran=-L$(UAL)/fortraninterface -lUALFORTRANInterface_gfortran -Wl,-rpath,$(UAL)/itmcatalog/lib -L$(UAL)/lowlevel -lUALLowLevel -lm
LDFLAGS += `pkg-config imas-ifort --libs`

TARGETS += dina_imas_circ.a test_dina test_circ

DINADIR := ../../src/scenario/


LIB_SOURCE1 += dina_circ.a dina_imas_circ.o n_dina_imas3.o test_dina_imas.o


#SCHEMAS = $(UAL)/fortraninterface/ids_schemas.f90


all: $(TARGETS)

#--------------------- gfortran ------------------------
test_dina: test_dina_imas.o dina_imas_circ.a dina_contr.a dina_put_slice.a
	@echo "   * $^ -> $@"
	$(F90) -o $@ $^ $(LDFLAGS)

test_circ: test_dina_circ.o dina_imas_circ.a dina_put_slice.a
	@echo "   * $^ -> $@"
	$(F90) -o $@ $^ $(LDFLAGS)

%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90) $(FFLAGS) -c -o $@ $^

n_dina_imas3.o: n_dina_imas3.f 
	$(F90) $(FFLAGS) -c n_dina_imas3.f

dina_imas_circ.a: $(LIB_SOURCE1)
	@echo "   * $^ -> $@"
	@cp dina_circ.a dina_imas_circ.a
	ar -rcs dina_imas_circ.a n_dina_imas3.o dina_imas_circ.o

dina_circ.a:
	make -f Makefile_circ

dina_contr.a: 
	@cp ../interface/kmc.a dina_contr.a

dina_put_slice.a:
	@cp ../interface/dina_put_slice.a dina_put_slice.a

clean:
	rm -f *.o
	rm -f *.a
	rm -f test_circ
	rm -f test_dina
	make -f Makefile_circ clean
