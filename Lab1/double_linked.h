#include<bits/stdc++.h>

using namespace std;

class List
{
    struct Node
    {
        int data;
        shared_ptr<Node> prev;
        shared_ptr<Node> next;
        ~Node(){}
    };
    int ln;// size of list
    shared_ptr<Node> first;
    shared_ptr<Node> last;
public:
    List():first(nullptr), last(nullptr), ln(0){};
    int push_back(int);
    int push_front(int);
    int insert(int, int);
    int size(){
        return ln;
    }
    shared_ptr<Node> begin()
    {
        return first;
    }
    shared_ptr<Node> end()
    {
        return nullptr;
    }
    shared_ptr<Node> rbegin()
    {
        return last;
    }
    shared_ptr<Node> rend()
    {
        return nullptr;
    }
    void erase(int);
    void merge(List list1);
    ~List() {}

    friend void print(List a);
    friend class ListIter;
};

class ListIter
{
    shared_ptr<List::Node> itr;
public:

    ListIter(shared_ptr<List::Node> temp):
        itr(temp)
    {};

    ListIter& operator= (const shared_ptr<List::Node> temp)
    {
        itr = temp;
        return *this;
    };

    ListIter& operator++()
    {
        itr = itr->next;
        return *this;
    };

    ListIter& operator--()
    {
        itr = itr->next;
        return *this;
    };

    bool operator== (const ListIter& rhs)
    {
        return itr == rhs.itr;
    };

    bool operator!= (const ListIter& rhs)
    {
        return itr != rhs.itr;
    };

    int& operator*()
    {
        return itr->data;
    };
};
