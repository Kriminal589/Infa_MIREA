#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {

setlocale(LC_ALL, "Russian");

int count = 0, sign = 0;
double s, m, n, p = 1;

cin >> s >> m >> n;

while ((s * (p / 100) * pow(1 + p / 100, n)) / (12 * (pow(1 + p / 100, n) - 1)) < m)
{
p += 0.1;
count += 1;
}

    cout << "Введите число до какого знака округлять " << sign << endl;
cin >> sign;

cout <<fixed << setprecision(sign) << p << endl;

cout << "Количество раз: " << count << endl;

return 0;

}
