#include <iostream>
#include <math.h>
using namespace std;
int main(){
    float n;
    cout<<"Введите: "; cin>>n;
    float x = 0; float sum = 0;
    for (int i = 1; i <= n; i++){
        x += sin(i);
        sum += i/x;
    }
    cout << sum << endl;
}
