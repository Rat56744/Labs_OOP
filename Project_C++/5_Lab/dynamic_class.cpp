#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdio.h>
using std::cout,std::setw, std::left;

template<class T>
class DynamicArray
{
    private:
        int n;
        T* Bp;
        T* Tp;
    public:
        // Методы класса
        void print(int size);
        T* find_min();
        // Конструкторы
    DynamicArray(int size);
    ~DynamicArray();
};

template<class T>
DynamicArray<T>::DynamicArray(int size):n(size)
{
    if (n <= 0) {
        throw std::invalid_argument("Размер массива должен быть положительным!");
    }
    Bp = new T[n]{};
    Tp = Bp;

    srand(time(0));
    for(int i=0;i<n;++i)
    {
        Bp[i] = static_cast<T>((rand() % 100) / 10.0);
    }
}

template<class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] Bp;
}

template<class T>
/*n - длинна таблицы*/
void DynamicArray<T>::print(int size)
{
    Tp = Bp;
    cout << "Размер массива: "<< n <<'\n';
    for(int i=0;i<n;i++)
    {
        if((i+1)%size != 0){cout<<setw(5)<< left<< Tp[i];}
        else{ cout<<setw(4)<< left<< Tp[i] << '\n';} // Завершаем строчку
    }
    cout <<"\n";
}

template<class T>
T* DynamicArray<T>::find_min()
{
    Tp = Bp;
    T* p = Tp;
    
    for(int i=0;i<n-1;++i)
    {
        if(Tp[i]<Tp[i+1] && Tp[i] < *p)
        {
            p = Tp+i;
        }
    }
    return p;
}

int main()
{
    DynamicArray<int> arr1(10);
    arr1.print(5);
    cout << "Минимальный элемент в arr1: "<<*arr1.find_min()<< "\n\n";

    DynamicArray<double> arr2(20);
    arr2.print(6);
    std::cout << "Минимальный элемент в arr2: " << *arr2.find_min() << '\n';
}