

#include "ParseCommandLineArgs.h"

/*
//***********************************************************************************************
//set filename for output as given from command line
//***********************************************************************************************
int convSetOFilename(convCmdArgs_t *cmdargs, int argidx, char* argv)
{
  assert (NULL != argv);
  //argv beeing NULL should be catched already in function "convParseCmdArgs"

  cmdargs -> outfilename = argv;
  oFilenameSpecified = true;
  return EXIT_SUCCESS;
}

//***********************************************************************************************
//set beamtype for output as given from command line
//***********************************************************************************************
int convSetBeamType(convCmdArgs_t *cmdargs, int argidx, char* argv)
{
  assert (NULL != argv);
  //argv beeing NULL should be catched already in function "convParseCmdArgs"

  if ( !strcmp (argv, "flat") )
  {
    cmdargs->beamtype = FLATBEAM;
  }else
  if ( !strcmp (argv, "pencil") )
  {
    cmdargs->beamtype = PENCILBEAM;
  }else
  if ( !strcmp (argv, "gaussian") )
  {
    cmdargs->beamtype = GAUSSIANBEAM;
  }
  return EXIT_SUCCESS;
}

//***********************************************************************************************
//set beamwidth as given from command line
//***********************************************************************************************
int convSetBeamWidth(convCmdArgs_t *cmdargs, int argidx, char* argv)
{
  assert (NULL != argv);
  //argv beeing NULL should be catched already in function "convParseCmdArgs"

  cmdargs->beamwidth = atof(argv);
  return EXIT_SUCCESS;
}

//***********************************************************************************************
//set output data type as given from command line
//***********************************************************************************************
int convSetODataType(convCmdArgs_t *cmdargs, int argidx, char* argv)
{
  assert (NULL != argv);
  //argv beeing NULL should be catched already in function "convParseCmdArgs"

  if ( !strcmp (argv, "original") )
  {
    cmdargs->outputtype = ORIGINALDATA;
  }else
  if ( !strcmp (argv, "convolved") )
  {
    cmdargs->outputtype = CONVOLVEDDATA;
  }
  return EXIT_SUCCESS;
}

//***********************************************************************************************
//set output columns format as given from command line
//***********************************************************************************************
int convSetColumnsFormat(convCmdArgs_t *cmdargs, int argidx, char* argv)
{
  int i = 0;

  for (; i < INVALIDCOLUMNFORMAT; i++)
  {
    if ( !strcmp(argv, convColumnFormatNames[i]) )
    {
      cmdargs -> columnformat = i;
      return EXIT_SUCCESS;
    }
  }
  cmdargs -> cmdargerror = INVALIDCOLUMNFORM_ERR;

  return EXIT_FAILURE;
}

char* convCheckOutputFormat(char* specifier, char** allowedspecifiers, size_t nspecifiers)
{
  int i = 0;

  for (; i < nspecifiers; i++)
  {
    if ( !strcmp(specifier, allowedspecifiers[i]) ) return allowedspecifiers[i];
  }
  return NULL;
}


//***********************************************************************************************
//Compare Identifier of command line option with list and return corresponding callback function
//***********************************************************************************************
cmdargOptionCallbackFunc_t *cmdargGetOptionCallbackFunc(char ch, cmdargOptionReaction_t *OptionsCallbackList, size_t noptions)
{
  unsigned int i = 0;

  for (; i < noptions; i++)
  {
    if (ch == OptionsCallbackList[i].spezifier) return OptionsCallbackList[i].OptionCallbackFunc;
  }
  return NULL;
}

//***********************************************************************************************
//check, if the given command line arg starts with '-' -> then it is option
//***********************************************************************************************
void convCmdArgSetError(convCmdArgs_t *cmdargs, int eno, char* errorstr)
{
  cmdargs -> cmdargerror = eno;
  if (NULL != errorstr)
  {
    cmdargs -> cmdargerrstring = errorstr;
  }else
  {
    cmdargs -> cmdargerrstring = convCmdArgErrNames[eno];
  }
}
//***********************************************************************************************
//check, if the given command line arg starts with '-' -> then it is option
//***********************************************************************************************
bool cmdargTestMinus(char* arg)
{
  return '-' == arg[0];
}

//***********************************************************************************************
//parse through list of command line args
//> Output mcml data (h for help) => h
//I   = Input parameters of mcml
//3   = reflectance, absorption, and transmittance
//AL  = absorption vs layer [-]
//Az  = absorption vs z [1/cm]
//Arz = absorption vs r & z [1/cm3]
//Fz  = fluence vs z [-]
//Frz = fluence vs r & z [1/cm2]
//Rr  = diffuse reflectance vs radius r [1/cm2]
//Ra  = diffuse reflectance vs angle alpha [1/sr]
//Rra = diffuse reflectance vs radius and angle [1/(cm2 sr)]
//Tr  = transmittance vs radius r [1/cm2]
//Ta  = transmittance vs angle alpha [1/sr]
//Tra = transmittance vs radius and angle [1/(cm2 sr)]
//K   = Keijzer's format
//Q   = Quit to main menu
//* input filename: mysim.mco
//***********************************************************************************************
convCmdArgs_t convParseCmdArgs(int argc, char* argv[])
{
  convCmdArgs_t cmdargs;
  cmdargOptionReaction_t OptionsCallbackList[] =
  {
    {
      .spezifier = 'o', .OptionCallbackFunc = convSetOFilename
    },
    {
      .spezifier = 'b', .OptionCallbackFunc = convSetBeamType
    },
    {
      .spezifier = 'w', .OptionCallbackFunc = convSetBeamWidth
    },
    {
      .spezifier = 't', .OptionCallbackFunc = convSetODataType
    },
    {
      .spezifier = 'c', .OptionCallbackFunc = convSetColumnsFormat
    }
  };
  cmdargOptionCallbackFunc_t *OptionCallbackFunc;
  char* convAllowedOutputFormats[] = {"Ra", "Rr", "Rd", "Rra", "Ta", "Td", "Tr", "Tra"};
  enum convAllowedOutputFormNames {RA, RR, RD, RRA, TA, TD, TR, TRA};

  uint8_t argidx = 1; //Start with 1, because index null indicates filename of running program
  char ch = '#';
  //char* argptr = NULL;
  bool foundinfileflag = false;

  cmdargs.infilename = "in.mco";
  cmdargs.outfilename = "out.mcc";
  cmdargs.beamtype = PENCILBEAM;
  cmdargs.outputtype = ORIGINALDATA;
  cmdargs.beamwidth = 0;
  cmdargs.cmdargerror = ARG_NOERR;
  cmdargs.cmdargerrstring = noerrorstr;
  cmdargs.outputformat = convAllowedOutputFormats[RRA];
  cmdargs.columnformat = XYZ;

  if (argc < 3)
  {
    cmdargs.cmdargerror = LESSCMDARGS_ERR;
    //return cmdargs;
  }

  for (; argidx < argc; ++argidx)
  {

    if ( cmdargTestMinus(argv[argidx]) )
    {
      if (strlen(argv[argidx]) < 2) convCmdArgSetError(&cmdargs, MISSINGSPEZIFIER_ERR, NULL);

      ch = argv[argidx][1];
      OptionCallbackFunc = cmdargGetOptionCallbackFunc(ch, OptionsCallbackList, GetArrayLength(OptionsCallbackList) );
      ++argidx;
      if ( argidx >= argc )
      {
        convCmdArgSetError(&cmdargs, MISSINGPARAM_ERR, NULL);
        return cmdargs;
      }
      if ( cmdargTestMinus(argv[argidx]) )
      {
        convCmdArgSetError(&cmdargs, MISSINGPARAM_ERR, NULL);
        return cmdargs;
      }
      if (NULL != OptionCallbackFunc) OptionCallbackFunc(&cmdargs, argidx, argv[argidx]);
    }else
    {
      if ( NULL ==  (cmdargs.outputformat =
                      convCheckOutputFormat ( argv[argidx], convAllowedOutputFormats, GetArrayLength(convAllowedOutputFormats) )
                    )
         )
      {
        if (foundinfileflag)
        {
          convCmdArgSetError(&cmdargs, INFILEMORETHANONCE_ERR, NULL);
          return cmdargs;
        }

        foundinfileflag = true;
        cmdargs.infilename = argv[argidx];
      }
    }
  }

  //If no arg is given after last commandline switch --> CRASH!

  return cmdargs;
};
*/

