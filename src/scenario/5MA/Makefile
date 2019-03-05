# Makefile for compilation of DINA components

AR = ar
ARFLAGS = -ru
FC = gfortran

f2c= cc -fpic

FFLAGS = -w -ffixed-line-length-none -fd-lines-as-comments -fno-automatic -fPIC

CONTROLSRC = t15_2.c t15_2_data.c pf_lookup3.c pf_lookup3_wrapper.c read_pf.c \
read_gaps.c  read_gaps_wrapper.c read_gaps_term.c  read_gaps_term_wrapper.c \
read_tt_kavin2.c read_tt_kavin2_wrapper.c read_Ics1_end.c \
read_Ics1_end_wrapper.c read_volt.c read_volt_wrapper.c rms_noise.c rms_noise_wrapper.c \
pow_sup.c pow_sup_wrapper.c \
rt_look.c rt_look1d.c \
rt_nonfinite.c rt_rand.c rtGetNaN.c rtGetInf.c

CONTROLOBJ = $(CONTROLSRC:.c=.o)

all: dina_kav.a

dina_kav.a: $(CONTROLOBJ)
	$(RM) -r dina_kav.a
	$(AR) $(ARFLAGS) $@ $(CONTROLOBJ)
	cp dina_kav.a ..

%.o: %.f
	$(FC) $(FFLAGS) -c $<

%.o: %.c
	$(f2c)  -c $<


clean:
	-rm -f *.o

distclean:
	-rm -f *.o *.a
