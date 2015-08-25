function CreateInitialIDS()

[status, result] = system('../../imas/interface/test_dina_to_imas');

status

result

AddToCPO(170, 1, 0);

end
