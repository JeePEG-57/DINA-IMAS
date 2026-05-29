# copy all xml files to ouptut directory   
python copy_input_parameters.py wfconfig.xml --source-dir . 

# ensure
if [ -z $DINA_ROOT ]; then
	echo ""
	echo "DINA_ROOT undefined. Run ci_scripts first!"
	return 1
fi

# run dina, and output logs to log_fortran in cwd. 
node $DINA_ROOT/imas/iwrap/wf_iter/dina_wf.exe wfconfig.xml 2>&1 | tee log_fortran
