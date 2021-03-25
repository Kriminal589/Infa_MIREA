#include "basic_file.hpp"
#include <iostream>
using namespace std;

basic_class::basic_class(basic_class* parent, string name){
    set_new_name(name);
    this->parent = parent;
    if (parent != 0)
        this->parent->children.push_back(this);
}

basic_class::basic_class(basic_class* parent){
    this->parent = parent;
}

void basic_class::set_new_name(string name){
    this->name = name;
}

string basic_class::get_name()
{
    return name;
}

void basic_class::show_tree()
{
    cout << this->get_name();
    for (int i = 0; i < this->children.size(); i++) {
        cout << " " << this->children[i]->get_name();
    }
    for (int i = 0; i < this->children.size(); i++) {
        if (this->children[i]->children.size() != 0) {
            cout << endl;
            children[i]->show_tree();
        }
    }
}



