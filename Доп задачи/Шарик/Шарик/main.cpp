/*
 Из урны с 10 пронумерованными шариками вынимают по одному шарику. Подсчитать общее количество ситуаций, когда номер хотя бы одного вынутого
 шарика совпадает с порядковым номером действия "вынимания", например, когда шарик № 3 будет вынут 3-им по порядку.
*/

#include <iostream>
using namespace std;
 
unsigned factorial(unsigned n) {
    return ((n > 1) ? n * factorial(n - 1) : n);
}
 
unsigned Count(bool select[], unsigned n, unsigned step = 0) {
    unsigned count = 0;
    if (step >= n) {
        count = 1;
    }
    else {
        for (unsigned i = 0; i < n; i++) {
            if ((i != step) && !select[i]) {
                select[i] = true;
                count += Count(select, n, step + 1);
                select[i] = false;
            }
        }
    }
 
    return count;
}

 
int main() {
    int N; cout << "Write N: "; cin >> N;
    bool select[N];
 
    for (auto &f : select) {
        f = false;
    }
 
    cout << factorial(N) - Count(select, N) << endl;
 
    return 0;
}
