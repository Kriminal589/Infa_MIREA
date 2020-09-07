#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;
int main(){
    setlocale(LC_ALL,"Russian");
    system("chcp 1251");
    double a, b, c, x;
    cout << "Пожалуйста, введите числа." << endl;
    cin >> a >> b >> c;
    x = (b*b - 4*a*c);
    if (x == 0)
    {
        x = (-b)/(-2*a);
        cout << x;
    }
    else if (x < 0)
    {
        cout << "Ошибка. Дискриминант меньше нуля.";
    }
    else if (x > 0)
    {
        double x1, x2;
        x1 = (-b + sqrt(x))/2*a;
        x2 = (-b - sqrt(x))/2*a;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    return 0;
}