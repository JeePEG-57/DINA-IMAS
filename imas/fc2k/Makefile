

all:
	# replace $$HOME with the value (fc2k does not do it)
	sed -i 's@$$HOME@'$$HOME'@' dinaimas19.xml dinacontr18.xml dinaputslice.xml
	@echo "Remember to run make fc2k to get the DINA actor into your kepler folder"

clean:
	# revert $$HOME instead of the value
	sed -i 's@'$$HOME'@$$HOME@' dinaimas19.xml dinacontr18.xml dinaputslice.xml

fc2k:
	$$FC2K/bin/fc2k dinaimas19.xml
	$$FC2K/bin/fc2k dinacontr18.xml
	$$FC2K/bin/fc2k dinaputslice.xml

