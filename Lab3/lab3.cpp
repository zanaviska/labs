#include <bits/stdc++.h>
#include "loop.h"

#define files(x) ((x != "")? (freopen(x".dat", "r", stdin), freopen(x".sol", "w", stdout)):(0))
#define fast ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
#define pb push_back
#define ft first
#define sd second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main()
{
    /*#ifdef ANDRII
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #else
        files("");
    #endif // ANDRII*/
    int n = 5;
    //cin >> n >> m;
    vector<vi> x =
    {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };
    for(int i = 0; i < n; i++)
        x[i].resize(n);
    vi ans = get_eiler_loop(x, n);
    cout << "Eiler loop:\n";
    for(auto i:ans)
        cout << i << ' ';
}
/*
1 2
1 3
1 4
2 3
2 4
4 5
*/
