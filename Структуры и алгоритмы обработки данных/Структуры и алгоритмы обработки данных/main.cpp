#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
const int N = 1000;

void inp_array (int *x,int n);

void out_array (int *x,int n);
/*
void inp_array_rand (int *x,int n);
 
int key(int *x,int n,int a);
 
int negative_array(int *x,int n);
 
void all_keys(int *x, int n, int a);
*/
void new_input(int *x, int &n, int a, int b);

void input_new(int* &x, int &n, int a, int b);

void deletion(int *x, int &n, int a);

void deletion_new(int *&x, int &n, int a);

void deletion_keys(int *x, int &n, int a);

void deletion_keys_new(int *&x, int &n, int a);

int main(){
    int a[N] = {0};
    int* pid = new int[1000];
    int b[N] = {0};
    int stop, key, stop_2;
    cout << "Введите N:" << endl;
    cin >> stop;
    stop_2 = stop;
    if (stop > N || stop < 0) return 1;
    inp_array(a, stop);
    out_array(a, stop);
    /*
    inp_array_rand(starushka, stopper);
    out_array(starushka, stopper);
    cout << "Vvedite klyuch:" << endl;
    cin >> key;
    key(a, stop, key);
    key(b, stop, key);
    all_keys(a, stop, key);
    all_keys(b, stop, key);
    negative_array(a, stop);
    */
    cout << "Новый индекс: ";
    int news; cin >> news;
    int newer; cin >> newer;
    new_input(a, stop, news, newer);
    out_array(a, stop);
    inp_array(pid, stop_2);
    out_array(pid, stop_2);
    input_new(pid, stop_2, news, newer);
    out_array(pid, stop_2);
    int d; cin >> d;
    deletion(a, stop, d);
    out_array(a, stop);
    deletion_new(pid, stop_2, d);
    out_array(pid, stop_2);
    int d_2; cin >> d_2;
    deletion_keys(a, stop, d_2);
    out_array(a, stop);
    deletion_keys_new(pid, stop_2, d_2);
    out_array(pid, stop_2);
}

void inp_array(int *x, int n){
    cout << "Введите " << n << " значений";
    for (int i = 0; i < n; i++) cin >> x[i];
}

void out_array(int *x, int n){
    cout << "Массив: " << endl;
    for (int i = 0; i < n; i++) cout << x[i] << endl;
}
/*
void inp_array_rand(int *x, int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++) x[i] = rand();
}
 
int key(int *x, int n, int a){
    for (int i = 0; i < n; i++){
        if (x[i] == a){
            cout << "Индекс: " << i << endl;
            return 0;
        }
    }
    cout << "Не найден индекс.";
    return 0;
}
 
int negative_array(int *x, int n){
    for (int i = 0; i < n; i++){
        if (x[i] < 0){
            cout << "Индекс: " << i << endl;
            return 0;
        }
    }
    cout << "Не найден индекс.";
    return 0;
}
 
void all_keys(int *x, int n, int a){
    int sum; sum = 0;
    for (int i = 0; i < n; i++){
        if (x[i] == a) sum += x[i];
    }
    cout << "Кол-во входов: " << sum << endl;
}
*/
void new_input(int *x, int &n, int a, int b){
    n++;
    for (int i = n; i > a; i--)
        x[i] = x[i-1];
    x[a] = b;
}

void input_new(int* &x, int &n, int a, int b){
    n++;
    x = (int*)realloc(x, sizeof(int)*n);
    for (int i = n; i > a; i--)
        x[i] = x[i-1];
    x[a] = b;
}

void deletion(int *x, int &n, int a){
    for (int i = a; i < n - 1; i++) x[i] = x[i+1];
    x[n-1] = NULL;
    n--;
}

void deletion_new(int *&x, int &n, int a){
    for (int i = a; i < n - 1; i++) x[i] = x[i+1];
    x[n-1] = NULL;
    n--;
    x = (int*)realloc(x, sizeof(int)*n);
}

void deletion_keys(int *x, int &n, int a){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (x[i] == a) count++;
        else x[i-count] = x[i];
    }
    for (int i = n - count; i < n; i++) x[i] = NULL;
    n -= count;
}

void deletion_keys_new(int *&x, int &n, int a){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (x[i] == a) count++;
        else x[i-count] = x[i];
    }
    for (int i = n - count; i < n; i++) x[i] = NULL;
    n -= count;
    x = (int*)realloc(x, sizeof(int)*n);
}
