.PHONY: validate actor actor-gui wf-run

actor:
	iwrap -a dina_iwrap_wf -f ./dina_iwrap_wf.yaml

actor-gui: 
	iwrap-gui -a dina_iwrap_wf -f ./dina_iwrap_wf.yaml


# TEST THE CONSISTENCY OF THE XML AND XSD FILES FOR INPUT PARAMETERS
validate:
	xmllint --noout ./wfconfig.xsd ../python_wf/wfconfig.xml
	xmllint --noout --schema ./wfconfig.xsd ../python_wf/wfconfig.xml
