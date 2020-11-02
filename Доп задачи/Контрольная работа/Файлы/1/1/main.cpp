#include <iostream>
#include <fstream>
using namespace std;
int main(){
    char f_name[] = "/Users/user/Desktop/lesson.txt";
    ifstream f(f_name);
    double a[3][3];
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            f >> a[i][j];
        }
    }
    cout<<"Игрушки, цена которых не превышает 400 р., и которые подходят детям 8 лет:"<<endl;
    int c = 1;
    for (int i = 0; i<3;i++){
        if (((int)a[i][1] < 400) && ((int)a[i][2] <= 8)){
            cout<<c<<". "<<a[i][0];
            c++;
        }
    }
}
