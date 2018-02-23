#include <bits/stdc++.h>

#define files(x) ((x != "")? (freopen(x".dat", "r", stdin), freopen(x".sol", "w", stdout)):(0))
#define fast ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
#define pb push_back
#define ft first
#define sd second

using namespace std;

struct Tree
{
    int l, key, value, r;
    bool is;
};

Tree tr[100000];
int pos = 0;
bool is;

void push(int x, int y)
{
    int now = 0;
    if(!is)
    {
        tr[0].key = x;
        tr[0].value = y;
        is = 1;
        return;
    }
    while(1)
        if(x <= tr[now].key)
        {
            if(!tr[now].l)
            {
                tr[now].l = ++pos;
                now = pos;
                break;
            }
            now = tr[now].l;
        } else
        {
            if(!tr[now].r)
            {
                tr[now].r = ++pos;
                now = pos;
                break;
            }
            now = tr[now].r;
        }
    tr[now].key = x;
    tr[now].value = y;
}

int findMin(int now)
{
    int ans = tr[now].value;
    if(tr[now].l)
        ans = min(ans, findMin(tr[now].l));
    if(tr[now].r)
        ans = min(ans, findMin(tr[now].r));
    return ans;
}

void print(int now)
{
    if(tr[now].l) print(tr[now].l);
    cout << tr[now].value << ' ';
    if(tr[now].r) print(tr[now].r);
}

int main()
{
    #ifdef ANDRII
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #else
        files("");
    #endif // ANDRII
    srand(time(0));
    for(int i = 0; i < 15; i++)
    {
        int a = rand()%199-99;
        int b = rand()%199-99;
        push(a, b);
        cout << a << ' ' << b << '\n';
    }
    cout << findMin(0) << '\n';
    print(0);
}
/*

*/
