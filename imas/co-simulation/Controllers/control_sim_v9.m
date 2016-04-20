
n_mc=11;

ntur=[554,554,554,554,554  248.6 115.2 185.9 169.9 216.8  459.4 1]';
wz=[[0 0 0 0 0 0 -1 -1 1 1 0 0]'./ntur [0 0 0 0 0 0 0 0 0 0 0 1]'];

VS1_up=6e3; VS1_low=-VS1_up;
VS3_up=575; VS3_low=-VS3_up;

%Vmc_up=[2.1e3 2.1e3 4.2e3 2.1e3 2.1e3  2.1e3 3.15e3*ones(1,4) 2.1e3]'./ntur(1:n_mc); Vmc_low=-Vmc_up;
Vmc_up=[2.1e3 2.1e3 4.2e3 2.1e3 2.1e3  2.1e3 3.15e3*ones(1,4) 2.1e3]'; Vmc_low=-Vmc_up;

Ratemc_up=(Vmc_up-Vmc_low)/0.015; Ratemc_low=-(Vmc_up-Vmc_low)/0.015;

Imax=[45  45  45  45  45   48  55  55  55  52  52]'*1; c_cur_max=0.98;

 t_tran2D=3.5;

k_gaplim=[1 1 1 0]'; 

tcont2=1.7; tgain_cont2=[0  tcont2 tcont2+0.3   1e6]'; gain_cont2= [0     0    1   1]';

kIpf_st=ones(n_mc,1); kIpf_st(5)=0;

Tfmc=0.015*1; %spws=eye(n_mc)*ss(tf(1,[Tfmc 1])); spwsd=c2d(spws,SimStep); [apows,bpows,cpows,dpows]=ssdata(spwsd);

Ip_div=3.3; ref_ramp=3; t_eob=80; Ip_rd=0; amp_noise=1.05/sqrt(20)*1e0;

c_a_tpl1=5; c_a_tpl1_eob=1.5; c_a_tpl2=5; c_a_tpl_min=0.75; y0=1; c1_y0=1.8e0; c2_y0=4e0;
c_eob=0.9999; dtpl_term_l=28; Ip_0=1e-4; dt_end_sim=200;

% Parameters should be account by Dina
Ics1_eob=-30; t_eob2=25; dt_contr_hl=0; cIp_end=1.5; dt_end=dtpl_term_l*cIp_end/7.5;

cd Controllers

fid=fopen('contr_vert_vs3_3.flat','r');
n_state=fscanf(fid,'%i',1);
AB_contr=fscanf(fid,'%g',[n_state+2 n_state]); AB_contr=AB_contr';
CD_contr=fscanf(fid,'%g',[n_state+2 2]); CD_contr=CD_contr';
fclose(fid);
A_vs=AB_contr(1:n_state,1:n_state); B_vs=AB_contr(1:n_state,n_state+1:end);
%C_vs=wz*CD_contr([2 1],1:n_state); D_vs=wz*CD_contr([2 1],n_state+1:end);
C_vs=CD_contr([2 1],1:n_state); D_vs=CD_contr([2 1],n_state+1:end);

fid=fopen('contr_vert_vs3_hl.flat','r');
n_state=fscanf(fid,'%i',1);
AB_contr=fscanf(fid,'%g',[n_state+2 n_state]); AB_contr=AB_contr';
CD_contr=fscanf(fid,'%g',[n_state+2 2]); CD_contr=CD_contr';
fclose(fid);
A_vs_hl=AB_contr(1:n_state,1:n_state); B_vs_hl=AB_contr(1:n_state,n_state+1:end);
%C_vs_hl=wz*CD_contr([2 1],1:n_state); D_vs_hl=wz*CD_contr([2 1],n_state+1:end);
C_vs_hl=CD_contr([2 1],1:n_state); D_vs_hl=CD_contr([2 1],n_state+1:end);

contr_lim_vs1=load('contr_lim_vs3_10ms.flat'); n_state=50;
A_lim=contr_lim_vs1(1:n_state,1:n_state); B_lim=contr_lim_vs1(1:n_state,1+n_state:n_state+20);
C_lim=contr_lim_vs1(n_state+1:n_mc+n_state,1:n_state);D_lim=contr_lim_vs1(n_state+1:n_mc+n_state,1+n_state:n_state+20);

%contr_div_vs3=load('contr_div_vs3_10ms.flat'); n_state=50;
contr_div_vs3=load('contr_div_vs3_10ms_2.flat'); n_state=50;
A_div=contr_div_vs3(1:n_state,1:n_state); B_div=contr_div_vs3(1:n_state,1+n_state:n_state+20);
C_div=contr_div_vs3(n_state+1:n_mc+n_state,1:n_state);D_div=contr_div_vs3(n_state+1:n_mc+n_state,1+n_state:n_state+20);

contr_divrd_vs3=load('contr_divrd_vs3_10ms.flat'); n_state=40;
A_divrd=contr_divrd_vs3(1:n_state,1:n_state); B_divrd=contr_divrd_vs3(1:n_state,1+n_state:n_state+20);
C_divrd=contr_divrd_vs3(n_state+1:n_mc+n_state,1:n_state);D_divrd=contr_divrd_vs3(n_state+1:n_mc+n_state,1+n_state:n_state+20);

contr_curr=load('contr_cur_term.flat'); n_state=40;
A_currterm=contr_curr(1:n_state,1:n_state); B_currterm=contr_curr(1:n_state,1+n_state:n_state+20);
C_currterm=contr_curr(n_state+1:n_mc+n_state,1:n_state);D_currterm=contr_curr(n_state+1:n_mc+n_state,1+n_state:n_state+20);

load('start_ffv_vv_2'); tIpfpr=tIpfpr(1:5:end,:); I0c=tIpfpr(1,2:end)';

load('cont_curr_1'); [Acd2,Bcd2,Ccd2,Dcd2]=ssdata(1*ssd);

cd ..

t_Resistors=[0           3       3+SimStep   3.5   3.5+SimStep   13   13+SimStep   1e6;
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
  7.5000e+003   -0.7029   -1.9498   -2.7279   -1.2072   -0.4726   -1.0794   -2.6288   -6.5197   -7.7771   -3.8710   -1.3654
  1.2000e+004   -1.0038   -2.7391   -3.7708   -2.2039   -0.8717   -2.1070   -6.1606   -1.6425  -11.9214   -3.7730    1.0005
  1.8000e+004   -0.7819   -2.1018   -5.2083   -1.5995   -0.6905   -1.6028   -4.8462   -4.7786  -10.1942   -2.9804   -0.5622
  2.5000e+004    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000
  9.0000e+008    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000];
volt=[volt_start; volt_sc]; volt(:,1)=volt(:,1)*1e-3;

pf0=I0c;
t_Ipl= [0   1.75   2.5   3.5]'; 
Ipl_pr=[0   0.66   1.2   1.6]'; 

scr_data=[...
    
  tIpfpr(:,1) interp1(t_Ipl,Ipl_pr,tIpfpr(:,1)) tIpfpr(:,2:end)*1e-6 tIpfpr(:,1:4)*0
  
  7.5000e+000    2.4800   13.6621    8.0000    8.7523    9.6604    8.3308    5.4042   -0.3684   -0.6898   -0.0729   -2.4717    9.4529    0.0000    0.0000    0.0000    0.0000
  1.2000e+001    3.5400   13.4258    6.0000    4.7625    9.0198    8.1520    5.2565   -0.4627   -1.0716   -0.5837   -2.7763    9.2411    0.0000    0.0000    0.0000    0.0000
  1.8000e+001    5.3300   13.1570    1.0000    0.5820    5.4039    7.2068    4.6657   -1.3741   -0.7451   -1.9226   -3.2144   10.4785    0.0000    0.0000    0.0000    0.0000
  2.5000e+001    7.5500   12.8189   -3.0000   -4.6058    2.9818    6.4519    4.1831   -2.0884   -0.9559   -3.1664   -3.4622   10.6975    0.0000    0.0000    0.0000    0.0000

     50.00       7.5500   9.8435    -5.6155   -8.9989   -0.13199   5.6523    1.94     -1.2242   -2.1551   -3.0836   -1.9909    6.3379    0.0000    0.0000    0.0000    0.0000
     100.00      7.5500   2.6375    -3.7621  -17.408    -3.9789    3.0542   -2.6269   -0.74327  -2.8073   -3.1615   -0.62123   1.4526    0.0000    0.0000    0.0000    0.0000
     300.00      7.5500   2.6375    -3.7621  -17.408    -3.9789    3.0542   -2.6269   -0.74327  -2.8073   -3.1615   -0.62123   1.4526    0.0000    0.0000    0.0000    0.0000];
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
  -1.500000e+001   29.0000
  3.500000e+000   29.0000 
  1.200000e+001   29.0000 
  1.800000e+001   25.6905 
  2.500000e+001   25.6905 
 15.000000e+002   25.6905];
  
g1_ref_term=[...
  0                           25.6905
  3.000000e+001*(dtpl_term_l/66)   6.6079
  6.600000e+001*(dtpl_term_l/66)   6.6079];
  
g2_ref=[...
  -1.500000e+001   28.0000
  3.500000e+000   28.0000 
  1.200000e+001   28.0000 
  1.800000e+001   22.0110 
  2.500000e+001   22.0110 
 15.000000e+002   22.0110];
  
g2_ref_term=[...
  0                            22.0110
  5.000000e+000*(dtpl_term_l/66)   22.0110
  6.600000e+001*(dtpl_term_l/66)   22.0110];
  
g3_ref=[...
  0         0
  1.208     0
  1.21      773.5
  3.49      773.5

  3.500000e+000  758.8000
  7.500000e+000  802.0000
  1.200000e+001  815.0000
  1.800000e+001  819.5000
  2.500000e+001  820.0000
 15.000000e+002  820.0000];
  
g3_ref_term=[...
  0                           820.0000
  3.000000e+001*(dtpl_term_l/66)  820.0000
  4.500000e+001*(dtpl_term_l/66)  808.0000
  5.000000e+001*(dtpl_term_l/66)  795.0000
  6.600000e+001*(dtpl_term_l/66)  795.0000];
  
g4_ref=[...

  -1.500000e+001   157.2000
  3.500000e+000   157.2000 
  7.500000e+000   72.0000  
  1.200000e+001   45.0000  
  1.800000e+001   29.5000  
  2.500000e+001   15.0000  
 15.000000e+002   15.0000];
  
g4_ref_term=[...
  0                           15.
  3.000000e+001*(dtpl_term_l/66)  70.
  4.500000e+001*(dtpl_term_l/66)  138.0000
  5.250000e+001*(dtpl_term_l/66)  185.0000
  5.850000e+001*(dtpl_term_l/66)  213.0000
  6.600000e+001*(dtpl_term_l/66)  213.0000];
  
g5_ref=[...
  -1.500000e+001  265.5000
  3.500000e+000  265.5000 
  7.500000e+000  162.0000 
  1.200000e+001  112.0000 
  1.800000e+001  88.0000  
  2.500000e+001  60.0000  
 15.000000e+002  60.0000];
  
g5_ref_term=[...
  0                            59.5995
  4.500000e+001*(dtpl_term_l/66)  275.0000
  5.250000e+001*(dtpl_term_l/66)  312.0000
  5.850000e+001*(dtpl_term_l/66)  345.0000
  6.600000e+001*(dtpl_term_l/66)  345.0000];
  
g6_ref=[...
  0              410.5000
  3.500000e+000  410.5000
  7.500000e+000  410.5000
  1.200000e+001  416.0000
  1.800000e+001  419.4000
  2.500000e+001  419.4000
 15.000000e+003  419.4000];
  
g6_ref_term=[...
  0                           0
  3.000000e+001*(dtpl_term_l/66.6)  -7.2
  4.500000e+001*(dtpl_term_l/66.6)  -7.2
  4.950000e+001*(dtpl_term_l/66.6)  -12.1
  5.250000e+001*(dtpl_term_l/66.6)  -14.6
  6.660000e+001*(dtpl_term_l/66.6)  -14.6];

%g6_ref_term=[...
%  0                           0
%  3.000000e+001*(dtpl_term_l/66)  6
%  6.600000e+001*(dtpl_term_l/66)  0];
