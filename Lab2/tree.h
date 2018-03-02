#include <bits/stdc++.h>

using namespace std;

class Tree
{
    struct Vertex
    {
        int key;
        int value;
        bool is_used;
    };
    Vertex* arr;
    int ln;//size of tree;
public:
    Tree():
        ln(0),
        arr(new Vertex[1<<20])
    {};

    void push(int, int);
    int find_min(int now = 1);
    int find_max(int now = 1);
    void get_all_values(vector<int>&vec, int now = 1);
    int size(){
        return ln;
    }
    ~Tree(){
        delete []arr;
    }
};

