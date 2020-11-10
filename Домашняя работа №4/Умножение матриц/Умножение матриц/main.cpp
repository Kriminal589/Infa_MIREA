#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <ctype.h>
using namespace std;
int main()
{
    double first_matrix[3][4];
    double second_matrix[4][2];
    double end_matrix[3][2];
    ifstream price("/Users/user/Desktop/second_matrix.txt");
    ifstream number("/Users/user/Desktop/first_matrix.txt");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            number >> first_matrix[i][j];
            if (first_matrix[i][j] < 0){
                cout <<"Введено отрицательное число."<<endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
            price >> second_matrix[i][j];
            if (second_matrix[i][j] < 0){
                cout <<"Введено отрицательное число."<<endl;
                return 0;
            }
        }
    }
    char k = 'a';
    if (isalpha(k))
        
    
    for (int z = 0; z < 3; z++){
        for (int f = 0; f < 4; f++){
            double n = 0;
            for (int g = 0; g < 4; g++){
                n += first_matrix[z][g] * second_matrix[g][f];
            }
            end_matrix[z][f] = n;
        }
    }
    
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            cout<<fixed<<setprecision(2)<<end_matrix[i][j]<<"   ";
        }
        cout<<endl;
    }
    
    
    
    double sum1, sum2, sum3;
    sum1 = end_matrix[0][0] + end_matrix[0][1];
    sum2 = end_matrix[1][0] + end_matrix[1][1];
    sum3 = end_matrix[2][0] + end_matrix[2][1];
    double sum_max, sum_min;
    sum_max = sum_min = sum1;
    if (sum_max < sum2)
        sum_max = sum2;
    if (sum_max < sum3)
        sum_max = sum3;
    if (sum_min > sum2)
        sum_min = sum2;
    if (sum_min > sum3)
        sum_min = sum3;
    if (sum_max == sum1)
        cout << "Первый продавец выручил больше всего денег." << endl;
    if (sum_max == sum2)
        cout << "Второй продавец выручил больше всего денег." << endl;
    if (sum_max == sum3)
        cout << "Третий продавец выручил больше всего денег." << endl;
    if (sum_min == sum1)
        cout << "Первый продавец выручил меньше всего денег." << endl;
    if (sum_min == sum2)
        cout << "Второй продавец выручил меньше всего денег." << endl;
    if (sum_min == sum3)
        cout << "Третий продавец выручил меньше всего денег." << endl;
    sum1 = end_matrix[0][0]; sum2 = end_matrix[1][0]; sum3 = end_matrix[2][0];
    double k_max, k_min; k_max = k_min = end_matrix[0][1]; int a = 1; int m = 1;
    for (int i = 1; i < 3; i++){
        if (k_max < end_matrix[i][1]){
            k_max = end_matrix[i][1]; a = i+1;
        }
        else if (k_min > end_matrix[i][1]){
            k_min = end_matrix[i][1]; m = i+1;
        }
    }
    cout <<"Наибольшие комиссионные получил "<<a<<" продавец. А наименьшие получил "<<m<<" продавец."<<endl;
    cout <<"Общая сумма вырученных денег равна "<<sum1+sum2+sum3<<endl;
    cout <<"Общая сумма комиссионных равна "<<end_matrix[0][1]+end_matrix[1][1]+end_matrix[2][1]<<endl;
    cout <<"Общая сумма денег равна "<<sum1+sum2+sum3+end_matrix[0][1]+end_matrix[1][1]+end_matrix[2][1]<<endl;
    return 0;
}
 
