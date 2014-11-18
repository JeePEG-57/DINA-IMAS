%shot=108;
run=1;

%i=1;

switch i
   case 1
       disp('EmCoupling');
  a=ViewEmCoupling(shot, run)
   case 2
       disp('CoreProfiles');
a=ViewCoreProfiles(shot, run)
   case 3
       disp('DINA');
       a=ViewDINA(shot, run)
   case 4
       disp('Equilibrium');
       a=ViewEquilibrium(shot, run)
   case 5
       disp('Magnetics');
       a=ViewMagnetics(shot, run)
   case 6
       disp('PFActive');
       a=ViewPFActive(shot, run)
   case 7
       disp('PFPassive');
       a=ViewPFPassive(shot, run)
   case 8
       disp('CoreTransport');
       a=ViewCoreTransport(shot, run)

   case 9
       disp('CoreSources');
       a=ViewCoreSources(shot, run)
otherwise
    
  disp('switch is wrong');
end
    


