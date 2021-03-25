#include <iostream>
#include <string>
#include "basic_file.hpp"
 
using namespace std;
 
int main()
{
    string root, parent, name;
    cin >> root;
    basic_class2* ob = new basic_class2(0, root);
    basic_class* ob_root = ob;
    basic_class2* temp = 0;
    for (int i = 0; ; i++)
    {
        cin >> parent >> name;
        if (parent == name)
            break;
        if (i != 0 && ob->get_name() != parent)
            ob = temp;
        temp = new basic_class2(ob, name);
    }
    cout << ob_root->get_name() << endl;
    ob_root->show_tree();
    delete ob_root;
    delete temp;
    cout<<endl;
    return 0;
}
