#include <iostream>
using namespace std;

void inMatrix(double **matrix, int N, int M){
    int x;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> x;
            matrix[i][j] = x;
        }
    }
}

void inVector(double *vector, int M){
    int x;
    for (int i = 0; i < M; i++){
        cin >> x;
        vector[i] = x;
    }
}

double* multiplication(double** matrix, double* vector, int N, int M){
    double* newVector = new double[M];
    double x;
    for (int i = 0; i < N; i++){
        x = 0;
        for (int j = 0; j < M; j++){
            x += matrix[i][j] * vector[j];
        }
        newVector[i] = x;
    }
    return newVector;
}

void outVector (double* vector, int N){
    for (int i = 0; i < N; i++){
        cout<<vector[i]<< " " <<endl;
    }
}

int main()
{
    int N,M;
    cout << "Введите размер матрицы в формате NxM, где N - кол-во строк, M - кол-во столбцов: ";
    cin >> N >> M;
    cout << "Вектор имеет " << M << " элементов."<<endl;
    double **first_matrix = new double* [N];
    double *second_matrix = new double [M];
    for (int i = 0; i < N; i++){
        first_matrix[i] = new double [M];
    }
    cout << "Заполните матрицу. Заполнение происходит построчно."<<endl;
    inMatrix(first_matrix, N, M);
    cout << "Заполните вектор: ";
    inVector(second_matrix, M);
    cout << "Происходит перемножение матриц..."<<endl;
    double* vector = multiplication(first_matrix, second_matrix, N, M);
    cout << "Умножение произведено успешно. Вот новый вектро:"<<endl;
    outVector(vector, N);
    return 0;
}
