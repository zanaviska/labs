#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Our matrix: \n";
    int xm[3][5];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
            cout << (xm[i][j] = rand()%20) << ' ';
        cout << '\n';
    }
    cout << "Enter count if you want to calculate row else we will calculate minimum in each line\n";
    string s;
    cin >> s;
    if(s == "count")
    {
        int cnt = 0;
        int last = -1;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 5; j++)
                if(xm[i][j] > 9 && last != i)
                    cnt++,
                    last = i;
        cout << cnt << '\n';
    } else
    {
        for(int i = 0; i < 3; i++)
        {
            int mn = xm[i][0];
            for(int j = 1; j < 5; j++)
                mn = min(mn, xm[i][j]);
            cout << mn << '\n';
        }
    }
    
}
