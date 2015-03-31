clear all
%close all

global t_start t_end ng1;

t_start=-18.7e3;
t_end=58.92e5;
ng1=52;

% the required m-files:
% read_names.m
% read_for042.m
% append_graph.m

names_file='na_ramp';                      % file with names 

i_gr=2;

%source_file(1).name='rez4_1\for042'   % name for second file "for042"
source_file(1).name='rez3\for042'   % name for second file "for042"
source_file(1).legend='1';          % legend for second file

if(i_gr > 1)

source_file(2).name='for042' ;                   % name for first file "for042"
source_file(2).legend='2';                 % legend for first file

end

if(i_gr > 2)
source_file(3).name='rez3\for042' ;                   % name for first file "for042"
source_file(3).legend='3';                 % legend for first file

end

if(i_gr > 3)
source_file(4).name='rez4\for042' ;                   % name for first file "for042"
source_file(4).legend='4';                 % legend for first file
end

if(i_gr > 4)
source_file(5).name='c:\ramp_2d\ramp_2a_test\rez_c4\for042'   % name for second file "for042"
source_file(5).legend='2e-5';          % legend for second file

%source_file(5).name='c:\ramp_2d\ramp_2a_test\rez_n11\for042'   % name for second file "for042"
%source_file(5).legend='1e-5';          % legend for second file


%source_file(5).name='c:\ramp_2d\ramp_2a_test\rez_00\for042'   % name for second file "for042"
%source_file(5).legend='1e-6';          % legend for second file
end

if(i_gr > 5)
source_file(6).name='c:\ramp_2d\ramp_2a_test\rez_15\for042'   % name for second file "for042"
source_file(6).legend='2e-5';          % legend for second file
end



%source_file(3).name='../cygwin_20ev/for042';    % name for third file "for042"
%source_file(3).legend='cygwin_{20eV}';          % legend for third file


append_graph(names_file,source_file)

