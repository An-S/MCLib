##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=MyCLib
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Stefan\Documents\Programmieren\EigeneCProgramme\MyCLib"
ProjectPath            := "C:\Users\Stefan\Documents\Programmieren\EigeneCProgramme\MyCLib"
IntermediateDirectory  :=$(VirtualFolder)/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Stefan
Date                   :=09/04/14
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="MyCLib.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/MallocWrapper_imalloc.c$(ObjectSuffix) $(IntermediateDirectory)/MallocWrapper_imalloc_blockheader.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "C:\Users\Stefan\Documents\Programmieren\EigeneCProgramme\MyCLib/.build-debug"
	@echo rebuilt > "C:\Users\Stefan\Documents\Programmieren\EigeneCProgramme\MyCLib/.build-debug/MyCLib"

$(VirtualFolder)/Debug:
	@$(MakeDirCommand) "$(VirtualFolder)/Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/MallocWrapper_imalloc.c$(ObjectSuffix): MallocWrapper/imalloc.c $(IntermediateDirectory)/MallocWrapper_imalloc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Stefan/Documents/Programmieren/EigeneCProgramme/MyCLib/MallocWrapper/imalloc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MallocWrapper_imalloc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MallocWrapper_imalloc.c$(DependSuffix): MallocWrapper/imalloc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MallocWrapper_imalloc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/MallocWrapper_imalloc.c$(DependSuffix) -MM "MallocWrapper/imalloc.c"

$(IntermediateDirectory)/MallocWrapper_imalloc.c$(PreprocessSuffix): MallocWrapper/imalloc.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MallocWrapper_imalloc.c$(PreprocessSuffix) "MallocWrapper/imalloc.c"

$(IntermediateDirectory)/MallocWrapper_imalloc_blockheader.c$(ObjectSuffix): MallocWrapper/imalloc_blockheader.c $(IntermediateDirectory)/MallocWrapper_imalloc_blockheader.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Stefan/Documents/Programmieren/EigeneCProgramme/MyCLib/MallocWrapper/imalloc_blockheader.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MallocWrapper_imalloc_blockheader.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MallocWrapper_imalloc_blockheader.c$(DependSuffix): MallocWrapper/imalloc_blockheader.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MallocWrapper_imalloc_blockheader.c$(ObjectSuffix) -MF$(IntermediateDirectory)/MallocWrapper_imalloc_blockheader.c$(DependSuffix) -MM "MallocWrapper/imalloc_blockheader.c"

$(IntermediateDirectory)/MallocWrapper_imalloc_blockheader.c$(PreprocessSuffix): MallocWrapper/imalloc_blockheader.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MallocWrapper_imalloc_blockheader.c$(PreprocessSuffix) "MallocWrapper/imalloc_blockheader.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(VirtualFolder)/Debug/*$(ObjectSuffix)
	$(RM) $(VirtualFolder)/Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)
	$(RM) ".build-debug/MyCLib"


