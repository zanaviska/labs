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
        int high;
        Node(string key, int data, shared_ptr<Node> left, shared_ptr<Node> right, shared_ptr<Node> parent)
        {
            this->key = key;
            this->data = data;
            this->left = left;
            this->right = right;
            this->parent = parent;
            this->high = 0;
        }
    };
    vector<int> st;
    int md = 9e4+7;
    shared_ptr<Node> arr[100000];
    int gesh(string s);
    void turn_left(shared_ptr<Node>);
    void turn_right(shared_ptr<Node>);
    void make_parent(shared_ptr<Node>, shared_ptr<Node>);
    int max_high(shared_ptr<Node> now);
    void up(shared_ptr<Node>);
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
