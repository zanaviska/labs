#include "tree.h"

using namespace std;

void Tree::push(int key, int value)
{
    length++;
    int now = 1;
    while(arr[now].is_used)
        now = (now<<1) + (arr[now].key < key);
    arr[now].key = key;
    arr[now].value = value;
    arr[now].is_used = 1;
    arr[now<<1].is_used = 0;
    arr[(now<<1)+1].is_used = 0;
}

int Tree::find_min(int now)
{
    if(length == 0)
        throw length_error("impossible to execute!!");
    if(arr[now].is_used == 0) return 10000;
    int ans = arr[now].value;
    ans = min(ans, find_min(now<<1));
    ans = min(ans, find_min((now<<1)+1));
    return ans;
}

int Tree::find_max(int now)
{
    if(length == 0)
        throw length_error("impossible to execute!!");
    if(arr[now].is_used == 0) return -10000;
    int ans = arr[now].value;
    ans = max(ans, find_max(now<<1));
    ans = max(ans, find_max((now<<1)+1));
    return ans;
}

void Tree::get_all_values(vector<int>&vec, int now)
{
    if(arr[now].is_used == 0) return;
    get_all_values(vec, now<<1);
    vec.push_back(arr[now].value);
    get_all_values(vec, (now<<1)+1);
}

void Tree::get_all_leaf(vector<int>&vec, int now)
{
    if(arr[now].is_used == 0) return;
    if(arr[now<<1].is_used == 0 && arr[(now<<1)+1].is_used == 0)
    {
        vec.push_back(arr[now].value);
        return;
    }
    get_all_leaf(vec, now<<1);
    get_all_leaf(vec, (now<<1)+1);
}
