function AddPulseSchedule(Shot, Run, Occurence)


S = load('../../machines/iter/ITER_7.5MA/ITER.mat');


for i=1:length(S.ITER.files)
    if strcmp(S.ITER.files(i).name,'ech.dat')
        ech = S.ITER.files(i);
    end
    if strcmp(S.ITER.files(i).name,'emo.dat')
        emo = S.ITER.files(i);
    end
    if strcmp(S.ITER.files(i).name,'n_d.dat')
        n_d = S.ITER.files(i);
    end
    if strcmp(S.ITER.files(i).name,'dens.dat')
        dens = S.ITER.files(i);
    end
    if strcmp(S.ITER.files(i).name,'gamma_z.dat')
        gamma_z = S.ITER.files(i);
    end   
    if strcmp(S.ITER.files(i).name,'gamma_z1.dat')
        gamma_z1 = S.ITER.files(i);
    end
    if strcmp(S.ITER.files(i).name,'gamma_z2.dat')
        gamma_z2 = S.ITER.files(i);
    end
    if strcmp(S.ITER.files(i).name,'gamma_z3.dat')
        gamma_z3 = S.ITER.files(i);
    end
    if strcmp(S.ITER.files(i).name,'gamma_z4.dat')
        gamma_z4 = S.ITER.files(i);
    end
    if strcmp(S.ITER.files(i).name,'for002')
        for002 = S.ITER.files(i);
    end
end


PSString = 'pulse_schedule';
EQString = 'equilibrium';

if nargin == 3
    if Occurence > 0
        PSString = [PSString '/' num2str(Occurence)];
        EQString = [EQString '/' num2str(Occurence)];
    end
elseif nargin == 2
else
    disp('Invalid inputs number, must be 2 or 3.');
    return
end


disp('Loading IDS...');

pulse_schedule = LoadIDS(Shot, Run, PSString);
equilibrium = LoadIDS(Shot, Run, EQString);

assignin('base', 'pulse_schedule', pulse_schedule);
assignin('base', 'equilibrium', equilibrium);

disp('IDS Loaded.');

%% Vacuum toroidal field
a = textscan(for002.data{4},'%f');
RBt0 = a{1}(4)*1.e-2; % sm to meters
a = textscan(for002.data{66},'%f');
Bt0 = a{1}(2)*1.e-1; % kG to Tesla

equilibrium.vacuum_toroidal_field.r0 = RBt0;
equilibrium.vacuum_toroidal_field.b0 = Bt0;
equilibrium.time = 0.0;


%% EC heating for Ip < 1.5 MA
a = textscan(ech.data{2},'%d');
nt = a{1}(1);
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(ech.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2)*1.e6; % EC, MW to W
end
pulse_schedule.ec.antenna{1}.power.reference.time = time;
pulse_schedule.ec.antenna{1}.power.reference.data = data;


%% EC+EQ heating for Ip > 1.5 MA
a = textscan(emo.data{2},'%d');
nt = a{1}(1);
time = zeros(1,nt);
data_e = zeros(1,nt);
data_q = zeros(1,nt);
for i=1:nt
    a = textscan(emo.data{3+i},'%f');
    time(i) = a{1}(1);
    data_e(i) = a{1}(2)*1.e6; % EC, MW to W
    data_q(i) = a{1}(3)*1.e6; % EQ, MW to W
end
pulse_schedule.ec.antenna{2}.power.reference.time = time;
pulse_schedule.ec.antenna{2}.power.reference.data = data_e; % EC, W
pulse_schedule.ec.antenna{3}.power.reference.time = time;
pulse_schedule.ec.antenna{3}.power.reference.data = data_q; % EQ, W


%% Plasma density for Ip > 1.5 MA
a = textscan(dens.data{2},'%d');
nt = a{1}(1);
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(dens.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{1}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{1}.flow_rate.reference.data = data;



%% Be relative density for Ip < 1.5 MA
a = textscan(gamma_z.data{2},'%d');
nt = a{1}(1);
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(gamma_z.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{2}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{2}.flow_rate.reference.data = data;


%% Be relative density for Ip > 1.5 MA
a = textscan(gamma_z1.data{2},'%d');
nt = a{1}(1);
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(gamma_z1.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{3}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{3}.flow_rate.reference.data = data;


%% W relative density for Ip > 1.5 MA
a = textscan(gamma_z2.data{2},'%d');
nt = a{1}(1);
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(gamma_z2.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{4}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{4}.flow_rate.reference.data = data;


%% Ar relative density for Ip > 1.5 MA
a = textscan(gamma_z3.data{2},'%d');
nt = a{1}(1);
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(gamma_z3.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{5}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{5}.flow_rate.reference.data = data;


%% Ne relative density for Ip > 1.5 MA
a = textscan(gamma_z4.data{2},'%d');
nt = a{1}(1);
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(gamma_z4.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{6}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{6}.flow_rate.reference.data = data;


%% Deuterium density for Ip < 1.5 MA
a = textscan(n_d.data{2},'%d');
nt = a{1}(1);
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(n_d.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{7}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{7}.flow_rate.reference.data = data;


disp('Saving IDS...');

SaveIDS(Shot, Run, PSString, pulse_schedule);
SaveIDS(Shot, Run, EQString, equilibrium);

disp('IDS Saved.');

end

