#include "double_linked.h"

using namespace std;

int List::push_back(int new_element_data)
{
    ln++;
    auto temp = make_shared<Node>(); // new element of list
    temp->data = new_element_data;
    temp->next = nullptr;
    temp->prev = nullptr;
    if(first == nullptr)
    {
        first = temp;
        last = temp;
        return 0;
    }
    temp->prev = last;
    last->next = temp;
    last = temp;
}

int List::insert(int pos, int new_element_data)
{
    if(pos < 0 || pos > ln)
        throw invalid_argument("Not possible to execute!!!!!");
    if(pos == 0) return push_front(new_element_data);
    if(pos == ln) return push_back(new_element_data);
    ln++;
    auto temp = make_shared<Node>(); // new element of list
    temp->data = new_element_data;
    shared_ptr<Node> now = first;
    for(int i = 0; i < pos; i++)
        now = now->next;
    now->prev->next = temp;
    temp->prev = now->prev;
    now->prev = temp;
    temp->next = now;
}

int List::push_front(int new_element_data)
{
    ln++;
    auto temp = make_shared<Node>(); // new element of list
    temp->data = new_element_data;
    temp->next = nullptr;
    temp->prev = nullptr;
    if(first == nullptr)
    {
        first = temp;
        last = temp;
        return 0;
    }
    temp->next = first;
    first->prev = temp;
    first = temp;
}

void List::erase(int position)
{
    if(position < 0 || position >= ln)
        throw invalid_argument("Not possible to execute");
    if(position == 0)
    {
        first = first->next;
        first->prev = nullptr;
        return;
    }
    if(position == ln-1)
    {
        last = last->prev;
        last->next = nullptr;
        return;
    }
    shared_ptr<Node> now = first;
    for(int i = 0; i < position; i++)
        now = now->next;
    now->prev->next = now->next;
    now->next->prev = now->prev;
}

void print(List a)// a is name of output List
{
    for(auto it = a.begin(); it != nullptr; it = it->next)
    {
        cout << it->data << "(";
        if(it->prev != nullptr)
            cout << it->prev->data << ", ";
        if(it->next != nullptr)
            cout << it->next->data;
        cout << ")\n";
    }
}

void List::merge(List list1)// merge two List in one
{
    shared_ptr<Node> now = list1.first;
    while(now != nullptr)
    {
        this->push_back(now->data);
        now = now->next;
    }
}

