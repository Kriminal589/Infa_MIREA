/*
 Под какой процент p выдана ссуда величиной S рублей, которая гасится месячными
 выплатами величиной m в течение n лет. Формула приведена в предыдущей задаче.
 p - need to find; S,m n - const
 
 r = p / 100.0; z = pow(r + 1,n)
 
 m = (S * (p / 100.0) * pow(1 + (p / 100.0), n)) / (12 * (pow(1 + (p / 100.0),n) - 1);
 */


#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    double S, m, n, p;
    cout << "Write S, m, n" << endl;
    S = 2000000;
    m = 29982;
    n = 10;
    
    
    if ((S < 0) || (m < 0) || (n < 0))
        return 0;
    
    p = 0.00001;
    
    for (;(S * (p / 100) * pow((1 + (p/100)), n)) / (12*(pow((1 + (p/100)), n)-1)) < m; p += 0.0000001)
    {
    }
    cout << fixed << setprecision(7) << p << endl;
    
}
