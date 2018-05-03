#include "tree.h"

using namespace std;

void Tree::push(int key)
{
    length++;
    if(root == nullptr)
    {
        root = make_shared<Vertex>(Vertex(key));
        return;
    }
    auto now = root;
    while(true)
        if(key < now->key)
        {
            if(now->left == nullptr)
            {
                now->left = make_shared<Vertex>(Vertex(key));
                return;
            }
            now = now->left;
        } else
        {
            if(now->right == nullptr)
            {
                now->right = make_shared<Vertex>(Vertex(key));
                return;
            }
            now = now->right;
        }
}

void Tree::get_all_keys(vector<int>&vec, shared_ptr<Vertex> now)
{
    if(now == nullptr) return;
    get_all_keys(vec, now->left);
    //cerr << now->key << '\n';
    vec.push_back(now->key);
    get_all_keys(vec, now->right);
}

int Tree::erase(int key)
{
    auto now = root;
    shared_ptr<Vertex> last = nullptr;
    bool r = 0;
    while(now != nullptr && now->key != key)
        if(key < now->key)
        {
            last = now;
            now = now->left;
            r = 0;
        }
        else
        {
            last = now;
            now = now->right;
            r = 1;
        }
    //cerr << '#' << now->key << '\n';
    //cerr << '#' << last->key << '\n';
    if(now == nullptr)
        return -1000;
    auto prev = now;
    auto next = now->right;
    if(now->left == nullptr)
    {
        if(now == root)
            root = now->right;
        else if(r)
            last->right = now->right;
        else
            last->left = now->right;
        return key;
    }
    if(now->right == nullptr)
    {
        if(now == root)
            root = now->left;
        else if(r)
            last->right = now->left;
        else
            last->left = now->left;
        return key;
    }
    while(next->left != nullptr)
    {
        prev = next;
        next = next->left;
    }
    if(prev == now)
        now->right = next->right;
    else
        prev->left = next->right;
    now->key = next->key;
    return key;
}

