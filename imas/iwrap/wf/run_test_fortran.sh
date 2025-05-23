mkdir sandbox
cd sandbox
rm -rf ./*

cp -rf ../../dina_green/code_parameters.xml ./codeparam_green.xml
cp -rf ../../../../machines/iter/15MA_40ka/codeparam_dina.xml ./codeparam_dina.xml
cp -rf ../../../../machines/iter/15MA_40ka/codeparam_kmc.xml ./codeparam_kmc.xml
cp -rf ../../../../machines/imp ./

../dina_wf.exe ../wfconfig.xml 2>&1 | tee log_fortran
