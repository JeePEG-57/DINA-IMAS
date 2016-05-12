% The script writes tokamak data files from one *.mat file.  
function MatFile = CleanTokamakDataF(FilesDir,MatFile)
%clear all
if nargin<2,
    MatFile = 'ITER.mat';
end
if nargin<1 || isempty(FilesDir),
    %FilesDir = '~lukashv/kepler';
    %cmd=sprintf('/bin/bash --login -c ''echo "$KEPLER"''');
    cmd = 'echo $KEPLER'; [r,s] = system(cmd); s(s==10)=[]; s(s==13)=[];
    FilesDir = s;
end


%% Loading *.mat
load(MatFile);


%% Cleaning files

%mkdir([FilesDir]);

for i = 1:length(ITER.files)
    
    %Write_any(ITER.files(i).name, FilesDir, ITER.files(i).data);
    delete([FilesDir filesep() ITER.files(i).name]);
       
end

%mkdir([FilesDir filesep() 'imp']);

for i = 1:length(ITER.imp.files)
    
    %Write_any(ITER.imp.files(i).name, [FilesDir filesep() 'imp'], ITER.imp.files(i).data);
    delete([FilesDir filesep() 'imp' filesep() ITER.imp.files(i).name]);   
end

rmdir([FilesDir filesep() 'imp']);
