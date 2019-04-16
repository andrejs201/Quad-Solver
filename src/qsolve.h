#ifndef QSOLVE_H
#define QSOLVE_H

int qsGetLine(char * line, int * nline);
int qsValidate(char * line, int nline, double * a, double * b, double * c);
int qsSolve(double a, double b, double c, double * x1, double * x2);
int qsError(int ret);
int qsResult(double x1, double x2, int ret);
int qsPutLine(char * line, int nline);
int qsLogEnable(int * logEnable);
int qsLog(int ret, int testNum, double a, double b, double c, FILE * outfile);
int qsHelp();

#endif
