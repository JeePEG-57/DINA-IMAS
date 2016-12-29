function CreateInitialIDS()

addpath('..');

[status, result] = system('../../imas/interface/test_dina_to_imas');

status

result

AddPFGeometry(170, 1, 0);
AddPulseSchedule(170, 1, 0);

end
