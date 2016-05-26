function [sys,x0,str,ts] = simimasdialog61(t,x,u,flag)

% parametre de metis
global KepFlag
% donnees de metis (accumulation)
global SimFlag
global fileID
% securite simulink
sys = [];
x0  = [];
str = [];
ts  = [];


switch flag

  case 0
    %initialisation de cronos
    [sys,x0,str,ts,KepFlag,SimFlag,fileID] = mdlInitializeSizes(); % Initialization

  case 3
    [sys,KepFlag,SimFlag] = mdlOutputs(t,x,u,KepFlag,SimFlag,fileID);      
   
  case 9
    %keyboard
    sys = mdlTerminate(t,x,u,fileID);
    case {1,2,4}
  	sys = [];
  otherwise
    error(['Unhandled flag = ',num2str(flag)]); % Error handling
end
 


function [sys,x0,str,ts,KepFlag,SimFlag,fileID] = mdlInitializeSizes()

KepFlag =0;
SimFlag =0;

wkf='./DINA_Scenario_PCSSP.xml'
%wkf='./test61.xml'
%[s,t]=unix(sprintf('/home/ITER/lukashv/ITERIS/TEST/launch_IMAS.sh %s',wkf));
%t
%s=unix(sprintf('nohup /home/ITER/lukashv/ITERIS/TEST/launch_IMAS.sh %s > /dev/null',wkf));
%s=unix(sprintf('nohup toto.sh %s > /dev/null',wkf));
% s=unix(sprintf('nohup  /home/ITER/lukashv/ITERIS/TEST5/launch_KEP.sh %s > /dev/null',wkf));
% s=unix(sprintf('nohup /home/ITER/lukashv/ITERIS/TEST5/get_KepID.sh %s > /dev/null',wkf));

%  s=unix(sprintf('nohup  ./launch_KEP1.sh %s',wkf));
%  s=unix(sprintf('nohup ./get_KepID.sh %s',wkf));
s=unix(sprintf('nohup  ./launch_KEP.sh %s > /dev/null',wkf));
s=unix(sprintf('nohup ./get_KepID.sh %s > /dev/null',wkf));

%le fichier KEPID contient les PID des processus kepler 
fileID=textread('./KEPID','%s','delimiter','\n','whitespace','');

% ceci est une initialisation pour simulink uniquement
sizes = simsizes;
sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumInputs      = 151;
sizes.NumOutputs     = 150;
sizes.DirFeedthrough = 1;  % flag=4 requires direct feedthrough
                           % if input u is involved in
                           % calculating the next sample time
                           % hit.
sizes.NumSampleTimes = 1;
sys = simsizes(sizes);
%
% Initialize the initial conditions.
%
x0 = []; % pas d'etat initial a exporter
%
% Set str to an empty matrix.
%
str = [];
%
% Initialize the array of sample times.
%
ts = [-1 0];      % variable sample time
% End of mdlInitializeSizes.

function   [sys,KepFlag,SimFlag] = mdlOutputs(t,x,u,KepFlag,SimFlag,fileID);      

%disp('Simulink iteration');

if SimFlag == 0
    [sreturn,treturn]=unix(sprintf('./activate_IMAS.sh %s',fileID{1}));
    [sreturn,treturn]=unix(sprintf('./activate_IMAS.sh %s',fileID{1}));
    treturn
    %return the mdl name
    MDLNAME=gcs;
    sprintf('./focus_SIM.sh %s',MDLNAME);
    %[s,t]=unix(sprintf('/home/ITER/lukashv/ITERIS/TEST/focus_SIM.sh %s',MDLNAME));
    %disp('Simulink communication init');
    SimSRFLAG.init()
end

%return the mdl name
%gcs
%sys=u+1;
SimFlag=SimFlag+1;

%disp('Simulink communications');

if KepFlag ~=-1
    SimSRFLAG.send(SimFlag)
    KepFlag=SimSRFLAG.recv();
    %Get simulink parameter
    %simparam = get_param(gcb, 'ObjectParameters');
    %An other way to get the parameter, here the solver parameter
    %hCs = getActiveConfigSet(gcs);
    %hSolverConfig = hCs.getComponent('Solver');
    %hSolverConfig.StopTime
    if KepFlag == -1
       disp('End of Kepler');
       disp('End of Simulink');    
       set_param(gcs, 'SimulationCommand', 'stop');
       sys=zeros(150,1);
       return;
    end
elseif KepFlag == -1
    %cette branche n'est a priori jamais utilise
    disp('End of Kepler');
    disp('End of Simulink');    
    set_param(gcs, 'SimulationCommand', 'stop');
    sys=zeros(150,1);
    %end the simulation
    return;
end 

if KepFlag ~=-1 && KepFlag ~= SimFlag 
    disp('Problems');
    return;
    %end the simulation
end    

%data communication
if KepFlag ~=-1      
     anArrayout = javaArray ('java.lang.Double', 151);
%      aaaa=[26682.600000000006, -1343.2000000000003, -13427.699999999999, -1028.3, 23813.0, 27449.4, -17583.779476508433, -23879.739797758564, -13481.683874603246, -32820.385547892285, 37499.200000000004, 4838.550148228533, -314.9000000000003, 0.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 1.13E7, 23.0, 24.0, 25.0, 26.0, 27.0, 7.151468160504377E7, 5.857629397066093E6, 30.0, 31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 0.224, 0.197, 0.184, 0.274, 0.444, 0.133, 0.3, 0.3, 2.5312E6, 2.2261E6, 2.0792E6, 3.0962E6, 5.0172E6, 1.5029E6, 3.39E6, 3.39E6, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0, 80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0, 92.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 36.7412058678139, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0];
aaaa = [1000.0, 1000.0, 3.0027974244669, 3.7906137184116, 7.5812274368231, 3.7906137184116, -2.3690819422645, -8.4473049074819, -27.34375, -3.9858172895967, -4.110132049014, -8.1960756258366, -4.3685426320791, 0.0, 0.0, 0.0, 0.0, 3.0027974244669, 3.7906137184116, 7.5812274368231, 3.7906137184116, -2.3690819422645, -8.4473049074819, -27.34375, -3.9858172895967, -4.110132049014, -8.1960756258366, -4.3685426320791, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0];

%     aaaa=ones(150,1);

     for n = 1:150
        anArrayout(n) = java.lang.Double(aaaa(n));
     end
     anArrayout(151) = java.lang.Double(0.0);
     %anArrayout(2) = java.lang.Double(2.0);

     if SimFlag > 1 
     %if SimFlag > 0 
         for n = 1:151
           anArrayout(n)   = java.lang.Double(u(n));
         end
     end
     SimSRFLAG.senddata(anArrayout);
     anArrayin=SimSRFLAG.recvdata();
     sys=double(anArrayin);
     %a commenter
     %!sync
else
     sys=zeros(150,1);
end
%!sleep 2

function  sys = mdlTerminate(t,x,u,fileID)

% on ne retourne rien vers simulink
sys = [];
SimSRFLAG.close();
[sreturn,treturn]=unix(sprintf('kill -9  %s',fileID{2}));
%t
[sreturn,treturn]=unix(sprintf('kill -9  %s',fileID{3}));
%t

% End of mdlTerminate

