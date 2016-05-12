
n_t=size(t_Resistors,1);
t_Resistors(1:n_t,14)=0.000642411;
t_Resistors(1:n_t,15)=0.000426511e15;  
t_Resistors(1:n_t,16)=0.000401657;   

fid=fopen('pfres.dat','w');                     
fprintf(fid,'%s\n',' n_t ');
fprintf(fid,'%d\n',n_t);
fprintf(fid,'%s\n',' PFres(i),i=1,npf ');
 
for i=1:n_t
fprintf(fid,' %g',t_Resistors(i,1));
for k=1:npf
fprintf(fid,' %g',t_Resistors(i,k+1));
end
fprintf(fid,'\n');
end
fid=fclose(fid);
