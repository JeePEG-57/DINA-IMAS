F90 ?= gfortran -w

TARGETS += test_flat

LIB_SOURCE1 += green_c_imas.o pers2.o

#SCHEMAS = $(UAL)/fortraninterface/ids_schemas.f90


all: $(TARGETS)

#--------------------- gfortran ------------------------

test_flat: green_c_imas.o pers2.o
	@echo "   * $^ -> $@"
	$(F90) -o $@ $^ $(LDFLAGS)


%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90) $(FFLAGS) -c -o $@ $^


green_c_imas.o: green_c_imas.f 
	$(F90) -c green_c_imas.f


pers2.o: pers2.f
	$(F90) -c pers2.f


clean:
	rm -f *.o
	rm -f *.a
	rm -f $(TARGETS)
