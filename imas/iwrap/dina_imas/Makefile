FCOMPILER?=gfortran
ACTOR=dina_imas
INCDIR:=../../../src/include


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

F90FLAGS=-fPIC -w
# COMPILER-SPECIFIC FLAGS
ifeq ($(FCOMPILER), ifort)
  F90FLAGS+=-fpp
  F90FLAGS+=-real-size 64 -assume no2underscores -extend_source
else ifeq ($(FCOMPILER), gfortran)
  F90FLAGS+=-cpp
  F90FLAGS+=-freal-4-real-8 -fno-second-underscore -ffree-line-length-none
else
  $(error Unsupported Fortran compiler)
endif

DEBUG = -g -O0
ifeq ($(TARGET), DEBUG)
  F90FLAGS += $(DEBUG)
endif

F90FLAGS+=$(F90DEF)

F90=$(FCOMPILER)

# FLAGS OF PACKAGES
F90LIB+=`pkg-config $(PACKAGES) --libs`
F90INC+=`pkg-config $(PACKAGES) --cflags`

# LIST OF OBJECT FILES
OBJS_ACTOR = ../../../src/scenario/dina_99.a dina_imas.o dina_params_imas.o
OBJS_TEST  = test_actor.o 

IWRAP_ACTORS_DIR ?= $(HOME)/IWRAP_ACTORS

TEST=test_actor

all: lib exe

lib: $(ACTOR).a

exe: $(TEST).exe

actor : lib ## Builds the IWrap actor
	iwrap -a $(ACTOR) -f iwrap_settings.yaml -i $(IWRAP_ACTORS_DIR)

actor-gui : lib ## Opens IWrap GUI 
	iwrap-gui -a $(ACTOR) -f iwrap_settings.yaml -i $(IWRAP_ACTORS_DIR)

$(TEST).exe: $(OBJS_TEST) $(ACTOR).a
	$(F90) $(F90FLAGS) -o $@ $^ $(F90LIB)

$(ACTOR).a: $(OBJS_ACTOR)
	@cp $< $@
	ar -rcs $@ $^

%.o:%.f90
	$(F90) $(F90FLAGS) -c $< $(F90INC)

validate:
	xmllint --noout test_wf_parameters.xsd test_wf_parameters.xml
	xmllint --noout --schema test_wf_parameters.xsd test_wf_parameters.xml
	xmllint --noout code_parameters.xsd code_parameters.xml
	xmllint --noout --schema code_parameters.xsd code_parameters.xml

clean:
	rm -rf *.exe *.a *.mod *.o
	rm -rf $(IWRAP_ACTORS_DIR)/$(ACTOR)

