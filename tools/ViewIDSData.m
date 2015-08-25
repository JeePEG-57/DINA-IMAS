function varargout = ViewIDSData(varargin)
% VIEWIDSDATA MATLAB code for ViewIDSData.fig
%      VIEWIDSDATA, by itself, creates a new VIEWIDSDATA or raises the existing
%      singleton*.
%
%      H = VIEWIDSDATA returns the handle to a new VIEWIDSDATA or the handle to
%      the existing singleton*.
%
%      VIEWIDSDATA('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in VIEWIDSDATA.M with the given input arguments.
%
%      VIEWIDSDATA('Property','Value',...) creates a new VIEWIDSDATA or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ViewIDSData_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ViewIDSData_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ViewIDSData

% Last Modified by GUIDE v2.5 24-Aug-2015 21:10:50

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ViewIDSData_OpeningFcn, ...
                   'gui_OutputFcn',  @ViewIDSData_OutputFcn, ...
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


% --- Executes just before ViewIDSData is made visible.
function ViewIDSData_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ViewIDSData (see VARARGIN)

% Choose default command line output for ViewIDSData
handles.output = hObject;



% UIWAIT makes ViewIDSData wait for user response (see UIRESUME)
% uiwait(handles.Figure_ViewIDS);

[MyPath,~,~] = fileparts(mfilename('fullpath'));

handles.MyPath = MyPath;

addpath(MyPath);

addpath([MyPath '/QuantitiesViewer']);
addpath([MyPath '/ProfilesViewer']);
addpath([MyPath '/EquilibriumViewer']);

addpath([MyPath '/mexIDS/fortran']);

handles.Shot = 170;
handles.Run = 5;

% Update handles structure
guidata(hObject, handles);

CreateMex([MyPath '/mexIDS/fortran']);

[~,~] = system(['cp -f -p ' MyPath '/mexIDS/fortran/mexLoadIDS.mex* ' MyPath]);

CheckFields(hObject);



% --- Outputs from this function are returned to the command line.
function varargout = ViewIDSData_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in Main_View0D.
function Main_View0D_Callback(hObject, eventdata, handles)
% hObject    handle to Main_View0D (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
QuantitiesViewer();


% --- Executes on button press in Main_View1D.
function Main_View1D_Callback(hObject, eventdata, handles)
% hObject    handle to Main_View1D (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
ProfilesViewer();


% --- Executes on button press in Main_ViewEq.
function Main_ViewEq_Callback(hObject, eventdata, handles)
% hObject    handle to Main_ViewEq (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
EquilibriumViewer();



function [flag] = CheckFields(hObject)

handles = guidata(hObject);

flag = 0;

Temp = str2double(get(handles.Main_Shot, 'String'));
if isnan(Temp)
    flag = 1;
else
    handles.Shot = round(abs(Temp));
end

Temp = str2double(get(handles.Main_Run, 'String'));
if isnan(Temp)
    flag = 1;
else
    handles.Run = round(abs(Temp));   
end
    
if flag == 0
    guidata(hObject, handles);

    Shot = handles.Shot;
    Run = handles.Run;
    save([handles.MyPath '/IDS_Coordinates.mat'], 'Shot', 'Run');
end



function Main_Shot_Callback(hObject, eventdata, handles)
% hObject    handle to Main_Shot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Main_Shot as text
%        str2double(get(hObject,'String')) returns contents of Main_Shot as a double
CheckFields(hObject);



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
CheckFields(hObject);



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
