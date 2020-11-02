#include <iostream>
using namespace std;

int sign (int Val)
{
    if (Val < 0.) return -1;
    
    else if (Val == 0.) return 0;
    
    else return 1;
    
}

int main()
{
    cout <<"Введите число..";
    int a; cin >> a;
    int b = sign(a);
    cout << b << endl;
    system("pause");
}
