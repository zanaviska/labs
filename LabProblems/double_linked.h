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
    int length;
    shared_ptr<Node> first;
    shared_ptr<Node> last;
public:
    List():
        first(nullptr),
        last(nullptr),
        length(0)
    {};
    void push_back(int data);
    void push_front(int data);
    void insert(int position, int data);
    int size(){
        return length;
    }
    shared_ptr<Node> begin()
    {
        return first;
    }
    shared_ptr<Node> end()
    {
        return last;
    }
    void erase(int position);
    void merge(List &list2);
    ~List() {}

    friend class ListIter;
};

class ListIter
{

};
