# Microsoft Developer Studio Generated NMAKE File, Based on BaseDLG_MFC.dsp
!IF "$(CFG)" == ""
CFG=BaseDLG_MFC - Win32 Debug
!MESSAGE No configuration specified. Defaulting to BaseDLG_MFC - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "BaseDLG_MFC - Win32 Release" && "$(CFG)" != "BaseDLG_MFC - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "BaseDLG_MFC.mak" CFG="BaseDLG_MFC - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "BaseDLG_MFC - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "BaseDLG_MFC - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "BaseDLG_MFC - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\BaseDLG_MFC.exe"


CLEAN :
	-@erase "$(INTDIR)\BaseDLG_MFC.obj"
	-@erase "$(INTDIR)\BaseDLG_MFC.pch"
	-@erase "$(INTDIR)\BaseDLG_MFC.res"
	-@erase "$(INTDIR)\BaseDLG_MFCDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\BaseDLG_MFC.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\BaseDLG_MFC.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x80a /fo"$(INTDIR)\BaseDLG_MFC.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\BaseDLG_MFC.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\BaseDLG_MFC.pdb" /machine:I386 /out:"$(OUTDIR)\BaseDLG_MFC.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BaseDLG_MFC.obj" \
	"$(INTDIR)\BaseDLG_MFCDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\BaseDLG_MFC.res"

"$(OUTDIR)\BaseDLG_MFC.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "BaseDLG_MFC - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\BaseDLG_MFC.exe"


CLEAN :
	-@erase "$(INTDIR)\BaseDLG_MFC.obj"
	-@erase "$(INTDIR)\BaseDLG_MFC.pch"
	-@erase "$(INTDIR)\BaseDLG_MFC.res"
	-@erase "$(INTDIR)\BaseDLG_MFCDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\BaseDLG_MFC.exe"
	-@erase "$(OUTDIR)\BaseDLG_MFC.ilk"
	-@erase "$(OUTDIR)\BaseDLG_MFC.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\BaseDLG_MFC.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x80a /fo"$(INTDIR)\BaseDLG_MFC.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\BaseDLG_MFC.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\BaseDLG_MFC.pdb" /debug /machine:I386 /out:"$(OUTDIR)\BaseDLG_MFC.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BaseDLG_MFC.obj" \
	"$(INTDIR)\BaseDLG_MFCDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\BaseDLG_MFC.res"

"$(OUTDIR)\BaseDLG_MFC.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("BaseDLG_MFC.dep")
!INCLUDE "BaseDLG_MFC.dep"
!ELSE 
!MESSAGE Warning: cannot find "BaseDLG_MFC.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "BaseDLG_MFC - Win32 Release" || "$(CFG)" == "BaseDLG_MFC - Win32 Debug"
SOURCE=.\BaseDLG_MFC.cpp

"$(INTDIR)\BaseDLG_MFC.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\BaseDLG_MFC.pch"


SOURCE=.\BaseDLG_MFC.rc

"$(INTDIR)\BaseDLG_MFC.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\BaseDLG_MFCDlg.cpp

"$(INTDIR)\BaseDLG_MFCDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\BaseDLG_MFC.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "BaseDLG_MFC - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\BaseDLG_MFC.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\BaseDLG_MFC.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "BaseDLG_MFC - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\BaseDLG_MFC.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\BaseDLG_MFC.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

