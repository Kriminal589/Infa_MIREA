#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double y;
    for (double x = -4.0; x <= 4.0; x += 0.5){
        if (x == 1){
            cout << "Ошибка. Деление на 0." << " ";
        }
        else {
            y = (x*x - 2*x + 2) / (x - 1);
            cout << y << " ";
        }
    }
}