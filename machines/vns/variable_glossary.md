# DINA-IMAS Variable Glossary

Generated from debugging session — VNS tokamak case, May 2026.

---

## Grid / Domain Parameters (`parf2` include)

| Variable | Type | Meaning |
|---|---|---|
| `nr` | integer param | Number of R grid points (65 for VNS) |
| `nz` | integer param | Number of Z grid points (129 for VNS) |
| `nn` | integer param | Same as `nr` (alias used in some routines) |
| `mm` | integer param | Same as `nz` (alias used in some routines) |
| `nwnh` | integer param | Total grid size = `nr * nz` (8385 for VNS) |
| `ntet` | integer param | Number of poloidal angles for boundary description (134) |
| `npo` | integer param | Number of radial profile points (310) |
| `mu` | integer param | Max number of PF coils / vessel segments |
| `mu1` | integer param | Max number of flux contour points |
| `kf` | integer param | Max number of PF circuits |
| `nre`, `nze` | integer param | Dimensions of external flux arrays |
| `ntime` | integer param | Max number of time points in time-dependent arrays |

## Grid Arrays (common `/eq1/`)

| Variable | Meaning |
|---|---|
| `x(nr)` | R grid coordinates (cm). `x(1)=0` for VNS (no central column) |
| `y(nz)` | Z grid coordinates (cm). Symmetric: `-400` to `+400` for VNS |
| `dx` | R grid spacing (cm). `dx = (x(nr)-x(1))/(nr-1)` |
| `dy` | Z grid spacing (cm). `dy = (y(nz)-y(1))/(nz-1)` |
| `dr`, `dz` | Same as `dx`, `dy` — used in different common blocks |
| `r(nr)`, `z(nz)` | Same arrays as `x`, `y` — aliased in different common blocks |

## Poloidal Flux Arrays

| Variable | Common block | Meaning |
|---|---|---|
| `psi(nr,nz)` | `/eq1/` | Total poloidal flux (2D grid, plasma + external) |
| `psi_g(nr,nz)` | `/eq1g/` | Previous iteration / IDS-loaded psi (used in omega-blending) |
| `pspl(nwnh)` | `/eq1/` | Plasma contribution to psi (1D linearised, from `buneto`) |
| `psext(nwnh)` | `/eq1e/` | External psi contribution (from PF coils + vessel currents) |
| `pspl0(nwnh)` | `/eq12/` | Previous time step total psi (for relaxation) |
| `omega` | `/eq12/` | Relaxation factor: `psi = omega*(pspl+psext) + (1-omega)*psi_g`. TCV: ~21.8. VNS: 0.5 |

## Plasma Parameters

| Variable | Common block | Meaning |
|---|---|---|
| `tpl` | `/ge1e/` | Total plasma current (A). VNS: ~2539700 A = 2.54 MA |
| `tpl_dir` | (common) | Sign convention for plasma current direction (+1 or -1) |
| `bt0_dir` | (common) | Sign convention for toroidal field direction (+1 or -1) |
| `r0`, `z0` | `/point1/` | Initial plasma centre estimate (R,Z) in cm |
| `rmag`, `zmag` | (various) | Magnetic axis position (R,Z) in cm, updated each iteration |
| `pmag` | `/fluxc6/` | Psi value at magnetic axis |
| `eu` | `/ge7/` | Plasma minor radius (cm). VNS: 160 cm |
| `rout`, `zout` | `/ge7/` | Plasma outer boundary reference point |
| `elong` | `/ge7/` | Plasma elongation |
| `um`, `vm` | `/pol4/` | Same as `rmag`, `zmag` — magnetic axis R,Z used in boundary search |
| `curd` | (local) | Plasma current density = `tpl / (pi * eu^2)` |

## Separatrix / Boundary

| Variable | Common block | Meaning |
|---|---|---|
| `psep` | `/fluxc6/` | Psi value at separatrix (X-point for diverted, limiter for limited) |
| `pbound` | `/fluxc6/` | Psi value used as plasma boundary = `psep + e_sep * delaval` |
| `delaval` | `/fluxc6/` | `pmag - psep` — psi difference axis to separatrix |
| `e_sep` | `/halo15/` | Small fraction to step inside separatrix for boundary |
| `rsep`, `zsep` | `/eq15/` | Separatrix point coordinates (cm) |
| `psepa` | (local) | Psi at limiter contact point from `separatrix1` scan |
| `rsepa`, `zsepa` | (local) | R,Z of limiter contact point |
| `ksepa` | (local) | 0 = limiter config, 1 = diverted (X-point) config |
| `p_s` | `/fluxc6/` | (alias for `psep` in some contexts) |

## PF Coils

| Variable | Common block | Meaning |
|---|---|---|
| `npf` | `/pf1/` | Number of PF circuits |
| `pf(kf)` | `/pf1/` | PF circuit currents (A·turns) at current time step |
| `pf0(kf)` | `/pf1/` | PF circuit currents at previous time step |
| `pf_turns(kf)` | `/v_turn/` | Number of turns per PF circuit |
| `ncirc(kf)` | `/pf_circuit/` | Circuit index for each coil (maps coil → circuit) |
| `dircirc(kf)` | `/pf_circuit/` | Direction (+1 or -1) of each coil within its circuit |
| `pfres(kf)` | `/pf8/` | PF circuit resistance (Ω) |
| `FLUXARR(nwnh,kf)` | `/eq3/` | Green's function: mutual flux between each PF circuit and each grid point |

## Vessel / Passive Structures

| Variable | Common block | Meaning |
|---|---|---|
| `ncam` | `/ves2/` | Number of vessel current filaments |
| `tcam(mu)` | `/ves1/` | Vessel filament currents (A) at current time |
| `tcam0(mu)` | `/ves1/` | Vessel filament currents at previous time |
| `rc(mu)`, `zc(mu)` | `/ves2/` | Vessel filament positions (cm) |
| `vesarr(nwnh,mu)` | `/eq10/` | Green's function: mutual flux between vessel filaments and grid |
| `tokc` | `/ves9/` | Total vessel current (sum of `tcam`) |

## Buneman Solver Parameters (common `/bunemn/`)

| Variable | Meaning |
|---|---|
| `nww` (or `m`) | Number of R intervals = `nr-1` = 64 for VNS |
| `nhh` (or `n`) | Number of Z intervals = `nz-1` = 128 for VNS |
| `drdz2` | `(dr/dz)^2` — aspect ratio of grid cells, used as `s` in solver |
| `rgrid1` (or `shift`) | `x(1)` — inner R boundary (0 for VNS, >0 for TCV) |
| `delr`, `delz` | Grid spacings = `dx`, `dy` |

## Work Arrays (common `/fluxc3/`)

| Variable | Meaning |
|---|---|
| `u(nwnh)` | Work array — boundary values of psi for Buneman solver |
| `work(nwnh)` | Work array — current density × R, then used as RHS |
| `sib(nwnh)` | Input/output array for `buneto` — contains boundary pspl values on edges, RHS in interior |

## Time Control

| Variable | Common block | Meaning |
|---|---|---|
| `tt` | `/ge2/` | Current simulation time (ms) |
| `tay` | (common) | Time step (ms) |
| `tt_kavin` | `/c_tt_kavin/` | Time threshold: before → `equil()`, after → `equil2()` (ms). VNS: 0.1 ms |
| `t_end` | (common) | End time of simulation (ms) |
| `tt_dina_c` | `/c_tran_times/` | Time reference for transport module start |
| `tay_simul_c13` | (common) | Simulation time step for 1D transport (ms) |
| `i_ramp` | `/keys11/` | Flag: 1 = ramp-up phase active |
| `i_bound` | (common) | Boundary condition iteration counter |

## Iteration / Convergence

| Variable | Meaning |
|---|---|
| `niter` | Current Newton iteration counter within one time step |
| `it1` | Flag: 1 = not yet converged (triggers another iteration via `go to 1`) |
| `errm` | Max relative error in psi between iterations |
| `eps2` | Convergence tolerance for psi error |
| `int` | Internal iteration counter |

## Equilibrium Solver Flags

| Variable | Common block | Meaning |
|---|---|---|
| `kpr` | `/ge5/` | Print verbosity flag (0=quiet, 1=verbose) |
| `key_b` | `/keys2/` | Boundary condition type flag |
| `i_old` | (local) | Flag for old vs new boundary update method |
| `i_c` | `/keys7/` | Configuration flag (1 = inner limiter active) |
| `ksepa` | (local/output) | 0 = limited plasma, 1 = diverted plasma |
| `ksep` | (argument) | Mode for `spoint`: -1 = find magnetic axis, 2 = find X-point |
| `i_graph` | `/keys1/` | Flag to enable graphical output |

## Boundary Tracing (`bound_coor`, `pom_lim`)

| Variable | Common block | Meaning |
|---|---|---|
| `pom(ntet)` | `/fluxc2/` | Distance from magnetic axis to plasma boundary in each poloidal direction (cm) |
| `delta0` | `/fluxc2/` | Tolerance for flux contour closure = `1.2*sqrt(dx^2+dy^2)` (cm) |
| `tetq(ntet)` | `/eq7/` | Poloidal angles for boundary description (rad) |
| `xbound(ntet)` | `/eq8/` | R coordinates of plasma boundary polygon |
| `ybound(ntet)` | `/eq8/` | Z coordinates of plasma boundary polygon |
| `jbound` | `/eq8/` | Number of boundary polygon points |
| `uk(ntet)`, `vk(ntet)` | `/pol4/` | Boundary polygon (R,Z) used in equilibrium reconstruction |
| `x11(mu1)`, `y11(mu1)` | `/fluxc4/` | Flux contour points (R,Z) from `fluxcont` |
| `mcurve` | `/fluxc4/` | Number of points in current flux contour |

## Green's Function Computation

| Variable | Meaning |
|---|---|
| `re(nre)`, `ze(nze)` | R,Z positions of external field sources (PF coils projected) |
| `api` | `1/(2*pi)` — normalisation constant |
| `coef` | `10/(4*pi)` — current-to-flux conversion factor |
| `coef1` | `al1 * dx * dy * coef` — normalised current density scale |
| `al1` | Current normalisation factor: `tpl / tok` (ratio of target to computed plasma current) |
| `tok` | Computed total plasma current from current density integral |
| `FP(R,R1,Z,Z1)` | Green's function — mutual flux between a unit current loop at (R1,Z1) and point (R,Z). Returns 0 when R1=0 (axis) after our fix |

## 1D Transport Arrays

| Variable | Meaning |
|---|---|
| `psval(npo)` | Psi values at radial profile grid points |
| `poa(npo)` | Normalised radial coordinate (0=axis, 1=boundary) |
| `AI(npo)` | Plasma current enclosed within each flux surface |
| `poA0(npo)` | Reference profile for current distribution |

## Key Subroutines Reference

| Subroutine | Purpose |
|---|---|
| `ptoke0()` | First equilibrium setup: computes `pspl` via `buneto`, adds `psext`, sets `psi_g` |
| `ptoke1()` / `ptoke1_c()` | Main equilibrium iteration: calls `psi_tot`, `psi_b`, `bound_coor`, `cur_dens` |
| `psi_tot()` | Assembles `psi = omega*psi0 + (1-omega)*psi_g`, finds magnetic axis via `spoint` |
| `buneto()` | Sets up and calls `rzpois` (Buneman solver) for plasma psi contribution |
| `rzpois()` | Buneman cyclic reduction solver for 2D elliptic PDE |
| `boxd()` | Bicubic spline interpolation of `psi(nr,nz)` at arbitrary (R,Z) |
| `boxda()` | Same as `boxd` but takes `psi` as explicit argument |
| `spoint()` | Newton iteration to find magnetic axis (`ksep=-1`) or X-point (`ksep=2`) |
| `psi_b()` | Finds separatrix psi using `separatrix1` + `spoint` |
| `separatrix1()` | Scans outward along poloidal rays to find separatrix contact |
| `pom_lim()` | Computes `pom(ntet)` — boundary distances in each direction |
| `bound_coor()` | Traces plasma boundary polygon via `fluxcont` at `pbound` |
| `fluxcont()` | Traces a flux surface contour at given psi value |
| `equil()` | Single equilibrium solve (used when `tt < tt_kavin`) |
| `equil2()` / `equil2_c()` | Full equilibrium solve with 1D transport (used when `tt > tt_kavin`) |
| `FP(R,R1,Z,Z1)` | Green's function for mutual inductance between two circular loops |

## Known Issues / Bug Fixes Applied

| Issue | Fix | File |
|---|---|---|
| `STOP boxd` NaN crash | `FP()` returns 0 when `R1=0` or `R=0` (VNS inner grid at R=0) | `src/scenario/green_imas.f`, `src/green/green_imas.f` |
| `buneto` refactoring bug | Restored original GOTO-based `rzpois` from commit `49de803` | `src/scenario/bunema.f`, `src/green/bunema.f` |
| `psext` huge negative values | Under investigation — likely PF coil Green's function scale or unit mismatch | `src/scenario/neqm.f` |
| `psep = pmag` (no separatrix found) | Root cause: `psext` corrupts total psi field — `separatrix1` works on wrong psi | `src/scenario/neq0_sep_lim_32.f` |
