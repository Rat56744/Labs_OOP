#include "pch.h"
#include "Matrix.h"

using namespace std;
//-----------------------------------------------------------------
Matrix::Matrix(int n)
{
    size = n;
    mxA = (double**)calloc(size, sizeof(double*));
    for (int i = 0; i < size; i++)
        mxA[i] = (double*)calloc(size, sizeof(double*));
    // Инициализация нулями
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            mxA[i][j] = 0;
    // Выделение памяти для векторов
    mxb = (double*)calloc(size, sizeof(double*));
    for (int i = 0; i < size; i++)
        mxb[i] = 0;
    rou = (double*)calloc(size, sizeof(double*));
    for (int i = 0; i < size; i++)
        rou[i] = 0;
    solving = (double*)calloc(size, sizeof(double*));
    for (int i = 0; i < size; i++)
        solving[i] = 0;
    // Выделение памяти для вспомогательной матрицы(Метод Крамера)
    mxj = (double**)calloc(size, sizeof(double*));
    for (int i = 0; i < size; i++)
        mxj[i] = (double*)calloc(size, sizeof(double*));

}
//-----------------------------------------------------------------
Matrix::Matrix(const Matrix& mx)
{
    size = mx.size;
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            mxA[i][j] = mx.mxA[i][j];
}
//-----------------------------------------------------------------
Matrix::~Matrix()
{
    // Освобождение памяти основной матрицы
    for (int i = 0; i < size; i++)
        free(mxA[i]);
    free(mxA);
    // Освобождение векторов
    free(mxb);
    free(rou);
    free(solving);
    // Освобождение векторов
    for (int i = 0; i < size; i++)
        free(mxj[i]);
    free(mxj);
}
//-----------------------------------------------------------------
Matrix& Matrix::operator=(const Matrix& mx)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            mxA[i][j] = mx.mxA[i][j];
    return *this;
}
//-----------------------------------------------------------------
bool Matrix::getSolving()
{
    double summ = 0;
    for (int i = 0; i < size; i++)
        summ += rou[i];
    if (summ == 0)
        return false;
    //-------------------------------------------
    cir_matrix(mxA, rou, size);
    double det_A = get_det(mxA, size);
    if (det_A == 0)
        return false;
    //-------------------------------------------
    for (int j = 0; j < size; j++)
    {
        cir_matrix(mxj, rou, size);
        for (int i = 0; i < size; i++)
            mxj[i][j] = mxb[i];
        solving[j] = get_det(mxj, size) / det_A;
    }
    //-------------------------------------------
    return true;
}
//-------------------------------------------------------------------
void Matrix::cir_matrix(double** mx, double* rou, int n) // Строим циркулянтную матрицу из первой строки
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (j >= i)
                mx[i][j] = rou[j - i];
            else
                mx[i][j] = rou[n - i + j];
        }
}
//------------------------------------------------------------------
void Matrix::get_mxb(double mxb[], double rou[], double solving[], int n) // Вычисляет произведение матрицы на вектор( проверка решения )
{
    double** mxa = new double* [n];
    for (int i = 0; i < n; i++)
        mxa[i] = new double[n];
    // cir matrix ------------------------------
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (j >= i)
                mxa[i][j] = rou[j - i];
            else
                mxa[i][j] = rou[n - i + j];
        }
    //---------------------------------------
    for (int i = 0; i < n; i++)
    {
        mxb[i] = 0;
        for (int j = 0; j < n; j++)
            mxb[i] += mxa[i][j] * solving[j];
    }
    for (int i = 0; i < n; i++)
        delete[] mxa[i];
    delete[] mxa;
}
//--------------------------------------------------
double Matrix::get_det(double** mx, int n) // Определитель
{
    if (n < 1)
        return -1;
    double summ = 0;
    switch (n)
    {
        case 1: return mx[0][0];
        case 2: return mx[0][0] * mx[1][1] - mx[0][1] * mx[1][0];
        case 3: return mx[0][0] * (mx[1][1] * mx[2][2] - mx[1][2] * mx[2][1]) - mx[0][1] * (mx[1][0] * mx[2][2] - mx[1][2] * mx[2][0]) + mx[0][2] * (mx[1][0] * mx[2][1] - mx[1][1] * mx[2][0]);
        case 4:
        {
            for (int j = 0; j < n; j++)
            {
                double x = -1;
                double y = (double)j;
                for (int k = 0; k < n - 1; k++)
                    for (int l = 0; l < n - 1; l++)
                    {
                        if (j == 0)
                            mx3[k][l] = mx[k + 1][l + 1];
                        if (l < j)
                            mx3[k][l] = mx[k + 1][l];
                        if (l > j)
                            mx3[k][l] = mx[k + 1][l + 1];
                    }
                summ += mx[0][j] * pow(x, y) * get_det3(mx3); 
            }
            return summ;
        }
        case 5: //------------------------
        {
            for (int j = 0; j < n; j++)
            {
                double x = -1;
                double y = (double)j;
                for (int k = 0; k < n - 1; k++)
                    for (int l = 0; l < n - 1; l++)
                    {
                        if (j == 0)
                            mx4[k][l] = mx[k + 1][l + 1];
                        if (l < j)
                            mx4[k][l] = mx[k + 1][l];
                        if (l > j)
                            mx4[k][l] = mx[k + 1][l + 1];
                    }
                summ += mx[0][j] * pow(x, y) * get_det4(mx4);
            }
            return summ;
        }
        case 6: //------------------------
        {
            for (int j = 0; j < n; j++)
            {
                double x = -1;
                double y = (double)j;
                for (int k = 0; k < n - 1; k++)
                    for (int l = 0; l < n - 1; l++)
                    {
                        if (j == 0)
                            mx5[k][l] = mx[k + 1][l + 1];
                        if (l < j)
                            mx5[k][l] = mx[k + 1][l];
                        if (l > j)
                            mx5[k][l] = mx[k + 1][l + 1];
                    }
                summ += mx[0][j] * pow(x, y) * get_det5(mx5);
            }
            return summ;
        }
        case 7: //------------------------
        {
            for (int j = 0; j < n; j++)
            {
                double x = -1;
                double y = (double)j;
                for (int k = 0; k < n - 1; k++)
                    for (int l = 0; l < n - 1; l++)
                    {
                        if (j == 0)
                            mx6[k][l] = mx[k + 1][l + 1];
                        if (l < j)
                            mx6[k][l] = mx[k + 1][l];
                        if (l > j)
                            mx6[k][l] = mx[k + 1][l + 1];
                    }
                summ += mx[0][j] * pow(x, y) * get_det6(mx6);
            }
            return summ;
        }
        case 8: //------------------------
        {
            for (int j = 0; j < n; j++)
            {
                double x = -1;
                double y = (double)j;
                for (int k = 0; k < n - 1; k++)
                    for (int l = 0; l < n - 1; l++)
                    {
                        if (j == 0)
                            mx7[k][l] = mx[k + 1][l + 1];
                        if (l < j)
                            mx7[k][l] = mx[k + 1][l];
                        if (l > j)
                            mx7[k][l] = mx[k + 1][l + 1];
                    }
                summ += mx[0][j] * pow(x, y) * get_det7(mx7);
            }
            return summ;
        }
        case 9: //------------------------
        {
            for (int j = 0; j < n; j++)
            {
                double x = -1;
                double y = (double)j;
                for (int k = 0; k < n - 1; k++)
                    for (int l = 0; l < n - 1; l++)
                    {
                        if (j == 0)
                            mx8[k][l] = mx[k + 1][l + 1];
                        if (l < j)
                            mx8[k][l] = mx[k + 1][l];
                        if (l > j)
                            mx8[k][l] = mx[k + 1][l + 1];
                    }
                summ += mx[0][j] * pow(x, y) * get_det8(mx8);
            }
            return summ;
        }
        default: //------------------------
        {
            double** mxX = (double**)calloc(n - 1, sizeof(double*)); 
            for (int i = 0; i < n - 1; i++)
                mxX[i] = (double*)calloc(n - 1, sizeof(double*));
            for (int j = 0; j < n; j++)
            {
                double x = -1;
                double y = (double)j;
                for (int k = 0; k < n - 1; k++)
                    for (int l = 0; l < n - 1; l++)
                    {
                        if (j == 0)
                            mxX[k][l] = mx[k + 1][l + 1];
                        if (l < j)
                            mxX[k][l] = mx[k + 1][l];
                        if (l > j)
                            mxX[k][l] = mx[k + 1][l + 1];
                    }
                summ += mx[0][j] * pow(x, y) * get_det(mxX, n - 1);
            }
            //------------------------------------------------------
            for (int i = 0; i < n - 1; i++)
                free(mxX[i]);
            free(mxX);
        }
    }   // switch(n)
    return summ;
}
//------------------------------------------------------------------------------------------------------------------
double Matrix::get_det3(double mx[3][3]) // Определитель для три на три
{
    return mx[0][0] * (mx[1][1] * mx[2][2] - mx[1][2] * mx[2][1]) - mx[0][1] * (mx[1][0] * mx[2][2] - mx[1][2] * mx[2][0]) + mx[0][2] * (mx[1][0] * mx[2][1] - mx[1][1] * mx[2][0]);
}
//------------------------------------------------------------------------------------------------------------------
double Matrix::get_det4(double mx[4][4]) // Определитель для четыре на четыре
{
    double det4 = 0;
    for (int j = 0; j < 4; j++)
    {
        double x = -1;
        double y = (double)j;
        for (int k = 0; k < 3; k++)
            for (int l = 0; l < 3; l++)
            {
                if (j == 0)
                    fmx3[k][l] = mx[k + 1][l + 1];
                if (l < j)
                    fmx3[k][l] = mx[k + 1][l];
                if (l > j)
                    fmx3[k][l] = mx[k + 1][l + 1];
            }
        det4 += mx[0][j] * pow(x, y) * get_det3(fmx3);
    }
    return det4;
}
//------------------------------------------------------------------------------------------------------------------
double Matrix::get_det5(double mx[5][5])
{
    double det5 = 0;
    for (int j = 0; j < 5; j++)
    {
        double x = -1;
        double y = (double)j;
        for (int k = 0; k < 4; k++)
            for (int l = 0; l < 4; l++)
            {
                if (j == 0)
                    fmx4[k][l] = mx[k + 1][l + 1];
                if (l < j)
                    fmx4[k][l] = mx[k + 1][l];
                if (l > j)
                    fmx4[k][l] = mx[k + 1][l + 1];
            }
        det5 += mx[0][j] * pow(x, y) * get_det4(fmx4);
    }
    return det5;
}
//------------------------------------------------------------------------------------------------------------------
double Matrix::get_det6(double mx[6][6])
{
    double det6 = 0;
    for (int j = 0; j < 6; j++)
    {
        double x = -1;
        double y = (double)j;
        for (int k = 0; k < 5; k++)
            for (int l = 0; l < 5; l++)
            {
                if (j == 0)
                    fmx5[k][l] = mx[k + 1][l + 1];
                if (l < j)
                    fmx5[k][l] = mx[k + 1][l];
                if (l > j)
                    fmx5[k][l] = mx[k + 1][l + 1];
            }
        det6 += mx[0][j] * pow(x, y) * get_det5(fmx5);
    }
    return det6;
}
//------------------------------------------------------------------------------------------------------------------
double Matrix::get_det7(double mx[7][7])
{
    double det7 = 0;
    for (int j = 0; j < 7; j++)
    {
        double x = -1;
        double y = (double)j;
        for (int k = 0; k < 6; k++)
            for (int l = 0; l < 6; l++)
            {
                if (j == 0)
                    fmx6[k][l] = mx[k + 1][l + 1];
                if (l < j)
                    fmx6[k][l] = mx[k + 1][l];
                if (l > j)
                    fmx6[k][l] = mx[k + 1][l + 1];
            }
        det7 += mx[0][j] * pow(x, y) * get_det6(fmx6);
    }
    return det7;
}
//------------------------------------------------------------------------------------------------------------------
double Matrix::get_det8(double mx[8][8])
{
    double det8 = 0;
    for (int j = 0; j < 8; j++)
    {
        double x = -1;
        double y = (double)j;
        for (int k = 0; k < 7; k++)
            for (int l = 0; l < 7; l++)
            {
                if (j == 0)
                    fmx7[k][l] = mx[k + 1][l + 1];
                if (l < j)
                    fmx7[k][l] = mx[k + 1][l];
                if (l > j)
                    fmx7[k][l] = mx[k + 1][l + 1];
            }
        det8 += mx[0][j] * pow(x, y) * get_det7(fmx7);
    }
    return det8;
}
//------------------------------------------------------------------------------------------------------------------
string Matrix::ToString()
{
    char buf[120];
    string str = "";
    str += "  \n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            snprintf(buf, 120, "%.1f", mxA[i][j]);
            str += (string)buf + " ";
        }
        snprintf(buf, 120, "%.1f", mxb[i]);
        str += "    " + (string)buf + "\n";
    }
    str += "\n\n";
    for (int j = 0; j < size; j++)
    {
        snprintf(buf, 120, "%.1f", solving[j]);
        str += (string)buf + " ";
    }
    //str += "\n";
    return str;
}
//-------------------------------------------------------------------------------------------------------------------
