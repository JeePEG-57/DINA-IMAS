function SaveIDS(shot, run, ids, cpo)
% Check arguments
if (nargin ~=4)
    error('Bad number of input arguments. (Must be 4: numShot, run, ids, cpo)');
end
UALInterface;

%  expIdx = imas_open('ids', shot, run);
expIdx = imas_open_env('ids', shot, run,'medveds','test','3');
ids_put(expIdx, ids, cpo);
%  imas_close(expIdx,'ids',shot,run);
imas_close(expIdx);
%
end