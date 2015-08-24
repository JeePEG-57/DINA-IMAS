function varargout = EquilibriumViewer(varargin)
% EQUILIBRIUMVIEWER MATLAB code for EQUILIBRIUMVIEWER.fig
%      EQUILIBRIUMVIEWER, by itself, creates a new EQUILIBRIUMVIEWER or raises the existing
%      singleton*.
%
%      H = EQUILIBRIUMVIEWER returns the handle to a new EQUILIBRIUMVIEWER or the handle to
%      the existing singleton*.
%
%      EQUILIBRIUMVIEWER('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in EQUILIBRIUMVIEWER.M with the given input arguments.
%
%      EQUILIBRIUMVIEWER('Property','Value',...) creates a new EQUILIBRIUMVIEWER or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before EQUILIBRIUMVIEWER_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to EQUILIBRIUMVIEWER_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help EQUILIBRIUMVIEWER

% Last Modified by GUIDE v2.5 24-Aug-2015 18:33:45

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @EquilibriumViewer_OpeningFcn, ...
                   'gui_OutputFcn',  @EquilibriumViewer_OutputFcn, ...
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


% --- Executes just before EQUILIBRIUMVIEWER is made visible.
function EquilibriumViewer_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to EQUILIBRIUMVIEWER (see VARARGIN)

% Choose default command line output for EQUILIBRIUMVIEWER
handles.output = hObject;

% UIWAIT makes EQUILIBRIUMVIEWER wait for user response (see UIRESUME)
% uiwait(handles.figure1);

[MyPath,~,~] = fileparts(mfilename('fullpath'));

handles.MyPath = MyPath;

addpath(MyPath);
addpath([MyPath '/..']);

IDSCoords = [MyPath '/../IDS_Coordinates.mat'];
if exist(IDSCoords,'file')
    S = load(IDSCoords);
else
    S = struct('Shot',170,'Run',5);
end

set(handles.Main_Shot, 'String', num2str(S.Shot));
set(handles.Main_Run, 'String', num2str(S.Run));

% Update handles structure
guidata(hObject, handles);


% --- Outputs from this function are returned to the command line.
function varargout = EquilibriumViewer_OutputFcn(hObject, eventdata, handles) 
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

if ~get(handles.Main_ButtonAnimation, 'Value')
    
    handles.Frame = min([handles.Frame+handles.Step handles.MaxStepNumber]);

    guidata(hObject, handles);

    DrawGraphs(hObject, handles.Main_Axes1);
    
    set(handles.Main_AnimationStatus, 'String', ...
        char('Stopped', ['Frame # ' num2str(handles.Frame)]));
end


% --- Executes on button press in Main_Button_Back.
function Main_Button_Back_Callback(hObject, eventdata, handles)
% hObject    handle to Main_Button_Back (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if ~get(handles.Main_ButtonAnimation, 'Value')
    
    handles.Frame = max([handles.Frame-handles.Step 1]);

    guidata(hObject, handles);

    DrawGraphs(hObject, handles.Main_Axes1);

    set(handles.Main_AnimationStatus, 'String', ...
        char('Stopped', ['Frame # ' num2str(handles.Frame)]));
end



% --- Executes on button press in Main_Button_Start.
function Main_Button_Start_Callback(hObject, eventdata, handles)
% hObject    handle to Main_Button_Start (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if ~get(handles.Main_ButtonAnimation, 'Value')
    
    handles.Frame = 1;

    guidata(hObject, handles);

    DrawGraphs(hObject, handles.Main_Axes1);

    set(handles.Main_AnimationStatus, 'String', ...
        char('Stopped', ['Frame # ' num2str(handles.Frame)]));
end



% --- Executes on button press in Main_Button_Finish.
function Main_Button_Finish_Callback(hObject, eventdata, handles)
% hObject    handle to Main_Button_Finish (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if ~get(handles.Main_ButtonAnimation, 'Value')
   
    handles.Frame = handles.MaxStepNumber;

    guidata(hObject, handles);

    DrawGraphs(hObject, handles.Main_Axes1);

    set(handles.Main_AnimationStatus, 'String', ...
        char('Stopped', ['Frame # ' num2str(handles.Frame)]));

end



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

set(handles.Main_LoadingStatus,'String', 'Loading...');
pause(0.01);

handles.Equilibrium = mexLoadIDS(handles.Shot, handles.Run, 'equilibrium');

handles.PFActive = mexLoadIDS(handles.Shot, handles.Run, 'pf_active');
handles.PFPassive = mexLoadIDS(handles.Shot, handles.Run, 'pf_passive');

% handles.Equilibrium = LoadIDS(handles.Shot, handles.Run, 'equilibrium');
% 
% handles.PFActive = LoadIDS(handles.Shot, handles.Run, 'pf_active');
% handles.PFPassive = LoadIDS(handles.Shot, handles.Run, 'pf_passive');


handles.Frame = 1;


Temp = str2double(get(handles.Main_FrameStep, 'String'));
if ~isnan(Temp)
    handles.Step = max([round(abs(Temp)) 1]);
else
    handles.Step = 1;
end

handles.TimeSteps = length(handles.Equilibrium.time);

handles.MaxStepNumber = handles.TimeSteps;

handles.Dynamic = [];

UserData = struct('ProfileName','','Lines',repmat(-1,[1,1]));

UserData.ProfileName = 'psi';
set(handles.Main_Axes1,'UserData',UserData);
cla(handles.Main_Axes1);


guidata(hObject,handles);

set(handles.Main_LoadingStatus,'String', char('Loaded', [num2str(handles.TimeSteps) ' steps']));




function Main_FrameStep_Callback(hObject, eventdata, handles)
% hObject    handle to Main_FrameStep (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Main_FrameStep as text
%        str2double(get(hObject,'String')) returns contents of Main_FrameStep as a double

Default = 1;

Value = str2double(get(hObject,'String'));

if ~isnan(Value)
    Value = round(Value);
    if Value ~= 0
        NewValue = Value;
    else
        NewValue = Default;
    end
else
    NewValue = Default;
end

set(hObject,'String',num2str(NewValue));

handles.Step = NewValue;
guidata(hObject,handles);


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

cla(handles.Main_Axes1);

LoadData(hObject);

handles = guidata(hObject);

DrawStatic(hObject, handles.Main_Axes1);

DrawGraphs(hObject, handles.Main_Axes1, handles.Frame);

AxesRefresh(handles.Main_Axes1);



% --- Executes on button press in Main_ButtonAnimation.
function Main_ButtonAnimation_Callback(hObject, eventdata, handles)
% hObject    handle to Main_ButtonAnimation (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

Code = -1;
CurrentFrame = handles.Frame;

while get(hObject, 'Value')
    
    handles = guidata(hObject);
    
    CurrentFrame = CurrentFrame + handles.Step;
    
    if CurrentFrame <1 || CurrentFrame > handles.MaxStepNumber
        break
    end
   
    [Code] = DrawGraphs(hObject, handles.Main_Axes1, CurrentFrame);

    
    if Code == 0    
        set(handles.Main_AnimationStatus, 'String', ...
            char('Animation...', ['Frame # ' num2str(CurrentFrame)]));
        pause(0.15); 
    end
   
end


set(handles.Main_AnimationStatus, 'String', ...
    char('Stopped', ['Frame # ' num2str(handles.Frame)]));

set(hObject, 'Value', 0);


% --- Executes when figure1 is resized.
function figure1_ResizeFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

handles = guidata(hObject);

if isfield(handles, 'Main_Axes1')
    AxesRefresh(handles.Main_Axes1);
end



% --- Executes on button press in Main_CheckWorkspace.
function Main_CheckWorkspace_Callback(hObject, eventdata, handles)
% hObject    handle to Main_CheckWorkspace (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Main_CheckWorkspace


assignin('base','equilibrium',handles.Equilibrium);
assignin('base','pf_active',handles.PFActive);
assignin('base','pf_passive',handles.PFPassive);



function Main_TargetStep_Callback(hObject, eventdata, handles)
% hObject    handle to Main_TargetStep (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Main_TargetStep as text
%        str2double(get(hObject,'String')) returns contents of Main_TargetStep as a double

Default = 1;

Value = str2double(get(hObject,'String'));

if ~isnan(Value)
    Value = round(Value);
    
    NewFrame = max(Value, Default);
    NewFrame = min(NewFrame, handles.MaxStepNumber);
    
else
    NewFrame = Default;
end

set(hObject,'String',num2str(NewFrame));

handles.Frame = NewFrame;
guidata(hObject,handles);

DrawGraphs(hObject, handles.Main_Axes1, NewFrame);



% --- Executes during object creation, after setting all properties.
function Main_TargetStep_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Main_TargetStep (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
