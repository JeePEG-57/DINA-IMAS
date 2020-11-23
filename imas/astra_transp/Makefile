F90_gfortran=gfortran -w
COPTS_gfortran = -O0 -fdefault-real-8 -fPIC -fno-second-underscore -ffree-line-length-none `pkg-config imas-gfortran --cflags` -g  
LIBS_gfortran=`pkg-config imas-gfortran --libs`

XLIB= /usr/X11R6/lib

#f2c= g77 -ff2c -fno-automatic
f2c= gfortran -w  -ffixed-line-length-none -fno-automatic -fPIC


S=./
V=$(S)



os=		a_main_dina.o add_dll.o main_astra.o \
		solsrs_IMAS.o neutex_IMAS.o pelsrs1_IMAS.o solpsz3.o nbicomR_IMAS.o

os1=		add_dll.o \
	        neutex_IMAS.o pelsrs1_IMAS.o solpsz3.o nbicomR_IMAS.o


os_d= $(os) a_dina.o tran6.o
os_s_pel= $(os1) tran_pel.o mainp_astra.o solsrsP_IMAS.o
os_s_puff= $(os1) tran_neut.o main_astra.o solsrs_IMAS.o

os_pel= feed_pel.o 
os_puff= feed_src.o 


all: p_4dina astra_transp_density.a  density_control_pellet.a density_control_valve.a astra_sources_pellet.a astra_sources_valve.a

astra_transp_density.a: astra_transp_density.o $(os_d)
	@echo "   * $^ -> $@"
	ar -rcs astra_transp_density.a astra_transp_density.o $(os_d) 


density_control_pellet.a: density_control_pellet.o $(os_pel)
	@echo "   * $^ -> $@"
	ar -rcs density_control_pellet.a density_control_pellet.o $(os_pel)

density_control_valve.a: density_control_valve.o $(os_puff)
	@echo "   * $^ -> $@"
	ar -rcs density_control_valve.a density_control_valve.o $(os_puff)

astra_sources_pellet.a: astra_sources_pellet.o $(os_s_pel)
	@echo "   * $^ -> $@"
	ar -rcs astra_sources_pellet.a astra_sources_pellet.o $(os_s_pel)

astra_sources_valve.a: astra_sources_valve.o $(os_s_puff)
	@echo "   * $^ -> $@"
	ar -rcs astra_sources_valve.a astra_sources_valve.o $(os_s_puff)

%.o: %.f90
	@echo "   * $^ -> $@"
	$(F90_gfortran) $(COPTS_gfortran) -c -o $@ $^

p_4dina:	$(os_d)
		gfortran -o p_4dina $(os_d) -lm -L$(XLIB) -lX11


a_main_dina.o:	$(S)a_main_dina.f
		$(f2c) -c   -w   $(S)a_main_dina.f

a_dina.o:	$(S)a_dina.f
		$(f2c) -c   -w   $(S)a_dina.f


add_dll.o:	$(S)add_dll.f
		$(f2c) -c   -w    $(S)add_dll.f

feed_pel.o:	$(S)feed_pel.f
		$(f2c) -c   -w    $(S)feed_pel.f

feed_src.o:	$(S)feed_src.f
		$(f2c) -c   -w    $(S)feed_src.f

tran6.o:	$(S)tran6.f
		$(f2c) -c   -w    $(S)tran6.f

tran_pel.o:	$(S)tran_pel.f
		$(f2c) -c   -w    $(S)tran_pel.f

tran_neut.o:	$(S)tran_neut.f
		$(f2c) -c   -w    $(S)tran_neut.f

main_astra.o:	$(S)main_astra.f
		$(f2c) -c   -w    $(S)main_astra.f
mainp_astra.o:	$(S)mainp_astra.f
		$(f2c) -c   -w    $(S)mainp_astra.f

solsrs_IMAS.o:	$(S)solsrs_IMAS.f
		$(f2c) -c   -w    $(S)solsrs_IMAS.f
solsrsP_IMAS.o:	$(S)solsrsP_IMAS.f
		$(f2c) -c   -w    $(S)solsrsP_IMAS.f

neutex_IMAS.o:	$(S)neutex_IMAS.f
		$(f2c) -c   -w    $(S)neutex_IMAS.f

pelsrs1_IMAS.o:	$(S)pelsrs1_IMAS.f
		$(f2c) -c   -w    $(S)pelsrs1_IMAS.f

solpsz3.o:	$(S)solpsz3.f
		$(f2c) -c   -w    $(S)solpsz3.f
nbicomR_IMAS.o:	$(S)nbicomR_IMAS.f
		$(f2c) -c   -w    $(S)nbicomR_IMAS.f

clean:
	rm -f *.o
	rm -f *.a
	rm -f p_4dina
	rm -f p_4dina_src
