function [cpo]= LoadIDSSlice(shot, run, ids, time, interp)
% Check arguments
if (nargin ~=5)
    error('Bad number of input arguments. (Must be 5: numShot, run, ids, time, interp)');
end
UALInterface;

%  expIdx = imas_open('ids', shot, run);
expIdx = imas_open_env('ids', shot, run,'medveds','test','3');
cpo=ids_get_slice(expIdx, ids, time, interp);
imas_close(expIdx,'ids',shot,run);
%
end