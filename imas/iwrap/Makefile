.PHONY: validate actor actor-gui wf-run

WF_CONFIG ?= ../python_wf/wfconfig.xml
NATIVE_CODE = ../interface/dina_iwrap_wf.a

actor: $(WF_CONFIG) $(NATIVE_CODE)
	iwrap -a dina_iwrap_wf -f dina_iwrap_wf.yaml

actor-gui: $(WF_CONFIG) $(NATIVE_CODE)
	iwrap-gui -a dina_iwrap_wf -f dina_iwrap_wf.yaml

$(WF_CONFIG) : ../../machines/iter/15MA_40ka/wfconfig.xml
	cp $^ $@
	sed -i -e 's|<pulse></pulse>|<pulse>0</pulse>|' $@
	sed -i -e 's|<run></run>|<run>0</run>|' $@
	sed -i -e "s|dubrovm|${USER}|" $@

$(NATIVE_CODE) :
	make -C ../interface

# TEST THE CONSISTENCY OF THE XML AND XSD FILES FOR INPUT PARAMETERS
validate:
	xmllint --noout wfconfig.xsd $(WF_CONFIG)
	xmllint --noout --schema wfconfig.xsd $(WF_CONFIG)
