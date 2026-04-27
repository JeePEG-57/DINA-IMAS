def debugg_addPath():
    import sys
    print("running addpaths")
    paths = ["/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/solps_imas",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/kmc_pfpo1_1b",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/kmc_pfpo1_1a",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/kmc_2madiv",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/kmc",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/dinatransp_heatsrc",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/dinatransp_energy",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/dinatransp_density_test0",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/dinatransp_density_test",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/dinatransp_density",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/dinatransp_curdrive",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/dinatransp_bootcond",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/dina_sdn",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/dinaimas_circ",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/dinaimas21",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/dina_green",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/dina_equil",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/density_control_valve",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/density_control_pellet",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/astra_transp_density",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/astra_sources_valve",
            "/home/ITER/svantnj/code/dina/dinatcv/imas/python_wf/actors/astra_sources_pellet"]
    for path in paths:
        sys.path.append(path)
    print("end addpaths")
    