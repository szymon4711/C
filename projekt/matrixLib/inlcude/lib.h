#ifndef PROJEKT_LIB_H
#define PROJEKT_LIB_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <math.h>

using namespace std;

void help();

int **create(int wiersze, int kolumny);

void enter(int **M, int wiersze, int kolumny);

void disp(int **M, int wiersze, int kolumny);

void del(int **M, int wiersze);


int **addMatrix(int **A, int **B, int wiersze, int kolumny);

int **subtractMatrix(int **A, int **B, int wiersze, int kolumny);

int **multiplyMatrix(int **A, int **B, int wiersze_A, int kolumny_A, int kolumny_B);

int **multiplyByScalar(int **A, int wiersze, int kolumny, int skal);

int **transpozeMatrix(int **A, int wiersze, int kolumny);

int **powerMatrix(int **A, int wiersze, unsigned int poteg);

int determinantMatrix(int **A, int wiersze);

bool matrixIsDiagonal(int **A, int n);

void swap(int &a, int &b);

void sortRow(int *A, int kolumny);

void sortRowsInMatrix(int **A, int wiersze, int kolumny);


double **create_d(int wiersze, int kolumny);

void enter(double **M, int wiersze, int kolumny);

void disp(double **M, int wiersze, int kolumny);

void del(double **M, int wiersze);


double **addMatrix(double **A, double **B, int wiersze, int kolumny);

double **subtractMatrix(double **A, double **B, int wiersze, int kolumny);

double **multiplyMatrix(double **A, double **B, int wiersze_A, int kolumny_A, int kolumny_B);

double **multiplyByScalar(double **A, int wiersze, int kolumny, double skal);

double **transpozeMatrix(double **A, int wiersze, int kolumny);

double **powerMatrix(double **A, int wiersze, unsigned int poteg);

double determinantMatrix(double **A, int wiersze);

bool matrixIsDiagonal(double **A, int n);

void swap(double &a, double &b);

void sortRow(double *A, int kolumny);

void sortRowsInMatrix(double **A, int wiersze, int kolumny);


#endif //PROJEKT_LIB_H
