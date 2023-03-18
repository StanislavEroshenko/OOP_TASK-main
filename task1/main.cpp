#include <iostream>
#include <vector>

int** CreateMatrix(int n)
{
    int** tmp = new int *[n];
    for(int i = 0; i < n; i++)tmp[i] = new int [n];
    std::cout << "Введите цифры в матрицу: " << std::endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            std::cin >> tmp[i][j];
    return tmp;
}

void DeleteMatrix(int** &matrix, int n)
{
    for(int i = 0; i < n; i++)delete matrix[i];
    delete matrix;
}

void MaxNum(int** matrix, int n)
{
    int max = matrix[0][0];
    std::vector <std::pair<int, int>> answer;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if (matrix[i][j] > max){max = matrix[i][j]; answer.clear();}
            if (matrix[i][j] == max)answer.push_back(std::make_pair(i, j));
        }
    std::cout << "максимальное число в матрице: " << max << " находиться по индексам: [";
    for(std::pair<int, int> i: answer)std::cout << i.first << "][" << i.second << "]; " << std::endl;
}

float DiagonalArithMid(int **matrix, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += matrix[i][i] + matrix[i][(n-1)-i];
    }
    if (n % 2)
    {
        sum -=  matrix[(n-1) / 2][(n-1) / 2];
        return sum / (n*2.0-1);
    }
    else return sum / (n*2.0);
}

int** SumMatNums(int** matrix, int n)
{
    int** tmp = new int *[n];
    for(int i = 0; i < n; i++)tmp[i] = new int [n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tmp[i][j] = 0;
            int buf = matrix[i][j];
            while(buf != 0)
            {
                tmp[i][j] += buf % 10;
                buf = buf / 10;
            }
        }
    }
    return tmp;
}

int** SumMat(int **mat_1, int** mat_2, int n)
{
    int** tmp = new int *[n];
    for(int i = 0; i < n; i++)tmp[i] = new int [n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp[i][j] = mat_1[i][j] + mat_2[i][j] ;
    return tmp;
}

int** MultMat(int **mat_1, int** mat_2, int n)
{
    int** tmp = new int *[n];
    for(int i = 0; i < n; i++)tmp[i] = new int [n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            tmp[i][j] = 0;
            for(int k = 0; k < n; k++)
                tmp[i][j] += mat_1[i][k] * mat_2[k][j];
        }
    return tmp;
}

void PrintMatrix(int** matrix, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
            
}

int main()
{
    int N;
    std:: cout << "Введите размерность матриц: ";
    std:: cin >> N;
    int** C = CreateMatrix(N);
    MaxNum(C, N);
    std::cout << DiagonalArithMid(C, N) << std::endl;
    int** A = SumMatNums(C, N);
    PrintMatrix(A, N);
    int** B = SumMat(A, C, N);
    B = MultMat(B, B, N);
    PrintMatrix(B, N);
    DeleteMatrix(A, N);
    DeleteMatrix(B, N);
    DeleteMatrix(C, N);
}