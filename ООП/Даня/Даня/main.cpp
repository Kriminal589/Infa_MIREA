#include <iostream>
using namespace std;

enum type
{
    decline,
    profit
};

struct node
{
    int acc_num;
    time_t date;
    type data;
    int sum;
    node* next;
    node* prev;
};


void create_undlist(node* L, node*& M, int num)
{
    node* q = L;
    M = new node;
    M = q;
    M->date = time(0);
    M->next = NULL;
    q = q->next;
    bool flag = false;
    cout << "flag created." << endl;
    while(q)
    {
        cout << "in L." << endl;
        if(q->acc_num == num)
        {
            cout << "numbers matched." << endl;
            if(!flag)
            {
                cout << "see no flag." << endl;
                if(q->data == profit)
                {
                    cout << "profit no flag." << endl;
                    M->sum += q->sum;
                }
                else
                {
                    cout << "decline no flag." << endl;
                    M->sum = (signed)( M->sum - q->sum);
                    flag = true;
                }
            }
            else
            {
                cout << "i see flag." << endl;
                if(q->data == decline)
                {
                    cout << "decline flag." << endl;
                    M->sum = (signed)(M->sum - q->sum);
                }
                else
                {
                    cout << "profit flag." << endl;
                    node *w = new node;
                    w = q->next;
                    M->next = w;
                    M = M->next;
                    M->sum += q->sum;
                    M->date = time(0);
                    flag = false;
                }
            }
        }
        else
            cout << "missed a cycle." << endl;
        if(q->next != NULL)
            q = q->next;
    }
    while (M->prev != NULL){
        cout << "in prev cycle.";
        M = M->prev;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
