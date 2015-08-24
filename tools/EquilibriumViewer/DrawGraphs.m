function [Code] = DrawGraphs(hObject, Axes, Frame)

Code = 1;

handles = guidata(hObject);

axes(Axes);


if nargin == 3
    handles.Frame = Frame;
elseif nargin == 2
    Frame = handles.Frame;
else
    return
end


if ishandle(handles.Dynamic)
    delete(handles.Dynamic);
end


UserData = get(Axes,'UserData');
DataName = UserData.ProfileName;


s_time = handles.Equilibrium.time(Frame);
    
y = 1.e2*handles.Equilibrium.time_slice{1,Frame}.profiles_2d{1}.grid.dim1;
x = 1.e2*handles.Equilibrium.time_slice{1,Frame}.profiles_2d{1}.grid.dim2; 

psi = handles.Equilibrium.time_slice{1,Frame}.profiles_2d{1}.psi;
    
    
pmag = handles.Equilibrium.time_slice{1,Frame}.global_quantities.psi_axis;
pbound = handles.Equilibrium.time_slice{1,Frame}.global_quantities.psi_boundary;


% if max(max(psi)) == min(min(psi))
if pmag == pbound
    return
end


lw=1; %LineWidth
fs=9; %FontSize

hold on
         
   
p_s = pbound;
delaval=pmag-pbound;
n_g=8;
d1=delaval/n_g;
avalb=pmag;
PL = [];
for i=1:n_g+20
    avalb=avalb-d1;
    PL(i)=avalb;
end 
  

%size(x)
%size(y)
%size(psi)

[~,h1]=contour(x,y,psi,PL(1:n_g-1),'r');  %flux

[~,h2]=contour(x,y,psi,PL(n_g+1:end),'b');  %flux

[~,h3]=contour(x,y,psi,[p_s p_s],'m');  %flux
set(h3,'LineWidth',2);

handles.Dynamic = [h1 h2 h3];


%	title('Halo region','FontSize',fs);
%	title('Plasma core + halo area','FontSize',fs);
title(['Time = ' num2str(s_time) 's'],'Color','w');

  
%   rmx=max(rc);
%   rmn=min(rc);
% %  rtext=rmn+0.10*(rmx-rmn);
%   rtext=rmn+0.80*(rmx-rmn);
%   zmn=min(zc);
%   ztext=0.85*zmn;
% 
%   text('Position',[rtext ztext],'String',['time=',s_time,'ms'],'FontSize',fs);

%	set(gca,'XGrid','on','YGrid','on','LineWidth',lw,'FontSize',fs);%,'PlotBoxAspectRatio',[1 1.7 1]);


%AxesRefresh(Axes);
%daspect([1 1 1]);
  
  
hold off

  
set(Axes,'UserData',UserData);

guidata(hObject, handles);

Code = 0;

end