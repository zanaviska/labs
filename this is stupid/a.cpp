#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Array m:\n";
    int m[15];
    for(int i = 0; i < 15; i++)
        cout << (m[i] = rand()%20) << ' ';
    cout << "\nEnter min, if I should write index of minimum element, and write in another case\n";
    string s;
    cin >> s;
    int md[15];
    int ind = 0;
    if(s == "min")
    {
        for(int i = 1; i < 15; i++)
        {
            if(m[i] < m[ind])
                ind = i;
            md[i-ind] = m[i];
        }
        cout << "minimum element has index: " << ind << '\n';
    } else
    {
        for(int i = 1; i < 15; i++)
        {
            if(m[i] > m[ind])
                ind = i;
            md[i-ind] = m[i];
        }
        cout << "maximum element has index: " << ind << '\n';
    }
    cout << "Array md:\n";
    for(int i = 0; i < 15-ind; i++)
        cout << md[i] << ' ';
}