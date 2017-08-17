F90_gfortran=gfortran -w
COPTS_gfortran = -O0 -fdefault-real-8 -fPIC -fno-second-underscore -ffree-line-length-none `pkg-config imas-gfortran --cflags` -g  
#LIBS_gfortran=-L$(UAL)/fortraninterface -lUALFORTRANInterface_gfortran -Wl,-rpath,$(UAL)/itmcatalog/lib -L$(UAL)/lowlevel -lUALLowLevel -lm
LIBS_gfortran=`pkg-config imas-gfortran --libs`

f2c= gfortran -w  -ffixed-line-length-none -fd-lines-as-comments -fno-automatic -fPIC  

TARGETS += dina_imas.a dina_put_slice.a dina_contr.a dina_transp1.a dina_transp2.a dina_transp3.a dina_transp4.a dina_transp5.a dina_sdn.a solps_imas.a test_dina_to_imas

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

test_dina_to_imas: test_dina_to_imas.o n_dina_imas4.o dina_to_imas.o
	@echo "   * $^ -> $@"
	$(F90_gfortran) -o $@ $^ $(LIBS_gfortran)

%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90_gfortran) $(COPTS_gfortran) -c -o $@ $^

n_dina_imas3.o: n_dina_imas3.f 
	$(f2c) -c n_dina_imas3.f

n_dina_imas4.o: n_dina_imas4.f
	$(f2c) -c n_dina_imas4.f

main_1l.o: main_1l.f 
	$(f2c) -c main_1l.f

n_kav.o: n_kav.f
	$(f2c) -c n_kav.f

out42_for.o: out42_for.f
	$(f2c) -c out42_for.f

tran1.o: tran1.f 
	$(f2c) -c tran1.f

tran2.o: tran2.f 
	$(f2c) -c tran2.f

tran3.o: tran3.f 
	$(f2c) -c tran3.f

tran4.o: tran4.f 
	$(f2c) -c tran4.f

tran5.o: tran5.f 
	$(f2c) -c tran5.f

add_dll.o: add_dll.f 
	$(f2c) -c add_dll.f

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

dina_transp1.a: dina_transp1.o tran1.o add_dll.o
	@echo "   * $^ -> $@"
	ar -rcs dina_transp1.a dina_transp1.o tran1.o add_dll.o

dina_transp2.a: dina_transp2.o tran2.o add_dll.o
	@echo "   * $^ -> $@"
	ar -rcs dina_transp2.a dina_transp2.o tran2.o add_dll.o

dina_transp3.a: dina_transp3.o tran3.o add_dll.o
	@echo "   * $^ -> $@"
	ar -rcs dina_transp3.a dina_transp3.o tran3.o add_dll.o

dina_transp4.a: dina_transp4.o tran4.o add_dll.o
	@echo "   * $^ -> $@"
	ar -rcs dina_transp4.a dina_transp4.o tran4.o add_dll.o

dina_transp5.a: dina_transp5.o tran5.o add_dll.o
	@echo "   * $^ -> $@"
	ar -rcs dina_transp5.a dina_transp5.o tran5.o add_dll.o

dina_sdn.a: dina_sdn.o
	@echo "   * $^ -> $@"
	ar -rcs dina_sdn.a dina_sdn.o

solps_imas.a: solps_imas.o
	@echo "   * $^ -> $@"
	@cp $(DINADIR)/solpsz2_vic.o solpsz2_vic.o
	ar -rcs solps_imas.a solps_imas.o solpsz2_vic.o

clean:
	rm -f *.o
	rm -f *.a
	rm -f test_dina_to_imas
