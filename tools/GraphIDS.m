function GraphIDS

shot = 150;
run = 22;

pf_active = LoadIDS(shot, run, 'pf_active');
pf_passive = LoadIDS(shot, run, 'pf_passive');
equilibrium = LoadIDS(shot, run, 'equilibrium');
core_profiles = LoadIDS(shot, run, 'core_profiles');


assignin('base','pf_active',pf_active);
assignin('base','pf_passive',pf_passive);
assignin('base','pf_equilibrium',equilibrium);
assignin('base','pf_core_profiles',core_profiles);


X = equilibrium.time;
XName = 'Time';
XUnits = 's';


%---------------------------------------

figure(1);

subplot(2,2,1);
PlotQuantity(X,equilibrium.global_quantities.ip,XName,XUnits,'I_p','A');


subplot(2,2,2);
PlotQuantity(X,equilibrium.global_quantities.li_3,XName,XUnits,'li 3','???');


subplot(2,2,3);
PlotQuantity(X,equilibrium.global_quantities.volume,XName,XUnits,'Volume','m^3');


subplot(2,2,4);
PlotQuantity(X,equilibrium.global_quantities.area,XName,XUnits,'Area','m^2');


%-------------------------------------------------------

figure(2);

subplot(2,2,1);
PlotQuantity(X,equilibrium.global_quantities.psi_axis,XName,XUnits,'psi_a_x_i_s','Wb');


subplot(2,2,2);
PlotQuantity(X,equilibrium.global_quantities.magnetic_axis.r,XName,XUnits,'r','m');


subplot(2,2,3);
PlotQuantity(X,equilibrium.global_quantities.magnetic_axis.z,XName,XUnits,'z','m');


subplot(2,2,4);
PlotQuantity(X,equilibrium.global_quantities.q_axis,XName,XUnits,'q_a_x_i_s','-');

%-------------------------------------------------------

figure(3);

subplot(2,2,1);
PlotQuantity(X,equilibrium.global_quantities.q_95,XName,XUnits,'q_9_5','-');


subplot(2,2,2);
PlotQuantity(X,equilibrium.global_quantities.vacuum_toroidal_field.r0,XName,XUnits,'r_B_0','m');


subplot(2,2,3);
PlotQuantity(X,equilibrium.global_quantities.vacuum_toroidal_field.b0,XName,XUnits,'B_0','T');


subplot(2,2,4);
PlotQuantity(X,equilibrium.global_quantities.w_mhd,XName,XUnits,'W_M_H_D','J');

end


function PlotQuantity(x,y,Namex,Unitsx,Namey,Unitsy)

plot(x,y);
title(Namey);
if strcmp(Unitsx, '-') || isempty(Unitsx)
    xlabel(Namex);
else
    xlabel([Namex ', ' Unitsx]);
end
if strcmp(Unitsy, '-') || isempty(Unitsy)
    ylabel(Namey)
else
    ylabel([Namey ', ' Unitsy]);
end

end