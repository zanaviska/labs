#include <bits/stdc++.h>

using namespace std;

class Tree
{
    struct Vertex
    {
        int key;
        bool is_used;
    };
    Vertex* arr;
    int ln;//size of tree;
public:
    Tree():
        ln(0),
        arr(new Vertex[1<<20])
    {};

    void push(int);
    void get_all_keys(vector<int>&vec, int now = 1);
    int erase(int key);
    void up(int, int);
    int size(){
        return ln;
    }
    ~Tree(){
        delete []arr;
    }

};

