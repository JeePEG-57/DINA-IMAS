clear all; close all;
%!del for042
%!del p_data1
%!del psi_data
%!del plasma.dat
%!del tok_data
%!del pfc_new.dat
%!del volt_new.dat

%!a_del

WriteTokamakData

add_path_iter;

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
%key_imas(4)=3;  % print
key_imas(4)=0;  % print

key_imas(6)=2;  % input1
%key_imas(7)=15;  % input2
key_imas(7)=38;  % input2
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
    load diagnostics
end

%  From here  for Kavin ...
control_sim_v8;

EqTime=0;

write_tok
write_pfres

tt_dw=t_eob*1e3;
write_tt_tran

SimTime=1e8; Time_stop=1530;

%iter_scen_vs1vs3_10_R2013a;
