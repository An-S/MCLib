#ifndef PARSECOMMANDLINEARGS_H_INCLUDED
#define PARSECOMMANDLINEARGS_H_INCLUDED

	#define CMDARGERRLIST C(CMDARG_NO_ERR, "No error"), C(CMDARG_LESSCMDARGS_ERR, "Too less arguments"), C(CMDARG_NOFILENAME_ERR, "No filename given"),\
				C(CMDARG_INVALIDFILENAME_ERR, "Invalid filename"), C(CMDARG_MISSINGPARAM_ERR, "Missing parameter"),\
				C(CMDARG_MISSINGSPEZIFIER_ERR, "Missing specifier"), C(CMDARG_INFILEMORETHANONCE_ERR, "More than one infile given")

	#define C(x,y) x
	typedef enum {CMDARGERRLIST} cmdargsErr_t;
	#undef C



	typedef double convBeamWidth_t;

	typedef struct
	{
		char* optionString;
		char* helptext;
	}cmdargs_t;

	typedef int cmdargsOptionCallbackFunc_t (cmdargs_t*);

	typedef struct
	{
		char* spezifier;
		cmdargsOptionCallbackFunc_t *OptionCallbackFunc;
	} cmdargsOptionReaction_t;

	int cmdargs_Parse(int argc, char* argv[]);
	int cmdargs_ConsoleOutput(cmdargs_t *cmdargs);
	int cmdargs_addSwitchDefinition(char* optionString, char* helptext);
	int cmdargs_addNSwitchDefinitions(char** optionStrings, char** helptexts, int n);
	int cmdargs_setError(char* errormsg);
	int cmdargs_clearError(void);
	char* cmdargs_getLastError(void);
	int cmdargs_ConsoleOutputLastError(void);

	extern char* convCmdArgErrNames[];
	extern char* convODataTypeNames[];
	extern char* convBeamTypeNames[];
	extern char* convColumnFormatNames[];

#endif // PARSECOMMANDLINEARGS_H_INCLUDED
