#include "basic_file.hpp"

BasicClass::BasicClass(BasicClass* parent, string name){
    NewHead(parent);
    SetterName(name);
}

BasicClass::BasicClass(BasicClass* parent){
    this->parent = parent;
}

void BasicClass::SetterName(string name){
    this->name = name;
}

string BasicClass::GetterName(){
    return this->name;
}

void BasicClass::NewHead(BasicClass* parent){
    this->parent = parent;
    if (parent){
        parent->children.push_back(this);
    }
}

void BasicClass::showtree(){
    if (children.empty())
        return;
    cout << endl << name;
    t = children.begin();
    while (t != children.end()){
        cout << " " << (*t)->GetterName();
        t++;
    }
    t--;
    (*t)->showtree();
}

Class1::Class1(BasicClass* parent) : BasicClass(parent){
}

void Class1::buildtree(){
    string parent_name, child_name;
    cin >> parent_name;
    SetterName(parent_name);
    temp_parent = this;
    do{
        cin >> parent_name >> child_name;
        if (parent_name == child_name)
            return;
        if (parent_name != temp_parent->GetterName()){
            if (parent_name == temp_child->GetterName()){
                temp_parent = temp_child;
            } else continue;
        }
        temp_child = new BasicClass(temp_parent, child_name);
    }while (true);
}

int Class1::start(){
    cout << GetterName();
    showtree();
    return 0;
}

