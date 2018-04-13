#include "hash_table.h"

int HashTable::gesh(string s)
{
    int gesh = 0;
    for(int i = 0; i < s.size(); i++)
        gesh = (gesh + (s[i]-'a'+1))%md;
    return gesh;
}

void HashTable::push(string key, int data)
{
    shared_ptr<Node> now = arr[gesh(key)];
    shared_ptr<Node> last = nullptr;
    while(now != nullptr)
    {
        last = now;
        if(now->key == key)
        {
            now->data = data;
            return;
        }
        if(key < now->key)
            now = now->left;
        else
            now = now->right;
    }
    auto it = make_shared<Node>(key, data, nullptr, nullptr, last);
    now = it;
    if(last == nullptr)
    {
        arr[gesh(key)] = it;
        return;
    }
    if(last->key > key)
        last->left = now;
    else
        last->right = now;
}

int HashTable::get(string key)
{
    shared_ptr<Node> now = arr[gesh(key)];
    while(now != nullptr && now->key != key)
        if(key < now->key)
            now = now->left;
        else
            now = now->right;
    if(now != nullptr)
        return now->data;
    else
        throw invalid_argument("there is not that key");
}

int HashTable::erase(string key)
{
    shared_ptr<Node> now = arr[gesh(key)];
    bool r = 0;
    while(now != nullptr && now->key != key)
        if(now->key < key)
            r = 1,
            now = now->right;
        else
            r = 0,
            now = now->left;
    if(now == nullptr)
        throw invalid_argument("there is not that key");
    int ans = now->data;
    if(now->left == nullptr)
    {
        if(now->right != nullptr)
            now->right->parent = now->parent;
        if(now->parent == nullptr)
        {
            arr[gesh(key)] = now->right;
            return ans;
        }
        if(r)
            now->parent->right = now->right;
        else
            now->parent->left = now->right;
        return ans;
    }
    if(now->right == nullptr)
    {
        if(now->left != nullptr)
            now->left->parent = now->parent;
        if(now->parent == nullptr)
        {
            arr[gesh(key)] = now->left;
            return ans;
        }
        if(r)
            now->parent->right = now->left;
        else
            now->parent->left = now->left;
        return ans;
    }
    shared_ptr<Node> next = now->right;
    r = 0;
    while(next->left != nullptr)
        r = 1,
        next = next->left;
    now->data = next->data;
    if(!r)
        next->parent->left = next->right;
    else
        now->right = next->right;
    if(next->right != nullptr)
        next->right->parent = next->parent;
    return ans;
}
