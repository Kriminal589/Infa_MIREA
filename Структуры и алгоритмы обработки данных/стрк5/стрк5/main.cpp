#include "Header.h"

int main()
{
// Realization for massive
//============================

//    Stack* a = new Stack;
//    int x; int N;
//    cin >> N;
//    for (int i = 0; i < N; i++){
//        cin >> x;
//        push(a, x);
//    }
//    for (int i = N-1; i >= 0; i--){
//        cout << a->array[i] << " ";
//    }
//    cout<<endl;
//    Empty(a);
//    cout << last(a)<<endl;
//    clear(a);
//    Empty(a);

//Realization for List
//==============================
    
    Stack* a = new Stack;
    int x; int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> x;
        push(a, x);
    }
    StackOut(a);
    Empty(a);
    cout << last(a) << endl;
    clear(a);
    Empty(a);
   
    
// a+b+c-b-s+d = +--++abcbsd
//    string equation;
//    cin >> equation;
//    string result = "";
//    for (long i = 0; i < equation.length(); i++){
//        if ((equation[i] == '+')||(equation[i] == '-')){
//        //============= Работает, не трогай =========================
//            if ((equation[i+2] != '*') && (equation[i+2] != '/')){
//                string t = result;
//                result = equation[i];
//                result += t;
//                result += equation[i-1];
//                if (i + 1 == equation.length()-1)
//                    result += equation[i+1];
//            }
//        }
//        //============= Работает, не трогай ==========================
//        else{
//            if (equation[i+2] == '*'){
//
//            }
//        }
//    }
//    cout << result;
//
    
    
    return 0;
}
