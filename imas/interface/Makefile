F90_gfortran=gfortran -w
COPTS_gfortran = -O0 -fdefault-real-8 -fPIC -fno-second-underscore -ffree-line-length-none -I$(UAL)/fortraninterface/amd64_gfortran -g  
LIBS_gfortran=-L$(UAL)/fortraninterface -lUALFORTRANInterface_gfortran -Wl,-rpath,$(UAL)/itmcatalog/lib -L$(UAL)/lowlevel -lUALLowLevel -lm

f2c= gfortran -w  -ffixed-line-length-none -fd-lines-as-comments -fno-automatic -fPIC  

TARGETS += test_dina dina_imas.a dina_contr.a dina_put_slice.a out42_for.o n_kav.o n_dina_imas3.o dina_put_slice.o main_1l.o

LIB_SOURCE1 += dina_imas.o n_dina_imas3.o out42_for.o

LIB_SOURCE2 += dina_contr.o n_kav.o out42_for.o main_1l.o

LIB_SOURCE3 += dina_put_slice.o

#SCHEMAS = $(UAL)/fortraninterface/ids_schemas.f90

DINADIR := ../../src/scenario

all: $(TARGETS)

#--------------------- gfortran ------------------------
test_dina: test_dina_imas.o dina_put_slice.a dina_imas.a dina_contr.a
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)

%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90_gfortran) $(COPTS_gfortran) -c -o $@ $^

n_dina_imas3.o: n_dina_imas3.f 
	$(F90_gfortran) $(COPTS_gfortran) -c n_dina_imas3.f

main_1l.o: main_1l.f 
	$(f2c) -c main_1l.f

n_kav.o: n_kav.f
	$(F90_gfortran) $(COPTS_gfortran) -c n_kav.f

out42_for.o: out42_for.f
	$(F90_gfortran) $(COPTS_gfortran) -c out42_for.f

dina_imas.a: $(LIB_SOURCE1)
	@echo "   * $^ -> $@"
	@cp $(DINADIR)/dina_99.a dina_imas.a
	ar -rcs dina_imas.a n_dina_imas3.o dina_imas.o 

dina_put_slice.a: $(LIB_SOURCE3)
	@echo "   * $^ -> $@"
	ar -rcs dina_put_slice.a dina_put_slice.o

dina_contr.a: $(LIB_SOURCE2)
	@echo "   * $^ -> $@"
	@cp $(DINADIR)/dina_kav.a dina_contr.a
	ar -rcs dina_contr.a dina_contr.o main_1l.o n_kav.o out42_for.o

clean:
	rm -f *.o
	rm -f test_dina
	rm -f dina_imas.a
	rm -f dina_contr.a
	rm -f dina_put_slice.a