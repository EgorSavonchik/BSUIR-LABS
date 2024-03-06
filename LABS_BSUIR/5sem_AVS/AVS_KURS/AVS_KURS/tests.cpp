#include <vector>
#include <cmath>
#include <iostream>
#include <chrono>
#include <omp.h>

//const double M_PI = 3.14159265358979323846;

typedef std::vector<double> RealVector;
std::vector<int> testValues { 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 55000, 60000, 65000, 70000, 75000 };

void dft_parallel(const RealVector& x, RealVector& X, int num_threads) {
    int N = x.size();
    X.resize(N);

#pragma omp parallel for num_threads(num_threads)
    for (int k = 0; k < N; k++) {
        double realPart = 0;
        double imagPart = 0;

#pragma omp parallel for reduction(+:realPart, imagPart) num_threads(num_threads)
        for (int n = 0; n < N; n++) {
            double angle = 2 * M_PI * k * n / N;
            realPart += x[n] * cos(angle);
            imagPart += x[n] * sin(angle);
        }

        X[k] = sqrt(realPart * realPart + imagPart * imagPart);
    }
}

int main() {
    int n = 0;
    int num_threads = 1;

    std::cout << "Choose the number of threads (1 for single-threaded, " << omp_get_max_threads() << " for all threads): ";
    std::cin >> num_threads;

    for (int i = 0; i < testValues.size(); i++)
    {
        n = testValues[i];
        
        // Генерация массива для тестирования
        RealVector input;
        for (int i = 0; i < n; i++) {
            input.push_back(sin(2 * M_PI * i / 10)); // Пример: синусоида с частотой 0.1
        }

        // Измерение времени выполнения
        auto start = std::chrono::steady_clock::now();

        // Применение распараллеленного преобразования Фурье с аффинитетом
        RealVector output;
        dft_parallel(input, output, num_threads);

        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;

        // Вывод времени выполнения
        std::cout << n << " : " << num_threads << " : " << std::chrono::duration <double, std::milli>(diff).count()  << " ms" << std::endl;
    }

    return 0;
}
