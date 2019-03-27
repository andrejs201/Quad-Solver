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
    char userInput[255];
    int length = 255;

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    printf("\nQuad Solver\nVersion 1.0\n\n");
    printf("This program takes 3 arguments representing a, b, and c in a quadratic equation and solves for its roots using the quadratic formula\n\n");
    printf("Press enter to continue or press \'h\' for help...\n");
    scanf("%[^\n]", userInput);
    getchar();

    if (strcmp(userInput, "h") == 0) {
        // ret = qsHelp();
        printf("Help\n");
    }

    if (ret == 0)
        ret = qsGetLine(userInput, &length);
    if (ret == 0)
        ret = qsValidate(userInput, length, &a, &b, &c);
    if (ret == 0)
        ret = qsSolve(a, b, c, &x1, &x2);
    if (ret == 0)
        ret = qsResult(x1, x2, ret);

    return ret;
}

int qsGetLine(char * line, int * nline) {
    int ret = 0;

    printf("input a b c: <a> <b> <c>\n");
    if (fgets(line, *nline, stdin) == NULL) {
        ret = -1;
    } else {
        *nline = strlen(line) + 1;
    }

    return ret;
}

int qsValidate(char * line, int nline, double * a, double * b, double * c) {
    int ret = 0;
    int i = 0;
    char * token;

    while (i < nline) {
        token = strtok(line, " ");
        int token_num = 1;
        while (token != NULL) {
            switch(token_num) {
                case(1):
                    sscanf(token, "%lf", a);
                    break;
                case(2):
                    sscanf(token, "%lf", b);
                    break;
                case(3):
                    sscanf(token, "%lf", c);
                    break;
            }
            token = strtok(NULL, " ");
            token_num++;

            if (token_num > 4)
                ret = -1;
        }
        i++;
    }

    return ret;
}

int qsSolve(double a, double b, double c, double * x1, double * x2) {
    int ret = 0;
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
    // GIVE FEEDBACK ON BAD INPUT DATA
    // INPUT A, B, C SHOULD BE IEEE FP 32 BIT NORMALIZED VALUES W/ NO MORE THAN 8 DECIMAL PLACES

    if (isnan(x1) || isnan(x2)) { // NO REAL ROOTS
        printf("There are no real roots. There are two complex roots.\n");
    } else if (x1 == x2) { // DOUBLE REAL ROOT
        printf("There is one real root: %.8lf\n", x1);
    } else { // TWO REAL ROOTS
        printf("There are two real roots: %.8lf %.8lf\n", x1, x2);
    }

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
// int qsError(int ret) {
//
//     return ret;
// }
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
// int qsHelp() {
//     int ret = 0;
//
//     return ret;
// }
