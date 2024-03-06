import numpy as np;
import copy;

def inintial():
    n = int(input("Введите порядок матрицы: "))
    
    matrix = np.empty((n, n))
    vector = np.empty(n)

    # Вводим элементы матрицы
    print("Введите элементы матрицы построчно:")
    for i in range(n):
        for j in range(n):
            matrix[i][j] = float(input(f"Элемент [{i+1}, {j+1}]: "))

    print("Введенная матрица:")
    print(matrix)

    matrix_inverted = np.linalg.inv(matrix);

    # Вводим элементы вектора
    print("Введите элементы вектора:")
    for i in range(n):
        vector[i] = float(input(f"Элемент {i+1}: "))

    print("Введенный вектор:")
    print(vector)

    i = int(input("Введите i:"))

    return matrix, matrix_inverted, vector, n, i

def algo(matrix_inverted, vector, n, i):
    l = np.dot(matrix_inverted, vector)

    print("Шаг 1")
    if(l[i - 1] == 0):
        print("Матрица необратима")
        return
    else :
        print("Матрица обратима")

    print("Шаг 2")
    l_tilda = copy.deepcopy(l)
    l_tilda[i - 1] = -1
    print("l~ = " + str(l_tilda))

    print("Шаг 3")
    l_angle = (-1 / l[i - 1]) * l_tilda
    print("l^ = " + str(l_angle))

    print("Шаг 4")
    matrix_q = np.eye(n)
    for j in range(0, n):
        matrix_q[j][i - 1] = l_angle[j]
    print("Q = \n" + str(matrix_q))

    print("Шаг 5")
    final_matrix = np.zeros((n, n))
    for j in range(0, n):
        for k in range(0, n):
            if i - 1 != j:
                final_matrix[j][k] = matrix_q[j][j] * matrix_inverted[j][k] + matrix_q[j][i - 1] * matrix_inverted[i - 1][k]
            else:  
                final_matrix[j][k] = matrix_q[j][i - 1] * matrix_inverted[i - 1][k]    
    print("обратная матрица = \n" + str(final_matrix))

def main():
    #matrix, matrix_inverted, vector, n, i = inintial()
    #algo(matrix, matrix_inverted, vector, n, i)
    algo(np.array([[1, -1, 0], [0, 1, 0], [0, 0, 1]]), np.array([[1, 1, 0], [0, 1, 0], [0, 0, 1]]), np.array([1, 0, 1]), 3, 3)


if __name__ == '__main__':
    main()