#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
long long C = 0;
long long M = 0;

void Selection_sort(int *a, int n){
    C = 0; M = 0;
    for (int j = 1; j < n; j++){
        int i_max = 0;
        for (int i = 1; i < n; i++){
            C++;
            if (a[i] > i_max){
                i_max = i;
            }
        }
        M++;
        swap(a[n-j], a[i_max]);
    }
}

//void insort(int *a, int n){
//    C = 0; M = 0;
//    for (int j = 1; j < n; j++)
//    {
//        int i; i = j;
//        int temp; temp = a[i];
//        while (i > 0 && temp < a[i-1])
//        {
//            C++;
//            M++;
//            a[i] = a[i-1];
//            i--;
//        }
//        a[i] = temp; M++;
//    }
//}

//void array_inc(int *a, int n)
//{
//    for (int i = 0; i < n; i++)
//        a[i] = i;
//}
//
//void array_dec(int *a, int n)
//{
//    for (int i = 0; i < n; i++)
//        a[i] = n - i + 1;
//}

void array_Rand(int *a, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10;
    }
}

int main()
{
    int start_time, end_time;
    int n = 10;
    for (int i = 0; i < 5; i++)
    {
        start_time = clock();
        n *= 10;
        int *a = new int[n];
        array_Rand(a, n);
        Selection_sort(a, n);
        end_time = clock();
        end_time -= start_time;
        cout << "N: " << n << endl << "Time: " << end_time << endl << "C + M: " << C + M << endl;
        delete [] a;
    }
}
