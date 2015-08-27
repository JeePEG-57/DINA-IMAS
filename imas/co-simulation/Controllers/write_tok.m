%pf0(1:npf)=sim_ipol(end,:);

pf0(12:npf)=0.;

fid=fopen('tok','w');                     
fprintf(fid,'%s\n',' npf');
fprintf(fid,'%d\n',npf);
for i=1:npf
fprintf(fid,'%d\n',i);
fprintf(fid,' %g  \n',pf0(i)*1.e-3);
end

fid=fclose(fid); 