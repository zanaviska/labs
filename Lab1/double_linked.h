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
    shared_ptr<Node> begin(){
        return first;
    }
    shared_ptr<Node> end(){
        return last;
    }
    void erase(int);

    friend List merge(List a, List b);

    ~List() {}
};

void print(List);// a is name of output List

List merge(List, List);// merge two List in one
