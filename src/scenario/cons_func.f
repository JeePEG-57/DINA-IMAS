      module IfwinW
    !missing unicode interfaces from IFWIN +  other missing interfaces
         use ifwinty
       !DEC$OBJCOMMENT LIB:"USER32.LIB"
       !DEC$OBJCOMMENT LIB:"KERNEL32.LIB"
        interface 
        function AttachConsole(dwProcessId)
        import !if intel add this missing inteface we should then get an error
        integer(bool)  :: AttachConsole
            !DEC$ ATTRIBUTES DEFAULT, STDCALL, DECORATE, 
     &  ALIAS:'AttachConsole' :: AttachConsole
            integer(dword) :: dwProcessId
            !DEC$ ATTRIBUTES VALUE :: dwProcessId
        end function AttachConsole
       end interface
      END MODULE IfwinW
      
      subroutine OpenCloseConsole(Iopen) !iopen=1 open, iopen=0 close
         use ifwin
       use IfwinW, only: AttachConsole
       use ifport, only: sleep, getlasterror
    
        implicit none
        integer, intent(in)     :: iopen
       integer(bool)           :: bret
        integer(handle)         :: fhandle,hNewScreenBuffer,hFile
       integer(dword)          :: dwX, dwY, dwXSize, dwYSize ! initial size and position of console (pix/screen)
       Type(T_COORD)           :: wpos
       type (T_STARTUPINFO)               :: StartupInfo
       type (T_PROCESS_INFORMATION), save :: ProcessInfo
      
!       structure struc
       


      
!      fhandle =freopen( "CON", "w", stdout ) 


!        bret = AttachConsole(ProcessInfo%dwProcessId)
!        bret = AttachConsole(ATTACH_PARENT_PROCESS)

!	call print1( 'bret==',dfloat(bret))

!        fhandle = GetStdHandle(STD_OUTPUT_HANDLE)
      
!      hFile=DeleteFile("a")
      
      hFile=CreateFile("a",GENERIC_WRITE,
     & FILE_SHARE_READ,NULL,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,0)

 !     hFile=CreateFile("a",GENERIC_WRITE,
 !    & FILE_SHARE_READ,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);


!      hFile=OpenFile("a",OFSTRUCT,
!     & OF_READWRITE);

 
!      hFile=CreateFile("a",GENERIC_WRITE,
!     & FILE_SHARE_READ,NULL,TRUNCATE_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
     
!      bret=FreeConsole()

      bret=AllocConsole() 

      bret=SetStdHandle(STD_OUTPUT_HANDLE,hFile)


!        fhandle = GetStdHandle(STD_OUTPUT_HANDLE)

!	call print1( 'fhandle==',dfloat(fhandle))


!        hNewScreenBuffer = CreateConsoleScreenBuffer( 
!     &   GENERIC_WRITE, 
!     &   FILE_SHARE_WRITE,
!     & NULL,            
!     & CONSOLE_TEXTMODE_BUFFER,
!     & NULL);              
     
     
!       bret =SetConsoleActiveScreenBuffer(hNewScreenBuffer)
!       bret =SetConsoleActiveScreenBuffer(fhandle)
       
       print *,' hello'
      
      end subroutine OpenCloseConsole


    