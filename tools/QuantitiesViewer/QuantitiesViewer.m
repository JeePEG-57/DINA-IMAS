function QuantitiesViewer(varargin)

if nargin == 2
    shot = varargin{1};
    run = varargin{2};
else
    
    [MyPath,~,~] = fileparts(mfilename('fullpath'));

    addpath(MyPath);
    addpath([MyPath '/..']);

    IDSCoords = [MyPath '/../IDS_Coordinates.mat'];
    if exist(IDSCoords,'file')
        S = load(IDSCoords);
    else
        S = struct('Shot',170,'Run',5);
    end
    
    shot = S.Shot;
    run = S.Run; 
end


IDSData = ViewIDSDataAccess();

pf_active = IDSData.pf_active;
pf_passive = IDSData.pf_passive;
equilibrium = IDSData.equilibrium;
core_profiles = IDSData.core_profiles;


Ntime = length(equilibrium.time);
Nslice = length(equilibrium.time_slice);
if  Ntime ~= Nslice
    disp(['Length of equilibrium.time_slice (' num2str(Nslice) ') is not equal length of equilibrium.time (' num2str(Ntime) ').']);
    %return
end


X = zeros(1);
for i=1:Nslice
    X(i) = equilibrium.time_slice{1,i}.time;
end
%X = equilibrium.time';
XName = 'Time';
XUnits = 's';


ip = zeros(1);
li_3 = zeros(1);
volume = zeros(1);
area = zeros(1);

psi_axis = zeros(1);
magnetic_axis_r = zeros(1);
magnetic_axis_z = zeros(1);
q_axis = zeros(1);

q_95 = zeros(1);
w_mhd = zeros(1);

ne = zeros(1);
Te = zeros(1);
Ti = zeros(1);
Te_bnd = zeros(1);
Ti_bnd = zeros(1);

for i=1:Nslice
    
    ip(i) = equilibrium.time_slice{1,i}.global_quantities.ip;
    li_3(i) = equilibrium.time_slice{1,i}.global_quantities.li_3;
    volume(i) = equilibrium.time_slice{1,i}.global_quantities.volume;
    area(i) = equilibrium.time_slice{1,i}.global_quantities.area;

    psi_axis(i) = equilibrium.time_slice{1,i}.global_quantities.psi_axis;
    magnetic_axis_r(i) = equilibrium.time_slice{1,i}.global_quantities.magnetic_axis.r;
    magnetic_axis_z(i) = equilibrium.time_slice{1,i}.global_quantities.magnetic_axis.z;
    q_axis(i) = equilibrium.time_slice{1,i}.global_quantities.q_axis;   

    q_95(i) = equilibrium.time_slice{1,i}.global_quantities.q_95;
    w_mhd(i) = equilibrium.time_slice{1,i}.global_quantities.w_mhd;
    
    %n = length(core_profiles.profiles_1d{1,i}.grid.rho_tor_norm);

    ne(i) = core_profiles.profiles_1d{1,i}.n_e(2);
    Te(i) = core_profiles.profiles_1d{1,i}.t_e(2);
    Ti(i) = core_profiles.profiles_1d{1,i}.t_i_average(2);
    
    Te_bnd(i) = core_profiles.profiles_1d{1,i}.t_e(end);
    Ti_bnd(i) = core_profiles.profiles_1d{1,i}.t_i_average(end);
    
end


r0 = equilibrium.vacuum_toroidal_field.r0;
b0 = equilibrium.vacuum_toroidal_field.b0';


t1 = 1;
t2 = Nslice;

% Time2 = 85.0;
% for i=t1:Nslice
%     if core_profiles.profiles_1d{1,i}.time > Time2
%        t2 = i;
%        break;
%     end
% end

%---------------------------------------

figure(1);



subplot(1,2,1);
PlotQuantity(X,Te_bnd,XName,XUnits,'T_e _b_n_d','eV',t1,t2);

subplot(1,2,2);
PlotQuantity(X,Ti_bnd,XName,XUnits,'T_i _b_n_d','eV',t1,t2);

%subplot(2,2,1);
%PlotQuantity(X,Te,XName,XUnits,'T_e _a_x_i_s','eV',t1,t2);

%subplot(2,2,3);
%PlotQuantity(X,Ti,XName,XUnits,'T_i _a_x_i_s','eV',t1,t2);


figure(2);

subplot(2,2,1);
PlotQuantity(X,ip,XName,XUnits,'I_p','A',t1,t2);


subplot(2,2,2);
PlotQuantity(X,ne,XName,XUnits,'N_e _a_x_i_s','m^-^3',t1,t2);


subplot(2,2,3);
PlotQuantity(X,magnetic_axis_z,XName,XUnits,'Z','m',t1,t2);



subplot(2,2,4);
PlotQuantity(X,magnetic_axis_r,XName,XUnits,'R','m',t1,t2);




%-------------------------------------------------------

figure(3);

subplot(2,2,1);
PlotQuantity(X,li_3,XName,XUnits,'li 3','-',t1,t2);


subplot(2,2,2);
PlotQuantity(X,q_axis,XName,XUnits,'q_a_x_i_s','-',t1,t2);


subplot(2,2,3);
PlotQuantity(X,q_95,XName,XUnits,'q_9_5','-',t1,t2);


subplot(2,2,4);
PlotQuantity(X,area,XName,XUnits,'Area','m^2',t1,t2);




%-------------------------------------------------------

% figure(4);
% 
% subplot(2,2,1);
% PlotQuantity(X,volume,XName,XUnits,'Volume','m^3');
% 
% 
% subplot(2,2,2);
% PlotQuantity(X,b0,XName,XUnits,['B_0 for R = ' num2str(r0) ' m'],'T');
% 
% 
% subplot(2,2,3);
% PlotQuantity(X,w_mhd,XName,XUnits,'W_M_H_D','J');
%
%
% subplot(2,2,4);
% PlotQuantity(X,psi_axis,XName,XUnits,'psi_a_x_i_s','Wb');
end


function PlotQuantity(x,y,Namex,Unitsx,Namey,Unitsy,t1,t2)

if size(x) ~= size(y)
    disp('Size of x != size of y');
    return 
end

plot(x(t1:t2),y(t1:t2));
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