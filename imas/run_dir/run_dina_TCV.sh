# copy all xml files to ouptut directory   
python copy_input_parameters.py wfconfig.xml --source-dir . --base-path /home/ITER

# run dina, and output logs to log_fortran in cwd. 
../iwrap/wf_tcv/dina_wf.exe wfconfig.xml 2>&1 | tee log_fortran
