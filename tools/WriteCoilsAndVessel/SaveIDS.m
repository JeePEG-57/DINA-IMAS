function SaveIDS(shot, run, ids, cpo)
% Check arguments
if (nargin ~=4)
    error('Bad number of input arguments. (Must be 4: numShot, run, ids, cpo)');
end
UALInterface;

expIdx = imas_open('ids', shot, run);
ids_put(expIdx, ids, cpo);
imas_close(expIdx,'ids',shot,run);
%
end