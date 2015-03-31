

all:
	# replace $$HOME with the value (fc2k does not do it)
	sed -i 's@$$HOME@'$$HOME'@' dinaimas20.xml dinacontr19.xml dinaputslice.xml
	@echo "Remember to run make fc2k to get the DINA actor into your kepler folder"

clean:
	# revert $$HOME instead of the value
	sed -i 's@'$$HOME'@$$HOME@' dinaimas20.xml dinacontr19.xml dinaputslice.xml

fc2k:
	$$FC2K/bin/fc2k dinaimas20.xml
	$$FC2K/bin/fc2k dinacontr19.xml
	$$FC2K/bin/fc2k dinaputslice.xml

