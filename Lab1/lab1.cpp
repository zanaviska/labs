#include <bits/stdc++.h>
#include "double_linked.h"

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
    int n, m;//n - size of first List, m - size of second List
    cin >> n;
    cin >> m;
    List a = List();
    List b = List();
    for(int i = 0; i < n; i++)
    {
        int s = i;
        cin >> s;
        a.push_back(s);
    }
    for(int i = 0; i < m; i++)
    {
        int s = i+n;
        cin >> s;
        b.push_front(s);
    }
    //print(a);
    //print(b);
    a.merge(b);
    cout << "Merged:\n";
    print(a);
    ListIter it = a.begin();
    while(it != a.end())
        cout << *it << ' ',
        ++it;
}
