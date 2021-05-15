#ifndef basa
#define basa

#include <iostream>
#include <vector>

using namespace std;

class basic
{
private:
    string name;
    basic* head;
public:
    vector <basic* > slave;
    vector <basic* >::iterator slave_iter;
    basic(basic* head, string name);
    basic(basic* head);
    void setname(string name);
    string getname();
    void out();
    void sethead(basic* head);
    basic* gethead();
};

class negr: public basic
{
public:
    negr(basic* head, string name);
};

class mainbas: public basic
{
private:
    basic* hhead;
    basic* sslave;
public:
    mainbas(basic* head = 0);
    void drevo();
    int run();
};

#endif
