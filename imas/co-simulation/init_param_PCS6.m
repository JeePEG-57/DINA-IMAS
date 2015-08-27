% from dina_matlab_1_r2

%  clear all; close all;
%  !del for042
%  !del p_data1
%  !del psi_data
%  !del plasma.dat
%  !del plasma_start.dat
%  
%  !a_del

add_path_iter;

%load iter_v80_may_16_2;

  Decim=1;
  DecimBoundary=1;
  DecimControl=1;
  DecimDiag=1;
  DecimEquil =1;
  DecimPF =1;
  DecimProfiles  =1;
  DecimShape  =1;
  DecimTransport =1;

SimStep=2e-3;


key_kav(1:25)=1;
vec_kav(1:30)=1.;

key_kav(1:25)=100;


key_kav(4)=0;  % print

key_kav(6)=15;  % input1
key_kav(7)=36;  % input2
key_kav(8)=54;  % input3


c_input1(1:2)=28;
c_input2(1:15)=38;

c_input1_kav(7)=10;
c_input1_kav(8)=6;

%	in_port1=key_mat[5];
%	in_port2=key_mat[6];
%	in_port3=key_mat[7];

%	out_port1=key_mat[10];
%	out_port2=key_mat[11];
%	out_port3=key_mat[12];
%	out_port4=key_mat[13];

key_kav(11)=2;   %  output1
key_kav(12)=15;  %  output2


key_imas(1:25)=1;
vec_imas(1:30)=1.;

key_imas(1:25)=100;


%key_imas(4)=1;  % print
key_imas(4)=3;  % print
%key_imas(4)=0;  % print

key_imas(6)=2;  % input1
key_imas(7)=15;  % input2
key_imas(8)=54;  % input3

key_imas(11)=15;       %  output1

npf=15;
ncam=100;
n_gaps=6;

key_imas(12)=n_gaps+npf+ncam+2;  %  output2
key_imas(13)=32;   %  output3

DecimShape=1;

i_65129=1;  %  33x65 grid
%i_65129=1   %  65x129 grid
if(i_65129 ==1)
  %  load tokamakdata_65129
    xuyu=load('limpnt_new_3.dat'); xu=xuyu(:,1)'; yu=xuyu(:,2)';
    load diagnostics
end

%  From here  for Kavin ...
control_sim_v3;

EqTime=0;

write_tok
write_pfres

tt_dw=600.e3;
write_tt_tran

%SimTime=1.2;
SimTime=100; Time_stop=SimTime;

for i=1:npf
    pfres(i)=0.;
Voltages(i)=pf0(i)*pfres(i);
end


V_in1(1:15)=1.;
V_in2(1:123)=10.;

load V_inp;

V_in1(9)=0.2;


%t_sw=4.2597598E+001;

% half toroidal field
%vec(8)=2.65;




%load /home/ITER/medveds/public/DINA_PCS/imas_s138/ITERIS/DINA_IMAS/PCS/SignalDefinitions.mat
%load /home/ITER/medveds/public/DINA_PCS/imas_s138/ITERIS/DINA_IMAS/PCS/PCS_JBL_001_mat.mat
%addpath /home/ITER/medveds/public/DINA_PCS/imas_s138/ITERIS/Matlab_Utilities

execiloop=1;   % initialise a loop counter

%IndexIPF = listmatch(SignalDefinitions.CP,{'Ics3u' 'Ics2u' 'Ics1ul' 'Ics2l' 'Ics3l' 'Ipf1' 'Ipf2' 'Ipf3'...
%            'Ipf4' 'Ipf5' 'Ipf6' 'Ivs1' 'Ivs2' 'Ivs3'});
%IndexUPF = listmatch(SignalDefinitions.Actuators,{'Vcs3u' 'Vcs2u' 'Vcs1ul' 'Vcs2l' 'Vcs3l'  'Vpf1' ...
%                        'Vpf2'  'Vpf3'  'Vpf4'  'Vpf5'  'Vpf6'  'Vvs1'  'Vvs2' 'Vvs3'});
%IndexIRZ = listmatch(SignalDefinitions.CP,{'Ip','IpRj', 'IpZj'});
%IndexGaps = listmatch(SignalDefinitions.CP,{'IpGap1' 'IpGap2' 'IpGap3' 'IpGap4' 'IpGap5' 'IpGap6'});


