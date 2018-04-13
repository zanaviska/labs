#include<bits/stdc++.h>

using namespace std;

class HashTable
{
    struct Node
    {
        string key;
        int data;
        shared_ptr<Node> left;
        shared_ptr<Node> right;
        shared_ptr<Node> parent;
        Node(string key, int data, shared_ptr<Node> left, shared_ptr<Node> right, shared_ptr<Node> parent)
        {
            this->key = key;
            this->data = data;
            this->left = left;
            this->right = right;
            this->parent = parent;
        }
    };
    vector<int> st;
    int md = 9e4+7;
    shared_ptr<Node> arr[100000];
    int gesh(string s);
public:
    HashTable()
    {
        st.push_back(1);
        for(int i = 1; i < 20; i++)
            st.push_back((st[i-1]*41)%md);
    }
    ~HashTable(){}
    void push(string key, int data);
    int get(string key);
    int erase(string key);
};
