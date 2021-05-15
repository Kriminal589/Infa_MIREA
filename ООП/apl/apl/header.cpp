//
//  header.cpp
//  apl
//
//  Created by Andrey Novikov on 04.05.2021.
//

#include "header.hpp"

basic::basic(basic* head, string name)
{
    sethead(head);
    setname(name);
}

void basic::setname(string name)
{
    this->name = name;
}

string basic::getname()
{
    return this->name;
}

void basic::out()
{
    if (slave.empty()) return;
    cout << endl << name;
    slave_iter = slave.begin();
    while (slave_iter != slave.end())
    {
        cout << " " << (*slave_iter)->getname();
        slave_iter++;
    }
    slave_iter--;
    (*slave_iter) -> out();
}

void basic::sethead(basic* head)
{
    this->head = head;
    if (head){
        head->slave.push_back(this);
    }
}

basic::basic(basic* head)
{
    sethead(head);
}

mainbas::mainbas(basic* head): basic(head){}

void mainbas::drevo()
{
    string head_name, slave_name;
    cin >> head_name;
    setname(head_name);
    hhead = this;
    while(true)
    {
        cin >> head_name >> slave_name;
        if (head_name == slave_name) return;
        if (head_name != hhead->getname())
        {
            if (head_name == sslave->getname()) hhead = sslave;
            else continue;
        }
        sslave = new negr(hhead, slave_name);
    }
}

int mainbas::run()
{
    cout << getname();
    out();
    return 0;
}


negr::negr(basic* head, string name): basic(head, name){}
