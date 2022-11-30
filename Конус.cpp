//Вычислить объем и полную поверхность усеченного конуса:
//V = 1/3h(R2+Rr+r2), S = (R2+(R+r)l+r2).
#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int V,R,r,l,S,h;
    cin >> R >> r >> l >> h;
    V = (3.14 * h*(R*R + R*r + r*r)) / 3;
    S = sqrt(R*R*(R+r)*l+r*r);
    cout<<"V = "<<V<<" "<<"S = "<<S; 
}