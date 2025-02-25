.phony: all clean fc2k

pyworkspace = ../python_wf/actors
#kepler = true


dina_actors = dina_imas dina_green dinatransp_energy dinatransp_density dinatransp_bootcond dinatransp_curdrive dinatransp_heatsrc
contr_actors = kmc kmc_2madiv kmc_pfpo1_1a kmc_pfpo1_1b
dina_regtest = dinaimas_circ dina_equil
astra_actors = solps_imas density_control_pellet density_control_valve astra_sources_pellet astra_sources_valve


ifdef kepler
usekep = ""
else
usekep = -nokepler
endif


ifdef pyworkspace
usepy = -pyworkspace $(pyworkspace)
else
usepy = ""
endif

#ifdef pyworkspace
#	mkdir -p $(pyworkspace)
#endif

all: $(dina_actors) $(contr_actors) $(astra_actors) $(dina_regtest)

fc2k:
	@echo "This option is obsolete"

%: %.xml $(pyworkspace)
	$$FC2K/bin/fc2k -nocompile $< $(usekep) $(usepy)

$(pyworkspace):
	mkdir -p $(pyworkspace)

ifdef kepler
	cd $(KEPLER)/build-area && ant clean-cache && ant compile && ant make-kars
endif

clean:
	rm -rf $(pyworkspace)/*
