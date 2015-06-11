

all:
	# replace $$HOME with the value (fc2k does not do it)
	sed -i 's@$$HOME@'$$HOME'@' dinaimas21.xml dinacontr21.xml dinaputslice21.xml
	@echo "Remember to run make fc2k to get the DINA actor into your kepler folder"

clean:
	# revert $$HOME instead of the value
	sed -i 's@'$$HOME'@$$HOME@' dinaimas21.xml dinacontr21.xml dinaputslice21.xml

fc2k:
	$$FC2K/bin/fc2k dinaimas21.xml
	$$FC2K/bin/fc2k dinacontr21.xml
	$$FC2K/bin/fc2k dinaputslice21.xml

