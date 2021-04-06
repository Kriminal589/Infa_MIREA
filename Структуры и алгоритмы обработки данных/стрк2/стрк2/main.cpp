/*
 Номер счета в банке, дата, вид операции (приход или расход), сумма вклада.
 
 Удаление сведений по счету (всех узлов), у которого общая сумма вклада равна нулю ( сумма по приходу, минус
 сумма по расходу). Создать новый список из исходного, которого будет содержать остаток по всем видам
 операций одного счета, указав вид операции – приход, и текущую дату.
 */
#include <iostream>
using namespace std;

struct Node {
   int data;
   Node* next;
   Node* prev;
};

void createlist(Node *&L, int n) {
   Node *q, *q1 = NULL;
   cout << "Введите " << n << " чисел: ";
   for(int i = 1; i <= n; i++)
   {
       q = new Node;
       cin >> q->data;
       q->next = NULL;
       q->prev = NULL;
       if(L == NULL){ L = q; q1 = L; }
       else
       {
           q1->next = q;
           q->prev = q1;
           q1 = q;
       }
   }
}

void NewStartNode(Node *&L){
    Node *q = new Node;
    Node *q1 = L;
    q->next = NULL;
    q->prev = NULL;
    cin >> q->data;
    q1->prev = q;
    q->next = q1;
    L = q;
}

void outlist(Node *&L)
{
    Node *q = L;
    while(q != NULL)
    {
        cout << q->data << " ";
        q = q->next;
    }
}

void DeleteNode(){}

int main()
{
    Node *L = NULL;
    createlist(L, 5);
    outlist(L);
    cout << endl;
    NewStartNode(L);
    outlist(L);
    return 0;
}


