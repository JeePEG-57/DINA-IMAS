## How to build DINA actors
Having the repository downloaded, one needs to:
   1. Setup the environment variables. Preferably, the IMAS environment setup is to be done by running a specially prepared script in imas/ci_scripts folder:
$ source imas/ci_scripts/ci_header.sh

   2. Build libraries and generate fc2k python actors:
$ make
  This command:
    a. builds DINA and magnetic controller core libraries in src/;
    b. builds DINA fortran with IDS interface and Fortran workflow in imas/interface/;
    c. builds Python actors in imas/fc2k. The python actors will be placed in the imas/python_wf/actors/.

## Running the workflow
Having the environment set and libraries built, one needs to:
   1. Create a working directory needed for the workflow.
   2. Put in the working directory XML files with code parameters for DINA actor and Magnetic controller actor - DINA_Parameters.xml and KMC_Parameters.xml.
   3. Put in the working directory the workflow configuration file wfconfig.xml with parameters: input and output IMAS databases, simulation start time, etc.
   4. Put in the working directory the machines/imp folder with atomic data.
   5. Create initial IDS's pulse_schedule (with target waveforms for DINA and the magnetic controller) and equilibrium (with defined RZ grid and vacuum toroidal field). The input pf_active, pf_passive, wall IDS's can be used from the Machine Description database.
   6. Run Python or Fortran version of the workflow. Navigate to the working directory and from there:
      - for the Python workflow run the script imas/python_wf/run_test_python.sh
      - for the Fortran workflow run the script imas/python_wf/run_test_fortran.sh


## GUI
Dedicated GUI is available to facilitate the preparation steps before running the workflow.
The GUI allows to load basic scenario target waveforms and code parameters, modify them and save in a working directory (creating a new one if needed).
To launch the GUI, having the environment set:
$ cd tools/GUI
$ python main.py
   - Press button “Load *.dat files", then select folder 15MA_40ka or 7.5MA_30kA_He10p in machines/iter/ (shown by default). 
      This will load corresponding scenario target waveforms with appropriate code parameters for the actors.
   - If needed, you can change target waveforms of the scenario or code parameters of DINA and magnetic controller.
   - Press button “Save to work directory”, then choose an arbitrary working directory (imas/python_wf/ is proposed by default).
      On this stage together with saving the XML files an IDS shot/run = 170/1 (can be changed before saving) is written in 'test' local database and contains pulse_schedule and equilibrium IDS's properly filled for the DINA actors.
   - The GUI main window can be closed now.
If you have modified the shot/run, you have to open the wfconfig.xml in the working directory, then specify your new shot/run in both <pulse_schedule> and <input_start> sections.
In the wfconfig.xml you can make other changes of the workflow parameters, such as input IMAS databases, simulation start time, etc.


## Workflow configuration file
To modify workflow parameters, one has to edit the wfconfig.xml file in the working directory.
   pulse_schedule - IMAS database with pulse_schedule IDS's (ocurrences 0 and 1) with the scenario target waveforms.
   input_pf_active - IMAS database with pf_active IDS. Contains PF active coils geometry. In case of restart additionally must contain coil currents.
   input_pf_passive> - IMAS database with pf_passive IDS. Contains PF passive coils geometry. In case of restart optionally can contain loop currents.
   input_wall - IMAS database with wall IDS. Contains the first wall contour.
   input_magnetics - IMAS database with magnetics IDS, optional. Contains the loops and probes geometry.
   input_em_coupling - IMAS database with em_coupling IDS, optional. If provided, is used directly, coupling matrices are not calculated by geometry.
   input_start - IMAS database with equilibrium and core_profiles IDS's. The core_profiles is required only in case of restart.
      time_start - time moment to start simulation from. Zero if start from fully charged CS, non-zero means restart mode.
   output - IMAS database to store the simulation output.
      decimation - time decimation of the output, stored in the IMAS database (one slice per this number will be stored).
   input_transp - IMAS database with core_profiles and core_sources IDS's, optional. Are provided as input to DINA at each time step, when external transport is used.
      interp_mode - IMAS interpolation mode to read external transport profiles.
   time_ext - Simulation time, after which the external transport profiles are provided to DINA input
   time_stop - Simulation maximum time
   step_max - Simulation maximum time steps
   controller - Magnetic controller version (one of src/controllers/), changes apply only in the Python workflow.
   use_astra - Using ASTRA transport actors instead of IDS's from input_transp section


## Step by step instruction to launch the workflow
$ git clone ssh://git@git.iter.org/scen/dina.git -b feature/passivecomponents dina_tutorial
$ cd dina_tutorial
$ source imas/ci_scripts/ci_header.sh
$ make clean
$ make
$ cd tools/GUI
$ python main.py
   - Press button “Load *.dat files", then select folder 15MA_40ka/ or 7.5MA_30kA_He10p/.
   - Press button “Save to work directory”, then ensure the imas/python_wf/ is chosen and press Save.
   - The GUI main window can be closed now.
$ cd ../../imas/python_wf (Navigate to the working directory).
   - If needed, change settings of the workflow in the wfconfig.xml.
$ source ./run_test_python.sh - to run the Python workflow
$ source ./run_test_fortran.sh - to run the Fortran workflow


## The restart mode
To start simulation from plasma with non-zero plasma current, stored in IMAS, one has to follow the instruction above until the last step. Before running the workflow, modify the wfconfig.xml:
   - input_pf_active - IMAS reference of the pf_active IDS with coil currents;
   - input_start - IMAS reference of the equilibrium and core_profiles IDS's with plasma profiles;
   - input_start/time_start - Time moment to start from.
Optional modification:
   - input_pf_passive - IMAS reference of the pf_passive IDS with passive currents to start with.
The pf_active and pf_passive input IDS's also have to contain geometry of coils and loops, otherwise the input_em_coupling section must provide the em_coupling IDS.


## The required IDS fields to initialize the DINA actor
Vacuum toroidal field
   equilibrium%vacuum_toroidal_field%b0(1)
   equilibrium%vacuum_toroidal_field%r0

2D rectangular uniform grid, each dimension must match value used at DINA compilation time (one of 33, 65, 129, 257).
   equilibrium%time_slice(1)%profiles_2d(1)%grid%dim1(:)
   equilibrium%time_slice(1)%profiles_2d(1)%grid%dim2(:)

First wall contour
   wall%description_2d(1)%limiter%unit(:)%outline%r(:)
   wall%description_2d(1)%limiter%unit(:)%outline%z(:)

Electromagnetic coupling matrices
   em_coupling%mutual_active_active(:,:)
   em_coupling%mutual_loops_active(:,:)
   em_coupling%field_probes_active(:,:)
   em_coupling%mutual_passive_active(:,:)
   em_coupling%mutual_grid_active(:,:)
   em_coupling%mutual_passive_passive(:,:)
   em_coupling%mutual_grid_passive(:,:)
   em_coupling%mutual_loops_passive(:,:)
   em_coupling%field_probes_passive(:,:)
   em_coupling%mutual_loops_grid(:,:)
   em_coupling%field_probes_grid(:,:)

Active coil resistances
   pf_active%coil(:)%resistance

Passive loop resistances
   pf_passive%loop(:)%resistance

Initial PF currents
   pf_active%coil(i)%current%data(1) - in case of the restart mode,
or
   pulse_schedule%pf_active%coil(:)%current%reference%data(1) - in case of starting from t=0 with fully charged Central Solenoid

SNU resistance
   pulse_schedule%pf_active%coil(:)%resistance_additional%reference%data(:)
   pulse_schedule%pf_active%coil(:)%resistance_additional%reference%time(:)

ECH heating at plasma breakdown (used in 0D transport model)
   pulse_schedule%ec%launcher(1)%power%reference%data(:)
   pulse_schedule%ec%launcher(1)%power%reference%time(:)

Auxiliary heating of electrons
   pulse_schedule%ec%power%reference%data(:)
   pulse_schedule%ec%power%reference%time(:)

Auxiliary heating of ions
   pulse_schedule%ic%power%reference%data(:)
   pulse_schedule%ic%power%reference%time(:)

Density of D
   pulse_schedule%density_control%ion(1)%n_i_volume_average%reference%data(:)
   pulse_schedule%density_control%ion(1)%n_i_volume_average%reference%time(:)

Density of T
   pulse_schedule%density_control%ion(2)%n_i_volume_average%reference%data(:)
   pulse_schedule%density_control%ion(2)%n_i_volume_average%reference%time(:)

Impurity content
   pulse_schedule%density_control%ion(3:7)%n_i_volume_average%reference%data(:)
   pulse_schedule%density_control%ion(3:7)%n_i_volume_average%reference%time(:)


## Additional IDS initialization data for DINA, required in case of restart

   equilibrium%time_slice(1)%time
   equilibrium%time_slice(1)%global_quantities%ip

   equilibrium%time_slice(1)%global_quantities%magnetic_axis%r
   equilibrium%time_slice(1)%global_quantities%magnetic_axis%z

   equilibrium%time_slice(1)%profiles_1d%rho_tor_norm(:)
   equilibrium%time_slice(1)%profiles_1d%psi(:)

   equilibrium%time_slice(1)%profiles_1d%dpressure_dpsi(:)
   equilibrium%time_slice(1)%profiles_1d%f_df_dpsi(:)

   core_profiles%profiles_1d(1)%grid%rho_tor_norm(:)
   core_profiles%profiles_1d(1)%grid%psi(:)


## IDS inputs to DINA, required at each time step
The transport profiles:
   core_profiles%profiles_1d(1)%grid%rho_tor_norm(:)
   core_profiles%profiles_1d(1)%electrons%temperature(:)
   core_profiles%profiles_1d(1)%t_i_average(:)

   core_profiles%profiles_1d(1)%electrons%density(:)
   core_profiles%profiles_1d(1)%ion(1)%density(:)
   core_profiles%profiles_1d(1)%ion(2)%density(:)

   core_profiles%profiles_1d(1)%j_bootstrap(:)
   core_profiles%profiles_1d(1)%conductivity_parallel(:)
   core_profiles%profiles_1d(1)%j_non_inductive(:)

   core_sources%source(1)%profiles_1d(1)%electrons%energy(:)
   core_sources%source(1)%profiles_1d(1)%total_ion_energy(:)

Control signals from the magnetic controller:
   pf_active%coil(:)%voltage%data(1)


## IDS fields required for initialization of the magnetic controller
First pulse_schedule input IDS for the ramp-up and flattop phase:
   pulse_schedule%flux_control%i_plasma%reference%data(:)
   pulse_schedule%pf_active%coil(1:12)%current%reference%data(:)
   pulse_schedule%pf_active%coil(1)%current%reference%time(:)

   pulse_schedule%pf_active%supply(1:11)%voltage%reference%data(:)
   pulse_schedule%pf_active%supply(1)%voltage%reference%time(:)

   pulse_schedule%position_control%elongation%reference%data(:)
   pulse_schedule%position_control%elongation%reference%time(:)

   pulse_schedule%position_control%gap(1:6)%value%reference%data
   pulse_schedule%position_control%gap(1:6)%value%reference%time

Second pulse_schedule input IDS for the ramp-down phase:
   pulse_schedule%position_control%gap(1:6)%value%reference%data
   pulse_schedule%position_control%gap(1:6)%value%reference%time


## IDS fields required for the magnetic controller at each time step
   equilibrium%time_slice(1)%time
   equilibrium%time_slice(1)%global_quantities%current_centre%z
   equilibrium%time_slice(1)%boundary%elongation
   equilibrium%time_slice(1)%global_quantities%ip
   equilibrium%time_slice(1)%boundary%type
   equilibrium%time_slice(1)%boundary%geometric_axis%r 
   equilibrium%time_slice(1)%boundary%minor_radius
   equilibrium0%time_slice(1)%boundary_separatrix%gap(25:30)%value
   pf_active%coil(1:14)%current%data(1)


## IDS fields required for the DINA_GREEN actor
Active coil geometry
   pf_active%coil(:)%element(:)%turns_with_sign
   pf_active%coil(:)%element(:)%geometry%geometry_type - types 2 (rectangle), 3 (oblique), 5 (annulus) are supported.
   pf_active%coil(:)%element(:)%geometry%... - corresponding to the geometry_type substructure.

Passive loop geometry
   pf_passive%loop(:)%element(:)%geometry%geometry_type - types 2 (rectangle), 3 (oblique) are supported.
   pf_passive%loop(:)%element(:)%geometry%... - corresponding to the geometry_type substructure.

Rectangular 2D grid
   equilibrium%time_slice(1)%profiles_2d(1)%grid%dim1(:)
   equilibrium%time_slice(1)%profiles_2d(1)%grid%dim2(:)

Flux loops
   magnetics%flux_loop(:)%position(1)%r
   magnetics%flux_loop(:)%position(1)%z

Flux probes
   magnetics%b_field_pol_probe(:)%position%r
   magnetics%b_field_pol_probe(:)%position%z
   magnetics%b_field_pol_probe(:)%poloidal_angle
   magnetics%b_field_pol_probe(:)%length



