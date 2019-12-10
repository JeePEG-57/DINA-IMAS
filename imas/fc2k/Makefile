.phony: all clean fc2k

all: dinaimas21.xml dinacontr21.xml dinaputslice21.xml solps_imas.xml dinasdn21.xml
	@echo "Remember to run make fc2k to get the DINA actors into your kepler folder"

%.xml: %-template.xml # Substitute environment variables
	sed	-e 's;$$IMAS_PREFIX;$(IMAS_PREFIX);'\
		-e 's;$$KEPLER;$(KEPLER);' \
		-e 's;$$FC2K;$(FC2K);' \
		-e 's;$$HOME;$(HOME);' \
	$< > $@

clean:
	rm -f dinaimas21.xml dinacontr21.xml dinaputslice21.xml dinasdn21.xml solps_imas.xml

fc2k: dinaimas21.xml dinacontr21.xml dinaputslice21.xml dinatransp_energy.xml dinatransp_density.xml dinatransp_bootcond.xml dinatransp_curdrive.xml dinatransp_heatsrc.xml dinasdn21.xml solps_imas.xml
	$$FC2K/bin/fc2k -nocompile dinaimas21.xml
	$$FC2K/bin/fc2k -nocompile dinacontr21.xml
	$$FC2K/bin/fc2k -nocompile dinaputslice21.xml
	$$FC2K/bin/fc2k -nocompile dinatransp_energy.xml
	$$FC2K/bin/fc2k -nocompile dinatransp_density.xml
	$$FC2K/bin/fc2k -nocompile astra_transp_density.xml
	$$FC2K/bin/fc2k -nocompile dinatransp_bootcond.xml
	$$FC2K/bin/fc2k -nocompile dinatransp_curdrive.xml
	$$FC2K/bin/fc2k -nocompile dinatransp_heatsrc.xml
	$$FC2K/bin/fc2k -nocompile dinasdn21.xml
	$$FC2K/bin/fc2k -nocompile solps_imas.xml
	cd $(KEPLER)/build-area && ant clean-cache && ant compile && ant make-kars
