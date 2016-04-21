function [Str] = Read_any(File,Dir)

fid = fopen([Dir filesep() File], 'r'); 

Str = {};
tline = fgets(fid);
i = 0;
while ischar(tline)
    i = i + 1;
    Str{i,1} = tline;
    tline = fgets(fid);
end

fclose(fid);

end
