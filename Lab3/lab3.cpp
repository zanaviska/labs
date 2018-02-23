#include <bits/stdc++.h>

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

bool is[100][100];
bool vis[100][100];
int cnt[100];
vi sol;
int n;

void dfs(int now, int last)
{
    sol.pb(now);
    if(now == last && cnt[now] == 0)
        return;
    for(int i = 1; i <= n; i++)
        if(is[now][i])
        {
            cnt[now]--;
            cnt[i]--;
            is[now][i] = 0;
            is[i][now] = 0;
            dfs(i, last);
            return;
        }
}

int main()
{
    #ifdef ANDRII
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #else
        files("");
    #endif // ANDRII
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        is[u][v] = 1;
        is[v][u] = 1;
        cnt[u]++;
        cnt[v]++;
    }
    int last = -1, now = -1;
    for(int i = 1; i <= n; i++)
        if(cnt[i]&1)
        {
            last = now;
            now = i;
        }
    if(last*now < 0) return cout << "Wrong input!!", 0;
    if(last == -1)
        last = 1,
        now = 1;
    vi ans;
    while(1)
    {
        sol.clear();
        bool x = 0;
        dfs(now, last);
        if(ans.empty())
            ans = sol;
        else
        {
            vi dop;
            for(int i = 0; i < ans.size(); i++)
                if(ans[i] == sol[0] && !x)
                {
                    x = 1;
                    for(auto j:sol)
                        dop.pb(j);
                }
                else
                    dop.pb(ans[i]);
            ans = dop;
        }
        x = 0;
        for(int i = 1; i <= n; i++)
            if(cnt[i])
            {
                x = 1;
                last = i;
                now = i;
                break;
            }
        if(!x)
            break;
    }
    for(auto i:ans)
        cout << i << ' ';

}
/*

*/
