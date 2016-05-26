% The script writes tokamak data files from one *.mat file.  

%clear all

%FilesDir = '~lukashv/kepler';
FilesDir = getenv('KEPLER');


%% Loading *.mat
load('ITER.mat');


%% Writing to files

%mkdir([FilesDir]);

for i = 1:length(ITER.files)
    
    Write_any(ITER.files(i).name, FilesDir, ITER.files(i).data);
       
end

mkdir([FilesDir filesep() 'imp']);

for i = 1:length(ITER.imp.files)
    
    Write_any(ITER.imp.files(i).name, [FilesDir filesep() 'imp'], ITER.imp.files(i).data);
       
end
