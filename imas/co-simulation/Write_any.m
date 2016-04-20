function Write_any(File,Dir,Data)

fid = fopen([Dir filesep() File], 'w+');

for i=1:size(Data,1)
    fprintf(fid,'%s',Data{i,1});
end

fclose(fid);

end

