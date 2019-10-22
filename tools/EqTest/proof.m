psi = cell(1,2);
pbound = cell(1,2);
time = cell(1,2);
txt = cell(1,2);

addpath ..

if 1
    
PSString = 'pulse_schedule';
EQString = 'equilibrium';


Shot = 170;
Run = 6;

disp('Loading IDS...');

pulse_schedule = LoadIDS(Shot, Run, PSString);
equilibrium = LoadIDS(Shot, Run, EQString);

%assignin('base', 'pulse_schedule', pulse_schedule);
%assignin('base', 'equilibrium', equilibrium);

disp('IDS Loaded.');

x = equilibrium.time_slice{1}.profiles_2d{1}.grid.dim2;
y = equilibrium.time_slice{1}.profiles_2d{1}.grid.dim1;

nr = length(x);
nz = length(y);

end

%% Regression equilibrium
ii = 1;

[tt, psi1, pbound1] = eq_regr(nr,nz);
psi{ii} = psi1*1.e-5*2.*pi;
pbound{ii} = pbound1*1.e-5*2.*pi;


time{ii} = tt*1.e-3;
txt{ii} = 'Regression';

%% DINA equilibrium
ii = 2;

ktime = 1;
dt = 1.e10;
for i=1:length(equilibrium.time_slice)
    if abs(equilibrium.time_slice{i}.time - time{1}) <= dt
        ktime = i;
        dt = abs(equilibrium.time_slice{i}.time - time{1});
    else
        break;
    end
end

pbound{ii} = equilibrium.time_slice{ktime}.global_quantities.psi_boundary;
psi{ii} = equilibrium.time_slice{ktime}.profiles_2d{1}.psi;

time{ii} = equilibrium.time_slice{ktime}.time;
txt{ii} = 'DINA';

%% Comparison
k_fig = 10;

figure(k_fig);
clf;
fs = 14;
lw = 2;


i = 1;
v = pbound{i};
[C,h]=contour(x,y,psi{i},[v v],'-b');

hold on;

i = 2;
v = pbound{i};
[C,h]=contour(x,y,psi{i},[v v],'-r');


title('ITER equilibrium','FontSize',12);
xlabel('r, m','FontSize',fs);
ylabel('z, m','FontSize',fs);
  
% i = 1; 
% rtext = 2;
% ztext = -2.7 - i*1.0;
% s_time = num2str(time{i});
% text('Position',[rtext ztext],'String',['time' num2str(i) ' = ' s_time ' m'],'FontSize',fs);
% 
% i = 2; 
% rtext = 2;
% ztext = -2.7 - i*1.0;
% s_time = num2str(time{i});
% text('Position',[rtext ztext],'String',['time' num2str(i) ' = ' s_time ' m'],'FontSize',fs);


set(gca,'XGrid','on','YGrid','on','LineWidth',lw,'FontSize',fs);%,'PlotBoxAspectRatio',[1 1.7 1]);
daspect([1 1 1]); 
  
  
legend([txt{1} ', time = ' num2str(time{1}) ' s'],[txt{2} ', time = ' num2str(time{2}) ' s']);


err_a = max(max(abs(psi{1} - psi{2})));
err_r = err_a/max(max(abs(psi{1})));

str_a = ['Maximum absolute error is ' num2str(err_a) ' Wb'];
str_r = ['Maximum relative error is ' num2str(err_r)];

disp(str_a);
disp(str_r);


text('Position',[2.0 -2.5],'String',str_a,'FontSize',fs);
text('Position',[2.0 -3.5],'String',str_r,'FontSize',fs);

ss='eq_compare';
print(k_fig, '-dtiff', ss)
  
saveas(gcf, ss, 'fig')  
  
  


