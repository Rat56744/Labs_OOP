#ifndef MYMATRIX
#define MYMATRIX

#include <math.h>
#include <string>
#include <stdio.h>

class Matrix
{
    double** mxj = nullptr;
    double mx3[3][3];
    double mx4[4][4];
    double mx5[5][5];
    double mx6[6][6];
    double mx7[7][7];
    double mx8[8][8];
    double fmx3[3][3];
    double fmx4[4][4];
    double fmx5[5][5];
    double fmx6[6][6];
    double fmx7[7][7];
    double fmx8[8][8];
    double get_det3(double mx[3][3]);
    double get_det4(double mx[4][4]);
    double get_det5(double mx[5][5]);
    double get_det6(double mx[6][6]);
    double get_det7(double mx[7][7]);
    double get_det8(double mx[8][8]);
    int size;
    void cir_matrix(double** mx, double* rou, int n);
    double get_det(double** mx, int n);
public:
    double** mxA=nullptr;
    double* mxb = nullptr;
    double* rou = nullptr;
    double* solving = nullptr;
    Matrix(int n);
    Matrix(const Matrix& mx);
    ~Matrix();
    Matrix& operator=(const Matrix&);
    bool getSolving();
    std::string ToString();
    static void get_mxb(double mxb[], double rou[], double solving[], int n);
};


#endif // !MYMATRIX
