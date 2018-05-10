% The script reads tokamak data files and save to one *.mat file
function [MatFile] = ReadTokamakData(FilesDir,varargin)
% First argument is directory to collect included files
% Second argument is mat-file name

if length(varargin) < 1
    [MyPath,~,~] = fileparts(mfilename('fullpath'));
    MatFile = [MyPath '/../../machines/iter/ITER_7.5MA/' 'ITER.mat'];
else
    MatFile = varargin{1};
end

if nargin<1
    FilesDir = '.';
end

%% Finding files

ITER = struct('imp',struct('files',struct([])),'files',struct([]));

AllFiles = dir([FilesDir filesep() 'imp']);
i = 1;
while i <= length(AllFiles)
    if isdir(AllFiles(i).name)
        AllFiles(i) = [];
    else
        i = i + 1;
    end
end
ITER.imp.files = AllFiles;


AllFiles = dir([FilesDir]);
i = 1;
while i <= length(AllFiles)
    if isdir([FilesDir filesep() AllFiles(i).name])
        AllFiles(i) = [];
    else
        i = i + 1;
    end
end
ITER.files = AllFiles;


%% Reading files

for i = 1:length(ITER.files)
    
    ITER.files(i).data = Read_any(ITER.files(i).name, FilesDir);
       
end


for i = 1:length(ITER.imp.files)
    
    ITER.imp.files(i).data = Read_any(ITER.imp.files(i).name, [FilesDir filesep() 'imp']);
       
end


%% Saving to *.mat

save(MatFile, 'ITER');

