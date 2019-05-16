#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Enter number of trains:\n";
    int n;
    cin >> n;
    map<string, int> cnt;
    map<int, vector<string>> trains;
    cout << "Enter destination and time of your trains:\n";
    while(n--)
    {
        int time;
        string des;
        cin >> time >> des;
        cnt[des]++;
        trains[time].push_back(des);
    }
    cout << "If you want to know about all trains, that arrive in some time enter 'time'\n";
    string s;
    cin >> s;
    if(s == "time")
    {
        cout << "Enter time:\n";
        int x;
        cin >> x;
        for(int i = 0; i < trains[x].size(); i++)
            cout << trains[x][i] << '\n';
    } else
    {
        cout << "Enter destination:\n";
        string s;
        cin >> s;
        cout << cnt[s];
    }
}