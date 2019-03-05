function CreateInitialIDS(varargin)

if nargin > 0
    initFile = varargin{1};
else
    initFile = '../../machines/iter/JINTRAC_case1/ITER.mat';
end

disp(['Init file is ' initFile]);

addpath('..');

[status, result] = system('../../imas/interface/test_dina_to_imas');

status

result

AddPulseSchedule(170, 1, 0, initFile);
AddPFGeometry(170, 1, 0);

WriteTokamakData(getenv('KEPLER'), initFile);


%[MyPath,MyName,~] = fileparts(mfilename('fullpath'));
%cd(getenv('KEPLER'));
%[status, result] = system([MyPath '/../../imas/jetto/JINTRAC_IDS/jetto_prof_to_ids']);

end
