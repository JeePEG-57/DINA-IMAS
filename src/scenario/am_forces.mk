XLIB= /usr/X11R6/lib

#f2c= g77 -ff2c -fno-automatic
f2c= gfortran -w -ffixed-line-length-none -fd-lines-as-comments -fno-automatic -fPIC -fno-omit-frame-pointer


S=./
V=$(S)

os=		add_dll.o con_vs3_17_ch10.o field_dina.o


dina_contr.a: $(os)
	ar -ru dina_contr.a $(os)


add_dll.o:	$(S)add_dll.f
		$(f2c) -c   -w   $(S)add_dll.f

con_vs3_17_ch10.o:	$(S)con_vs3_17_ch10.f
		$(f2c) -c  -w $(S)con_vs3_17_ch10.f

field_dina.o:	$(S)field_dina.f
		$(f2c) -c  -w $(S)field_dina.f







