#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

//Вывод списка
void out_list(Node* L){
    Node* q = L;
    while(q){
        cout << q->data <<" ";
        q = q->next;
    }
    cout<<endl;
}

//Добавление элемента в список, упорядоченный по не возрастанию
void add(Node *&L){
    Node *q1=new Node;
    cout << "Заполните узел: ";
    cin >> q1->data;
    Node* q = L;
    if (q->data <= q1->data){
        q1->next=q;
        L = q1;
    }
    else{
        while(q->next){
            if (q->next->data <= q1->data){
                q1->next=q->next;
                q->next = q1;
                break;
            }
            if (q->next->next == NULL){
                q->next->next = q1;
                q1->next = NULL;
                break;
            }
            q = q->next;
        }
    }
}

//Создание нового списка
void new_list(Node *&L){
    Node *q, *q1;
    cout << "Введите количество узлов: ";
    int x; cin >> x;
    for (int i = 0; i<x; i++){
        q = new Node;
        cin >> q->data;
        q->next = NULL;
        if(L == NULL){
            L = q;
            q1 = q;
        }
        else{
            q1->next = q;
        }
        q1 = q;
    }
}

//Нахождение нужного узла
Node *FindNode(Node *L, int n){
    int i = 1;
    Node *q = L;
    while (q != 0 && i < n){
        i++;
        q = q->next;
    }
    return q;
}

//функция, которая переформирует список L1, переписав в начало списка его часть, начиная с заданной позиции
void remove_list(Node *&L, int n){
    if (n != 1){
    Node *q1 = FindNode(L, n);
    Node *q = FindNode(L, n-1);
    Node * L1 = q1;
    q->next=NULL;
    while(q1->next){
        q1 = q1->next;
    }
    q1->next = L;
    L = L1;
    }
}


int main(int argc, const char * argv[]) {
    Node* L;
    new_list(L);
    cout<<endl;
    out_list(L);
    int n; cout << "С какого элемента перемещаем список? ";
    cin >> n;
    remove_list(L, n);
    out_list(L);
    add(L);
    out_list(L);
    return 0;
}
