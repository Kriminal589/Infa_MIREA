#include <iostream>
using namespace std;

int main()
{
    const int N = 30;
    char a[N];
    int flag = 1;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    while (flag == 1)
    {
        flag = 2;
        for (int i = 0; i < (N - 1); i++)
        {
            if (a[i] > a[i + 1])
            {
                flag = 1;
                swap(a[i], a[i + 1]);
            }
        }
    }
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
}
