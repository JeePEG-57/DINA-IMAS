function AddPulseSchedule(Shot, Run, Occurence, initFile)

disp('AddPulseSchedule...');

S = load(initFile);


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

if nargin >= 3
    if Occurence > 0
        PSString = [PSString '/' num2str(Occurence)];
        EQString = [EQString '/' num2str(Occurence)];
    end
elseif nargin == 2
else
    disp('Invalid inputs number, must be at least 2.');
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
equilibrium.time_slice{1}.time = 0.0;


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


%% Deuterium density
iv = 7;
a = textscan(n_d.data{2},'%d');
nt = a{1}(1);
n_z = 1;
n_a = 2;
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(n_d.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{iv}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{iv}.flow_rate.reference.data = data;

pulse_schedule.density_control.valve{iv}.species{1}.element{1}.z_n = n_z;
pulse_schedule.density_control.valve{iv}.species{1}.element{1}.a = n_a;

%% Tritium density
iv = 1;
a = textscan(dens.data{2},'%d');
nt = a{1}(1);
n_z = 1;
n_a = 3;
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(dens.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{iv}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{iv}.flow_rate.reference.data = data;

pulse_schedule.density_control.valve{iv}.species{1}.element{1}.z_n = n_z;
pulse_schedule.density_control.valve{iv}.species{1}.element{1}.a = n_a;


%% Be relative density for Ip < 1.5 MA
iv = 2;
a = textscan(gamma_z.data{2},'%d');
nt = a{1}(1);
n_z = a{1}(2);
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(gamma_z.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{iv}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{iv}.flow_rate.reference.data = data;

pulse_schedule.density_control.valve{iv}.species{1}.element{1}.z_n = n_z;

%% Be relative density for Ip > 1.5 MA
iv = 3;
a = textscan(gamma_z1.data{2},'%d');
nt = a{1}(1);
n_z = a{1}(2);
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(gamma_z1.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{iv}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{iv}.flow_rate.reference.data = data;

pulse_schedule.density_control.valve{iv}.species{1}.element{1}.z_n = n_z;

%% W relative density for Ip > 1.5 MA
iv = 4;
a = textscan(gamma_z2.data{2},'%d');
nt = a{1}(1);
n_z = a{1}(2);
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(gamma_z2.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{iv}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{iv}.flow_rate.reference.data = data;

pulse_schedule.density_control.valve{iv}.species{1}.element{1}.z_n = n_z;

%% Ar relative density for Ip > 1.5 MA
iv = 5;
a = textscan(gamma_z3.data{2},'%d');
nt = a{1}(1);
n_z = a{1}(2);
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(gamma_z3.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{iv}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{iv}.flow_rate.reference.data = data;

pulse_schedule.density_control.valve{iv}.species{1}.element{1}.z_n = n_z;

%% Ne relative density for Ip > 1.5 MA
iv = 6;
a = textscan(gamma_z4.data{2},'%d');
nt = a{1}(1);
n_z = a{1}(2);
time = zeros(1,nt);
data = zeros(1,nt);
for i=1:nt
    a = textscan(gamma_z4.data{3+i},'%f');
    time(i) = a{1}(1); 
    data(i) = a{1}(2); % 
end
pulse_schedule.density_control.valve{iv}.flow_rate.reference.time = time;
pulse_schedule.density_control.valve{iv}.flow_rate.reference.data = data;

pulse_schedule.density_control.valve{iv}.species{1}.element{1}.z_n = n_z;

%%

disp('Saving IDS...');

pulse_schedule.ids_properties.homogeneous_time = 1;
pulse_schedule.time = time;

SaveIDS(Shot, Run, PSString, pulse_schedule);
SaveIDS(Shot, Run, EQString, equilibrium);

disp('IDS Saved.');

end

