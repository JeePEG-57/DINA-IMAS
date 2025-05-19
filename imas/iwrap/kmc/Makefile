FCOMPILER?=gfortran
ACTOR=kav_mag_contr
INCDIR:=../../../src/include

DEBUG=-g -O0

PACKAGES=
#PACKAGES+=imas-$(FCOMPILER)
PACKAGES+=al-fortran
#PACKAGES+=libxml-2.0
PACKAGES+=xmllib

F90LIB=
F90INC=-I$(INCDIR)

F90DEF=-D'GIT_URL="$(GIT_URL)"'
F90DEF+=-D'GIT_COMMIT_ID="$(GIT_COMMIT_ID)"'
F90DEF+=-D'GIT_VERSION="$(GIT_VERSION)"'

# COMPILER-SPECIFIC FLAGS
ifeq ($(FCOMPILER), ifort)
  F90FLAGS=-fPIC -fpp -g
else ifeq ($(FCOMPILER), gfortran)
  F90FLAGS=-fPIC -cpp
else
  $(error Unsupported Fortran compiler)
endif

F90FLAGS+=-w -freal-4-real-8 -fno-second-underscore -ffree-line-length-none
F90FLAGS+=$(F90DEF)
F90FLAGS+=$(DEBUG)

F90=$(FCOMPILER)

FC = $(FCOMPILER) -I$(INCDIR) -w -ffixed-line-length-none -fd-lines-as-comments -fno-automatic -fPIC

# FLAGS OF PACKAGES
F90LIB+=`pkg-config $(PACKAGES) --libs`
F90INC+=`pkg-config $(PACKAGES) --cflags`

# LIST OF OBJECT FILES
OBJS_ACTOR = ../../../src/controllers/kmc/kmc.a kav_contr.o dina_contr.o contr_params_imas.o
OBJS_TEST  = test_actor.o 

IWRAP_ACTORS_DIR ?= $(HOME)/IWRAP_ACTORS

TEST=test_actor

all: lib exe

lib: $(ACTOR).a

exe: $(TEST).exe

actor : lib ## Builds the IWrap actor
	iwrap -a $(ACTOR) -f iwrap_settings.yaml
	
actor-gui : lib ## Opens IWrap GUI 
	iwrap-gui -a $(ACTOR) -f iwrap_settings.yaml
	
$(TEST).exe: $(OBJS_TEST) $(ACTOR).a
	$(F90) $(F90FLAGS) -o $@ $^ $(F90LIB)

$(ACTOR).a: $(OBJS_ACTOR)
	@cp $< $@
	ar -rcs $@ $^

%.o:%.f90
	$(F90) $(F90FLAGS) -c $< $(F90INC)

%.o: %.f
	@echo "   * $^ -> $@"
	$(FC) -c $<

validate:
	xmllint --noout test_wf_parameters.xsd test_wf_parameters.xml
	xmllint --noout --schema test_wf_parameters.xsd test_wf_parameters.xml
	xmllint --noout code_parameters.xsd code_parameters.xml
	xmllint --noout --schema code_parameters.xsd code_parameters.xml

clean:
	rm -rf *.exe *.a *.mod *.o
	rm -rf $(IWRAP_ACTORS_DIR)/$(ACTOR)

