/*
 Под какой процент p выдана ссуда величиной S рублей, которая гасится месячными
 выплатами величиной m в течение n лет. Формула приведена в предыдущей задаче.
 p - need to find; S,m n - const
 
 r = p / 100.0; z = pow(r + 1,n)
 
 m = (S * (p / 100.0) * pow(1 + (p / 100.0), n)) / (12 * (pow(1 + (p / 100.0),n) - 1);
 */


#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double S, m, n, p;
    bool Right = true;
    
    cout << "Write S, m, n" << endl;
    cin >> S >> m >> n;
    
    // Идея в том, что в цикле while мы будем менять число до тех пор, пока оно не совпадет.
    
    p = 1.0;
    
    double z = (S * (p / 100.0) * pow(1.0 + (p / 100.0), n)) / (12 * (pow(1.0 + (p / 100.0),n) - 1.0)) ;
    

    if (m > z)
    {
        while (Right)
        {
            p += 0.01;
            z = (S * (p / 100.0) * pow(1 + (p / 100.0), n)) / (12 * (pow(1 + (p / 100.0),n) - 1)) ;
            z = round(z * 1000) / 1000;
            
            if (z == m)
            {
                Right = false;
                break;
            }
        }
    }
    
    if (z > m)
    {
        while (Right)
        {
            p -= 0.01;
            if (p == 0.0)
                continue;
            z = (S * (p / 100.0) * pow(1 + (p / 100.0), n)) / (12 * (pow(1 + (p / 100.0),n) - 1)) ;
            z = round(z * 1000) / 1000;
            
            if (z == m)
            {
                Right = false;
                break;
            }
        }
    }
    
    cout <<"p = "<< p << endl;
    return 0;
    
}

