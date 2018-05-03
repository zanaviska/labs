#include <bits/stdc++.h>

using namespace std;

class Tree
{
    struct Vertex
    {
        int key;
        shared_ptr<Vertex> left;
        shared_ptr<Vertex> right;
        Vertex(int key)
        {
            this->key = key;
            this->left = nullptr;
            this->right = nullptr;
        }
    };
    int length;
    shared_ptr<Vertex> root;
public:
    Tree():
        length(0),
        root(nullptr)
    {};
    shared_ptr<Vertex> begin()
    {
        return root;
    }
    void push(int);
    void get_all_keys(vector<int>&vec, shared_ptr<Vertex> now);
    int erase(int key);
    int size(){
        return length;
    }
    ~Tree(){}

};

