function [a]= ViewCoreProfiles(shot, run)
% Check arguments
if (nargin ~=2)
    error('Bad number of input arguments. (Must be 2: numShot, run)');
end
addpath /work/imas/projects/ual/2.0/matlabinterface;

expIdx = imas_open('ids', shot, run);
a=ids_get(expIdx, 'core_profiles');
imas_close(expIdx,'ids',shot,run);
%
%disp('get_core_profiles results:');
%disp('ids_properties:');
%disp(a.ids_properties);
end
