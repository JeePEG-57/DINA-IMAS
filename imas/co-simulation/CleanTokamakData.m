% The script writes tokamak data files from one *.mat file.  

%clear all

FilesDir = getenv('KEPLER');

%% Loading *.mat
load('ITER.mat');


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
