function [ng,name]=read_name(file_name)
% [ng,name]=read_names(file_name)
% outputs:
% ng - number of names
% name - name of variable
% input:
% name of file_name

fid=fopen(file_name);
% [ng,count]
ng=fscanf(fid,'%d\n',1);
text=cell(1,1);
for i=1:ng
%     [text,count]=fscanf(fid,'%s',1);
    a=fgetl(fid);
    name(i).text=a;    
end
