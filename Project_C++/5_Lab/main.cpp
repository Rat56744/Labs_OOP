#include "../5_Lab/function.h"

int main()
{
    int size = 5;
    int Int[size];
    double Double[size];
    char Char[size];

    initialization_mass(Int,size);
    initialization_mass(Double,size);
    initialization_mass(Char,size);

    print_mass(Int,size,3);
    print_mass(Double,size,2);
    print_mass(Char,size,5);
}