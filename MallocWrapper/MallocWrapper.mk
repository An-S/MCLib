##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=MallocWrapper
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Stefan\Documents\Programmieren\EigeneCProgramme\MyCLib"
ProjectPath            := "C:\Users\Stefan\Documents\Programmieren\EigeneCProgramme\MyCLib\MallocWrapper"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Stefan
Date                   :=09/26/14
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="MallocWrapper.txt"
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
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/imalloc.c$(ObjectSuffix) $(IntermediateDirectory)/imalloc_blockheader.c$(ObjectSuffix) $(IntermediateDirectory)/defaultMarkers.c$(ObjectSuffix) $(IntermediateDirectory)/imalloc_errorMessages.c$(ObjectSuffix) $(IntermediateDirectory)/imalloc_blockstructure.c$(ObjectSuffix) $(IntermediateDirectory)/imalloc_helperfunctions.c$(ObjectSuffix) $(IntermediateDirectory)/imalloc_alloclist.c$(ObjectSuffix) $(IntermediateDirectory)/imalloc_alloclistAccessFunctions.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Stefan/Documents/Programmieren/EigeneCProgramme/MyCLib/MallocWrapper/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/imalloc.c$(ObjectSuffix): imalloc.c $(IntermediateDirectory)/imalloc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Stefan/Documents/Programmieren/EigeneCProgramme/MyCLib/MallocWrapper/imalloc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/imalloc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/imalloc.c$(DependSuffix): imalloc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/imalloc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/imalloc.c$(DependSuffix) -MM "imalloc.c"

$(IntermediateDirectory)/imalloc.c$(PreprocessSuffix): imalloc.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/imalloc.c$(PreprocessSuffix) "imalloc.c"

$(IntermediateDirectory)/imalloc_blockheader.c$(ObjectSuffix): imalloc_blockheader.c $(IntermediateDirectory)/imalloc_blockheader.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Stefan/Documents/Programmieren/EigeneCProgramme/MyCLib/MallocWrapper/imalloc_blockheader.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/imalloc_blockheader.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/imalloc_blockheader.c$(DependSuffix): imalloc_blockheader.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/imalloc_blockheader.c$(ObjectSuffix) -MF$(IntermediateDirectory)/imalloc_blockheader.c$(DependSuffix) -MM "imalloc_blockheader.c"

$(IntermediateDirectory)/imalloc_blockheader.c$(PreprocessSuffix): imalloc_blockheader.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/imalloc_blockheader.c$(PreprocessSuffix) "imalloc_blockheader.c"

$(IntermediateDirectory)/defaultMarkers.c$(ObjectSuffix): defaultMarkers.c $(IntermediateDirectory)/defaultMarkers.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Stefan/Documents/Programmieren/EigeneCProgramme/MyCLib/MallocWrapper/defaultMarkers.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/defaultMarkers.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/defaultMarkers.c$(DependSuffix): defaultMarkers.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/defaultMarkers.c$(ObjectSuffix) -MF$(IntermediateDirectory)/defaultMarkers.c$(DependSuffix) -MM "defaultMarkers.c"

$(IntermediateDirectory)/defaultMarkers.c$(PreprocessSuffix): defaultMarkers.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/defaultMarkers.c$(PreprocessSuffix) "defaultMarkers.c"

$(IntermediateDirectory)/imalloc_errorMessages.c$(ObjectSuffix): imalloc_errorMessages.c $(IntermediateDirectory)/imalloc_errorMessages.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Stefan/Documents/Programmieren/EigeneCProgramme/MyCLib/MallocWrapper/imalloc_errorMessages.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/imalloc_errorMessages.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/imalloc_errorMessages.c$(DependSuffix): imalloc_errorMessages.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/imalloc_errorMessages.c$(ObjectSuffix) -MF$(IntermediateDirectory)/imalloc_errorMessages.c$(DependSuffix) -MM "imalloc_errorMessages.c"

$(IntermediateDirectory)/imalloc_errorMessages.c$(PreprocessSuffix): imalloc_errorMessages.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/imalloc_errorMessages.c$(PreprocessSuffix) "imalloc_errorMessages.c"

$(IntermediateDirectory)/imalloc_blockstructure.c$(ObjectSuffix): imalloc_blockstructure.c $(IntermediateDirectory)/imalloc_blockstructure.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Stefan/Documents/Programmieren/EigeneCProgramme/MyCLib/MallocWrapper/imalloc_blockstructure.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/imalloc_blockstructure.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/imalloc_blockstructure.c$(DependSuffix): imalloc_blockstructure.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/imalloc_blockstructure.c$(ObjectSuffix) -MF$(IntermediateDirectory)/imalloc_blockstructure.c$(DependSuffix) -MM "imalloc_blockstructure.c"

$(IntermediateDirectory)/imalloc_blockstructure.c$(PreprocessSuffix): imalloc_blockstructure.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/imalloc_blockstructure.c$(PreprocessSuffix) "imalloc_blockstructure.c"

$(IntermediateDirectory)/imalloc_helperfunctions.c$(ObjectSuffix): imalloc_helperfunctions.c $(IntermediateDirectory)/imalloc_helperfunctions.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Stefan/Documents/Programmieren/EigeneCProgramme/MyCLib/MallocWrapper/imalloc_helperfunctions.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/imalloc_helperfunctions.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/imalloc_helperfunctions.c$(DependSuffix): imalloc_helperfunctions.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/imalloc_helperfunctions.c$(ObjectSuffix) -MF$(IntermediateDirectory)/imalloc_helperfunctions.c$(DependSuffix) -MM "imalloc_helperfunctions.c"

$(IntermediateDirectory)/imalloc_helperfunctions.c$(PreprocessSuffix): imalloc_helperfunctions.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/imalloc_helperfunctions.c$(PreprocessSuffix) "imalloc_helperfunctions.c"

$(IntermediateDirectory)/imalloc_alloclist.c$(ObjectSuffix): imalloc_alloclist.c $(IntermediateDirectory)/imalloc_alloclist.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Stefan/Documents/Programmieren/EigeneCProgramme/MyCLib/MallocWrapper/imalloc_alloclist.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/imalloc_alloclist.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/imalloc_alloclist.c$(DependSuffix): imalloc_alloclist.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/imalloc_alloclist.c$(ObjectSuffix) -MF$(IntermediateDirectory)/imalloc_alloclist.c$(DependSuffix) -MM "imalloc_alloclist.c"

$(IntermediateDirectory)/imalloc_alloclist.c$(PreprocessSuffix): imalloc_alloclist.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/imalloc_alloclist.c$(PreprocessSuffix) "imalloc_alloclist.c"

$(IntermediateDirectory)/imalloc_alloclistAccessFunctions.c$(ObjectSuffix): imalloc_alloclistAccessFunctions.c $(IntermediateDirectory)/imalloc_alloclistAccessFunctions.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Stefan/Documents/Programmieren/EigeneCProgramme/MyCLib/MallocWrapper/imalloc_alloclistAccessFunctions.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/imalloc_alloclistAccessFunctions.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/imalloc_alloclistAccessFunctions.c$(DependSuffix): imalloc_alloclistAccessFunctions.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/imalloc_alloclistAccessFunctions.c$(ObjectSuffix) -MF$(IntermediateDirectory)/imalloc_alloclistAccessFunctions.c$(DependSuffix) -MM "imalloc_alloclistAccessFunctions.c"

$(IntermediateDirectory)/imalloc_alloclistAccessFunctions.c$(PreprocessSuffix): imalloc_alloclistAccessFunctions.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/imalloc_alloclistAccessFunctions.c$(PreprocessSuffix) "imalloc_alloclistAccessFunctions.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/MallocWrapper"


