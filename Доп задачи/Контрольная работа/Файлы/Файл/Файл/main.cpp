#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <ctype.h>
using namespace std;
int main(){
    //словарь для перевода из char в int
    map<char,int> number = {
        {'0',0}, {'1',1}, {'2',2}, {'3',3}, {'4',4}, {'5',5}, {'6',6}, {'7',7}, {'8',8}, {'9',9}
    };
    
    string k; int count = 0;

    ifstream file("/Users/user/Desktop/Информатика/lesson.txt");
    
    //Нужно посчитать кол-во стран. Это будет размером нашего будущего массива.
    while (!file.eof()){
        file >> k;
        if (isalpha((int)k[0]))
            count++;
    }
    
    file.close();
    
    ifstream co("/Users/user/Desktop/Информатика/lesson.txt");
    
    string** country = new string* [count]; // динамический массив в который я перенесу все
    
    for (int i = 0; i < count; i++){
        country[i] = new string [5];
    }
    
    // Заполняю массив данными из файла
    for (int i = 0; i < count; i++){
        for (int j = 0; j < 5; j++){
                co >> country[i][j];
        }
    }
    
    co.close();
    
    //Массив для хранения суммы очков. Сначала его нужно обнулить
    int* point = new int [count];
    
    for (int i = 0; i < count; i++){
        point[i] = 0;
    }
    
    // Берем только элементы, где стоят числа (мы заведомо знаем их индексы). Складываем с помощью словаря и умножаем на нужное число
    for (int i = 0; i < count; i++){
        for (int j = 2; j < 5; j++){
            k = country[i][j]; int sum = 0;
            for (int g = 0; g < k.length(); g++){
                sum *= 10;
                sum += number[k[g]];
            }
            
            if (j == 2)
                sum *= 7;
            
            if (j == 3)
                sum *= 6;
            
            if (j == 4)
                sum *= 5;
            
            point[i] += sum;
        }
    }

    // Делаем сортировку по макс. баллов. Не забываем менять не только баллы, но и массив типа string
    for (int i = 0; i < count-1; i++){
        for (int j = 0; j < count-1; j++){
            if (point[j] < point[j+1]){
                int temp = point[j]; point[j] = point[j+1]; point[j+1] = temp;
                k = country[j][0]; country[j][0] = country[j+1][0]; country[j+1][0] = k;
                k = country[j][2]; country[j][2] = country[j+1][2]; country[j+1][2] = k;
                k = country[j][3]; country[j][3] = country[j+1][3]; country[j+1][3] = k;
                k = country[j][4]; country[j][4] = country[j+1][4]; country[j+1][4] = k;
            }
        }
    }
    
    // Запишем полученные массивы обратно в файл
    ofstream c ("/Users/user/Desktop/Информатика/lesson.txt");
    for (int i = 0; i < count; i++){
        for (int j = 0; j < 5; j++){
            c << country[i][j] << ' ';
        }
        c << '|'<<'|' << ' ' << point[i];
        c << endl;
    }
    
    return 0;
}
