function [ id ] = imas_open( name, shot, run )
% idx = imas_open (name, shot, run)
% Open the database.
%
% idx  : database index
% name : name of the database (by convention ids).
% shot : shot number.
% run  : run number.
% YB.

import ualmemory.javainterface.*

if (nargin ~=3)
    error('Bad number of input arguments. Must be 3');
end
if ~ischar(name);
    error('First input argument must be a string (BD name)')
end
if ~isnumeric(shot)
        error('Second input argument must be a numeric (shot num)')
end
if ~isnumeric(run)
        error('Third input argument must be a numeric (run number)');
end

id = imas.open(name, shot, run);

