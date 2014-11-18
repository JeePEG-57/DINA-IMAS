function varargout = ProfilesViewer(varargin)
% PROFILESVIEWER MATLAB code for ProfilesViewer.fig
%      PROFILESVIEWER, by itself, creates a new PROFILESVIEWER or raises the existing
%      singleton*.
%
%      H = PROFILESVIEWER returns the handle to a new PROFILESVIEWER or the handle to
%      the existing singleton*.
%
%      PROFILESVIEWER('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PROFILESVIEWER.M with the given input arguments.
%
%      PROFILESVIEWER('Property','Value',...) creates a new PROFILESVIEWER or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ProfilesViewer_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ProfilesViewer_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ProfilesViewer

% Last Modified by GUIDE v2.5 29-Oct-2014 06:50:53

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ProfilesViewer_OpeningFcn, ...
                   'gui_OutputFcn',  @ProfilesViewer_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before ProfilesViewer is made visible.
function ProfilesViewer_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ProfilesViewer (see VARARGIN)

% Choose default command line output for ProfilesViewer
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes ProfilesViewer wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = ProfilesViewer_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in Main_Button_Next.
function Main_Button_Next_Callback(hObject, eventdata, handles)
% hObject    handle to Main_Button_Next (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

handles.StepNumber = min([handles.StepNumber+1 handles.MaxStepNumber]);

handles.Frame = GetFrame(handles.StepNumber,handles.Step,3);

guidata(hObject, handles);


DrawGraphs(hObject, handles.Main_Axes1);
DrawGraphs(hObject, handles.Main_Axes2);
DrawGraphs(hObject, handles.Main_Axes3);
DrawGraphs(hObject, handles.Main_Axes4);



% --- Executes on button press in Main_Button_Back.
function Main_Button_Back_Callback(hObject, eventdata, handles)
% hObject    handle to Main_Button_Back (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

handles.StepNumber = max([handles.StepNumber-1 1]);

handles.Frame = GetFrame(handles.StepNumber,handles.Step,3);

guidata(hObject, handles);


DrawGraphs(hObject, handles.Main_Axes1);
DrawGraphs(hObject, handles.Main_Axes2);
DrawGraphs(hObject, handles.Main_Axes3);
DrawGraphs(hObject, handles.Main_Axes4);


function [Frame] = GetFrame(FrameStep, Step, Graphs)

Frame = 1 + (FrameStep-1)*Step*Graphs;



% --- Executes on button press in Main_Button_Start.
function Main_Button_Start_Callback(hObject, eventdata, handles)
% hObject    handle to Main_Button_Start (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.StepNumber = 1;

handles.Frame = GetFrame(handles.StepNumber,handles.Step,3);

guidata(hObject, handles);


DrawGraphs(hObject, handles.Main_Axes1);
DrawGraphs(hObject, handles.Main_Axes2);
DrawGraphs(hObject, handles.Main_Axes3);
DrawGraphs(hObject, handles.Main_Axes4);


% --- Executes on button press in Main_Button_Finish.
function Main_Button_Finish_Callback(hObject, eventdata, handles)
% hObject    handle to Main_Button_Finish (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.StepNumber = handles.MaxStepNumber;

handles.Frame = GetFrame(handles.StepNumber,handles.Step,3);

guidata(hObject, handles);


DrawGraphs(hObject, handles.Main_Axes1);
DrawGraphs(hObject, handles.Main_Axes2);
DrawGraphs(hObject, handles.Main_Axes3);
DrawGraphs(hObject, handles.Main_Axes4);


function Main_Shot_Callback(hObject, eventdata, handles)
% hObject    handle to Main_Shot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Main_Shot as text
%        str2double(get(hObject,'String')) returns contents of Main_Shot as a double



% --- Executes during object creation, after setting all properties.
function Main_Shot_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Main_Shot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Main_Run_Callback(hObject, eventdata, handles)
% hObject    handle to Main_Run (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Main_Run as text
%        str2double(get(hObject,'String')) returns contents of Main_Run as a double


% --- Executes during object creation, after setting all properties.
function Main_Run_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Main_Run (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in Main_ListProfiles.
function Main_ListProfiles_Callback(hObject, eventdata, handles)
% hObject    handle to Main_ListProfiles (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns Main_ListProfiles contents as cell array
%        contents{get(hObject,'Value')} returns selected item from Main_ListProfiles


% --- Executes during object creation, after setting all properties.
function Main_ListProfiles_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Main_ListProfiles (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function AxesNumber_Callback(hObject, eventdata, handles)
% hObject    handle to AxesNumber (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of AxesNumber as text
%        str2double(get(hObject,'String')) returns contents of AxesNumber as a double


% --- Executes during object creation, after setting all properties.
function AxesNumber_CreateFcn(hObject, eventdata, handles)
% hObject    handle to AxesNumber (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function [flag] = CheckFields(hObject)

handles = guidata(hObject);

flag = 1;

Temp = str2double(get(handles.Main_Shot, 'String'));
if isnan(Temp)
    flag = 0;
    return
end
handles.Shot = round(abs(Temp));


Temp = str2double(get(handles.Main_Run, 'String'));
if isnan(Temp)
    flag = 0;
    return
end
handles.Run = round(abs(Temp));   
    
guidata(hObject, handles);    

    


function LoadData(hObject)

handles = guidata(hObject);

handles.CoreProfiles = LoadIDS(handles.Shot, handles.Run, 'core_profiles');

handles.Frame = 1;
handles.StepNumber = 1;

Temp = str2double(get(handles.Main_FrameStep, 'String'));
if ~isnan(Temp)
    handles.Step = round(abs(Temp));
else
    handles.Step = 10;
end

handles.TimeSteps = length(handles.CoreProfiles.time);

handles.MaxStepNumber = floor((handles.TimeSteps - 1)/(handles.Step*3) + 1);

UserData = struct('ProfileName','','Lines',repmat(-1,[1,3]));

UserData.ProfileName = 'T_e';
set(handles.Main_Axes1,'UserData',UserData);
cla(handles.Main_Axes1);

UserData.ProfileName = 'T_i average';
set(handles.Main_Axes2,'UserData',UserData);
cla(handles.Main_Axes2);

UserData.ProfileName = 'j_t_o_r';
set(handles.Main_Axes3,'UserData',UserData);
cla(handles.Main_Axes3);

UserData.ProfileName = 'q';
set(handles.Main_Axes4,'UserData',UserData);
cla(handles.Main_Axes4);


guidata(hObject,handles);




function Main_FrameStep_Callback(hObject, eventdata, handles)
% hObject    handle to Main_FrameStep (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Main_FrameStep as text
%        str2double(get(hObject,'String')) returns contents of Main_FrameStep as a double


% --- Executes during object creation, after setting all properties.
function Main_FrameStep_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Main_FrameStep (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Main_Button_Load.
function Main_Button_Load_Callback(hObject, eventdata, handles)
% hObject    handle to Main_Button_Load (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


if CheckFields(hObject) == 0
    return
end

LoadData(hObject);


DrawGraphs(hObject, handles.Main_Axes1);
DrawGraphs(hObject, handles.Main_Axes2);
DrawGraphs(hObject, handles.Main_Axes3);
DrawGraphs(hObject, handles.Main_Axes4);



function DrawGraphs(hObject, Axes)

handles = guidata(hObject);

axes(Axes);


n1 = handles.Frame;
n2 = n1 + handles.Step;
n3 = n2 + handles.Step;


t = handles.CoreProfiles.time;

x = handles.CoreProfiles.rho_tor_norm;


UserData = get(Axes,'UserData');

DataName = UserData.ProfileName;
if strcmp(DataName,'n_e')
    y = handles.CoreProfiles.n_e;
elseif strcmp(DataName,'T_e')
    y = handles.CoreProfiles.t_e;
elseif strcmp(DataName,'T_i average')
    y = handles.CoreProfiles.t_i_average;
elseif strcmp(DataName,'j_t_o_r')
    y = handles.CoreProfiles.j_tor;
elseif strcmp(DataName,'q')
    y = handles.CoreProfiles.q;
elseif strcmp(DataName,'rho_t_o_r _n_o_r_m')
    y = handles.CoreProfiles.rho_tor_norm;
    x = zeros(size(handles.CoreProfiles.rho_tor_norm,1),size(handles.CoreProfiles.rho_tor_norm,2));
    for i=1:size(x,1)
        x(i,:) = (i-1)/(size(x,1)-1);
    end
else
    return
end
   

LegendStrings = {};


if UserData.Lines(1) == -1
    UserData.Lines(1) = line(NaN,NaN);
end

if n1 <= handles.TimeSteps
    t1 = t(n1);
    x1 = x(:,n1);
    y1 = y(:,n1); 


    set(UserData.Lines(1),'XData',x1,'YData',y1);

    set(UserData.Lines(1),'Color','b');
    
    LegendStrings{length(LegendStrings)+1} = ['t = ' num2str(t1)];
else
    set(UserData.Lines(1),'XData',NaN,'YData',NaN);
end



if UserData.Lines(2) == -1
    UserData.Lines(2) = line(NaN,NaN);
end

if n2 <= handles.TimeSteps
    t2 = t(n2);
    x2 = x(:,n2);
    y2 = y(:,n2); 


    set(UserData.Lines(2),'XData',x2,'YData',y2);

    set(UserData.Lines(2),'Color','g');
    
    LegendStrings{length(LegendStrings)+1} = ['t = ' num2str(t2)];
else
    set(UserData.Lines(2),'XData',NaN,'YData',NaN);
end



if UserData.Lines(3) == -1
    UserData.Lines(3) = line(NaN,NaN);
end

if n3 <= handles.TimeSteps
    t3 = t(n3);
    x3 = x(:,n3);
    y3 = y(:,n3); 


    set(UserData.Lines(3),'XData',x3,'YData',y3);

    set(UserData.Lines(3),'Color','r');
    
    LegendStrings{length(LegendStrings)+1} = ['t = ' num2str(t3)];
else
    set(UserData.Lines(3),'XData',NaN,'YData',NaN);
end


set(Axes,'UserData',UserData);

if strcmp(DataName,'rho tor norm')
    xlabel('r_n_o_r_m');
else
    xlabel('rho_t_o_r _n_o_r_m');
end

ylabel(DataName);
title(DataName, 'Color','w');

legend(LegendStrings);



function [cpo]= LoadIDS(shot, run, ids)
% Check arguments
if (nargin ~=3)
    error('Bad number of input arguments. (Must be 3: numShot, run, ids)');
end
addpath /work/imas/projects/ual/2.0/matlabinterface;

expIdx = imas_open('ids', shot, run);
cpo=ids_get(expIdx, ids);
imas_close(expIdx,'ids',shot,run);
