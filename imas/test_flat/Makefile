
F90_gfortran=gfortran -w

f2c= gfortran -w  -ffixed-line-length-none -fd-lines-as-comments -fno-automatic -fPIC  


TARGETS += test_flat


LIB_SOURCE1 += green_c_imas.o pers2.o


#SCHEMAS = $(UAL)/fortraninterface/ids_schemas.f90


all: $(TARGETS)

#--------------------- gfortran ------------------------

test_flat: green_c_imas.o pers2.o
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)


%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90_gfortran) $(COPTS_gfortran) -c -o $@ $^


green_c_imas.o: green_c_imas.f 
	$(f2c) -c green_c_imas.f


pers2.o: pers2.f
	$(f2c) -c pers2.f


clean:
	rm -f *.o
	rm -f *.a
	rm -f $(TARGETS)
