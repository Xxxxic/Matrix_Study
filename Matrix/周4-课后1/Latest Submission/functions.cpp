#include "check.h"
// #include <iostream>
#include <stdio.h>
#include "functions.h"

int* Array(int len) {
    int* arr = new int[len];
    return arr;
}
int** Reshape(int* vec, int row, int col) {
    int** arr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++)
            arr[i][j] = vec[i * col + j];
    }
    return arr;
}
void FreeArray(int* vec) {
    delete[] vec;
}
void FreeMatrix(int** mat, int row) {
    for (int i = 0; i < row; i++)
        delete[] mat[i];
    delete[] mat;
}