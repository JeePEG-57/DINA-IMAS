XLIB= /usr/X11R6/lib

#f2c= g77 -ff2c -fno-automatic
f2c= gfortran -w  -ffixed-line-length-none -fno-automatic 


S=./
V=$(S)



os=		a_main_dina.o a_dina.o add_dll.o tran6.o main_astra.o \
		solsrs_IMAS.o neutex_IMAS.o pelsrs1_IMAS.o solpsz2.o nbicomR_IMAS.o
		 

p_4dina:	$(os)

		gfortran -o p_4dina $(os) -lm -L$(XLIB) -lX11


a_main_dina.o:	$(S)a_main_dina.f
		$(f2c) -c   -w   $(S)a_main_dina.f

a_dina.o:	$(S)a_dina.f
		$(f2c) -c   -w   $(S)a_dina.f

add_dll.o:	$(S)add_dll.f
		$(f2c) -c   -w    $(S)add_dll.f

tran6.o:	$(S)tran6.f
		$(f2c) -c   -w    $(S)tran6.f

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

