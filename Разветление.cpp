#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int x, a;
    int w;
    cin >> a >> x;
    if (abs(x) >= 1){
        w = sqrt(a - x*x);
    }
    else {
        w = a*log(abs(x));
    }
    cout << w;
}