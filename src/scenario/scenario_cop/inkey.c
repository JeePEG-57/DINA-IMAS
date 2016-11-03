/*The file includes the next C-functions:
  initvm_    openWindow    createGC    newgc_    endvm_    drawvm_   rectvm_
  erasvm_    colovm_       redraw_     waitas_   textvm_   askev_    events_
  */
#include	<X11/Xlib.h>
#include	<X11/Xutil.h>
#include 	<X11/cursorfont.h>
#include 	<stdio.h>
#include	<signal.h>
#include	"x_pc_c.dat"
#include	<X11/keysym.h>
#include	<X11/keysymdef.h>
Display		*theDisplay;
Window		theRootWindow, theMenuWindow;
GC		theGC;
XGCValues	GCValues;

XFontStruct	*fontStructR, *fontStruct1;
Colormap	theColormap;
Cursor		theRootCursor, theMenuCursor, thePauseCursor;
long	int	XWx,XWy,XWwidth,XWheight;
int		theScreen;
int		theDepth;
int		xButton,yButton;
int		iconState, geomStatus;
unsigned long	theBlackPixel;
unsigned long	theWhitePixel;
XEvent		theEvent;
char *ColorNames[16]={"Black","NavyBlue","DarkGreen","cyan4",
			"red4","magenta4","Brown","LightGray",
			"gray","Blue","Green","Cyan",
			"Red","Magenta","Yellow","White"};
/*
char *ColorNames[16]={"Black","NavyBlue","DarkGreen","cyan4",
			"red4","magenta4","Brown","LightGray",
			"gray","gray","gray","gray",
			"gray","LightGray","LightGray","White"};
char *ColorNames[16]={"Black","NavyBlue","DarkGreen","cyan4",
			"red4","magenta4","Brown","LightGray",
			"White","White","White","White",
			"Black","White","White","White"};
*/

long int ColorPix[16];
int Xbeg=0; Ybeg=0; Pixw; Pixh;
int indSHIFT=1, indCTRL=4, indALT=8, indCAPL=2;

#define	BORDER_WIDTH	2
#define	NORMAL_WINDOW	0
#define	POP_UP_WINDOW	1
#define	DEFAULT_GEOMETRY	NULL
#define	DEFAULT_FONT1	"variable"
#define	DEFAULT_FONT2	"8x13"
#define	DEFAULT_FONT3	"8x13bold"
#define	DEFAULT_TITLE	"ASTRA"
#define EV_MASK (ButtonPressMask | StructureNotifyMask |\
		 KeyPressMask | ExposureMask |  KeyPressMask)

initvm_(x,y,width,height)
     int	*x,*y,*width,*height;
{
  Window	openWindow();
  XFontStruct	*initFont();
  char		theDisplayName[120], theTitle[120];
  GC		theD1GC, theD2GC, theD3GC;
  XColor        theColor;
  int i;
  XWx=*x;	XWy=*y;	XWwidth=*width;	XWheight=*height;
  theDisplay	=XOpenDisplay(NULL);
  if(theDisplay == NULL)
    {
      fprintf(stderr,
	      "ERROR: Cannot connect to the X Server %s\n",
	      XDisplayName(NULL));
      exit(1);
    }
  theScreen	=DefaultScreen(theDisplay);
  theDepth	=DefaultDepth(theDisplay,theScreen);
  theBlackPixel	=BlackPixel(theDisplay,theScreen);
  theWhitePixel	=WhitePixel(theDisplay,theScreen);
  theColormap	= DefaultColormap(theDisplay,theScreen);
  theRootCursor	= XCreateFontCursor(theDisplay,XC_fleur);
  theMenuCursor	= XCreateFontCursor(theDisplay,XC_hand2);
  thePauseCursor= XCreateFontCursor(theDisplay,XC_X_cursor);
/*  
    Get environment information (not used):

    printf("%s version %d of the X Window system, X%d R%d\n",
    ServerVendor(theDisplay),
    VendorRelease(theDisplay),
    ProtocolVersion(theDisplay),
    ProtocolRevision(theDisplay));
    if(theDepth==1)
    printf("Color plane depth        %d (monochrome)\n",theDepth);
    else	printf("Color plane depth     %d\n",theDepth);
    printf("Display Width         %d\n",
    DisplayWidth (theDisplay,theScreen));
    printf("Display Height         %d\n",
    DisplayHeight (theDisplay,theScreen));
    printf("The display %s\n", XDisplayName(theDisplay));
  

    Open root XWindow
    */
 
 iconState	= 0;
  strcpy( theTitle,"EMEQ");

  theRootWindow	=openWindow(*x,*y,*width,*height,0,
			    theTitle, iconState,
			    RootWindow(theDisplay,theScreen),
			    &theGC, theRootCursor);
  
  XSelectInput (theDisplay, theRootWindow, EV_MASK);
  /*Determine default font
    5x7,6x10,7x13,8x13,9x15,10x20,12x24
    */
  
  fontStructR	=initFont(theGC,"9x15"); Pixw=8; Pixh=13;
  for(i=0; i<16;i++)
    {
      XParseColor(theDisplay,theColormap,ColorNames[i],&theColor);
      XAllocColor(theDisplay,theColormap,&theColor);
      ColorPix[i]=theColor.pixel;
    }
}

XFontStruct	*initFont(theGC,fontName)
     GC		theGC;
     char		fontName[];
{
  XFontStruct	*fontStruct;
  fontStruct	=XLoadQueryFont(theDisplay,fontName);
  if(fontStruct != NULL)
    {XSetFont(theDisplay,theGC,fontStruct->fid);}
  return(fontStruct);
}

Window openWindow (x, y, width, height, flag,
		   theTitle, iconicState, theParent, theNewGC, theCursor)
     int	x, y, width, height;
     int	flag,iconicState;
     char	theTitle[];
     Window	theParent;
     GC	        *theNewGC;
     Cursor	theCursor;
{
  XSetWindowAttributes theWindowAttributes;
  XSizeHints theSizeHints;
  unsigned long theWindowMask;
  Window theNewWindow;
  Pixmap theIconPixmap;
  XWMHints theWMHints;
  XClassHint	theClassHint;
  theWindowAttributes.border_pixel	= theBlackPixel;
  theWindowAttributes.background_pixel	= theWhitePixel;
  theWindowAttributes.cursor		= theCursor;
  if(flag == POP_UP_WINDOW)
    {
      theWindowAttributes.override_redirect	= True;
      theWindowAttributes.save_under		= True;
      theWindowMask
	= CWBackPixel | CWBorderPixel | CWCursor | CWOverrideRedirect;
    }
  else
    {
      theWindowAttributes.override_redirect	= False;
      theWindowMask 	= CWBackPixel | CWBorderPixel;
    }
  
  theNewWindow = XCreateWindow (theDisplay, theParent,
				x, y, width, height, BORDER_WIDTH,
				theDepth, InputOutput, CopyFromParent,
				theWindowMask, &theWindowAttributes);
  
  theIconPixmap = XCreateBitmapFromData (theDisplay,
					 theNewWindow,
					 theIcon_bits,
					 theIcon_width,
					 theIcon_height);
  
  theWMHints.input = True;
  if(iconicState == 0)	theWMHints.initial_state= NormalState;
  else			theWMHints.initial_state= IconicState;
  
  theWMHints.icon_pixmap = theIconPixmap;
  theWMHints.flags  = InputHint | IconPixmapHint | StateHint;
  
  XSetWMHints (theDisplay, theNewWindow, &theWMHints);
  XStoreName (theDisplay, theNewWindow, theTitle);
  
  theSizeHints.flags = USPosition | PSize;
  theSizeHints.x = x;
  theSizeHints.y = y;
  theSizeHints.width = width;
  theSizeHints.height = height;
  
  XSetNormalHints (theDisplay, theNewWindow, &theSizeHints);
  
  if (createGC (theNewWindow, theNewGC) == 0)
    {
      XDestroyWindow (theDisplay, theNewWindow);
      return (Window) 0 ;
    }
  
  XMapWindow (theDisplay, theNewWindow);
  XFlush (theDisplay);
  
  if(flag == NORMAL_WINDOW)
    {
      sleep(1);
      XDrawRectangle(theDisplay,theNewWindow,
		     *theNewGC,0L,0L,width-1L,height-1L);
    }
  return theNewWindow;
}

createGC(theWindow,theNewGC)
     Window	theWindow;
     GC	*theNewGC;
{
  XGCValues	theGCValues;
  unsigned long	theValueMask;
  theValueMask	=0L;
  *theNewGC	= XCreateGC(theDisplay,theWindow,
			    theValueMask,&theGCValues);
  if	(*theNewGC==0){return(0);}
  else{	XSetForeground(theDisplay,*theNewGC,theBlackPixel);
	XSetBackground(theDisplay,*theNewGC,theWhitePixel);
	return(1);}
}

wrtchr_(filenm,string)
     char filenm[],string[];
{
  FILE *fl;
  short int i;
  char  nm[40];
  i=0;
  while (filenm[i]!=' ')
    {nm[i]=filenm[i];
     i++;}
  nm[i]=0;
  fl=fopen(nm,"w+");
  
  if(fl != NULL)
    {
      fputs(string,fl);
    }
  else
    printf("I can't open the file\n");  
  if( fclose(fl) !=NULL)
    printf("I cannot close the file\n");  
}

endvm_()
{	XDestroySubwindows(theDisplay,theRootWindow);
	XDestroyWindow(theDisplay,theRootWindow);
	if(fontStructR != 0)	XFreeFont(theDisplay,fontStructR);
	if(fontStruct1 != 0)	XFreeFont(theDisplay,fontStruct1);
	XFreeGC(theDisplay,theGC);
	XFreeCursor(theDisplay, theMenuCursor);
	XFreeCursor(theDisplay, thePauseCursor);
	XFreeCursor(theDisplay, theRootCursor);
	XCloseDisplay(theDisplay);
}

/*=======================================================================*/
moveab_(x,y)
     float *x,*y;
{
  Xbeg=*x; Ybeg=*y;
}

drawab_(x,y)
     float *x,*y;
{
  int x2,y2;
  x2=*x; y2=*y;
  XDrawLine(theDisplay,theRootWindow,theGC,Xbeg,Ybeg,x2,y2);
  Xbeg=x2; Ybeg=y2;
}

moveto_(ix,iy)
     int *ix,*iy;
{
  Xbeg=*ix; Ybeg=*iy;
}

lineto_(ix,iy)
     int *ix,*iy;
{
  int x2,y2;
  x2=*ix; y2=*iy;
  XDrawLine(theDisplay,theRootWindow,theGC,Xbeg,Ybeg,x2,y2);
  Xbeg=x2; Ybeg=y2;
}

drawvm_(x1,y1,x2,y2)
	int	*x1,*y1,*x2,*y2;
{
  XDrawLine(theDisplay,theRootWindow,theGC,*x1,*y1,*x2,*y2);
}

rectvm_(x,y,w,h,fill)
     int	*x,*y,*w,*h;
     Bool *fill;
{
  if(*fill)
    {
      XFillRectangle(theDisplay,theRootWindow,theGC,*x,*y,*w,*h);
    }
  else
    {
      XDrawRectangle(theDisplay,theRootWindow,theGC,*x,*y,*w,*h);
    }
}

rectab_(x,y,x1,y1,fill)
     int	*x,*y,*x1,*y1;
     Bool *fill;
{
  int X,Y,W,H;
  if(*x > *x1)
    {X=*x1;W=*x-*x1;}
  else
    {X=*x;W=*x1-*x;}
  if(*y > *y1)
    {Y=*y1;H=*y-*y1;}
  else
    {Y=*y;H=*y1-*y;}

  if(*fill)
    {
      XFillRectangle(theDisplay,theRootWindow,theGC,X,Y,W,H);
    }
  else
    {
      XDrawRectangle(theDisplay,theRootWindow,theGC,X,Y,W,H);
    }
}

/*curvvm_(number,array)
	long	int	*number,*array[];
{	long	int	Xnumber,Xx1,Xx2,Xy1,Xy2,i;
	if(*number<=0)	return 0;
	Xnumber	=*number;	Xx1=*array[0];	Xy1=*array[1];
	i	=0;	while(i<=Xnumber)
	{	Xx2=*array[2*i];	Xy2=*array[2*i+1];
	XDrawLine(theDisplay,theRootWindow,theGC,Xx1,Xy1,Xx2,Xy2);
	Xx1=Xx2;	Xy1=Xy2;	i++;}
}*/

erasvm_()
{
XClearWindow(theDisplay, theRootWindow);
}

setlin_(style,width)
     int	*style,*width;
{	unsigned	long	theMask;
	XGCValues	theXGCV;
	static unsigned char dash[8]={8,2,2,2,12,2,4,4};
	if(*style)
	  theXGCV.line_style=LineOnOffDash;
	else
	  theXGCV.line_style=LineSolid;
	switch(*style)
	  {
	  case 0: break;
	  case 1: 
	    XSetDashes(theDisplay,theGC,0,dash+2,2);break;
	  case 2: 
	    XSetDashes(theDisplay,theGC,0,dash,2);break;
	  case 3: 
	    XSetDashes(theDisplay,theGC,0,dash,4);break;
	  case 4: 
	    XSetDashes(theDisplay,theGC,0,dash+4,2);break;
	  case 5: 
	    XSetDashes(theDisplay,theGC,0,dash+2,4);break;
	  case 6: 
	    XSetDashes(theDisplay,theGC,0,dash+6,2);break;
	  default: 
	    XSetDashes(theDisplay,theGC,0,dash+4,4);break;
	  }
	theXGCV.line_width	=*width;
	theMask	=GCLineWidth|GCLineStyle;
	XChangeGC(theDisplay,theGC,theMask,&theXGCV);
}

color_(color)
     int	*color;
{
  XSetForeground(theDisplay,theGC,ColorPix[*color]);
}

redraw_()
{
  XFlush(theDisplay);
}

waitas_(sec)
	long	int	*sec;
{	sleep(*sec);		}

textvm_(x,y,string,string_length)
	int	*x,*y,*string_length;
	char	string[];
{	XDrawString(theDisplay,theRootWindow,theGC,*x,*y,
			string,*string_length);
}

text_(string,length)
     int	*length;
     char	string[];
{
  long	int Xsl;
  Xsl=*length;
/*
  XFillRectangle(theDisplay,theRootWindow,theGC,Xbeg,Ybeg,Xsl*Pixw,Pixh);
*/
  XDrawString(theDisplay,theRootWindow,theGC,Xbeg,Ybeg+Pixh-2,string,Xsl);
}

dfnfnt_(sfont,width,zero)
int	*sfont,*width,*zero;
{
switch(*width)
  {
  case 5:     fontStructR=initFont(theGC,"5x7");Pixw=5;Pixh=7;break;
  case 6:    fontStructR=initFont(theGC,"6x10");Pixw=6;Pixh=10;break;
  case 7:    fontStructR=initFont(theGC,"7x13");Pixw=5;Pixh=13;break;
  case 8:    fontStructR=initFont(theGC,"8x13");Pixw=8;Pixh=13;break;
  case 9:    fontStructR=initFont(theGC,"9x15");Pixw=9;Pixh=15;break;
  case 10:    fontStructR=initFont(theGC,"10x20");Pixw=10;Pixh=20;break;
  case 12:    fontStructR=initFont(theGC,"12x24");Pixw=12;Pixh=24;break;
  }
}
/*----------------------------------------------------------------------*/
keybrd_(Key1,Key2,Keycod)
     unsigned char *Key1,*Key2,*Keycod;
{
  short int ind;
  /*
    the comments may be included to adjust cases to the keyboard
    */
  XComposeStatus	theComposeStatus;
  KeySym		theKeySym;
  int		length, ix, iy, theKeyBufferMaxLen = 64;
  char		theKeyBuffer[65];
  XNextEvent(theDisplay, &theEvent);
  ind=1&theEvent.xkey.state;
  printf("code=%d, st=%d, ind=%d\t",
	 theEvent.xkey.keycode,theEvent.xkey.state,ind);
  *Keycod=theEvent.xkey.keycode;
  switch(theEvent.xkey.keycode)
    {
    case  36: *Key1= 97; break;
    case  58: *Key1= 98; break;
    case  41: *Key1= 99; break;
    case  43: *Key1=100; break;
    case  44: *Key1=101; break;
    case  51: *Key1=102; break;
    case  60: *Key1=103; break;
    case  59: *Key1=104; break;
    case  75: *Key1=105; break;
    case  67: *Key1=106; break;
    case  74: *Key1=107; break;
    case  83: *Key1=108; break;
    case  66: *Key1=109; break;
    case  57: *Key1=110; break;
    case  76: *Key1=111; break;
    case  85: *Key1=112; break;
    case  29: *Key1=113; break;
    case  53: *Key1=114; break;
    case  35: *Key1=115; break;
    case  52: *Key1=116; break;
    case  68: *Key1=117; break;
    case  50: *Key1=118; break;
    case  37: *Key1=119; break;
    case  42: *Key1=120; break;
    case  61: *Key1=121; break;
    case  34: *Key1=122; break;
    default: switch(theEvent.xkey.keycode)
      {
      case  49: *Key1= 32; break;
      case  82: if(ind) *Key1= 63; else *Key1= 47; break;
      case  77: if(ind) *Key1= 41; else *Key1= 48; break;
      case  30: if(ind) *Key1= 33; else *Key1= 49; break;
      case  38: if(ind) *Key1= 64; else *Key1= 50; break;
      case  46: if(ind) *Key1= 35; else *Key1= 51; break;
      case  45: if(ind) *Key1= 36; else *Key1= 52; break;
      case  54: if(ind) *Key1= 37; else *Key1= 53; break;
      case  62: if(ind) *Key1= 94; else *Key1= 54; break;
      case  69: if(ind) *Key1= 38; else *Key1= 55; break;
      case  70: if(ind) *Key1= 42; else *Key1= 56; break;
      case  78: if(ind) *Key1= 40; else *Key1= 57; break;
      case  73: if(ind) *Key1= 60; else *Key1= 44; break;
      case  81: if(ind) *Key1= 62; else *Key1= 46; break;
      case  84: if(ind) *Key1= 58; else *Key1= 59; break;
      case  90: if(ind) *Key1= 34; else *Key1= 39; break;
      case  22: if(ind) *Key1=126; else *Key1= 96; break;
      case  92: if(ind) *Key1=123; else *Key1= 91; break;
      case  99: if(ind) *Key1=125; else *Key1= 93; break;
      case  86: if(ind) *Key1= 95; else *Key1= 45; break;
      case  93: if(ind) *Key1= 43; else *Key1= 61; break;
      case 100: if(ind) *Key1=124; else *Key1= 92; break;
      default: *Key1= 0;
	switch(theEvent.xkey.keycode)
	  {
	  case  98: printf("'Ret   '\t K_S=%d",65293);
	    *Key2=  0;*Key1= 13;break;
	  case 110: printf("'BS    '\t K_S=%d",65535);
	    *Key2= 14;*Key1=  8;break;
	  case  16: printf("'Esc   '\t K_S=%d",65307);
	    *Key2=  0;*Key1= 27;break;
	  case  21: printf("'TAB   '\t K_S=%d",65289);
	    *Key2=  0;*Key1= 9; break;
	  case   1: printf("'Bt_1  '\t K_S=%d",65293); *Key2=  1; break;
	  case   2: printf("'Bt_2  '\t K_S=%d",65293); *Key2=  2; break;
	  case   3: printf("'Bt_3  '\t K_S=%d",65293); *Key2=  3; break;
	  case 108: printf("'Del   '\t K_S=%d",65288); *Key2=248; break;
	  case 111: printf("'Ins   '\t K_S=%d",65379); *Key2= 83; break;
	  case  28: printf("'Ctrl  '\t K_S=%d",65507); *Key2= 29; break;
	  case  26: printf("'Shft-L'\t K_S=%d",65505); *Key2= 31; break;
	  case  25: printf("'CapL  '\t K_S=%d",65509); *Key2= 27; break;
	  case  33: printf("'Alt-L '\t K_S=%d",65511); *Key2= 25; break;
	  case  65: printf("'Alt-R '\t K_S=%d",65512); *Key2= 24; break;
	  case  96: printf("'Opt   '\t K_S=%d",65508); *Key2= 28; break;
	  case  97: printf("'Shft-R'\t K_S=%d",65506); *Key2= 30; break;
	  case 105: printf("'Left  '\t K_S=%d",65361); *Key2= 75; break;
	  case 107: printf("'Up    '\t K_S=%d",65362); *Key2= 72; break;
	  case 104: printf("'Down  '\t K_S=%d",65364); *Key2= 80; break;
	  case 114: printf("'Right '\t K_S=%d",65363); *Key2= 77; break;
	  case 118: printf("'Home  '\t K_S=%d",65360); *Key2= 71; break;
	  case 109: printf("'End   '\t K_S=%d",65367); *Key2= 79; break;
	  case 119: printf("'PgUp  '\t K_S=%d",65365); *Key2= 73; break;
	  case 117: printf("'PgDn  '\t K_S=%d",65366); *Key2= 81; break;
	  case  15: printf("'F1    '\t K_S=%d",65470); *Key2= 66; break;
	  case  23: printf("'F2    '\t K_S=%d",65471); *Key2= 65; break;
	  case  31: printf("'F3    '\t K_S=%d",65472); *Key2= 64; break;
	  case  39: printf("'F4    '\t K_S=%d",65473); *Key2= 63; break;
	  case  47: printf("'F5    '\t K_S=%d",65474); *Key2= 62; break;
	  case  55: printf("'F6    '\t K_S=%d",65475); *Key2= 61; break;
	  case  63: printf("'F7    '\t K_S=%d",65476); *Key2= 60; break;
	  case  71: printf("'F8    '\t K_S=%d",65477); *Key2= 59; break;
	  case  79: printf("'F9    '\t K_S=%d",65478); *Key2= 58; break;
	  case  87: printf("'F10   '\t K_S=%d",65479); *Key2= 57; break;
	  case  94: printf("'F11   '\t K_S=%d",65480); *Key2= 56; break;
	  case 102: printf("'F12   '\t K_S=%d",65481); *Key2= 55; break;
	  case  95: printf("'LFeed '\t K_S=%d",65290); *Key2=246; break;
	  case 103: printf("'Break '\t K_S=%d",65387); *Key2=149; break;
	  case 126: printf("'NumL  '\t K_S=%d",65407); *Key2=129; break;
	  case 127: printf("'Grey/ '\t K_S=%d",65455); *Key2= 81; break;
	  case 134: printf("'Grey* '\t K_S=%d",65450); *Key2= 86; break;
	  case 140: printf("'Grey- '\t K_S=%d",65453); *Key2= 83; break;
	  case 116: printf("'GHome '\t K_S=%d",65463); *Key2= 71; break;
	  case 125: printf("'GUp   '\t K_S=%d",65464); *Key2= 72; break;
	  case 133: printf("'GPgUp '\t K_S=%d",65465); *Key2= 73; break;
	  case 132: printf("'Grey+ '\t K_S=%d",65451); *Key2= 85; break;
	  case 115: printf("'G<=   '\t K_S=%d",65460); *Key2= 75; break;
	  case 123: printf("'G_    '\t K_S=%d",65461); *Key2= 75; break;
	  case 124: printf("'G=>   '\t K_S=%d",65462); *Key2= 77; break;
	  case 113: printf("'GEnd  '\t K_S=%d",65457); *Key2= 79; break;
	  case 122: printf("'GDn   '\t K_S=%d",65458); *Key2= 80; break;
	  case 130: printf("'GPgDn '\t K_S=%d",65459); *Key2= 81; break;
	  case 120: printf("'GIns  '\t K_S=%d",65456); *Key2= 83; break;
	  case 121: printf("'Del   '\t K_S=%d",65288); *Key2=248; break;
	  case 129: printf("'Enter '\t K_S=%d",65421); *Key2=115; break;
	  default: break;
	  }
	printf("\t%d %d\n",*Key1,*Key2);
	return 2;
      }
      *Key2=0;
      printf("'%c'\t K_S=%d\t%d %d\n",*Key1,*Key1,*Key1,*Key2);
      return 1;
    }
  *Key2=0;
  if(3&theEvent.xkey.state) *Key1=*Key1&223;
  if(4&theEvent.xkey.state) {printf("'^%c'",*Key1); *Key1=*Key1&159;}
  else printf("'%c'",*Key1);
  printf("\t K_S=%d\t%d %d\n",*Key1,*Key1,*Key2);
  return 0;
}
/*----------------------------------------------------------------------*/
inkey_(Key2,Key1)
     unsigned char *Key1,*Key2;
{
  short int ind;
  /*
    the comments may be included to adjust cases to the keyboard
    */
  XComposeStatus	theComposeStatus;
  KeySym		theKeySym;
  int		length, ix, iy, theKeyBufferMaxLen = 64;
  char		theKeyBuffer[65];
  /*
  XSelectInput (theDisplay, theRootWindow, EV_MASK);
    get event;
    switch(keycode)
    {
    case alpha:...break;
    default:switch(keycode):
    {case alphabetic:...break;
    default:switch(keycode)
    {case:other;break;
    default:unknown;breake;
    }
    return 2;
    }
    return 1;
    }
    return 0;
    */
  XNextEvent(theDisplay, &theEvent);
/*
  printf("code=%d, st=%d, ind=%d\n",
  theEvent.xkey.x,theEvent.xkey.y,ind);
*/
  ind=1&theEvent.xkey.state;
  switch(theEvent.xkey.keycode)
    {
    case  36: *Key1= 97; break;
    case  58: *Key1= 98; break;
    case  41: *Key1= 99; break;
    case  43: *Key1=100; break;
    case  44: *Key1=101; break;
    case  51: *Key1=102; break;
    case  60: *Key1=103; break;
    case  59: *Key1=104; break;
    case  75: *Key1=105; break;
    case  67: *Key1=106; break;
    case  74: *Key1=107; break;
    case  83: *Key1=108; break;
    case  66: *Key1=109; break;
    case  57: *Key1=110; break;
    case  76: *Key1=111; break;
    case  85: *Key1=112; break;
    case  29: *Key1=113; break;
    case  53: *Key1=114; break;
    case  35: *Key1=115; break;
    case  52: *Key1=116; break;
    case  68: *Key1=117; break;
    case  50: *Key1=118; break;
    case  37: *Key1=119; break;
    case  42: *Key1=120; break;
    case  61: *Key1=121; break;
    case  34: *Key1=122; break;
    default: switch(theEvent.xkey.keycode)
      {
      case  49: *Key1= 32; break;
      case  82: if(ind) *Key1= 63; else *Key1= 47; break;
      case  77: if(ind) *Key1= 41; else *Key1= 48; break;
      case  30: if(ind) *Key1= 33; else *Key1= 49; break;
      case  38: if(ind) *Key1= 64; else *Key1= 50; break;
      case  46: if(ind) *Key1= 35; else *Key1= 51; break;
      case  45: if(ind) *Key1= 36; else *Key1= 52; break;
      case  54: if(ind) *Key1= 37; else *Key1= 53; break;
      case  62: if(ind) *Key1= 94; else *Key1= 54; break;
      case  69: if(ind) *Key1= 38; else *Key1= 55; break;
      case  70: if(ind) *Key1= 42; else *Key1= 56; break;
      case  78: if(ind) *Key1= 40; else *Key1= 57; break;
      case  73: if(ind) *Key1= 60; else *Key1= 44; break;
      case  81: if(ind) *Key1= 62; else *Key1= 46; break;
      case  84: if(ind) *Key1= 58; else *Key1= 59; break;
      case  90: if(ind) *Key1= 34; else *Key1= 39; break;
      case  22: if(ind) *Key1=126; else *Key1= 96; break;
      case  92: if(ind) *Key1=123; else *Key1= 91; break;
      case  99: if(ind) *Key1=125; else *Key1= 93; break;
      case  86: if(ind) *Key1= 95; else *Key1= 45; break;
      case  93: if(ind) *Key1= 43; else *Key1= 61; break;
      case 100: if(ind) *Key1=124; else *Key1= 92; break;
      default: *Key1= 0;
	switch(theEvent.xkey.keycode)
	  {
	  case  98:*Key2=  0;*Key1= 13;break;
	  case 110:*Key2= 14;*Key1=  8;break;
	  case  16:*Key2=  0;*Key1= 27;break;
	  case  21:*Key2=  0;*Key1= 9; break;
	  case   1: *Key2=  1; break;
	  case   2: *Key2=  2; break;
	  case   3: *Key2=  3; break;
	  case 108: *Key2=248; break;
	  case 111: *Key2= 83; break;
	  case  28: *Key2= 29; break;
	  case  26: *Key2= 31; break;
	  case  25: *Key2= 27; break;
	  case  33: *Key2= 25; break;
	  case  65: *Key2= 24; break;
	  case  96: *Key2= 28; break;
	  case  97: *Key2= 30; break;
	  case 105: *Key2= 75; break;
	  case 107: *Key2= 72; break;
	  case 104: *Key2= 80; break;
	  case 114: *Key2= 77; break;
	  case 118: *Key2= 71; break;
	  case 109: *Key2= 79; break;
	  case 119: *Key2= 73; break;
	  case 117: *Key2= 81; break;
	  case  15: *Key2= 66; break;
	  case  23: *Key2= 65; break;
	  case  31: *Key2= 64; break;
	  case  39: *Key2= 63; break;
	  case  47: *Key2= 62; break;
	  case  55: *Key2= 61; break;
	  case  63: *Key2= 60; break;
	  case  71: *Key2= 59; break;
	  case  79: *Key2= 58; break;
	  case  87: *Key2= 57; break;
	  case  94: *Key2= 56; break;
	  case 102: *Key2= 55; break;
	  case  95: *Key2=246; break;
	  case 103: *Key2=149; break;
	  case 126: *Key2=129; break;
	  case 127: *Key2= 81; break;
	  case 134: *Key2= 86; break;
	  case 140: *Key2= 83; break;
	  case 116: *Key2= 71; break;
	  case 125: *Key2= 72; break;
	  case 133: *Key2= 73; break;
	  case 132: *Key2= 85; break;
	  case 115: *Key2= 75; break;
	  case 123: *Key2= 75; break;
	  case 124: *Key2= 77; break;
	  case 113: *Key2= 79; break;
	  case 122: *Key2= 80; break;
	  case 130: *Key2= 81; break;
	  case 120: *Key2= 83; break;
	  case 121: *Key2=248; break;
	  case 129: *Key2=115; break;
	  default: break;
	  }
	return 2;
      }
      *Key2=0;
      return 1;
    }
  *Key2=0;
  if(3&theEvent.xkey.state) *Key1=*Key1&223;
  if(4&theEvent.xkey.state) *Key1=*Key1&159;
  return 0;
}
/*----------------------------------------------------------------------*/
xy_scr_(ix,iy)
     int *ix,*iy;
{
  *ix=theEvent.xkey.x;  *iy=theEvent.xkey.y;
}





