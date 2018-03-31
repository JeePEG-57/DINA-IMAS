F90_gfortran=gfortran -w
COPTS_gfortran = -O0 -fdefault-real-8 -fPIC -fno-second-underscore -ffree-line-length-none `pkg-config imas-gfortran --cflags` -g  
#LIBS_gfortran=-L$(UAL)/fortraninterface -lUALFORTRANInterface_gfortran -Wl,-rpath,$(UAL)/itmcatalog/lib -L$(UAL)/lowlevel -lUALLowLevel -lm
LIBS_gfortran=`pkg-config imas-gfortran --libs`

f2c= gfortran -w  -ffixed-line-length-none -fd-lines-as-comments -fno-automatic -fPIC  

TARGETS += jetto_prof_to_ids jetto_prof_from_ids

#SCHEMAS = $(UAL)/fortraninterface/ids_schemas.f90


all: $(TARGETS)

#--------------------- gfortran ------------------------
jetto_prof_to_ids: jetto_prof_to_ids.o jetto_ids.o
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)

jetto_prof_from_ids: jetto_prof_from_ids.o jetto_ids.o
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)

%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90_gfortran) $(COPTS_gfortran) -c -o $@ $^

clean:
	rm -f *.o
	rm -f jetto_prof_to_ids
	rm -f jetto_prof_from_ids
