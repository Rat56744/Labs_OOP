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

// Запись сигнала в файл
void writeSignal(const string& filename, const vector<complex<double>>& data) {
    std::ofstream file(filename, ios::binary);
    if (!file) throw runtime_error("File error");

    const int size = data.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(int));
    file.write(reinterpret_cast<const char*>(data.data()), size * sizeof(complex<double>));
}

class SignalProcessor {
public:
    static vector<complex<double>> computeConvolution(
        const vector<complex<double>>& x,
        const vector<complex<double>>& h) {
        
        const size_t N = x.size();
        const size_t M = h.size();
        vector<complex<double>> result(N + M - 1);

        #pragma omp parallel for
        for (int n = 0; n < result.size(); ++n) {
            const int k_start = std::max(0, n - static_cast<int>(M) + 1);
            const int k_end = std::min(static_cast<int>(N), n + 1);
            
            complex<double> sum(0, 0);
            for (int k = k_start; k < k_end; ++k) {
                sum += x[k] * h[n - k];
            }
            result[n] = sum;
        }

        return result;
    }
};

class FileIO {
    public:
        static bool readSignals(const string& path, 
                              vector<complex<double>>& x,
                              vector<complex<double>>& y) {
            std::ifstream file(path, std::ios::binary);
            if (!file) return false;
    
            int32_t size;
            file.read(reinterpret_cast<char*>(&size), sizeof(size));
            
            if (size <= 0) return false;
            
            x.resize(size);
            y.resize(size);
            file.read(reinterpret_cast<char*>(x.data()), size * sizeof(complex<double>));
            file.read(reinterpret_cast<char*>(y.data()), size * sizeof(complex<double>));
    
            return file.good();
        }

    static bool writeResult(const string& path, 
                          const vector<complex<double>>& data) {
        std::ofstream file(path, std::ios::binary);
        if (!file) return false;

        const int32_t size = data.size();
        file.write(reinterpret_cast<const char*>(&size), sizeof(size));
        file.write(reinterpret_cast<const char*>(data.data()), size * sizeof(complex<double>));

        return true;
    }
};

// -------------------------- Свертка с помощью БПФ ---------------------

vector<complex<double>> convolutionFFT(const vector<complex<double>>& x, 
        const vector<complex<double>>& y) {
    // 1. Определяем необходимый размер
    const int m = x.size();
    const int l = y.size();
    const int min_size = m + l - 1;

    // 2. Находим ближайшую степень двойки
    int n = 1;
    while (n < min_size) {
    n <<= 1;
    }

    // 3. Дополняем сигналы нулями
    vector<complex<double>> x_padded(n, 0.0);
    vector<complex<double>> y_padded(n, 0.0);
    copy(x.begin(), x.end(), x_padded.begin());
    copy(y.begin(), y.end(), y_padded.begin());

    // 4. Вычисляем БПФ для обоих сигналов
    auto x_fft = FFT(x_padded);
    auto y_fft = FFT(y_padded);

    // 5. Поэлементное умножение спектров с масштабированием
    vector<complex<double>> product_fft(n);
    const double scale = sqrt(n);
    for (int i = 0; i < n; ++i) {
    product_fft[i] = x_fft[i] * y_fft[i] * scale;
    }

    // 6. Обратное преобразование Фурье
    auto result_padded = IFFT(product_fft);

    // 7. Обрезаем результат до нужного размера
    vector<complex<double>> result(min_size);
    copy(result_padded.begin(), result_padded.begin() + min_size, result.begin());

    return result;
}
int main() {
    setlocale(LC_ALL, "Russian");
    const string inputPath = "5_task_convol.bin";
    const string outputPath1 = "convol_result_direct.bin";  // Для обычной свертки
    const string outputPath2 = "convol_result_fft.bin";     // Для свертки через БПФ

    vector<complex<double>> signalX, signalY;
    if (!FileIO::readSignals(inputPath, signalX, signalY)) {
        cerr << "Ошибка чтения входных данных" << endl;
        return 1;
    }

    // Обычная свертка
    vector<complex<double>> result_direct;
    cout << "Время выполнения свертки: ";
    MEASURE_TIME(result_direct = SignalProcessor::computeConvolution(signalX, signalY););
    cout << "Размер свертки: " << result_direct.size() << '\n';
    
    // Свертка через БПФ
    vector<complex<double>> result_fft;
    cout << "Время выполнения свертки c БПФ: ";
    MEASURE_TIME(result_fft = convolutionFFT(signalX, signalY););


    if (!FileIO::writeResult(outputPath1, result_direct)) {
        cerr << "Ошибка сохранения обычной свертки" << endl;
        return 1;
    }
    if (!FileIO::writeResult(outputPath2, result_fft)) {
        cerr << "Ошибка сохранения FFT-свертки" << endl;
        return 1;
    }

    return 0;
}