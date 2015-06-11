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

addpath ..;


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

handles.TimeSteps = length(handles.CoreProfiles.profiles_1d);

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

GraphsInAxes = 3;


if handles.Frame <= handles.TimeSteps
    Times = zeros(1,1);

    Times(1,1) = handles.Frame;

    for i=1:(GraphsInAxes-1)
        NextStep = Times(1,i) + handles.Step;
        if NextStep <= handles.TimeSteps
            Times(1,i+1) = NextStep;
        else
            break
        end
    end
else
    Times = [];
end

t = handles.CoreProfiles.time;

UserData = get(Axes,'UserData');

DataName = UserData.ProfileName;

LegendStrings = {};

ColorString = 'bgrymc';

for it = 1:length(Times)

    x = handles.CoreProfiles.profiles_1d{1,Times(1,it)}.grid.rho_tor_norm;
    
    if strcmp(DataName,'n_e')
        y = handles.CoreProfiles.profiles_1d{1,Times(1,it)}.n_e;
    elseif strcmp(DataName,'T_e')
        y = handles.CoreProfiles.profiles_1d{1,Times(1,it)}.t_e;
    elseif strcmp(DataName,'T_i average')
        y = handles.CoreProfiles.profiles_1d{1,Times(1,it)}.t_i_average;
    elseif strcmp(DataName,'j_t_o_r')
        y = handles.CoreProfiles.profiles_1d{1,Times(1,it)}.j_tor;
    elseif strcmp(DataName,'q')
        y = handles.CoreProfiles.profiles_1d{1,Times(1,it)}.q;
    elseif strcmp(DataName,'rho_t_o_r _n_o_r_m')
        y = handles.CoreProfiles.profiles_1d{1,Times(1,it)}.grid.rho_tor_norm;
        x = zeros(length(handles.CoreProfiles.profiles_1d{1,Times(1,it)}.grid.rho_tor_norm));
        for i=1:length(x)
            x(i) = (i-1)/(length(x)-1);
        end
    else
        return
    end


    if UserData.Lines(it) == -1
        UserData.Lines(it) = line(NaN,NaN);
    end


    CurTime = t(Times(1,it));

    set(UserData.Lines(it),'XData',x,'YData',y);

    set(UserData.Lines(it),'Color',ColorString(it));

    LegendStrings{length(LegendStrings)+1} = ['t = ' num2str(CurTime) ' s'];

end


for it = (size(Times,2)+1):GraphsInAxes;
    set(UserData.Lines(it),'XData',NaN,'YData',NaN);
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

