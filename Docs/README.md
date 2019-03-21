Here are prototypes for the qsolve functions called from
main(). 

1) Following the functional programming style unless noted, these functions should do no IO. 

2) All functions validate their arguments.

4) All functions should log, if logging on, the args when called. Also log any invalid args.

5) All functions should return a flag indicating success or failure.

3) All functions should list copyright information.


On program start up there should be a brief summary of the program, verison information, and a help command.

qsolve should be a tar file with README, VERSION, LICENSE and INSTALL files

when untarring qsolve, it should untar into ./qsolve-<VERISON>

to compile and test
	make qsolve
	make test
		this does not do unit testing, only numerous tests of the compiled program and reports a clear message on what fails

Outputs should be
	-bad input data (with help)
	-double real root
	-two real roots
	-No real roots
	-Internal error
	-possible loss of significance in result
	-input a,b,c should be ieee-fp 32 bit normalized with no more 		than 8 decimal places
	-print 8 significant decimal places

qsolve prompt for input
input a b c: <a> <b> <c>

Functions:
	int qsGetline(char *line, int nline)
	int qsValidate(char *line, int nline, double *a, double *b, double *c)
	int qsSolve(double a, double b, double c, double *x1, double x2)
	int qsError();
	int qsResult();
	int qsPutline(char line*, int nline);
	int qsLogEnable();
	int qsLog();
	int qsHelp();
