function [a]= ViewEmCoupling(shot, run)
% Check arguments
if (nargin ~=2)
    error('Bad number of input arguments. (Must be 2: numShot, run)');
end
addpath /work/imas/projects/ual/2.0/matlabinterface;
import ualmemory.javainterface.*

expIdx = imas_open('ids', shot, run);

keyboard;


a=ids_get(expIdx, 'em_coupling');
%
disp('get_em_coupling results:');
%disp(a.IDS_Properties);
disp('Global/Ip:');
disp(a.Global.Ip');
disp('Global/li_3:');
disp(a.Global.li_3');
%
% 2D signals
%
disp('mutual_active_active');
curdata = a.mutual_active_active;
disp('-size');
[dim1,dim2]=size(curdata)


disp('mutual_passive_active');
curdata = a.mutual_passive_active;
disp('-size');
[dim1,dim2]=size(curdata)


disp('mutual_loops_active');
curdata = a.mutual_loops_active;
disp('-size');
[dim1,dim2]=size(curdata)


disp('field_probes_active');
curdata = a.field_probes_active;
disp('-size');
[dim1,dim2]=size(curdata)


disp('mutual_passive_passive');
curdata = a.mutual_passive_passive;
disp('-size');
[dim1,dim2]=size(curdata)


disp('mutual_loops_passive');
curdata = a.mutual_loops_passive;
disp('-size');
[dim1,dim2]=size(curdata)


disp('field_probes_passive');
curdata = a.field_probes_passive;
disp('-size');
[dim1,dim2]=size(curdata)


disp('mutual_grid_grid');
curdata = a.mutual_grid_grid;
disp('-size');
[dim1,dim2]=size(curdata)


disp('mutual_grid_active');
curdata = a.mutual_grid_active;
disp('-size');
[dim1,dim2]=size(curdata)


disp('mutual_grid_active');
curdata = a.mutual_grid_active;
disp('-size');
[dim1,dim2]=size(curdata)


disp('mutual_grid_passive');
curdata = a.mutual_grid_passive;
disp('-size');
[dim1,dim2]=size(curdata)


disp('field_probes_grid');
curdata = a.field_probes_grid;
disp('-size');
[dim1,dim2]=size(curdata)


disp('mutual_loops_grid');
curdata = a.mutual_loops_grid;
disp('-size');
[dim1,dim2]=size(curdata)



disp('time');
curdata = a.time;
disp('-size');
[dim1,dim2]=size(curdata)


%
disp('Code_Parameters.Code_Name: ');
disp(a.Code_Parameters.Code_Name);
disp('Code_Parameters.Code_Version: ');
disp(a.Code_Parameters.Code_Version);
%
imas_close(expIdx,'ids',shot,run);
