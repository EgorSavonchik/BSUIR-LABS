#include <vector>
#include <cmath>
#include <iostream>
#include <chrono>
#include <omp.h>

//const double M_PI = 3.14159265358979323846;

typedef std::vector<double> RealVector;

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

    std::cout << "Enter signal length: ";
    std::cin >> n;

    // Генерация массива для тестирования
    RealVector input;
    for (int i = 0; i < n; i++) {
        input.push_back(sin(2 * M_PI * i / 10)); // Пример: синусоида с частотой 0.1
    }

    std::cout << "Choose the number of threads (1 for single-threaded, " << omp_get_max_threads() << " for all threads): ";
    std::cin >> num_threads;

    // Измерение времени выполнения
    auto start = std::chrono::steady_clock::now();

    // Применение распараллеленного преобразования Фурье с аффинитетом
    RealVector output;
    dft_parallel(input, output, num_threads);

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    // Вывод времени выполнения
    std::cout << "Time taken: " << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;
    std::cin >> num_threads;

    return 0;
}
