function [a]= ViewMagnetics(shot, run)
% Check arguments
if (nargin ~=2)
    error('Bad number of input arguments. (Must be 2: numShot, run)');
end
addpath /work/imas/projects/ual/2.0/matlabinterface;
import ualmemory.javainterface.*
expIdx = imas_open('ids', shot, run);
a=ids_get(expIdx, 'em_coupling');
imas_close(expIdx,'ids',shot,run);
%

end