#include <iostream>
using namespace std;

int main()
{
    int L, M;
    cin >> L >> M;
    while (L != M) {
        if (L > M)
            L = L - M;
        else
            M = M - L;
    }
    cout << M << endl;
}
