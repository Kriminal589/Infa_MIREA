#include <iostream>
#include "nes_fun.cpp"
using namespace std;
int main(){
    int x,y;
    cin >> x >> y;
    int sum = rectangle(x, y);
    cout << sum <<endl;
}
