mkdir sandbox
cd sandbox
rm -rf ./*

cp -rf $DINA_ROOT/imas/iwrap/dina_green/code_parameters.xml ./codeparam_green.xml
cp -rf $DINA_ROOT/machines/vns/codeparam_dina.xml ./codeparam_dina.xml
cp -rf $DINA_ROOT/machines/imp ./

node $DINA_ROOT/imas/iwrap/wf_vns/dina_wf.exe ../wfconfig.xml 2>&1 | tee log_fortran
