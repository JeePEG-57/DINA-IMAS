function DrawStatic(hObject, Axes)

handles = guidata(hObject);

axes(Axes);


Frame = 1;


% Read limiter line
Lszx = size(handles.Equilibrium.time_slice{1,Frame}.coordinate_system.r);
Lszy = size(handles.Equilibrium.time_slice{1,Frame}.coordinate_system.z);
if length(Lszx) == 2 && length(Lszy) == 2
    xu = 1.e2*handles.Equilibrium.time_slice{1,Frame}.coordinate_system.r(:,1);
    yu = 1.e2*handles.Equilibrium.time_slice{1,Frame}.coordinate_system.z(:,1);
else
    xu = [NaN];
    yu = [NaN];
end


lw=1; %LineWidth
fs=9; %FontSize

hold on
      

xpfact = [NaN];
ypfact = [NaN];
for i=1:length(handles.PFActive.coil)
    for j=1:length(handles.PFActive.coil{i}.element)
               
        xpfact = [xpfact NaN handles.PFActive.coil{i}.element{j}.geometry.outline.r'];
        ypfact = [ypfact NaN handles.PFActive.coil{i}.element{j}.geometry.outline.z'];
        
    end
end


xpfpass = [NaN];
ypfpass = [NaN];
for i=1:length(handles.PFPassive.loop)
    
    xpfpass = [xpfpass NaN handles.PFPassive.loop{i}.geometry.outline.r'];
    ypfpass = [ypfpass NaN handles.PFPassive.loop{i}.geometry.outline.z'];
 
end


xpfact = xpfact*1.e2;
ypfact = ypfact*1.e2;

xpfpass = xpfpass*1.e2;
ypfpass = ypfpass*1.e2;

% h = line(xpfact,ypfact);
% set(h,'Color',[1 0 0]);
% set(h,'LineWidth',2);
% 
% h = line(xpfpass,ypfpass);
% set(h,'Color',[0 0 0]);
% set(h,'LineWidth',1);

plot(xpfact,ypfact,'Color',[0 0 1],'LineWidth',2);
plot(xpfpass,ypfpass,'Color',[0 0 0],'LineWidth',1);


plot(xu,yu,'Color',[0 0 0],'LineWidth',3); % limiter
   
   
xlabel('r [cm]','FontSize',fs);
ylabel('z [cm]','FontSize',fs);
    
  
hold off

end