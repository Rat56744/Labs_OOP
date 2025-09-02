#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <cmath>
#include <numbers>
#define MEASURE_TIME(code) \
    do { \
        auto start = std::chrono::high_resolution_clock::now(); \
        code \
        auto end = std::chrono::high_resolution_clock::now(); \
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); \
        std::cout << duration.count() << " микросекунд\n"; \
    } while(0)

using namespace std;

// -------------  ДПФ и ОДПФ --------------------------------

class FourierTransformer {
public:
    static vector<complex<double>> transform(const vector<complex<double>>& signal) {
        return compute(signal, -1);
    }

    static vector<complex<double>> inverseTransform(const vector<complex<double>>& signal) {
        return compute(signal, 1);
    }

private:
    static vector<complex<double>> compute(const vector<complex<double>>& signal, int direction) {
        const size_t N = signal.size();
        vector<complex<double>> result(N);
        const double norm = sqrt(N);

        for (size_t k = 0; k < N; ++k) {
            result[k] = 0;
            for (size_t n = 0; n < N; ++n) {
                const double angle = direction * 2 * M_PI * k * n / N;
                result[k] += signal[n] * polar(1.0, angle);
            }
            result[k] /= norm;
        }

        return result;
    }
};

// Обратная перестановка битов
unsigned int reverseBits(unsigned int x, int bitCount) {
    unsigned int reversed = 0;
    while (bitCount--) {
        reversed = (reversed << 1) | (x & 1);
        x >>= 1;
    }
    return reversed;
}

// ----------------------- БПФ и ОБПФ --------------------------

// Общая часть для БПФ и ОБПФ
void butterflyTransform(vector<complex<double>>& data, double sign) {
    const int n = data.size();
    const int log2n = log2(n);
    
    // Перестановка элементов
    vector<complex<double>> temp(n);
    for (int i = 0; i < n; ++i) 
        temp[reverseBits(i, log2n)] = data[i];
    data = temp;

    // Алгоритм бабочки
    for (int stage = 1; stage <= log2n; ++stage) {
        int m = 1 << stage;
        int half_m = m/2;
        complex<double> wm = exp(complex<double>(0, sign * 2 * M_PI / m));
        
        for (int k = 0; k < n; k += m) {
            complex<double> w = 1.0;
            for (int j = 0; j < half_m; ++j) {
                auto t = w * data[k + j + half_m];
                auto u = data[k + j];
                data[k + j] = u + t;
                data[k + j + half_m] = u - t;
                w *= wm;
            }
        }
    }
}

// Прямое БПФ с нормировкой
vector<complex<double>> FFT(vector<complex<double>> signal) {
    butterflyTransform(signal, -1.0);
    
    const double norm = sqrt(signal.size());
    transform(signal.begin(), signal.end(), signal.begin(), 
             [norm](auto x) { return x / norm; });
             
    return signal;
}

// Обратное БПФ с нормировкой
vector<complex<double>> IFFT(vector<complex<double>> spectrum) {
    butterflyTransform(spectrum, 1.0);
    
    const double norm = sqrt(spectrum.size());
    transform(spectrum.begin(), spectrum.end(), spectrum.begin(),
             [norm](auto x) { return x / norm; });
             
    return spectrum;
}

// Проверка степени двойки
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Чтение сигнала из файла
vector<complex<double>> readSignal(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) throw runtime_error("File error");

    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(int));
    
    vector<complex<double>> data(size);
    file.read(reinterpret_cast<char*>(data.data()), size * sizeof(complex<double>));
    
    return data;
}

// Запись сигнала в файл
void writeSignal(const string& filename, const vector<complex<double>>& data) {
    ofstream file(filename, ios::binary);
    if (!file) throw runtime_error("File error");

    const int size = data.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(int));
    file.write(reinterpret_cast<const char*>(data.data()), size * sizeof(complex<double>));
}

vector<complex<double>> readSignalData(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) throw runtime_error("Файл не открылся");

    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(int));
    
    vector<complex<double>> data(size);
    file.read(reinterpret_cast<char*>(data.data()), size * sizeof(complex<double>));
    
    return data;
}

void max_error(const std::vector<std::complex<double>>& signal, const std::vector<std::complex<double>>& ẋ)
{
    double Real = 0.0;
    double Im = 0.0;
    for (int i = 0; i < signal.size(); ++i) {
        double realDiff = abs(ẋ[i].real() - signal[i].real());
        double imagDiff = abs(ẋ[i].imag() - signal[i].imag());
        
        if (realDiff > Real) {
            Real = realDiff;
        }
        
        if (imagDiff > Im) {
            Im = imagDiff;
        }
    }

    
    cout << "Отклонение: " << endl;
    cout << "Вещественная часть: " << Real << endl;
    cout << "Мнимая: " << Im << endl;

}

int main() {
    try {
        cout << "n = 6:\n";
        cout << "Время ДПФ:\t";
        auto signal = readSignalData("index_of_exponent_6.bin");
        MEASURE_TIME(auto spectrum_dpf = FourierTransformer::transform(signal););
        cout << "Время БПФ:\t";
        MEASURE_TIME(auto spectrum_bpf = FFT(signal););

        cout << "\nn = 7:\n";
        cout << "Время ДПФ:\t";
        signal = readSignalData("index_of_exponent_7.bin");
        MEASURE_TIME(auto spectrum_dpf = FourierTransformer::transform(signal););
        cout << "Время БПФ:\t";
        MEASURE_TIME(auto spectrum_bpf = FFT(signal););

        cout << "\nn = 8:\n";
        cout << "Время ДПФ:\t";
        signal = readSignalData("index_of_exponent_8.bin");
        MEASURE_TIME(auto spectrum_dpf = FourierTransformer::transform(signal););
        cout << "Время БПФ:\t";
        MEASURE_TIME(auto spectrum_bpf = FFT(signal););
        
        cout << "\nn = 9:\n";
        cout << "Время ДПФ:\t";
        signal = readSignalData("index_of_exponent_9.bin");
        MEASURE_TIME(auto spectrum_dpf = FourierTransformer::transform(signal););
        cout << "Время БПФ:\t";
        MEASURE_TIME(auto spectrum_bpf = FFT(signal););
        
        cout << "\nn = 10:\n";
        cout << "Время ДПФ:\t";
        signal = readSignalData("index_of_exponent_10.bin");
        MEASURE_TIME(auto spectrum_dpf = FourierTransformer::transform(signal););
        cout << "Время БПФ:\t";
        MEASURE_TIME(auto spectrum_bpf = FFT(signal););
        
        cout << "\nn = 11:\n";
        cout << "Время ДПФ:\t";
        signal = readSignalData("index_of_exponent_11.bin");
        MEASURE_TIME(auto spectrum_dpf = FourierTransformer::transform(signal););
        cout << "Время БПФ:\t";
        MEASURE_TIME(auto spectrum_bpf = FFT(signal););
        
        cout << "\nn = 12:\n";
        cout << "Время ДПФ:\t";
        signal = readSignalData("index_of_exponent_12.bin");
        MEASURE_TIME(auto spectrum_dpf = FourierTransformer::transform(signal););
        cout << "Время БПФ:\t";
        MEASURE_TIME(auto spectrum_bpf = FFT(signal););
        
        // auto signal = readSignalData("binary_file_signal.bin");

        // if (!isPowerOfTwo(signal.size()))
        //     throw runtime_error("Не степень двойки((");

        // auto spectrum_dpf = FourierTransformer::transform(signal);
        // auto ẋ_dpf = FourierTransformer::inverseTransform(spectrum_dpf); // По сути исходный сигнал, но мы его два раза преобразовали

        // cout << "ДПФ и ОДПФ\n";
        // max_error(signal, ẋ_dpf);

        // cout << "\nБПФ и ОБПФ\n";
        // auto spectrum_bpf = FFT(signal);
        // //writeSignal("FFT_task.bin", spectrum_bpf);
        // auto ẋ_bpf = IFFT(spectrum_bpf);
        // max_error(signal, ẋ_bpf);

        // cout << "\nОтличие ДПФ и БПФ\n";
        // max_error(ẋ_dpf, ẋ_bpf);

    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}