function CreateInitialIDS(varargin)

if nargin > 0
    initFile = varargin{1};
else
    initFile = '../../machines/iter/JINTRAC_case1/ITER.mat';
end

disp(['Init file is ' initFile]);

addpath('..');

if 1
    idx = imas_create_env('ids',170, 1, 0, 0,'medveds','test','3');
    imas_close(idx);
else
    [status, result] = system('../../imas/interface/test_dina_to_imas');
    status
    result
end

AddPulseSchedule(170, 1, 0, initFile);
AddPFGeometry(170, 1, 0);

WriteTokamakData(getenv('KEPLER'), initFile);


%[MyPath,MyName,~] = fileparts(mfilename('fullpath'));
%cd(getenv('KEPLER'));
%[status, result] = system([MyPath '/../../imas/jetto/JINTRAC_IDS/jetto_prof_to_ids']);

end
