
#ifndef basic_file_hpp
#define basic_file_hpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class basic_class
{
private:
    string name;
    basic_class* parent;
public:
    basic_class(basic_class* parent, string name);
    basic_class(basic_class* parent);
    void set_new_name(string name);
    string get_name();
    void show_tree();
    vector <basic_class*> children;
    
};

class basic_class1: public basic_class{
public:
    using basic_class::basic_class;
};
class basic_class2: public basic_class{
public:
    using basic_class::basic_class;
};
#endif 
