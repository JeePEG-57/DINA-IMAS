function AxesRefresh(CurAxes)

set(CurAxes,'XLimMode','auto');
set(CurAxes,'YLimMode','auto');

set(CurAxes,'units','pixels');
Axes_Main_Position_P = get(CurAxes,'Position');
set(CurAxes,'units','normalized');

Grow = 0.7;

XLim = get(CurAxes,'XLim');
YLim = get(CurAxes,'YLim');


XLimN = zeros(1, 2); 
YLimN = zeros(1, 2);


XPixels = Axes_Main_Position_P(3);
YPixels = Axes_Main_Position_P(4);


XArea = XLim(2) - XLim(1);
YArea = YLim(2) - YLim(1);


XCoeff = XArea/XPixels;
YCoeff = YArea/YPixels;

MaxCoeff = max([XCoeff YCoeff]);

XAreaNew = MaxCoeff*XPixels;
YAreaNew = MaxCoeff*YPixels;

XLimN(1) = XLim(1) - (XAreaNew - XArea)/2;
XLimN(2) = XLim(2) + (XAreaNew - XArea)/2;

YLimN(1) = YLim(1) - (YAreaNew - YArea)/2;
YLimN(2) = YLim(2) + (YAreaNew - YArea)/2;


set(CurAxes,'XLim',XLimN);
set(CurAxes,'YLim',YLimN);