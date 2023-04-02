#include <iostream>
#include <string>
#include <cmath>

int ucheck() {
    int x = 0, i, m = 0;
    std::string n;

    std::cin >> n;

    while (m == 0) {
        for (i = 0; i < (int)n.length(); i++) {
            if (!((n[i] - '0') >= 0 && (n[i] - '0') <= 9)) {
                std::cout << "incorrect number" << std::endl;

                m = 1;
                break;
            }
        }

        if (m == 1) {
            m = i = 0;

            std::cout << "enter right number" << std::endl;
            std::cin >> n;
        }

        if (i == (int)n.length()) {
            for (int a = 0; a < (int)n.length(); a++) {
                x += (n[a] - '0') * std::pow(10, n.length() - a - 1);
            }
            m = 1;
        }
    }

    return x;
}

int main() {
    int n, counter = 1;

    std::cout << "builds a magic square of any order" << std::endl;
    std::cout << "enter square order n" << std::endl;
    n = ucheck();

    int** p_arr = new int* [n];

    for (int i = 0; i < n; i++)
        p_arr[i] = new int[n];

    if (n % 2 == 1) {
        int** p_odd = new int* [2 * n - 1];

        for (int i = 0; i < 2 * n - 1; i++) 
            p_odd[i] = new int[2 * n - 1];

        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                p_odd[i][j] = 0;
            }
        }

        for (int i = (n * 2 - 1) / 2, j = 0; i < 2 * n - 1; i++, j++) {
            for (int x = i, y = j, num = 0; num < n; x--, y++, num++) {
                p_odd[x][y] = counter;
                counter++;
            }
        }

        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                if (i > ((n / 2) * 3) && p_odd[i][j] != 0) {
                    p_odd[i - n][j] = p_odd[i][j];
                }
                else if (i < n / 2 && p_odd[i][j] != 0) {
                    p_odd[n + i][j] = p_odd[i][j];
                }
                else if (j > ((n / 2) * 3) && p_odd[i][j] != 0) {
                    p_odd[i][j - n] = p_odd[i][j];
                }
                else if (j < n / 2 && p_odd[i][j] != 0) {
                    p_odd[i][n + j] = p_odd[i][j];
                }
            }
        }
        for (int i = n / 2, x = 0; i < 2 * n - (n / 2) - 1; i++, x++) {
            for (int j = n / 2, y = 0; j < 2 * n - (n / 2) - 1; j++, y++)
                p_arr[x][y] = p_odd[i][j];
        }

        for (int i = 0; i < 2 * n - 1; i++) {
            delete[] p_odd[i];
        }
        delete[] p_odd;
    } else if (n % 4 == 2) {
        n /= 2;

        int** p_odd = new int* [2 * n - 1];

        for (int i = 0; i < 2 * n - 1; i++)
            p_odd[i] = new int[2 * n - 1];

        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                p_odd[i][j] = 0;
            }
        }

        for (int i = (n * 2 - 1) / 2, j = 0; i < 2 * n - 1; i++, j++) {
            for (int x = i, y = j, num = 0; num < n; x--, y++, num++) {
                p_odd[x][y] = counter;
                counter++;
            }
        }

        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                if (i > ((n / 2) * 3) && p_odd[i][j] != 0) {
                    p_odd[i - n][j] = p_odd[i][j];
                }
                else if (i < n / 2 && p_odd[i][j] != 0) {
                    p_odd[n + i][j] = p_odd[i][j];
                }
                else if (j > ((n / 2) * 3) && p_odd[i][j] != 0) {
                    p_odd[i][j - n] = p_odd[i][j];
                }
                else if (j < n / 2 && p_odd[i][j] != 0) {
                    p_odd[i][n + j] = p_odd[i][j];
                }
            }
        }

        for (int i = n / 2, x = 0; i < 2 * n - (n / 2) - 1; i++, x++) {
            for (int j = n / 2, y = 0; j < 2 * n - (n / 2) - 1; j++, y++)
                p_arr[x][y] = p_odd[i][j];
        }

        for (int i = 0; i < 2 * n - 1; i++) {
            delete[] p_odd[i];
        }
        delete[] p_odd;

        n *= 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < n / 2 && j >= n / 2) {
                    p_arr[i][j] = p_arr[i][j - n / 2] + n * n / 2;
                }
                else if (i >= n / 2 && j < n / 2) {
                    p_arr[i][j] = p_arr[i - n / 2][j] + 3 * n * n / 4;
                }
                else if (i >= n / 2 && j >= n / 2) {
                    p_arr[i][j] = p_arr[i - n / 2][j - n / 2] + n * n / 4;
                }
            }
        }

        for (int i = 0; i < n / 2; i++) {
            if (i == 0 || i == n / 2 - 1) {
                p_arr[i][0] += p_arr[i + n / 2][0];
                p_arr[i + n / 2][0] = p_arr[i][0] - p_arr[i + n / 2][0];
                p_arr[i][0] -= p_arr[i + n / 2][0];
            } else {
                p_arr[i][1] += p_arr[i + n / 2][1];
                p_arr[i + n / 2][1] = p_arr[i][1] - p_arr[i + n / 2][1];
                p_arr[i][1] -= p_arr[i + n / 2][1];
            }
        }

        for (int i = 0; i < n / 2; i++) {
            for (int j = n / 2 - 1 + (n / 2 - 3) / 2; j > n / 2 - 1 + (n / 2 - 3) / 2 - n / 2 + 3; j--) {
                p_arr[i][j] += p_arr[i + n / 2][j];
                p_arr[i + n / 2][j] = p_arr[i][j] - p_arr[i + n / 2][j];
                p_arr[i][j] -= p_arr[i + n / 2][j];
            }
        }
    } else {
        counter = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 4 == 0 || i % 4 == 3) {
                    if (j % 4 == 1 || j % 4 == 2) {
                        p_arr[i][j] = counter;
                    }
                } else {
                    if (j % 4 == 0 || j % 4 == 3) {
                        p_arr[i][j] = counter;
                    }
                }
                counter++;
            }
        }

        counter--;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 4 == 0 || i % 4 == 3) {
                    if (j % 4 == 0 || j % 4 == 3) {
                        p_arr[i][j] = counter;
                    }
                } else {
                    if (j % 4 == 1 || j % 4 == 2) {
                        p_arr[i][j] = counter;
                    }
                }
                counter--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << p_arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++)
        delete[] p_arr[i];

    delete[] p_arr;
}