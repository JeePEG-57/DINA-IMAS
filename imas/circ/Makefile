F90_gfortran=gfortran -w
COPTS_gfortran = -O0 -fdefault-real-8 -fPIC -fno-second-underscore -ffree-line-length-none `pkg-config imas-gfortran --cflags` -g  
#LIBS_gfortran=-L$(UAL)/fortraninterface -lUALFORTRANInterface_gfortran -Wl,-rpath,$(UAL)/itmcatalog/lib -L$(UAL)/lowlevel -lUALLowLevel -lm
LIBS_gfortran=`pkg-config imas-gfortran --libs`

f2c= gfortran -w  -ffixed-line-length-none -fd-lines-as-comments -fno-automatic -fPIC  

TARGETS += dina_imas_circ.a test_dina_circ

DINADIR := ../../src/scenario/


LIB_SOURCE1 += dina_90.a dina_imas_circ.o n_dina_imas3.o


#SCHEMAS = $(UAL)/fortraninterface/ids_schemas.f90


all: $(TARGETS)

#--------------------- gfortran ------------------------
test_dina_circ: test_dina_imas.o dina_imas_circ.a dina_contr.a
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)


%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90_gfortran) $(COPTS_gfortran) -c -o $@ $^


n_dina_imas3.o: n_dina_imas3.f 
	$(f2c) -c n_dina_imas3.f



add_dll.o: add_dll.f 
	$(f2c) -c add_dll.f

dina_imas_circ.a: $(LIB_SOURCE1)
	@echo "   * $^ -> $@"
	@cp dina_90.a dina_imas_circ.a
	ar -rcs dina_imas_circ.a  n_dina_imas3.o dina_imas_circ.o


clean:
	rm -f *.o
	rm -f *.a
	rm -f test_dina_circ
