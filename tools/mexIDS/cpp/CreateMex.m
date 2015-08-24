function CreateMex

AFS = '/work/imas/projects';
MDSPLUS_DIR = [AFS '/mdsplus/mdsplus'];

BLITZ_DIR = [AFS '/blitz/blitz-0.9_X86_64_GNU'];
INCDIR = ['-I$UAL/cppinterface -I$UAL/lowlevel' [' -I' BLITZ_DIR '/include'] [' -I' BLITZ_DIR] ];
LIBDIR = ['-L' MDSPLUS_DIR '/lib64 -L' MDSPLUS_DIR '/lib -L$UAL/cppinterface -L$UAL/lowlevel -L$HDF5_DIR/lib -Wl,-rpath,$UAL/itmcatalog/lib'];
LIBS = ['-lUALCPPInterface -lUALLowLevel -lTreeShr -lTdiShr -lMdsShr -lMdsIpShr -lXTreeShr' [' ' BLITZ_DIR '/lib/libblitz.a']]; 


%-ansi -D_GNU_SOURCE -fPIC -fno-omit-frame-pointer -pthread
CXXFLAGS = ['CXXFLAGS=\$CXXFLAGS' ' -O0 -fPIC ' INCDIR];
% CXXFLAGS = ['CXXFLAGS=-D_GNU_SOURCE -fPIC -fno-omit-frame-pointer' ' -O0 -fPIC ' INCDIR];


%-pthread -shared -Wl,--version-script,/opt/matlab/2012b/extern/lib/glnxa64/mexFunction.map -Wl,--no-undefined
LDFLAGS = ['LDFLAGS=\$LDFLAGS -g ' LIBDIR ' ' LIBS];
% LDFLAGS = ['LDFLAGS=-shared -Wl,--version-script,/opt/matlab/2012b/extern/lib/glnxa64/mexFunction.map' ...
%     ' -g ' LIBDIR ' ' LIBS];


mex('-v', ...
    CXXFLAGS, ...
    'COPTIMFLAGS=-O0', ...
    'CDEBUGFLAGS=-g', ...
    LDFLAGS, ...
    'LDOPTIMFLAGS=-O0', ...
    'LDDEBUGFLAGS=-g', ...
    'LoadIDSmex.cpp');

end