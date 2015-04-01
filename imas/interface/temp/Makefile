F90_gfortran=gfortran
COPTS_gfortran = -O0 -fdefault-real-8 -fPIC -fno-second-underscore -ffree-line-length-none -I$(UAL)/fortraninterface/amd64_gfortran -g  
LIBS_gfortran=-L$(UAL)/fortraninterface -lUALFORTRANInterface_gfortran -Wl,-rpath,$(UAL)/itmcatalog/lib -L$(UAL)/lowlevel -lUALLowLevel -lm

dir_v96=./


TARGETS += test_dina dina_imas.a test

LIB_SOURCE += dina_imas.o 

#SCHEMAS = /work/imas/projects/ual/2.0/fortraninterface/ids_schemas.f90

all: $(TARGETS)
	

#--------------------- gfortran ------------------------

test_dina: test_dina_imas.o dina_imas.o $(dir_v96)dina_95.a
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)
		

%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90_gfortran) $(COPTS_gfortran) -c -o $@ $^


dina_imas.a: $(LIB_SOURCE)
	@echo "   * $^ -> $@"
	@cp dina_95.a dina_imas.a
	ar -rcs dina_imas.a $^
	${FC2K}/bin/fc2k dina_imas.xml

#test: ~/kepler/itm/src/cpp/itm/dinaimas/dinaimas.exe
#	@kepler.sh -runwf -nogui -nocache PCSSP_IMAS_S131.xml

clean:
	rm *.o
	rm test_dina
	rm dina_imas.a
#	rmactor dina_imas
#	rmactor dinaimas
