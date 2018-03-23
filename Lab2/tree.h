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
    int length;//size of tree;
public:
    Tree():
        length(0),
        arr(new Vertex[1<<20])
    {};

    void push(int key, int value);
    int find_min(int now = 1);
    int find_max(int now = 1);
    void get_all_values(vector<int>&vec, int now = 1);
    void get_all_leaf(vector<int>&vec, int now = 1);
    int size(){
        return length;
    }
    ~Tree(){
        delete []arr;
    }
};

