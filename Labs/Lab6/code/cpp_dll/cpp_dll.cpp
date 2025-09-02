#define MYDLL_EXPORTS
#include "cpp_dll.h"
#include "Matrix.h"
#include <ctime>

extern "C" {
    MYDLL_API bool SolutionOfMatrixByKramer(double solving[], double rou[], double mxb[], int mx_size)
    {
        Matrix mx(mx_size);
        for (int i = 0; i < mx_size; i++) {
            mx.rou[i] = rou[i];
            mx.mxb[i] = mxb[i];
        }
        
        bool result = mx.getSolving();
        if(result) {
            for (int j = 0; j < mx_size; j++)
                solving[j] = mx.solving[j];
        }
        
        return result;
    }

    MYDLL_API double ProcessMatrix(int mx_size, int cicle_num)
    {
        clock_t start, finish;
        Matrix mx(mx_size);
        
        for (int i = 0; i < mx_size; i++) {
            mx.rou[i] = i;
            mx.mxb[i] = i*4+2;
        }
        mx.rou[0] = 55;
        
        start = clock();
        for (int i = 0; i < cicle_num; i++)
            mx.getSolving();
        finish = clock();
        
        return (double)(finish - start) / CLOCKS_PER_SEC;
    }
}