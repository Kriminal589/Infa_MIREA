#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float S, p, m, n, r;
    cout << "S = ";
    cin >> S;
    cout << "p = ";
    cin >> p;
    cout << "n = ";
    cin >> n;
    if (S <= 0 || p <= 0 || n <= 0) {
        cout << "Ошибка";
        return 0;
    }
    else {
        r = p / 100;
        m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
        cout << "m = " << m;
    }
}
// 2000000  10  12.4
