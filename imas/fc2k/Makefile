.phony: all clean fc2k

all: dinaimas21.xml dinacontr21.xml dinaputslice21.xml
	@echo "Remember to run make fc2k to get the DINA actor into your kepler folder"

%.xml: %-template.xml # Substitute environment variables
	sed	-e 's;$$IMAS_PREFIX;$(IMAS_PREFIX);'\
		-e 's;$$KEPLER;$(KEPLER);' \
		-e 's;$$FC2K;$(FC2K);' \
		-e 's;$$HOME;$(HOME);' \
	$< > $@

clean:
	rm dinaimas21.xml dinacontr21.xml dinaputslice21.xml

fc2k: dinaimas21.xml dinacontr21.xml dinaputslice21.xml
	$$FC2K/bin/fc2k dinaimas21.xml
	$$FC2K/bin/fc2k dinacontr21.xml
	$$FC2K/bin/fc2k dinaputslice21.xml

