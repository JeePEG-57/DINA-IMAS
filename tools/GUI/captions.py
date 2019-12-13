
tooltip = dict()

# control_data.dat
tooltip['Vvs1_max'] = 'Maximum voltage in VS1 circuit [V]'
tooltip['Vvs3_max'] = 'Maximum voltage in VS3 circuit [V]'
tooltip['Vpfs_max'] = 'Maximum voltages on CS3U, CS2U, CS1, CS2L, CS3L, PF1, PF2, PF3, PF4, PF5, PF6 [V]'
tooltip['Time_V'] = 'Minimum time of voltage variation from –Vmax to +Vmax (in s) for CS3U, CS2U, CS1, CS2L, CS3L, PF1, PF2, PF3, PF4, PF5, PF6 [s]'
tooltip['c_cur_max'] = 'Parameter used in “Current Limitation Algorithm"'
tooltip['Ipfs_max'] = 'Maximum currents in CS3U, CS2U, CS1, CS2L, CS3L, PF1, PF2, PF3, PF4, PF5, PF6 [kA]'

# control_data2.dat
tooltip['Time_cont2'] = 'Time when the “Limiter Controller” is switched on (block “Lim. contr) [s]'
tooltip['Ip_div'] = 'Plasma current when the “Divertor Controller 1” is switched on at ramp-up phase (block “lim_div_tr”) [MA]'
tooltip['Time_ref_ramp'] = 'Transition time of the control voltages at the switching of controllers (blocks “div_divrd, tt_kavin2.dat(4,1)) [s]'
tooltip['Ip_rd'] = 'Plasma current when the “Divertor Controller 2” is switched on at ramp-down phase (blocks “div_divrd, tt_kavin2.dat(4,1)) [MA]'
tooltip['Time_rd_ref'] = 'Last time moment in files g1_term.dat - g6_term.dat (block “g1-g6.dat,g1_term-g6_term.dat”) [s]'
tooltip['c_a_tpl1'] = 'Tuning coefficient for VS gain during plasma ramp-up and flat top phases (block “VS gain1)'
tooltip['c_a_tpl1_EOB'] = 'Tuning coefficient for VS gain during plasma ramp-down phase (block “VS gain 3”)'
tooltip['c_a_tpl2'] = 'Tuning coefficient for divertor controller gain (block “lim. gain”)'
tooltip['c_a_tpl_min'] = 'Minimum value of tuning coefficient for VS gain during plasma ramp-down phase (block “Saturation4”)'
tooltip['y0'] = 'Tuning coefficient for divertor controller gain during plasma ramp-down phase (block “scr_data.dat”)'
tooltip['c1_y0'] = 'Tuning coefficient for divertor controller gain during plasma ramp-down phase (block “scr_data.dat”)'
tooltip['c2_y0'] = 'Tuning coefficient for divertor controller gain during plasma ramp-down phase (block “scr_data.dat”)'

# equilibrium%vacuum_toroidal_field%r0
tooltip['R0'] = 'Reference major radius where the vacuum toroidal magnetic field is given [m]'

# equilibrium%vacuum_toroidal_field%b0
tooltip['Bt'] = 'Vacuum toroidal field at R0 [T]'

# -
tooltip['TAU_before3.5s'] = 'Time-step before 3.5 s plasma operation point (default value 2 ms)'

# tay_simul.dat
tooltip['TAU_beforeEOB'] = 'Time-step after 3.5 s plasma operation point (default value 10 ms) [ms]'

# dw.dat
tooltip['TAU_afterEOB'] = 'Time-step after EOB plasma operation point (default value 5 ms) [ms]'

# !!!
tooltip['q_sauteeth'] = 'q value inside of which the mixing is taken place'

# tran_times.dat
tooltip['Time_ext_trans'] = 'Time to switch on the external transport modules in DINA [ms]'

# pcchp_end.dat
tooltip['Ndt_rampdw'] = 'Level to which the plasma density decreases during 4 s after start of plasma current ramp-down phase [19]'

# k_jetto.dat
tooltip['k_bohm_gbohm'] = 'Key to switch DINA transport model [0] to JINTRAC one [1]'

# bohm_gbohm.dat
tooltip['k_bohm_gbohm'] = 'Key to switch on (=1) or off (=0) Bohm-giro-Bohm scaling'

# init.dat
tooltip['Initial D pressure'] = 'Plasma initiation D particles pressure [Pa]'
tooltip['Initial Te'] = 'Initial Te [eV]'
tooltip['Initial Ti'] = 'Initial Ti [eV]'
tooltip['Initial ionization state'] = 'initial Ne/Nd'
tooltip['Puff_gain'] = 'Neutrals puffing gain to keep the prescribed waveform of D up to Ip = 1.5 MA'

# tt_kavin2.dat
tooltip['dt_rampup'] = 'Duration of ramp-up phase [ms]'
tooltip['dt_end_sim'] = 'Time during which the poloidal coils currents are forced to be zero after the time when Ip = 0 [s]'
tooltip['dt_rampdw'] = 'Duration of ramp-down phase [s]'
tooltip['cIp_end'] = 'Plasma current at ramp-down phase after that the equilibrium is not calculated [MA]'
tooltip['Ics1_EOB'] = 'CS1 current at the end of flat top phase [kA]'
tooltip['RMS_noise'] = 'RMS value of uniformly distributed noise added to the “diagnostic” signal dZ/dt [m/s]'

# scr_data.dat
tooltip['Ip_ref'] = 'Preprogrammed time trace of plasma current [MA]'
tooltip['Ipfs_ref'] = 'Preprogrammed time traces of CS3U, CS2U, CS1, CS2L, CS3L, PF1, PF2, PF3, PF4, PF5, PF6 currents [MA*turn]'

# volt.dat
tooltip['Vpfs_fw'] = 'Preprogrammed time traces of feed forward voltages of CS3U, CS2U, CS1, CS2L, CS3L, PF1, PF2, PF3, PF4, PF5, PF6  [V/turn]'

# elong_ref.dat
tooltip['g1_ref'] = 'Time trace of preprogrammed plasma elongation during limiter phase'

# g1.dat - g6.dat
tooltip['g1_ref'] = 'Time trace of preprogrammed gap (minimum distance) between separatrix and reference left strike point during divertor phase of scenario up to the end of flattop [cm]'
tooltip['g2_ref'] = 'Time trace of preprogrammed gap (minimum distance) between separatrix and reference right strike point  during divertor phase of scenario up to the end of flattop [cm]'
tooltip['g3_ref'] = 'Time trace of preprogrammed R-coordinates of the separatrix outermost point  during both limiter and divertor phases of scenario up to the end of flattop [cm]'
tooltip['g4_ref'] = 'Time trace of preprogrammed gap (minimum distance) between separatrix and point g4  during both limiter and divertor phase of scenario up to the end of flattop [cm]'
tooltip['g5_ref'] = 'Time trace of preprogrammed gap (minimum distance) between separatrix and point g5  during both limiter and divertor phase of scenario up to the end of flattop [cm]'
tooltip['g6_ref'] = 'Time trace of preprogrammed R-coordinates of the separatrix innermost point  during divertor phase of scenario up to the end of flattop [cm]'

# g1_term.dat - g6_term.dat
tooltip['g1_term_ref'] = 'Time trace of preprogrammed gap (minimum distance) between separatrix and reference left strike point  during the divertor phase of plasma current termination starting from the end of flattop [cm]'
tooltip['g2_term_ref'] = 'Time trace of preprogrammed gap (minimum distance) between separatrix and reference right strike point  during the divertor phase of plasma current termination starting from the end of flattop [cm]'
tooltip['g3_term_ref'] = 'Time trace of preprogrammed R-coordinates of the separatrix outermost point  during the divertor phase of plasma current termination starting from the end of flattop [cm]'
tooltip['g4_term_ref'] = 'Time trace of preprogrammed gap (minimum distance) between separatrix and point g4 during divertor phase of plasma current termination starting from the end of flattop [cm]'
tooltip['g5_term_ref'] = 'Time trace of preprogrammed gap (minimum distance) between separatrix and point g5 during divertor phase of plasma current termination starting from the end of flattop [cm]'
tooltip['g6_term_ref'] = 'Time trace of preprogrammed R-coordinates of the separatrix innermost point  during divertor phase of plasma current termination starting from the end of flattop [cm]'

# gaps_data_ramp
tooltip['bnd_points'] = 'R, Z coordinates of points from which the distances to the separatrix are controlled in divertor magnetic configuration [cm]'

# pfres.dat
tooltip['pfres'] = 'Time dependent values of CS, PF coil resistances, in-vessel coil resistance and resistances of passive axisymmetric elements [Ohm]'