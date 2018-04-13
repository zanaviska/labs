#include "tree.h"

using namespace std;

void Tree::push(int key)
{
    int now = 1;
    while(arr[now].is_used)
        now = (now<<1) + (arr[now].key < key);
    arr[now].key = key;
    arr[now].is_used = 1;
}

void Tree::get_all_keys(vector<int>&vec, int now)
{
    if(arr[now].is_used == 0) return;
    get_all_keys(vec, now<<1);
    vec.push_back(arr[now].key);
    get_all_keys(vec, (now<<1)+1);
}

void Tree::up(int pos, int old)
{
    queue<pair<int, int>> q;
    q.push({pos, old});
    while(!q.empty())
    {
        pos = q.front().first;
        old = q.front().second;
        q.pop();
        arr[pos] = arr[old];
        if(!arr[old].is_used)
            continue;
        q.push({pos<<1, old<<1});
        q.push({(pos<<1)+1, (old<<1)+1});
    }
}

int Tree::erase(int key)
{
    int now = 1;
    while(arr[now].is_used && arr[now].key != key)
    {
        //if(key == 15) cout << arr[now].key << ' ';
        now = (now<<1)+(arr[now].key < key);
    }
    if(!arr[now].is_used)
        return -1000;
    if(!arr[now<<1].is_used)
    {
        up(now, (now<<1)+1);
        return key;
    }
    if(!arr[(now<<1)+1].is_used)
    {
        up(now, now<<1);
        return key;
    }
    int ver = (now<<1)+1;
    while(arr[ver<<1].is_used)
        ver <<= 1;
    arr[now] = arr[ver];
    up(ver, (ver<<1)+1);
    return key;
}
