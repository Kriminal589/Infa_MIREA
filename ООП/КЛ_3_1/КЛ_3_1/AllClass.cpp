/*
 Проверка готовности объектов к работе


 Фрагмент методического указания.
 Создание объектов и построение исходного иерархического дерева объектов.
 Система собирается из объектов, принадлежащих определенным классам. В тексте постановки задачи классу соответствует уникальный номер. Относительно номера класса определяются требования (свойства, функциональность).
 Первоначальная сборка системы (дерева иерархии объектов, программы) осуществляется исходя из входных данных. Данные вводятся построчно.


 Первая строка содержит имя корневого объекта (объект приложение). Номер класса корневого объекта 1. Корневой объект объявляется в основной программе (main). Исходное состояние корневого объекта соответствует его функционированию.
 Далее, каждая строка входных данных определяет очередной объект, задает его характеристики и расположение на дереве иерархии.
 Структура данных в строке:
 «Наименование головного объекта» «Наименование очередного объекта» «Номер класса принадлежности очередного объекта» «Номер исходного состояния очередного объекта»


 Ввод иерархического дерева завершается, если наименование головного объекта равно «endtree» (в данной строке ввода больше ничего не указывается).


 Готовность объекта характеризуется значением его состояния. Значение состояния - целое число.
 Определены правила для значения состояния:
     0 – объект выключен;
     Отрицательное – объект включен, но не функционирует, обнаружена неисправность. Значение классифицирует характер неисправности.
    Положительное – объект включен, функционирует в штатном режиме. Значение определяет текущее состояние объекта.


 Подчиненные объекты располагаются слева на право относительно головного, согласно их следованию в исходных данных. Исходные данные подготовлены таким образом, что любой головной объект предварительно добавлен в качестве подчиненного. Подразумевается, что все объекты имеют уникальные имена.
 Для организации исходя из входных данных создания экземпляров объектов и формирования иерархического дерева, необходимо:
 1.      В базовом классе реализовать метод поиска объекта на дереве объектов по его наименованию и возврата указателя на него. Если объект не найден, то вернуть нулевой указатель.
 2.      В корневом объекте (объект приложения) реализовать метод чтения исходных данных, создания объектов и построения исходного дерева иерархии.

 ==============================================
 Пример


 Ввод
 
 app_root
 app_root object_1 3 1
 app_root object_2 2 1
 object_2 object_4 3 -1
 object_2 object_5 3 1
 app_root object_3 3 1
 object_2 object_6 2 1
 object_1 object_7 2 1
 endtree
 
 Вывод списка готовности объектов

 The object app_root is ready
 The object object_1 is ready
 The object object_7 is ready
 The object object_2 is ready
 The object object_4 is not ready
 The object object_5 is ready
 The object object_6 is ready
 The object object_3 is ready
 */

#include "AllClass.hpp"

#include <iostream>
using namespace std;

Application::Application(BasicClass* parent,int state) : BasicClass(parent, state) {}

Application::Application(BasicClass* parent, int state,string name) : BasicClass(parent, state, name) {}

void Application::buildTree() {
    string parent_name, child_name;
    int classNum, state;
    cin >> parent_name;
    setName(parent_name);
    temp_parent = this;
    root_parent = this;
    do {
        cin >> parent_name;
        if (parent_name == "endtree") return;
        if (parent_name != temp_parent->getName()) {
            temp_parent =find(parent_name);
        }
        cin >> child_name >> classNum >> state;
        switch(classNum)
        {
            case 2:
                temp_child = new Class4(temp_parent, state, child_name);
                break;
            case 3:
                temp_child = new Class2(temp_parent, state, child_name);
                break;
            case 4:
                temp_child = new Class3(temp_parent,state, child_name);
                break;
        }
    } while (true);
}
int Application::execute() {
    cout<<"Test result"<<endl;
    printState();
    return 0;
}

BasicClass::BasicClass(BasicClass* parent, int state, string name) {
    setParent(parent);
    setName(name);
    setState(state);
}
void BasicClass::setName(string name) {
    this->name = name;
}
void BasicClass::setState(int state) {
    this->state = state;
}
string BasicClass::getName() {
    return name;
}
int BasicClass::getState()
{
    return state;
}

void BasicClass::setParent(BasicClass* parent) {
    this->parent = parent;
    if (parent) {
        parent->children.push_back(this);
    }
}

void BasicClass::printState() {
    if (this->parent==0)
    {
        cout << "The object " << this->name << " is ready";
    }
    if (children.empty())
        return;
    children_iterator = children.begin();
    while (children_iterator != children.end()) {
        if ((*children_iterator)->getState()>0)
        {
            cout<<endl << "The object " << (*children_iterator)->getName()<<" is ready";
            (*children_iterator)->printState();
        }
        else
        {
            cout<< endl << "The object " << (*children_iterator)->getName() << " is not ready" ;
            (*children_iterator)->printState();
        }
        children_iterator++;
    }
    children_iterator--;
}

BasicClass* BasicClass::find(string parentName)
{
    BasicClass* search = nullptr;
    if (this->name == parentName){
        search=this;
        return search;
    }
    else
    {
        if (!children.empty()) {
            children_iterator = children.begin();
            while (children_iterator != children.end())
            {
                if (search != 0)
                    return search;
                search = (*children_iterator)->find(parentName);
                children_iterator++;
            }
            children_iterator--;
        }
        return(search);
    }
}

Class2::Class2(BasicClass* parent,int state, string name) : BasicClass(parent,state, name) {}

Class3::Class3(BasicClass* parent,int state, string name) : BasicClass(parent,state, name) {}

Class4::Class4(BasicClass* parent,int state, string name) : BasicClass(parent,state, name) {}
