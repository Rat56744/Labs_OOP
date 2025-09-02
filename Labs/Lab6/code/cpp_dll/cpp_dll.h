#pragma once

#ifdef __linux__
    #define MYDLL_API __attribute__((visibility("default")))
#else
    #ifdef MYDLL_EXPORTS
        #define MYDLL_API __declspec(dllexport)
    #else
        #define MYDLL_API __declspec(dllimport)
    #endif
#endif

extern "C" {
    MYDLL_API bool SolutionOfMatrixByKramer(double solving[], double rou[], double mxb[], int mx_size);
    MYDLL_API double ProcessMatrix(int mx_size, int cicle_num);
}