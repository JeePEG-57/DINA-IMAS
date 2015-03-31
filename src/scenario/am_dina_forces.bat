
objects= 	add_dll.obj con_vs3vs1_hl_1.obj  field_dina.obj n_kav.obj



dina_v90.dll:   $(objects)


add_dll.obj:    add_dll.f
		mex  -v -c add_dll.f -f df60opts.bat


con_vs3vs1_hl_1.obj:	con_vs3vs1_hl_1.f 
		mex   -v  -c con_vs3vs1_hl_1.f -f df60opts.bat

cons_func.obj:	cons_func.f 
		mex   -v  -c cons_func.f -f df60opts.bat

field_dina.obj:	field_dina.f
		mex    -v  -c  field_dina.f -f df60opts.bat

n_kav.obj:	n_kav.f
		mex    -v  -c  n_kav.f -f df60opts.bat
