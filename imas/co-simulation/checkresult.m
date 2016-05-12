addpath /work/imas/projects/ual/2.0/matlabinterface/;
idx=imas_open('ids',150,101);
equi=ids_get(idx,'equilibrium');
figure
plot(equi.time,equi.global_quantities.magnetic_axis.r);
title('magnetic axis, major radius (m)');
figure
plot(equi.time,equi.global_quantities.magnetic_axis.z);
title('magnetic axis, height (m)');

%for i=1,length(equi.time)
    