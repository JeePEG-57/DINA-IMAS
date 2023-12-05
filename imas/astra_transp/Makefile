
PACKAGES =
PACKAGES += imas-$(FCOMPILER)

F90=$(FCOMPILER)
FFLAGS ?= -w -fdefault-real-8 -fPIC -fno-second-underscore -ffree-line-length-none
FFLAGS += `pkg-config $(PACKAGES) --cflags`  
LDFLAGS = `pkg-config $(PACKAGES) --libs`

#XLIB= /usr/X11R6/lib

#FC= g77 -ff2c -fno-automatic
FC= $(FCOMPILER) -w -ffixed-line-length-none -fno-automatic -fPIC


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
	$(F90) $(FFLAGS) -c -o $@ $^

p_4dina:	$(os_d)
		$(F90) -o $@ $^ $(LDFLAGS)


a_main_dina.o:	$(S)a_main_dina.f
		$(FC) -c   -w   $(S)a_main_dina.f

a_dina.o:	$(S)a_dina.f
		$(FC) -c   -w   $(S)a_dina.f


add_dll.o:	$(S)add_dll.f
		$(FC) -c   -w    $(S)add_dll.f

feed_pel.o:	$(S)feed_pel.f
		$(FC) -c   -w    $(S)feed_pel.f

feed_src.o:	$(S)feed_src.f
		$(FC) -c   -w    $(S)feed_src.f

tran6.o:	$(S)tran6.f
		$(FC) -c   -w    $(S)tran6.f

tran_pel.o:	$(S)tran_pel.f
		$(FC) -c   -w    $(S)tran_pel.f

tran_neut.o:	$(S)tran_neut.f
		$(FC) -c   -w    $(S)tran_neut.f

main_astra.o:	$(S)main_astra.f
		$(FC) -c   -w    $(S)main_astra.f
mainp_astra.o:	$(S)mainp_astra.f
		$(FC) -c   -w    $(S)mainp_astra.f

solsrs_IMAS.o:	$(S)solsrs_IMAS.f
		$(FC) -c   -w    $(S)solsrs_IMAS.f
solsrsP_IMAS.o:	$(S)solsrsP_IMAS.f
		$(FC) -c   -w    $(S)solsrsP_IMAS.f

neutex_IMAS.o:	$(S)neutex_IMAS.f
		$(FC) -c   -w    $(S)neutex_IMAS.f

pelsrs1_IMAS.o:	$(S)pelsrs1_IMAS.f
		$(FC) -c   -w    $(S)pelsrs1_IMAS.f

solpsz3.o:	$(S)solpsz3.f
		$(FC) -c   -w    $(S)solpsz3.f
nbicomR_IMAS.o:	$(S)nbicomR_IMAS.f
		$(FC) -c   -w    $(S)nbicomR_IMAS.f

clean:
	rm -f *.o
	rm -f *.a
	rm -f p_4dina
	rm -f p_4dina_src
