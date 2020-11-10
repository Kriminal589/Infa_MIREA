#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <ctype.h>
using namespace std;
int main(){
    
    map<char,int> number = {
        {'0',0}, {'1',1}, {'2',2}, {'3',3}, {'4',4}, {'5',5}, {'6',6}, {'7',7}, {'8',8}, {'9',9}
    };
    
    string k; int count = 0; int z = 0;
    bool flag = true; bool pr = true;
    ofstream c ("/Users/user/Desktop/countrys.txt");
    ofstream p ("/Users/user/Desktop/points.txt");
    ifstream file("/Users/user/Desktop/Информатика/lesson.txt");
    
    int amount[193][3];
    for (int i = 0; i < 193; i++){
        for (int j = 0; j < 3; j++){
            amount[i][j] = 0;
        }
    }
    
    // Разбиваю страны и числа в разные файлы и считаю их кол-ва
    
    while (!file.eof()){
        k = ' ';
        file >> k;
        if (isalpha((int)k[0])){
            if (pr == true){
                p << ' ';
                pr = false;
            }
            count++;
            flag = true;
            c << k;
        }
        else {
            if (flag == true){
                c << ' ';
                flag = false;
            }
            
            if (isdigit(k[0])){
                pr = true;
                p << k;
            }
        }
    }
    file.close();
    p.close();
    c.close();
    
    
    ifstream po("/Users/user/Desktop/points.txt");
    ifstream co("/Users/user/Desktop/countrys.txt");
    
    
    
    string* country = new string[count]; // динамический массив со странами
    
    // создаю двумерный динамический массив с медалями
    int** point = new int* [count];
    for (int j = 0; j < count; j++){
        point[j] = new int [4];
    }
    
    for (int i = 0; i < count; i++){
        for (int j = 0; j < 4; j++){
            point[i][j] = 0;
        }
    }
    
    for (int i = 0; i < count; i ++){
        int f = 0; po >> k;
        for (int j = 0; j < 3; j++){
            z = 0;
            while (z < 2) {
                if (f == k.length())
                    break;
                z++;
                point[i][j] *= 10;
                point[i][j] += number[k[f]];
                f++;
            }
        }
    }
    

    for (int i = 0; i < count; i++){
        for (int j = 0; j < 4; j++){
            cout << point[i][j] << " ";
        }
        cout<<endl;
    }
 
    
    for (int i = 0; i < count; i++){
        co >> country[i];
    }

/*
    for (int i = 0; i < count; i++){
        cout << country[i] << " ";
    }
    cout<<endl;
*/
    
    int sum; int bal = 7;
    for (int i = 0; i < count; i++){
        for (int j = 0; j < 3; j++){
            sum = point[i][j] * bal;
            point[i][3] += sum;
        }
    }
    
    int temp;
    for (int i = 0; i < count-1; i++){
        if (point[i][3] < point[i+1][3]){
            k = country[i]; country[i] = country[i+1]; country[i+1] = k;
            temp = point[i][0]; point[i][0] = point[i+1][0]; point[i+1][0] = temp;
            temp = point[i][1]; point[i][1] = point[i+1][1]; point[i+1][1] = temp;
            temp = point[i][2]; point[i][2] = point[i+1][2]; point[i+1][2] = temp;
            temp = point[i][3]; point[i][3] = point[i+1][3]; point[i+1][3] = temp;
        }
    }
    
    //cout << country[1]<<endl;
    
    for (int i = 0; i < count; i++){
        cout << country[i] <<": ";
        for (int j = 0; j < 4; j++){
            cout << point[i][j] << " ";
        }
        cout<<endl;
    }
    
    return 0;
    
}
