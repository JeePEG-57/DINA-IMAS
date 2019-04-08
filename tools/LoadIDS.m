function [cpo]= LoadIDS(shot, run, ids)
% Check arguments
if (nargin ~=3)
    error('Bad number of input arguments. (Must be 3: numShot, run, ids)');
end
UALInterface;

expIdx = imas_open('ids', shot, run);
cpo=ids_get(expIdx, ids);
imas_close(expIdx,'ids',shot,run);

disp(['Loaded IDS ' ids ', shot = ' num2str(shot) ', run = ' num2str(run)]);

%
end