#include "tree.h"

using namespace std;

void Tree::push(int key, int value)
{
    int now = 1;
    while(arr[now].is_used)
        now = (now<<1) + (arr[now].key < key);
    arr[now].key = key;
    arr[now].value = value;
    arr[now].is_used = 1;
}

int Tree::find_min(int now)
{
    if(!arr[now].is_used) return 10000;
    int ans = arr[now].value;
    ans = min(ans, find_min(now<<1));
    ans = min(ans, find_min((now<<1)+1));
    return ans;
}

int Tree::find_max(int now)
{
    if(!arr[now].is_used) return -10000;
    int ans = arr[now].value;
    ans = max(ans, find_min(now<<1));
    ans = max(ans, find_min((now<<1)+1));
    return ans;
}

void Tree::print(int now)
{
    if(!arr[now].is_used) return;
    print(now<<1);
    cout << arr[now].value << ' ';
    print((now<<1)+1);
}
