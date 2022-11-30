#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int S, n, p;
    double m;
    
    cout << "Write S, n, p" << endl;
    cin >> S >> n >> p;
    
    if (p == 0.0)
        return 0;
    
    double r = p / 100.0;
    double k = r + 1;
    
    m = (S * r * pow(k,n)) / (12 * (pow(k,n) - 1));
    
    cout << m << endl;
    return 0;
}
