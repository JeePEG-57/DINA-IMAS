%clear; npf=15; EqTime=3.5;

n_mc=11;

ntur=[554,554,554,554,554  248.6 115.2 185.9 169.9 216.8  459.4 1]';
wz=[[0 0 0 0 0 0 -1 -1 1 1 0 0]'./ntur [0 0 0 0 0 0 0 0 0 0 0 1]'];

VS_up=[6e3./ntur(1:n_mc); 575]; VS_low=-VS_up;
Vmc_up=[2.1e3 2.1e3 4.2e3 2.1e3 2.1e3  2.1e3 3.15e3*ones(1,4) 2.1e3]'./ntur(1:n_mc); Vmc_low=-Vmc_up;
Ratemc_up=(Vmc_up-Vmc_low)/0.015; Ratemc_low=-(Vmc_up-Vmc_low)/0.015;

Imax=[45  45  45  45  45   48  55  55  55  52  52]'*1; c_cur_max=0.98;

 t_tran2D=3.5;

%pfres(1:n_mc)=0; pfres(n_mc+1)=750e-6;
%pfres(n_mc+2:npf)=[6.42411e+002 1e+010 4.01657e+002]'*1e-6;

tcont2=1.7; tgain_cont2=[0  tcont2 tcont2+0.3   1e6]'; gain_cont2= [0     0    1   1]';

kIpf_st=ones(n_mc,1); kIpf_st(5)=0;

Tfmc=0.015*1; spws=eye(n_mc)*ss(tf(1,[Tfmc 1])); spwsd=c2d(spws,0.01); [apows,bpows,cpows,dpows]=ssdata(spwsd);

%Ip_div=3.273; ref_ramp=1; t_eob=600; Ip_rd=4.4; amp_noise=0.35/sqrt(2e3*SimStep)*1e0;
Ip_div=3.273; ref_ramp=2; t_eob=600; Ip_rd=4.4; amp_noise=0.35/sqrt(2e3*SimStep)*1e0;
%Ip_div=3.4; ref_ramp=2; t_eob=600; Ip_rd=4.4; amp_noise=0.35/sqrt(2e3*SimStep)*1e0;

c_a_tpl1=5; c_a_tpl1_eob=1.5; c_a_tpl2=5; c_a_tpl_min=0.75; y0=0.75; c1_y0=1.8e0; c2_y0=4e0;
dt_contr_hl=4e0; dt_term=66; dtpl_term_l=70; Ip_0=1e-9;

%x_dat=[]; save data_kav x_dat;

cd Controllers

%fid=fopen('contr_vert_vs3.flat','r');
fid=fopen('contr_vert_vs3_3.flat','r');
n_state=fscanf(fid,'%i',1);
AB_contr=fscanf(fid,'%g',[n_state+2 n_state]); AB_contr=AB_contr';
CD_contr=fscanf(fid,'%g',[n_state+2 2]); CD_contr=CD_contr';
status=fclose(fid);
A_vs=AB_contr(1:n_state,1:n_state); B_vs=AB_contr(1:n_state,n_state+1:end);
C_vs=wz*CD_contr([2 1],1:n_state); D_vs=wz*CD_contr([2 1],n_state+1:end);

fid=fopen('contr_vert_vs3_hl.flat','r');
n_state=fscanf(fid,'%i',1);
AB_contr=fscanf(fid,'%g',[n_state+2 n_state]); AB_contr=AB_contr';
CD_contr=fscanf(fid,'%g',[n_state+2 2]); CD_contr=CD_contr';
status=fclose(fid);
A_vs_hl=AB_contr(1:n_state,1:n_state); B_vs_hl=AB_contr(1:n_state,n_state+1:end);
C_vs_hl=wz*CD_contr([2 1],1:n_state); D_vs_hl=wz*CD_contr([2 1],n_state+1:end);

A_lim=load('a_div_lim_2.flat');B_lim=load('b_div_lim_2.flat');
C_lim=load('c_div_lim_2.flat');D_lim=load('d_div_lim_2.flat');

A_div=load('a_div_vs3_vs1_10ms.flat');B_div=load('b_div_vs3_vs1_10ms.flat');
C_div=load('c_div_vs3_vs1_10ms.flat');D_div=load('d_div_vs3_vs1_10ms.flat');

A_divrd=load('a_rd_invess_10_10ms.flat');B_divrd=load('b_rd_invess_10_10ms.flat');
C_divrd=load('c_rd_invess_10_10ms.flat');D_divrd=load('d_rd_invess_10_10ms.flat');

A_currterm=load('a_cur_term_4.flat');B_currterm=load('b_cur_term_4.flat');
C_currterm=load('c_cur_term_4.flat');D_currterm=load('d_cur_term_4.flat');

load('start_ffv_vv_4');
load('cont_curr_1'); [Acd2,Bcd2,Ccd2,Dcd2]=ssdata(0*ssd);

cd ..

%load('start_ffv_vv_4_1');

t_Resistors=[0           3       3+SimStep   3.3   3.3+SimStep   13   13+SimStep   1e6;
          [rescs(1)   rescs(1)      0         0        0         0       0          0]/ntur(1)^2;
          [rescs(2)   rescs(2)      0         0        0         0       0          0]/ntur(2)^2;
          [rescs(3)   rescs(3)    0.12      0.12     0.12       0.12     0          0]/ntur(3)^2;
          [rescs(4)   rescs(4)      0         0        0         0       0          0]/ntur(4)^2;
          [rescs(5)   rescs(5)      0         0        0         0       0          0]/ntur(5)^2;
          [respf1     respf1        0         0        0         0       0          0]/ntur(6)^2;
          [   0         0           0         0        0         0       0          0];
          [   0         0           0         0        0         0       0          0];
          [   0         0           0         0        0         0       0          0];
          [   0         0           0         0        0         0       0          0];
          [respf6     respf6        0         0        0         0       0          0]/ntur(11)^2;
             1e3       1e3         1e3       1e3     750e-6   750e-6   750e-6     750e-6;
             
          [642.411   642.411     642.411   642.411  642.411   642.411  642.411  642.411]*1e-6;
             1e3        1e3        1e3       1e3      1e3        1e3     1e3        1e3;
          [401.657   401.657     401.657   401.657  401.657   401.657  401.657  401.657]*1e-6];
      
t_Resistors=t_Resistors';

volt_start=[tu*1e3 VU*diag(1./ntur(1:n_mc))];
volt_sc=[...
  7.5000e+003   -0.7327   -1.2128    0.7888   -2.3618   -0.2479   -3.1777   -4.1723   -5.6438   -7.1295   -7.8234    3.8977
  1.2000e+004   -0.6707   -1.4933   -0.7096   -1.3450   -0.5773   -1.5189   -4.1840   -6.1057   -5.7216   -2.0876   -1.1396
  1.8000e+004   -1.4864   -2.3884   -2.9770   -2.0140   -1.2635   -0.1764   -4.0490   -5.2966   -5.8411   -4.6797    0.2403
  5.0000e+004    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000
  9.0000e+008    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000];
volt=[volt_start; volt_sc]; volt(:,1)=volt(:,1)*1e-3;

pf0=diag(ntur(1:n_mc))*I0c;
scr_data=[...
    0               0      pf0'*1e-6     0.0000    0.0000    0.0000    0.0000
   1.75            0.66    interp1([0 3.5],[pf0'; Ipf_pr2]*1e-6,1.75)     0.0000    0.0000    0.0000    0.0000
   2.5             1.2     interp1([0 3.5],[pf0'; Ipf_pr2]*1e-6,2.5)      0.0000    0.0000    0.0000    0.0000
  3.5000e+000    1.6      Ipf_pr2*1e-6    0.0000    0.00    0.0000    0.00
  7.5000e+000    2.5000   18.5700   18.1882   13.4461   18.9666   15.1173    5.1834    0.8522   -0.8500   -0.1855   -1.0000    8.0000    0.0000    0.0000    0.0000    0.0000
  1.2000e+001    3.5000   17.0270   17.8172    9.2975   15.8399   15.3296    4.1982    0.6020   -1.1000   -0.5805   -2.2254   10.3234    0.0000    0.0000    0.0000    0.0000
  1.8000e+001    5.4000   14.9700   15.4193    3.0752   14.7189   15.1403    3.7528   -0.3912   -1.1000   -1.9752   -1.7103    9.4104    0.0000    0.0000    0.0000    0.0000
  5.0000e+001   15.0000    4.0000  -10.8000  -21.6400   -7.7080    5.5000    5.0210   -3.1300   -5.0270   -4.2720   -7.8310   17.3340    0.0000    0.0000    0.0000    0.0000
  5.8000e+002   15.0000    1.1808  -12.585   -24.292   -12.045     2.6705    4.0148   -3.0267   -5.5744   -4.7935   -7.7114   15.76      0.0000    0.0000    0.0000    0.0000
  6.6000e+002   15.0000    1.0024  -12.885   -24.456   -12.3       2.5892    3.8884   -3.0155   -5.5539   -4.8345   -7.6771   15.622     0.0000    0.0000    0.0000    0.0000
  6.6000e+003   15.0000    2.4574  -11.8850  -21.6460  -10.0770    2.5264    4.5547   -3.0821   -5.2758   -4.3947   -8.1489   17.5550    0.0000    0.0000    0.0000    0.0000];
scr_PF=scr_data(:,[1 3:2+n_mc]);

elong_ref=[...
  0.000000e+000    1.1
  3.500000e+000    1.1
  7.500000e+000    1.3100
  1.200000e+001    1.6700
  1.800000e+001    1.7200
  2.500000e+001    1.7700
  1.000000e+002    1.7700];
  
g1_ref=[...
  -1.500000e+001   25.6905
  3.500000e+000   25.6905
  1.200000e+001   25.6905
  5.000000e+001   25.6905
  
  t_eob                             25.6905
  t_eob+3.000000e+001*(dt_term/66)   6.6079
  t_eob+6.600000e+001*(dt_term/66)   6.6079];
  
g2_ref=[...
  -1.500000e+001   25.0000
  3.500000e+000   25.0000
  1.200000e+001   25.0000
  5.000000e+001   22.0110
  
  t_eob                              22.0110
  t_eob+5.000000e+000*(dt_term/66)   22.0110
  t_eob+6.600000e+001*(dt_term/66)   22.0110];
  
g3_ref=[...
  0         0
  1.208     0
  1.21      773.5
  3.49      773.5

  3.500000e+000  767.0000
  7.500000e+000  803.0000
  1.200000e+001  820.0000
  5.031399e+001  820.0000
  
  t_eob                             820.0000
  t_eob+3.000000e+001*(dt_term/66)  820.0000
  t_eob+5.000000e+001*(dt_term/66)  795.0000
  t_eob+6.600000e+001*(dt_term/66)  795.0000];
  
g4_ref=[...

  -1.500000e+001  148.900
  3.500000e+000   148.900
  1.200000e+001   25.0000
  1.797400e+001   24.0000
  5.000000e+001   22.7609
  
  t_eob                             22.7609
  t_eob+3.000000e+001*(dt_term/66)  70.
  t_eob+4.500000e+001*(dt_term/66)  138.0000
  t_eob+6.600000e+001*(dt_term/66)  241.0000];
  
g5_ref=[...
  -1.500000e+001  265.500
  3.500000e+000  265.500
  1.200000e+001  100.0000
  5.000000e+001   59.5995
  
  t_eob                              59.5995
  t_eob+3.000000e+001*(dt_term/66)  161.0000
  t_eob+4.500000e+001*(dt_term/66)  232.0000
  t_eob+6.600000e+001*(dt_term/66)  373.0000];
  
g6_ref=[...
  0              413.0000
  3.500000e+000  413.0000
  1.000000e+001  413.0000
  1.200000e+001  418.0000
  1.797400e+001  424.4000
  2.000000e+002  424.4000
  5.000000e+002  430.0000
  
  t_eob                             430.0000
  t_eob+3.000000e+001*(dt_term/66)  422.3000
  t_eob+6.600000e+001*(dt_term/66)  430.0000];
