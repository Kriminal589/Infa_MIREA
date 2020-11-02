#include <iostream>
#include <string>
using namespace std;

int main()
{
    int star = 0;
    int stripe = 24;
    for (int i = 0; i < 13;i++)
    {
        if (i==1)
        {
            stripe = 16;
            star = 8;
        }

        if (i>6)
        {
            stripe = 24;
            star = 0;
        }

        int a = star;
        int b;
        if (i% 2 !=0) b = stripe;
        else b = 0;

        while (a > 0)
        {
            cout << "* ";
            a--;
        }

        while (b > 0)
        {
            cout << "= ";
            b--;
        }

        cout << endl;
    }
}
