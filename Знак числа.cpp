#include <iostream>
using namespace std;

int sign (float Val)
{
    if (Val < 0.) return -1;
    
    if (Val == 0.) return 0;
    
    if (Val > 0) return 1;
    
    return 0;
}

int main()
{
    cout <<"Введите число..";
    float a; cin >> a;
    int b = sign(a);
    cout << b << endl;
    system("pause");
}
