/*
Authors: Nick Bobich, Megan Solomon, Andrejs Tomsons
Project: Quad Solver
Description: This program takes 3 arguments representing a, b, and c in a
    quadratic equation and solves for its roots using the quadratic formula
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "qsolve.h"

int main(int argc, char const *argv[]) {
    int ret = 0;
    int cmp = 1;
    char userInput[255];

    while (cmp) {

        int length = 255;
        double a = 0, b = 0, c = 0;
	   	double x1 = 0, x2 = 0;

		printf("\nQuad Solver\nVersion 1.0\n\n");
		printf("This program takes 3 arguments representing a, b, and c in a quadratic equation and solves for its roots using the quadratic formula\n\n");
		printf("Press enter to continue or press \'h\' for help...\n");
		scanf("%[^\n]", userInput);
		getchar();

		if (strncmp(userInput, "h", length) == 0)
			ret = qsHelp();

		if (ret == 0)
			ret = qsGetLine(userInput, &length);

		if ((cmp = strncmp(userInput, "q\n", length))) {

            if (ret == 0)
				ret = qsValidate(userInput, length, &a, &b, &c);

			if (ret == 0)
				ret = qsSolve(a, b, c, &x1, &x2);

			if (ret == 0)
				ret = qsResult(x1, x2, ret);

		}

        if (ret != 0)
            ret = qsError(ret);
	}

    return ret;
}

int qsGetLine(char * line, int * nline) {
    int ret = 0;

    printf("input a b c: <a> <b> <c>\n");
    printf("or q to exit\n");

    if (fgets(line, *nline, stdin) == NULL) {
        ret = 1;
    } else {
        *nline = strlen(line);
    }

    return ret;
}

int qsValidate(char * line, int nline, double * a, double * b, double * c) {
    int ret = 0;
    char * token;
    int token_num = 1;
    int scanned = 0;

    token = strtok(line, " ");
    while (token != NULL) {
        switch(token_num) {
            case(1):
                scanned += sscanf(token, "%lf", a);
                break;
            case(2):
                scanned += sscanf(token, "%lf", b);
                break;
            case(3):
                scanned += sscanf(token, "%lf", c);
                break;
        }
        token = strtok(NULL, " ");
        token_num++;
    }

    if (scanned != 3 || token_num > 4)
        ret = 1;

    if (ret == 0)
        fprintf(stdout, "\nYou entered: a: %.8lf b: %.8lf c: %.8lf\n\n", *a, *b, *c);

    return ret;
}

int qsSolve(double a, double b, double c, double * x1, double * x2) {
    int ret = 0;
    // GIVE FEEDBACK ON BAD INPUT DATA
    // INPUT A, B, C SHOULD BE IEEE FP 32 BIT NORMALIZED VALUES W/ NO MORE THAN 8 DECIMAL PLACES


    double underSqrt = (b * b) - (4 * a * c);

    if (underSqrt == 0) {
        *x1 = (-b / (2 * a));
        *x2 = (-b / (2 * a));
    } else {
        *x1 = ((-b + sqrt(underSqrt)) / (2 * a));
        *x2 = ((-b - sqrt(underSqrt)) / (2 * a));
    }

    return ret;
}

int qsResult(double x1, double x2, int ret) {

    if (isnan(x1) || isnan(x2)) { // NO REAL ROOTS
        printf("There are no real roots. There are two complex roots.\n\n");
    } else if (x1 == x2) { // DOUBLE REAL ROOT
        printf("There is one real root: %.8lf\n\n", x1);
    } else { // TWO REAL ROOTS
        printf("There are two real roots: %.8lf, %.8lf\n\n", x1, x2);
    }

    printf("Press enter to continue...");
    getchar();
    printf("----------------------------------------\n");

    // INTERNAL ERROR

    // POSSIBLE LOSS OF SIGNIFICANCE

    return ret;
}

// int qsPutLine(char * line, int nline) {
//     int ret = 0;
//
//     return ret;
// }
//
int qsError(int ret) {

    switch(ret) {
        case(1):
            printf("\nBad input.\n\n");
            qsHelp();
            break;
        case(2):
            printf("\nInput a, b, c should be IEEE floating point 32 bit normalized values, with no more than 8 decimal places.\n\n");
            break;
        case(3):
            printf("\nWarning: Possible loss of significance.\n\n");
            break;
        case(4):
            printf("\nInternal error.\n\n");
            break;
    }

    ret = 0;
    return ret;
}
//
// int qsLogEnable() {
//     int ret = 0;
//
//     return ret;
// }
//
// int qsLog() {
//     int ret = 0;
//
//     return ret;
// }
//
int qsHelp() {
    int ret = 0;

    printf("Enter three numbers. Make sure to include a space between "
            "each number. Numbers you enter cannot exceed 8 decimal places.\n\n"
            "Example: 2.25 18 7.66554542\n\n");
    printf("----------------------------------------\n");

    return ret;
}
