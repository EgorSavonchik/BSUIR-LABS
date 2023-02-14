import numpy as np

np.set_printoptions(suppress=True, precision=5, floatmode="fixed")
epsilon = 10.0 ** (-5)
num = int(input("Enter an integer number of unknowns: "))
A = np.zeros((num, num))
b = np.zeros((num, 1))


# function for inputting matrix A
def input_matrix_A(n):
    # filling matrix A with coefficients
    print("Enter coefficients in the matrix A:")
    for i in range(n):
        for j in range(n):
            A[i][j] = float(input('A[' + str(i) + '][' + str(j) + ']='))

    return A


# function for inputting vector b
def input_matrix_b(n):
    # filling matrix b with coefficients
    print("Enter coefficients in the matrix b:")
    for i in range(n):
        for j in range(1):
            b[i][j] = float(input('b[' + str(i) + '][' + str(j) + ']='))

    return b


# function for creating matrix B (B = E - A)
def condition_2_B(matrix_A):
    n = matrix_A.shape[0]
    E = np.zeros((n, n))

    for i in range(n):
        for j in range(n):
            if i == j:
                E[i][j] = 1
            else:
                E[i][j] = 0

    return E - matrix_A


# function for creating matrix c (c = b)
def condition_2_c(matrix_b):
    return matrix_b


# function for creating matrix B (Jacobi scheme)
def CreateMatrixB(matrix_A):
    size = matrix_A.shape[0]
    B = np.zeros((size, size))
    for i in range(size):
        for j in range(size):
            if i == j:
                B[i][j] = 0
            else:
                B[i][j] = -matrix_A[i][j] / matrix_A[i][i]
    return B


# function for creating vector c (Jacobi scheme)
def CreateVectorC(matrix_A, vectorB):
    size = vectorB.shape[0]
    C = np.zeros(size)
    for i in range(size):
        C[i] = vectorB[i] / matrix_A[i][i]
    return C


# function for normalizing matrix B ( ||B||1 )
def normalize_B1(matrix_B):
    n = matrix_B.shape[0]

    norm1 = 0
    for i in range(n):
        temp_max = 0
        for j in range(n):
            temp_max += abs(matrix_B[i][j])
        if temp_max > norm1:
            norm1 = temp_max

    return norm1


# function for normalizing matrix B ( ||B||3 )
def normalize_B3(matrix_B):
    n = matrix_B.shape[0]

    norm3 = 0
    for j in range(n):
        temp_max = 0
        for i in range(n):
            temp_max += abs(matrix_B[i][j])
        if temp_max > norm3:
            norm3 = temp_max

    return norm3


# simple iterations method, jacobi scheme
def simple_iterations_jacobi_scheme(matrix_A, matrix_b):
    print("Simple iterations method, Jacobi scheme\n")
    n = matrix_A.shape[0]

    for i in range(n):
        if matrix_A[i, i] == 0.0:
            print("Element", [i, i], "is zero")
            return "ERROR"

    B = CreateMatrixB(matrix_A)
    c = CreateVectorC(matrix_A, matrix_b)

    # check diagonal predominance of rows
    sum3 = 0
    condition3 = True
    for i in range(n):
        sum3 = 0
        for j in range(n):
            if i != j:
                sum3 += abs(matrix_A[i, j])
        if sum3 >= abs(matrix_A[i, i]):
            print("Condition of diagonal predominance is not executed")
            condition3 = False
            break

    condition5 = True
    if not (normalize_B1(B) < 1):
        print("Norm1 of matrix >= 1, condition is not executed")
        condition5 = False

    # check diagonal predominance of columns
    condition4 = True
    condition6 = True
    if not condition3:
        sum4 = 0
        for i in range(n):
            sum4 = 0
            for j in range(n):
                if i != j:
                    sum4 += abs(matrix_A[j, i])
            if sum4 >= abs(matrix_A[i, i]):
                print("Condition of diagonal predominance is not executed")
                condition4 = False
                break

        if not (normalize_B3(B) < 1):
            print("Norm3 of matrix >= 1, condition is not executed")
            condition6 = False

    x = c

    norm = 1
    coef = 1
    if condition3 and condition5:
        norm = normalize_B1(B)
        coef = norm / (1 - norm)
    elif condition4 and condition6:
        norm = normalize_B3(B)
        coef = norm / (1 - norm)

    count = 0
    prev_x = x
    x = B.dot(x) + c
    if condition3:
        print("Condition of diagonal predominance of rows is executed")
        while coef*max(abs(x - prev_x)) >= epsilon:
            prev_x = x
            x = B.dot(x) + c
            count += 1

    elif condition4:
        print("Condition of diagonal predominance of columns is executed")
        while coef*abs(x - prev_x).sum() >= epsilon:
            prev_x = x
            x = B.dot(x) + c
            count += 1

    else:
        print("Loop is limited by number of iterations")
        NUMBER_OF_ITERATIONS = 300
        while NUMBER_OF_ITERATIONS > 0:
            prev_x = x
            x = B.dot(x) + c
            NUMBER_OF_ITERATIONS -= 1
            count += 1

    print("Number of iterations:", count)
    return x


# simple iterations method, second way
def simple_iterations_second_way(matrix_A, matrix_b):
    print("simple iterations' method, the second way\n")
    n = A.shape[0]

    for i in range(n):
        if A[i, i] == 0.0:
            print("Element", [i, i], "is zero")
            return "ERROR"

    mtrx_B = condition_2_B(matrix_A)
    mtrx_c = condition_2_c(matrix_b)

    condition1 = True
    if not (normalize_B1(mtrx_B) < 1):
        print("Norm1 of matrix >= 1, condition is not executed")
        condition1 = False

    condition2 = True
    if not (normalize_B3(mtrx_B) < 1):
        print("Norm3 of matrix >= 1, condition is not executed")
        condition2 = False

    x = mtrx_c

    norm = 1
    coef = 1
    if condition1:
        norm = normalize_B1(mtrx_B)
        coef = norm / (1 - norm)
    elif condition2:
        norm = normalize_B3(mtrx_B)
        coef = norm / (1 - norm)

    count = 0
    prev_x = x
    x = mtrx_B.dot(x) + mtrx_c
    if condition1:
        print("Condition of norm1 is executed")
        while coef*max(abs(x - prev_x)) >= epsilon:
            prev_x = x
            x = mtrx_B.dot(x) + mtrx_c
            count += 1

    elif condition2:
        print("Condition of norm3 is executed")
        while coef*abs(x - prev_x).sum() >= epsilon:
            prev_x = x
            x = mtrx_B.dot(x) + mtrx_c
            count += 1

    else:
        print("Loop limited by amount of iterations")
        NUMBER_OF_ITERATIONS = 300
        while NUMBER_OF_ITERATIONS > 0:
            prev_x = x
            x = mtrx_B.dot(x) + mtrx_c
            NUMBER_OF_ITERATIONS -= 1
            count += 1
        # x = np.linalg.solve(matrix_A, matrix_b)

    print("Number of iterations:", count)
    return x


# seidel method, jacobi scheme
def seidel_jacobi_scheme(matrix_A, matrix_b):
    print("Seidel method, Jacobi scheme\n")
    n = matrix_A.shape[0]

    for i in range(n):
        if matrix_A[i, i] == 0.0:
            print("Element", [i, i], "is zero")
            return "ERROR"

    B = CreateMatrixB(matrix_A)
    c = CreateVectorC(matrix_A, matrix_b)

    # check diagonal predominance of rows
    sum3 = 0
    condition3 = True
    for i in range(n):
        sum3 = 0
        for j in range(n):
            if i != j:
                sum3 += abs(matrix_A[i, j])
        if sum3 >= abs(matrix_A[i, i]):
            print("Condition of diagonal predominance is not executed")
            condition3 = False
            break

    condition5 = True
    if not (normalize_B1(B) < 1):
        print("Norm1 of matrix >= 1, condition is not executed")
        condition5 = False

    # check diagonal predominance of columns
    condition4 = True
    condition6 = True
    if not condition3:
        sum4 = 0
        for i in range(n):
            sum4 = 0
            for j in range(n):
                if i != j:
                    sum4 += abs(matrix_A[j, i])
            if sum4 >= abs(matrix_A[i, i]):
                print("Condition of diagonal predominance is not executed")
                condition4 = False
                break

        if not (normalize_B3(B) < 1):
            print("Norm3 of matrix >= 1, condition is not executed")
            condition6 = False

    H = np.zeros((n, n))
    for i in range(n):
        for j in range(i):
            H[i, j] = B[i, j]

    F = np.zeros((n, n))
    for i in range(n):
        for j in range(i+1, n):
            F[i, j] = B[i, j]

    count = 0
    x = c
    norm = 1
    coef = 1
    if condition3 and condition5:
        norm = normalize_B1(B)
        coef = norm / (1 - norm)
    elif condition4 and condition6:
        norm = normalize_B3(B)
        coef = norm / (1 - norm)

    prev_x = x
    x = H.dot(x) + F.dot(prev_x) + c
    if condition3:
        print("Condition of diagonal predominance of rows is executed")
        while coef*max(abs(x - prev_x)) >= epsilon:
            prev_x = x
            x = H.dot(x) + F.dot(prev_x) + c
            count += 1

    elif condition4:
        print("Condition of diagonal predominance of columns is executed")
        while coef*abs(x - prev_x).sum() >= epsilon:
            prev_x = x
            x = H.dot(x) + F.dot(prev_x) + c
            count += 1

    else:
        print("Loop is limited by amount of iterations")
        NUMBER_OF_ITERATIONS = 300
        while NUMBER_OF_ITERATIONS > 0:
            prev_x = x
            x = H.dot(x) + F.dot(prev_x) + c
            NUMBER_OF_ITERATIONS -= 1
            count += 1

    print("Number of iterations:", count)
    return x


# seidel method, second way
def seidel_second_way(matrix_A, matrix_b):
    print("Seidel method, the second variant\n")
    n = matrix_A.shape[0]

    for i in range(n):
        if matrix_A[i, i] == 0.0:
            print("Element", [i, i], "is zero")
            return "ERROR"

    mtrx_B = condition_2_B(matrix_A)
    mtrx_c = condition_2_c(matrix_b)

    condition1 = True
    if not (normalize_B1(mtrx_B) < 1):
        print("Norm1 of matrix >= 1, condition is not executed")
        condition1 = False

    condition2 = True
    if not (normalize_B3(mtrx_B) < 1):
        print("Norm3 of matrix >= 1, condition is not executed")
        condition2 = False

    x = mtrx_c

    norm = 1
    coef = 1
    if condition1:
        norm = normalize_B1(mtrx_B)
        coef = norm / (1 - norm)
    elif condition2:
        norm = normalize_B3(mtrx_B)
        coef = norm / (1 - norm)

    H = np.zeros((n, n))
    for i in range(n):
        for j in range(i):
            H[i, j] = mtrx_B[i, j]

    F = np.zeros((n, n))
    for i in range(n):
        for j in range(i, n):
            F[i, j] = mtrx_B[i, j]

    count = 0
    prev_x = x
    x = H.dot(x) + F.dot(prev_x) + mtrx_c
    if condition1:
        print("Condition of norm1 is executed")
        while coef * max(abs(x - prev_x)) >= epsilon:
            prev_x = x
            x = H.dot(x) + F.dot(prev_x) + mtrx_c
            count += 1

    elif condition2:
        print("Condition of norm3 is executed")
        while coef * abs(x - prev_x).sum() >= epsilon:
            prev_x = x
            x = H.dot(x) + F.dot(prev_x) + mtrx_c
            count += 1

    else:
        print("Loop is limited by amount of iterations")
        NUMBER_OF_ITERATIONS = 300
        while NUMBER_OF_ITERATIONS > 0:
            prev_x = x
            x = H.dot(x) + F.dot(prev_x) + mtrx_c
            NUMBER_OF_ITERATIONS -= 1
            count += 1
        # x = np.linalg.solve(matrix_A, matrix_b)

    print("Number of iterations:", count)
    return x


# testing program
matrixA = input_matrix_A(num)
matrixb = input_matrix_b(num)
matrixB = condition_2_B(matrixA)
n1 = normalize_B1(matrixB)
n3 = normalize_B3(matrixB)

np.set_printoptions(suppress=True, precision=abs(-5), floatmode="fixed")
print('**********************************************')
print('seidel method, 2nd way answer:')
answer_seidel2 = seidel_second_way(matrixA, matrixb)
print(answer_seidel2)
print('***********************************************')
print('simple iterations method, 2nd way answer:')
answer_simple_iters2 = simple_iterations_second_way(matrixA, matrixb)
print(answer_simple_iters2)
print('***********************************************')
print('seidel method, 1st way answer:')
answer_seidel1 = seidel_jacobi_scheme(matrixA, matrixb)
print(answer_seidel1)
print('***********************************************')
print('simple iterations method, 1st way answer:')
answer_simple_iters1 = simple_iterations_jacobi_scheme(matrixA, matrixb)
print(answer_simple_iters1)
print('***********************************************')
print()
print('numpy answer:')
print(np.linalg.solve(matrixA, matrixb))
