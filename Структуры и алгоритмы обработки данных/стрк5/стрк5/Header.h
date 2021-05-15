//
//  Header.h
//  стрк5
//
//  Created by Andrey Novikov on 02.05.2021.
//

#ifndef Header_h
#define Header_h

#include <iostream>
using namespace std;

// Realization for massive
//============================


//int N = 1;
//
//struct Stack{
//    int* array = new int[N];
//    int top = -1;
//};
//
//void NewArray(Stack*& a){
//    N = N*2;
//    int* array = new int [N];
//    for (int i = 0; i < N/2; i++)
//        array[i] = a->array[i];
//    delete[] a->array;
//    a->array = array;
//}
//
//void push(Stack*& a, int b){
//    if (a->top == N-1)
//        NewArray(a);
//    a->top++;
//    a->array[a->top] = b;
//}
//
//int last(Stack* a){
//    return a->array[a->top];
//}
//
//void Empty(Stack* a){
//    if (a->top == -1)
//        cout<<"Stack is empty."<<endl;
//    else
//        cout<<"Stack is not empty."<<endl;
//}
//
//void clear(Stack*& a){
//    a->top = -1;
//    for (int i = 0; i < N; i++){
//        a->array[i] = NULL;
//    }
//}


//Realization for List
//========================


struct Stack{
    Stack* pred = NULL;
    int i;
    bool status = false;
};

void push(Stack*& a, int b){
    Stack* q = new Stack;
    q->status = true;
    Stack* q1 = a;
    q->i = b;
    if (a != NULL)
        q->pred = q1;
    else
        q->pred = NULL;
    a = q;
}

void StackOut(Stack* a){
    if (a->pred != NULL){
        cout << a->i << " ";
        a = a->pred;
        if (a->pred != NULL)
            StackOut(a);
        else
            cout<<endl;
    }
}

int last(Stack* a){
    return a->i;
}

void Empty(Stack* a){
    if (a->status == false)
        cout<<"Stack is empty."<<endl;
    else
        cout<<"Stack is not empty."<<endl;
}

void clear(Stack*& a){
    Stack *q, *q1;
    q = a;
    while(q != NULL){
        q1 = q->pred;
        delete q;
        q = q1;
    }
}

#endif /* Header_h */
