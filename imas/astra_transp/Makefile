F90_gfortran=gfortran -w
COPTS_gfortran = -O0 -fdefault-real-8 -fPIC -fno-second-underscore -ffree-line-length-none `pkg-config imas-gfortran --cflags` -g  
LIBS_gfortran=`pkg-config imas-gfortran --libs`

XLIB= /usr/X11R6/lib

#f2c= g77 -ff2c -fno-automatic
f2c= gfortran -w  -ffixed-line-length-none -fno-automatic -fPIC


S=./
V=$(S)



os=		a_main_dina.o add_dll.o main_astra.o \
		solsrs_IMAS.o neutex_IMAS.o pelsrs1_IMAS.o solpsz2.o nbicomR_IMAS.o

os_d= $(os) a_dina.o tran6.o
os_s= $(os) a_dina_src.o tran7.o

all: p_4dina p_4dina_src astra_transp_density.a astra_transp_src.a density_control_pellet.a density_control_valve.a astra_sources_pellet.a astra_sources_valve.a

astra_transp_density.a: astra_transp_density.o $(os_d)
	@echo "   * $^ -> $@"
	ar -rcs astra_transp_density.a astra_transp_density.o $(os_d) 

astra_transp_src.a: astra_transp_src.o $(os_s)
	@echo "   * $^ -> $@"
	ar -rcs astra_transp_src.a astra_transp_src.o $(os_s)

density_control_pellet.a: density_control_pellet.o
	@echo "   * $^ -> $@"
	ar -rcs density_control_pellet.a density_control_pellet.o

density_control_valve.a: density_control_valve.o
	@echo "   * $^ -> $@"
	ar -rcs density_control_valve.a density_control_valve.o

astra_sources_pellet.a: astra_sources_pellet.o
	@echo "   * $^ -> $@"
	ar -rcs astra_sources_pellet.a astra_sources_pellet.o $(os_s)

astra_sources_valve.a: astra_sources_valve.o
	@echo "   * $^ -> $@"
	ar -rcs astra_sources_valve.a astra_sources_valve.o $(os_s)

%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90_gfortran) $(COPTS_gfortran) -c -o $@ $^

p_4dina:	$(os_d)
		gfortran -o p_4dina $(os_d) -lm -L$(XLIB) -lX11

p_4dina_src:	$(os_s)
		gfortran -o p_4dina_src $(os_s) -lm -L$(XLIB) -lX11

a_main_dina.o:	$(S)a_main_dina.f
		$(f2c) -c   -w   $(S)a_main_dina.f

a_dina.o:	$(S)a_dina.f
		$(f2c) -c   -w   $(S)a_dina.f

a_dina_src.o:	$(S)a_dina_src.f
		$(f2c) -c   -w   $(S)a_dina_src.f

add_dll.o:	$(S)add_dll.f
		$(f2c) -c   -w    $(S)add_dll.f

tran6.o:	$(S)tran6.f
		$(f2c) -c   -w    $(S)tran6.f

tran7.o:	$(S)tran7.f
		$(f2c) -c   -w    $(S)tran7.f

main_astra.o:	$(S)main_astra.f
		$(f2c) -c   -w    $(S)main_astra.f

solsrs_IMAS.o:	$(S)solsrs_IMAS.f
		$(f2c) -c   -w    $(S)solsrs_IMAS.f

neutex_IMAS.o:	$(S)neutex_IMAS.f
		$(f2c) -c   -w    $(S)neutex_IMAS.f

pelsrs1_IMAS.o:	$(S)pelsrs1_IMAS.f
		$(f2c) -c   -w    $(S)pelsrs1_IMAS.f

solpsz2.o:	$(S)solpsz2.f
		$(f2c) -c   -w    $(S)solpsz2.f
nbicomR_IMAS.o:	$(S)nbicomR_IMAS.f
		$(f2c) -c   -w    $(S)nbicomR_IMAS.f

clean:
	rm -f *.o
	rm -f *.a
	rm -f p_4dina
	rm -f p_4dina_src
