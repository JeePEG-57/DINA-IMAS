% The script writes tokamak data files from one *.mat file.  
function [MatFile] = WriteTokamakDataF(varargin)
% First argument is directory to unpac files
% Second argument is mat-file name

%%
if length(varargin) < 2
    [MyPath,~,~] = fileparts(mfilename('fullpath'));
    MatFile = [MyPath '/../../machines/iter/ITER_7.5MA/' 'ITER.mat'];
%     MatFile = 'ITER.mat';
else
    MatFile = varargin{2};
end
if length(varargin) < 1
    %FilesDir = '~lukashv/kepler';
    %cmd=sprintf('/bin/bash --login -c ''echo "$KEPLER"''');
    %cmd = 'echo $KEPLER'; [r,s] = system(cmd); s(s==10)=[]; s(s==13)=[];  
    FilesDir = getenv('KEPLER');
    if isempty(FilesDir)
        FilesDir = [getenv('HOME') '/kepler'];
    end
else
    FilesDir = varargin{1};
    if ~exist(FilesDir,'dir')
        disp(['Creation the new directory ' FilesDir]);
        mkdir(FilesDir);
    end
end

%% Loading *.mat
load(MatFile);

%% Writing to files

for i = 1:length(ITER.files)
    
    Write_any(ITER.files(i).name, FilesDir, ITER.files(i).data);
       
end

mkdir([FilesDir filesep() 'imp']);

for i = 1:length(ITER.imp.files)
    
    Write_any(ITER.imp.files(i).name, [FilesDir filesep() 'imp'], ITER.imp.files(i).data);
       
end
