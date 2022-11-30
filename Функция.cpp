#include <iostream>
#include <math.h>
using namespace std;

//x = i; y = j; b = k;

int f(int i, int j, int k)
{
    return log(k - j) * sqrt(k - i); 
}

int main()
{
    int x, y, b;
    cin >> x >> y >> b;
    cout << f(x,y,b);
    return 0;
}
