function AddPFGeometry(Shot, Run, Occurence)


S = load('env_VS_coils1.mat');

Coils = S.device.coils;
Vessel = S.device.vessel;

assignin('base', 'Coils', Coils);
assignin('base', 'Vessel', Vessel);


PFActiveString = 'pf_active';
PFPassiveString = 'pf_passive';

if nargin == 3
    if Occurence > 0
        PFActiveString = [PFActiveString '/' num2str(Occurence)];
        PFPassiveString = [PFPassiveString '/' num2str(Occurence)];
    end
elseif nargin == 2
else
    disp('Invalid inputs number, must be 2 or 3.');
    return
end


disp('Loading IDS...');

pf_active = LoadIDS(Shot, Run, PFActiveString);
pf_passive = LoadIDS(Shot, Run, PFPassiveString);

assignin('base', 'pf_active', pf_active);
assignin('base', 'pf_passive', pf_passive);

disp('IDS loaded.');


if length(pf_active.coil) ~= max(Coils.pf_num)
    disp('Coils amount error.');
    return
end

if length(pf_passive.loop) ~= Vessel.ncam
    disp('Vessel amount error.');
    return
end

for i=1:length(pf_active.coil)
    
    pf_active.coil{i}.element = {};
    
    %pf_active.coil{Coils.pf_num(i)}.resistance = 0.0;
    
end



for i=1:length(Coils.r)
    
    S = GetCommonStructure(Coils,i,1);

    r = zeros(1,5);
    z = zeros(1,5);

    r(1)=S.rc-0.5*(S.dr*cos(S.Beta)+S.dz*cos(S.Alfa));
    z(1)=S.zc-0.5*(S.dr*sin(S.Beta)+S.dz*sin(S.Alfa));

    r(2)=r(1)+S.dr*cos(S.Beta);
    z(2)=z(1)+S.dr*sin(S.Beta);


    r(3)=r(1)+S.dr*cos(S.Beta)+S.dz*cos(S.Alfa);
    z(3)=z(1)+S.dr*sin(S.Beta)+S.dz*sin(S.Alfa);


    r(4)=r(1)+S.dz*cos(S.Alfa);
    z(4)=z(1)+S.dz*sin(S.Alfa);

    r(5)=r(1);
    z(5)=z(1);
 
    
    j = length(pf_active.coil{Coils.pf_num(i)}.element) + 1;
    
    %pf_active.coil{Coils.pf_num(i)}.resistance = pf_active.coil{Coils.pf_num(i)}.resistance + S.Resistance;
        
    pf_active.coil{Coils.pf_num(i)}.element{j}.turns_with_sign = Coils.nt(i);
    
    pf_active.coil{Coils.pf_num(i)}.element{j}.area = S.dr*S.dz*sin(abs(S.Alfa - S.Beta));
    
    pf_active.coil{Coils.pf_num(i)}.element{j}.geometry.geometry_type = 1; % 0 - RZ; 1 - RZDRDZ
    
    pf_active.coil{Coils.pf_num(i)}.element{j}.geometry.outline.r = r;
    pf_active.coil{Coils.pf_num(i)}.element{j}.geometry.outline.z = z;
    
    pf_active.coil{Coils.pf_num(i)}.element{j}.geometry.oblique.r = S.rc;
    pf_active.coil{Coils.pf_num(i)}.element{j}.geometry.oblique.z = S.zc;
    pf_active.coil{Coils.pf_num(i)}.element{j}.geometry.oblique.length = max([S.dr S.dz]);
    pf_active.coil{Coils.pf_num(i)}.element{j}.geometry.oblique.thickness = min([S.dr S.dz]);
    pf_active.coil{Coils.pf_num(i)}.element{j}.geometry.oblique.alpha = S.Alfa;
    pf_active.coil{Coils.pf_num(i)}.element{j}.geometry.oblique.beta = S.Beta;
    
    pf_active.coil{Coils.pf_num(i)}.element{j}.geometry.rectangle.r = S.rc;
    pf_active.coil{Coils.pf_num(i)}.element{j}.geometry.rectangle.z = S.zc;
    pf_active.coil{Coils.pf_num(i)}.element{j}.geometry.rectangle.width = S.dr*abs(cos(S.Beta)) + S.dz*abs(cos(S.Alfa));   
    pf_active.coil{Coils.pf_num(i)}.element{j}.geometry.rectangle.height = S.dr*abs(sin(S.Beta)) + S.dz*abs(sin(S.Alfa));
    
    
end




for i=1:length(Vessel.rc)
    
    S = GetCommonStructure(Vessel,i,0);

    r = zeros(1,5);
    z = zeros(1,5);

    r(1)=S.rc-0.5*(S.dr*cos(S.Beta)+S.dz*cos(S.Alfa));
    z(1)=S.zc-0.5*(S.dr*sin(S.Beta)+S.dz*sin(S.Alfa));

    r(2)=r(1)+S.dr*cos(S.Beta);
    z(2)=z(1)+S.dr*sin(S.Beta);


    r(3)=r(1)+S.dr*cos(S.Beta)+S.dz*cos(S.Alfa);
    z(3)=z(1)+S.dr*sin(S.Beta)+S.dz*sin(S.Alfa);


    r(4)=r(1)+S.dz*cos(S.Alfa);
    z(4)=z(1)+S.dz*sin(S.Alfa);

    r(5)=r(1);
    z(5)=z(1);
 
    
    %pf_passive.loop{i}.resistance = S.Resistance;
        
    
    pf_passive.loop{i}.area = S.dr*S.dz*sin(abs(S.Alfa - S.Beta));
    
    pf_passive.loop{i}.geometry.geometry_type = 1; % 0 - RZ; 1 - RZDRDZ
    
    pf_passive.loop{i}.geometry.outline.r = r;
    pf_passive.loop{i}.geometry.outline.z = z;
    
    pf_passive.loop{i}.geometry.oblique.r = S.rc;
    pf_passive.loop{i}.geometry.oblique.z = S.zc;
    pf_passive.loop{i}.geometry.oblique.length = max([S.dr S.dz]);
    pf_passive.loop{i}.geometry.oblique.thickness = min([S.dr S.dz]);
    pf_passive.loop{i}.geometry.oblique.alpha = S.Alfa;
    pf_passive.loop{i}.geometry.oblique.beta = S.Beta;
    
    pf_passive.loop{i}.geometry.rectangle.r = S.rc;
    pf_passive.loop{i}.geometry.rectangle.z = S.zc;
    pf_passive.loop{i}.geometry.rectangle.width = S.dr*abs(cos(S.Beta)) + S.dz*abs(cos(S.Alfa));   
    pf_passive.loop{i}.geometry.rectangle.height = S.dr*abs(sin(S.Beta)) + S.dz*abs(sin(S.Alfa));
    
    
end


disp('Saving IDS...');

SaveIDS(Shot, Run, PFActiveString, pf_active);
SaveIDS(Shot, Run, PFPassiveString, pf_passive);

disp('IDS saved.');
end



function [S] = GetCommonStructure(S0,i,IsCoil)

S = struct('rc',0,'zc',0,'dr',0,'dz',0,'Alfa',0,'Beta',0,'Resistance',0);

if IsCoil
   S.rc = S0.r(i);
   S.zc = S0.z(i);
   S.dr = S0.dr(i);
   S.dz = S0.dz(i);
   S.Alfa = S0.alpha(i);
   S.Beta = S0.beta(i);
   S.Resistance = S0.res(i);
else
   S.rc = S0.rc(i);
   S.zc = S0.zc(i);
   S.dr = S0.dl(i);
   S.dz = S0.dh(i);
   S.Alfa = S0.alpha(i);
   S.Beta = S0.beta(i);
   S.Resistance = S0.rcam(i);   
end

end