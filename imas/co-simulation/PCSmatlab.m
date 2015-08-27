function sdnout=PCSmatlab(sdninput)

persistent old_z
if isempty(old_z)
	old_z = sdninput(29);
end
IndexUPF = evalin('base','IndexUPF');
sdnout=sdninput;
outputs=zeros(1,58);
try
     dzdt = (sdninput(29) - old_z)/0.005;
catch
     dzdt= 0;
end
P=-0.002; D=-0.002;
outputs(1,IndexUPF(12)) = (sdninput(29)-sdninput(22)*0.52)*P + dzdt*D;
old_z = sdninput(29);
sdnout(93:150)=outputs(end,:);
