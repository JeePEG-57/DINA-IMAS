# Instruction how to build and run the workflow with selected scenario

## 1. Setup the IMAS environment.
   Preferably, the IMAS environment setup is to be done by running a specially prepared script in imas/ci_scripts folder:
$ . ./imas/ci_scripts/ci_header.sh

## 2. Build libraries and generate fc2k python actors:
$ make

## 3. Setup initial IDS with static tokamak data.
   - Move to directory tools/GUI to run GUI application:
$ cd tools/GUI
$ python main.py
   - Press button “Load setups” to setup the DINA start up parameters, 
select folder example/15MA_40ka in machines/iter directory. 
   - Press button “Save to work directory”, save the files to imas/python_wf. On this stage together with saving the files an IDS shot/run = 170/1 is written in 'test' local database and contains static data related to the tokamak and scenario. These data are not used in simulation; simulation will add time-dependent data to existing in initial IDS and store it as an output. 
   - Close the GUI main window.

## 4. Set scenario to simulate.
   To provide for simulation its settings and input data for the actors involved, find the folder corresponding to the desired scenario in machines/iter/ and copy all files to the workflow working directory imas/python_wf.

## 5. Running the Python workflow (maximum about 3000 time steps or 60 seconds simulated).
   Move to directory imas/python_wf and use command
$ cd imas/python_wf
$ ./run_test_python.sh 
to start DINA-IMAS under python workflow. The workflow will read created before initial IDS shot/run = 170/1 and produce shot/run = 170/45.
One can modify these shot and run numbers inside the script imas/python_wf/test_python_wf.py.

## 6. Running with external transport profiles
   Inside the script imas/python_wf/test_python_wf.py in the main routine:
   - To take the transport profiles from the IMAS_Input database, one need to specify time value Workflow.Time_ExternalTranspStarts. Starting from this value, the Workflow will pass transport profiles from the IMAS_Input (can be less then Workflow.Time_Start).
   - In the DINA input file dina_data.dat specify tt_dina parameter (line 631) to be 1000.0*Workflow.Time_ExternalTranspStarts (it is in ms)

## 7. Running restart with external transport profiles
   If you have scenario simulated with DINA or any source with properly filled IDS's, then inside the script imas/python_wf/test_python_wf.py in the main routine change Workflow.Time_Start to a value greater than tt_dina/1000.0 (in the dina_data.dat).

## 8. There is an option to run pure Fortran version of the workflow, without any limit on steps simulated. Useful to create an entire scenario to play short restarts after in python (or also in Fortran). For this purpose there is another script in the working folder:
$ cd imas/python_wf
$ run_test_python.sh 
   All the workflow settings are placed in the file fortranworkflow.dat, their meaning is the same as for the python workflow.




