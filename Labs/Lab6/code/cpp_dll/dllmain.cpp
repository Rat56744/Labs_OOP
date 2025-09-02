// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "cpp_dll.h"
#include <random>
#include <time.h>
#include "Matrix.h"
//-----------------------------------------------------------------


int getRandom(const int a, const int b);

Matrix* cir = nullptr;

bool SolutionOfMatrixByKramer(double solving[], double rou[], double mxb[], int mx_size)
{
    Matrix* mx = new Matrix(mx_size);
    for (int i = 0; i < mx_size; i++)
        mx->rou[i] = rou[i];
    for (int i = 0; i < mx_size; i++)
        mx->mxb[i] = mxb[i];
    if (mx->getSolving())
        for (int j = 0; j < mx_size; j++)
            solving[j] = mx->solving[j];
    else
        return false;
    return true;
}
//----------------------------------------------------------------
double ProcessMatrix(int mx_size, int cicle_num)
{
    clock_t start, finish;
    Matrix* mx = new Matrix(mx_size);
    for (int i = 0; i < mx_size; i++)
        mx->rou[i] = i;
    mx->rou[0] = 55;
    for (int i = 0; i < mx_size; i++)
        mx->mxb[i] = i*4+2;
    start = clock();
    for (int i = 0; i < cicle_num; i++)
        mx->getSolving();
    finish = clock();
    return (double)(finish - start) / CLOCKS_PER_SEC;;
}
//--------------------------------------------------
std::random_device rd;   // non-deterministic generator
std::mt19937 gen(rd());  // to seed mersenne twister.
int getRandom(const int a, const int b)
{
    std::uniform_int_distribution<int> dist(a, b); // distribute results between 1 and 10 inclusive.
    return dist(gen);
}
//-------------------------------------------------------------------------------------------------------------------
