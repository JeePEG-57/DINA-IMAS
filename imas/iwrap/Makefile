.PHONY: validate actor actor-gui help

WF_CONFIG ?= ../python_wf/wfconfig.xml
NATIVE_CODE = ../interface/dina_iwrap_wf.f90
NATIVE_LIB = ../interface/dina_iwrap_wf.a
IWRAP_ACTORS_DIR ?= ${HOME}/IWRAP_ACTORS
ACTOR = $(IWRAP_ACTORS_DIR)/dina_iwrap_wf/actor.py

actor : $(ACTOR) ## Builds the IWrap actor

$(ACTOR) : $(WF_CONFIG) $(NATIVE_LIB)
	sed -i -e 's|<pulse></pulse>|<pulse>0</pulse>|' $(WF_CONFIG)
	sed -i -e 's|<run></run>|<run>0</run>|' $(WF_CONFIG)
	sed -i -e "s|dubrovm|${USER}|" $(WF_CONFIG)
	iwrap -a dina_iwrap_wf -f dina_iwrap_wf.yaml

actor-gui : $(WF_CONFIG) $(NATIVE_LIB) ## Opens IWrap GUI 
	sed -i -e 's|<pulse></pulse>|<pulse>0</pulse>|' $(WF_CONFIG)
	sed -i -e 's|<run></run>|<run>0</run>|' $(WF_CONFIG)
	sed -i -e "s|dubrovm|${USER}|" $(WF_CONFIG)
	iwrap-gui -a dina_iwrap_wf -f dina_iwrap_wf.yaml

$(WF_CONFIG) : ../../machines/iter/15MA_40ka/wfconfig.xml
	cp $^ $@

native: $(NATIVE_LIB) ## Builds native library

$(NATIVE_LIB) : $(NATIVE_CODE)
	make -C ../interface $(notdir $(NATIVE_LIB))

validate: ## Test the consistency of the XML and XSD files for input parameters
	xmllint --noout wfconfig.xsd $(WF_CONFIG)
	xmllint --noout --schema wfconfig.xsd $(WF_CONFIG)

clean: ## Removes wfconfig.xml and IWRAP_ACTORS
	rm -fr $(WF_CONFIG) ~/IWRAP_ACTORS/dina_iwrap_wf

help :
	@grep -Eh '^[a-zA-Z0-9_%\./-]+[ ]*:.*?## .*$$' $(MAKEFILE_LIST) |sort|awk \
	'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
	