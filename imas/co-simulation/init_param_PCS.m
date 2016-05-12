load /home/ITER/huynhp/public/DINA_PCS/imas_s138/ITERIS/DINA_IMAS/PCS/SignalDefinitions.mat
load /home/ITER/huynhp/public/DINA_PCS/imas_s138/ITERIS/DINA_IMAS/PCS/PCS_JBL_001_mat.mat
addpath /home/ITER/huynhp/public/DINA_PCS//imas_s138/ITERIS/Matlab_Utilities

execiloop=1;   % initialise a loop counter

IndexIPF = listmatch(SignalDefinitions.CP,{'Ics3u' 'Ics2u' 'Ics1ul' 'Ics2l' 'Ics3l' 'Ipf1' 'Ipf2' 'Ipf3'...
            'Ipf4' 'Ipf5' 'Ipf6' 'Ivs1' 'Ivs2' 'Ivs3'});
IndexUPF = listmatch(SignalDefinitions.Actuators,{'Vcs3u' 'Vcs2u' 'Vcs1ul' 'Vcs2l' 'Vcs3l'  'Vpf1' ...
                        'Vpf2'  'Vpf3'  'Vpf4'  'Vpf5'  'Vpf6'  'Vvs1'  'Vvs2' 'Vvs3'});
IndexIRZ = listmatch(SignalDefinitions.CP,{'Ip','IpRj', 'IpZj'});
IndexGaps = listmatch(SignalDefinitions.CP,{'IpGap1' 'IpGap2' 'IpGap3' 'IpGap4' 'IpGap5' 'IpGap6'});


